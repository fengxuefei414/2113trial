#include "user_control.h"
#include <iostream>
#include <sys/select.h>
#include <termios.h>
#include <unistd.h>
#include <cmath>

struct termios UserControl::orig_termios; // 静态成员变量定义

// 构造函数：启用终端原始模式
UserControl::UserControl() : leftPressed(false), rightPressed(false) {
    enableRawMode();
}

// 析构函数：恢复终端原始模式
UserControl::~UserControl() {
    disableRawMode();
}

// 启用终端原始模式
void UserControl::enableRawMode() {
    tcgetattr(STDIN_FILENO, &orig_termios); // 保存当前终端设置
    atexit(disableRawMode);                 // 程序退出时恢复终端模式

    struct termios raw = orig_termios;
    raw.c_lflag &= ~(ECHO | ICANON | ISIG); // 关闭回显、行缓冲和信号处理
    raw.c_cc[VMIN] = 0;                     // 非阻塞输入
    raw.c_cc[VTIME] = 1;                    // 设置超时时间
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw);
}

// 恢复终端原始模式（静态函数）
void UserControl::disableRawMode() {
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &orig_termios); // 恢复原始终端设置
}

// 检测按键输入
char UserControl::getKeyPress() {
    char c = 0;
    fd_set fds;
    struct timeval tv = {0, 0}; // 非阻塞
    FD_ZERO(&fds);
    FD_SET(STDIN_FILENO, &fds);

    if (select(STDIN_FILENO + 1, &fds, NULL, NULL, &tv) > 0) {
        read(STDIN_FILENO, &c, 1);
    }
    return c;
}

// 处理用户输入
void UserControl::handleInput(int &playerX, int &playerY, bool &isJumping, float &playerVelocityX, float &playerVelocityY, const float JUMP_FORCE, int SCREEN_WIDTH) {
    char key = getKeyPress();

    leftPressed = false;
    rightPressed = false;

    // 处理按键输入
    if (key == 'a' || key == 'A') {
        if (playerX > 0) {
            playerX--; // 向左移动
        }
    } else if (key == 'd' || key == 'D') {
        if (playerX < SCREEN_WIDTH - 3) {
            playerX++; // 向右移动
        }
    } else if ((key == 'w' || key == 'W') && !isJumping) {
        isJumping = true;
        playerVelocityY = JUMP_FORCE; // 开始跳跃
    } else if (key == 'q' || key == 'Q') {
        // 退出逻辑可由主程序处理
    }

    const float acceleration = 0.5f;  // 加速度值
    const float maxSpeed = 3.0f;      // 最大移动速度
    const float friction = 0.85f;     // 摩擦系数（减速效果）

    // 根据按键状态更新水平速度
    if (leftPressed) {
        playerVelocityX -= acceleration;    // 向左加速
        playerVelocityX = std::max(playerVelocityX, -maxSpeed); // 限制最大速度
    } else if (rightPressed) {
        playerVelocityX += acceleration;    // 向右加速
        playerVelocityX = std::min(playerVelocityX, maxSpeed);
    } else {
        // 没有按键时应用摩擦力
        playerVelocityX *= friction;
        if (std::abs(playerVelocityX) < 0.1f) {
            playerVelocityX = 0.0f;  // 速度过小时归零
        }
    }
}