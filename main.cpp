#include <iostream>
#include <vector>
#include <unistd.h>
#include "user_control.h"
#include "map.h"

using namespace std;

// 游戏常量
const float GRAVITY = 0.35f;        // 增加重力
const float JUMP_FORCE = -1.2f;     // 减小跳跃力度
const float TERMINAL_FPS = 30.0f;   // 目标帧率

// 玩家状态
struct Player {
    int x;
    int y;
    float velocityX;
    float velocityY;
    bool isJumping;
    char symbol;
};

// 检查是否碰到平台
bool isPlatform(const vector<vector<char> >& map, int x, int y) {
    if (y < 0 || y >= MAP_HEIGHT || x < 0 || x >= MAP_WIDTH) {
        return false;
    }
    char c = map[y][x];
    return (c == '-' || c == 'v' || c == '[' || c == ']');
}

// 更新玩家位置
void updatePlayer(Player& player, const vector<vector<char> >& map) {
    // 应用重力
    player.velocityY += GRAVITY;
    
    // 限制最大下落速度
    if (player.velocityY > 2.0f) {  // 恢复最大下落速度
        player.velocityY = 2.0f;
    }
    
    // 更新垂直位置
    float newY = player.y + player.velocityY;
    int newYInt = static_cast<int>(newY);
    
    // 检查垂直移动路径上的碰撞
    if (player.velocityY > 0) { // 下落
        // 检查从当前位置到目标位置之间的所有点
        for (int y = player.y; y <= newYInt; y++) {
            if (isPlatform(map, player.x, y)) {
                player.velocityY = 0;
                player.isJumping = false;
                player.y = y - 1;
                return;
            }
        }
    } else if (player.velocityY < 0) { // 上升
        // 检查从当前位置到目标位置之间的所有点
        for (int y = player.y; y >= newYInt; y--) {
            if (isPlatform(map, player.x, y)) {
                player.velocityY = 0;
                player.y = y + 1;
                return;
            }
        }
    }
    
    // 如果没有碰撞，更新位置
    player.y = newYInt;
    
    // 检查是否超出地图边界
    if (player.y >= MAP_HEIGHT - 1) {
        player.y = MAP_HEIGHT - 2;
        player.velocityY = 0;
        player.isJumping = false;
    }
    
    // 更新水平位置
    float newX = player.x + player.velocityX;
    int newXInt = static_cast<int>(newX);
    
    // 检查水平移动路径上的碰撞
    if (player.velocityX > 0) { // 向右移动
        for (int x = player.x; x <= newXInt; x++) {
            if (isPlatform(map, x, player.y)) {
                player.velocityX = 0;
                player.x = x - 1;
                return;
            }
        }
    } else if (player.velocityX < 0) { // 向左移动
        for (int x = player.x; x >= newXInt; x--) {
            if (isPlatform(map, x, player.y)) {
                player.velocityX = 0;
                player.x = x + 1;
                return;
            }
        }
    }
    
    // 如果没有碰撞，更新位置
    player.x = newXInt;
    
    // 检查是否超出地图边界
    if (player.x < 0) player.x = 0;
    if (player.x >= MAP_WIDTH) player.x = MAP_WIDTH - 1;
}

// 显示游戏画面
void displayGame(const vector<vector<char> >& map, const Player& player) {
    system("clear");  // 清屏
    
    // 复制地图
    vector<vector<char> > displayMap = map;
    
    // 放置玩家
    if (player.y >= 0 && player.y < MAP_HEIGHT && player.x >= 0 && player.x < MAP_WIDTH) {
        displayMap[player.y][player.x] = player.symbol;
    }
    
    // 显示地图
    for (int i = 0; i < MAP_HEIGHT; ++i) {
        for (int j = 0; j < MAP_WIDTH; ++j) {
            cout << displayMap[i][j];
        }
        cout << endl;
    }
    
    // 显示玩家状态
    cout << "位置: (" << player.x << ", " << player.y << ") ";
    cout << "速度: (" << player.velocityX << ", " << player.velocityY << ") ";
    cout << "跳跃: " << (player.isJumping ? "是" : "否") << endl;
}

int main() {
    // 初始化地图
    vector<vector<char> > map(MAP_HEIGHT, vector<char>(MAP_WIDTH));
    generateMap(map);
    
    // 初始化玩家
    Player player = {
        .x = 5,
        .y = 15,
        .velocityX = 0.0f,
        .velocityY = 0.0f,
        .isJumping = false,
        .symbol = '@'
    };
    
    // 初始化用户控制
    UserControl controller;
    
    // 游戏主循环
    while (true) {
        // 处理用户输入
        controller.handleInput(player.x, player.y, player.isJumping, 
                            player.velocityY, JUMP_FORCE, MAP_WIDTH);
        
        // 更新玩家位置
        updatePlayer(player, map);
        
        // 显示游戏画面
        displayGame(map, player);
        
        // 控制帧率
        usleep(1000000 / TERMINAL_FPS);
    }
    
    return 0;
} 