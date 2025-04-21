#include <iostream>
#include <vector>
#include "user_control.h" // 包含用户控制逻辑的头文件

using namespace std;

class Game {
public:
    void run();

private:
    vector<vector<char>> map; // 地图
    int playerX, playerY;     // 玩家位置
    bool isJumping;           // 是否在跳跃
    bool gameOver;            // 游戏结束标志

    void initializeGame();
    void handleInput();
    void update();
    void render();
    bool checkGameOver();
};

void Game::initializeGame() {
    map = generateMap(); // 使用 map_2 提供的地图生成函数
    playerX = 1;         // 玩家初始位置
    playerY = MAP_HEIGHT - 2;
    isJumping = false;
    gameOver = false;
}

void Game::handleInput() {
    char input = getInput(); // 使用 user_control 提供的键盘输入函数
    switch (input) {
        case 'w': // 跳跃
            if (!isJumping) {
                isJumping = true;
                playerY -= 1; // 向上跳
            }
            break;
        case 'a': // 左移
            if (playerX > 0) playerX -= 1;
            break;
        case 'd': // 右移
            if (playerX < MAP_WIDTH - 1) playerX += 1;
            break;
        default:
            break;
    }
}

void Game::update() {
    if (isJumping) {
        playerY += 1; // 模拟跳跃后下落
        isJumping = false;
    }

    // 检查玩家是否掉到地图底部
    if (playerY >= MAP_HEIGHT) {
        gameOver = true;
    }

    // 检查玩家是否碰到障碍物
    if (map[playerY][playerX] == '#') {
        cout << "撞到障碍物！" << endl;
        gameOver = true;
    }
}

void Game::render() {
    system("clear"); // 清屏（Linux 系统）
    map[playerY][playerX] = 'P'; // 设置玩家位置

    displayMap(map); // 使用 map_2 提供的地图显示函数

    map[playerY][playerX] = ' '; // 清除玩家位置
}

bool Game::checkGameOver() {
    // 检查是否到达地图右侧边界
    if (playerX == MAP_WIDTH - 1) {
        cout << "恭喜你到达终点！" << endl;
        return true;
    }
    return gameOver;
}

void Game::run() {
    initializeGame();
    while (!checkGameOver()) {
        handleInput();
        update();
        render();
    }
    cout << "游戏结束！" << endl;
}

int main() {
    Game game;
    game.run();
    return 0;
}
