#ifndef USER_CONTROL_H
#define USER_CONTROL_H

#include <termios.h>
#include <unistd.h>

class UserControl {
private:
    static struct termios orig_termios; // 保存原始终端设置
    void enableRawMode();              // 启用终端原始模式
    static void disableRawMode();      // 恢复终端正常模式
    char getKeyPress();                // 检测按键输入
    bool leftPressed;   // 新增：跟踪左方向键是否被按下
    bool rightPressed;

public:
    UserControl();                     // 构造函数，初始化终端设置
    ~UserControl();                    // 析构函数，恢复终端设置
    void handleInput(int &playerX, int &playerY, bool &isJumping, float &playerVelocityY, float &playerVelocityX, const float JUMP_FORCE, int SCREEN_WIDTH);
};

#endif