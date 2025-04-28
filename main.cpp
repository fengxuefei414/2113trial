#include <iostream>
#include <vector>
#include <unistd.h>
#include <ctime>
#include <string>
#include "user_control.h"
#include "DUE.h"
#include "All map/map1001.h"
#include "All map/map1117.h"
#include "All map/map1000.h"
#include "All map/map1016.h"
#include "All map/map2014.h"
#include "All map/map2601.h"
#include "Incidents/incidents.h"

using namespace std;

// 事件记录结构体
struct IncidentRecord {
    string message;      // 事件消息
    time_t startTime;    // 事件开始时间
    int level;          // 事件发生的关卡
};

// 游戏常量
const float GRAVITY = 0.3f;        // 减小重力
const float JUMP_FORCE = -1.0f;     // 减小跳跃力度
const float TERMINAL_FPS = 30.0f;   // 目标帧率

// 当前关卡
int currentLevel = 1;
const int MAX_LEVEL = 6;

// 计时相关变量
time_t levelStartTime;  // 当前关卡开始时间
int currentLevelTime;   // 当前关卡已用时间（秒）

// 事件记录相关变量
vector<IncidentRecord> incidentRecords;  // 存储所有事件记录
const int MESSAGE_DISPLAY_TIME = 3;      // 显示3秒

// 出生点结构体
struct SpawnPoint {
    int x;
    int y;
};

// 每个关卡的出生点（暂时都使用相同的出生点）
const SpawnPoint LEVEL_SPAWNS[] = {
    {5, 13},    // 第1关出生点
    {5, 13},    // 第2关出生点
    {5, 13},    // 第3关出生点
    {5, 9},    // 第4关出生点
    {5, 5},    // 第5关出生点
    {5, 15}     // 第6关出生点
};

// 获取当前关卡的出生点
SpawnPoint getCurrentSpawnPoint() {
    return LEVEL_SPAWNS[currentLevel - 1];
}

// 加载指定关卡的地图
void loadLevel(vector<vector<char> >& map, int level) {
    // 重置计时器
    levelStartTime = time(nullptr);
    currentLevelTime = 0;
    
    // 初始化DUE
    initDUE();
    
    switch(level) {
        case 1:
            generateMap1001(map);
            break;
        case 2:
            generateMap1117(map);
            break;
        case 3:
            generateMap1000(map);
            break;
        case 4:
            generateMap1016(map);
            break;
        case 5:
            generateMap2014(map);
            break;
        case 6:
            generateMap2601(map);
            break;
        default:
            generateMap1001(map); // 默认加载第一关
            break;
    }
}

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
    return (c == '-' || c == 'v' || c == '[' || c == ']' || c == '|' || c == '\\' || c == '/' );
}

// 检查是否碰到关卡切换点
bool isLevelSwitch(const vector<vector<char> >& map, int x, int y) {
    if (y < 0 || y >= MAP_HEIGHT || x < 0 || x >= MAP_WIDTH) {
        return false;
    }
    char c = map[y][x];
    return (c == '[' || c == ']');
}

// 更新玩家位置
void updatePlayer(Player& player, vector<vector<char> >& map) {
    // 检查是否碰到DUE
    if (checkDUECollision(map, player.x, player.y)) {
        if (currentLevel < MAX_LEVEL) {
            currentLevel++;
            loadLevel(map, currentLevel);
            // 使用新关卡的出生点
            SpawnPoint spawn = getCurrentSpawnPoint();
            player.x = spawn.x;
            player.y = spawn.y;
            player.velocityX = 0;
            player.velocityY = 0;
            player.isJumping = false;
            return;
        } else {
            // 通关后显示胜利信息
            system("clear");
            cout << "恭喜通关！" << endl;
            exit(0);
        }
    }
    
    // 检查是否碰到关卡切换点
    if (isLevelSwitch(map, player.x, player.y)) {
        if (currentLevel < MAX_LEVEL) {
            currentLevel++;
            loadLevel(map, currentLevel);
            // 使用新关卡的出生点
            SpawnPoint spawn = getCurrentSpawnPoint();
            player.x = spawn.x;
            player.y = spawn.y;
            player.velocityX = 0;
            player.velocityY = 0;
            player.isJumping = false;
            return;
        } else {
            // 通关后显示胜利信息
            system("clear");
            cout << "恭喜通关！" << endl;
            exit(0);
        }
    }
    
    // 检查是否碰到$
    if (map[player.y][player.x] == '$') {
        currentLevelTime = static_cast<int>(time(nullptr) - levelStartTime);
        IncidentType incident = triggerRandomIncident(currentLevelTime);
        
        // 创建新的事件记录
        IncidentRecord newRecord;
        newRecord.message = "触发随机事件：" + getIncidentName(incident);
        newRecord.startTime = time(nullptr);
        newRecord.level = currentLevel;
        
        // 添加到事件记录列表
        incidentRecords.push_back(newRecord);
        
        levelStartTime = time(nullptr) - currentLevelTime;  // 更新开始时间以反映减少的时间
        map[player.y][player.x] = ' ';  // 移除$
    }
    
    // 应用重力
    player.velocityY += GRAVITY;
    
    // 限制最大下落速度
    if (player.velocityY > 1.0f) {  // 减小最大下落速度
        player.velocityY = 1.0f;
    }
    
    // 更新垂直位置
    float newY = player.y + player.velocityY;
    int newYInt = static_cast<int>(newY);
    
    // 检查是否达到最大跳跃高度（2格）
    if (player.velocityY < 0 && newY < player.y - 2.0f) {
        player.velocityY = 0; // 达到最大高度，开始下落
        return;
    }
    
    // 检查垂直移动路径上的碰撞
    if (player.velocityY > 0) { // 下落
        // 检查从当前位置到目标位置之间的所有点
        for (int y = player.y; y <= newYInt; y++) {
            if (isPlatform(map, player.x, y)) {
                player.velocityY = 0;
                player.velocityX = 0; // 重置水平速度
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
    
    // 在跳跃时减小向左移动的速度
    if (player.isJumping && player.velocityX < 0) {
        newX = player.x + player.velocityX * 0.5f; // 向左移动速度减小50%
        newXInt = static_cast<int>(newX);
    }
    
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
    // 使用ANSI转义序列来移动光标到左上角，而不是清屏
    cout << "\033[1;1H";  // 移动光标到左上角
    
    // 更新当前关卡用时
    currentLevelTime = static_cast<int>(time(nullptr) - levelStartTime);
    
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
    
    // 显示玩家位置和关卡信息
    cout << "----------------------------------------" << endl;
    cout << "位置: (" << player.x << ", " << player.y << ")";
    
    // 根据当前关卡显示对应的地图名称
    string mapName;
    switch(currentLevel) {
        case 1: mapName = "map1001"; break;
        case 2: mapName = "map1117"; break;
        case 3: mapName = "map1000"; break;
        case 4: mapName = "map1016"; break;
        case 5: mapName = "map2014"; break;
        case 6: mapName = "map2601"; break;
    }
    
    cout << "    第" << currentLevel << "关/" << MAX_LEVEL << "关 (" << mapName << ")" << endl;
    cout << "用时: " << currentLevelTime << "秒" << endl;
    cout << "DUE位置: " << DUEPosition << endl;  // 显示DUE位置
    
    // 显示当前关卡的事件记录
    cout << "当前关卡事件记录：" << endl;
    for (const auto& record : incidentRecords) {
        if (record.level == currentLevel && 
            time(nullptr) - record.startTime < MESSAGE_DISPLAY_TIME) {
            cout << record.message << endl;
        }
    }
    
    // 刷新输出缓冲区
    cout.flush();
}

void gameLoop() {
    // 初始化地图
    vector<vector<char> > map(MAP_HEIGHT, vector<char>(MAP_WIDTH));
    loadLevel(map, currentLevel);
    
    // 获取初始出生点
    SpawnPoint spawn = getCurrentSpawnPoint();
    
    // 初始化玩家
    Player player = {
        .x = spawn.x,
        .y = spawn.y,
        .velocityX = 0.0f,
        .velocityY = 0.0f,
        .isJumping = false,
        .symbol = 'H'
    };
    
    // 初始化用户控制
    UserControl controller;
    
    // 游戏主循环
    while (true) {
        // 处理用户输入
        controller.handleInput(player.x, player.y, player.isJumping, 
                            player.velocityY, player.velocityX, JUMP_FORCE, MAP_WIDTH);
        
        // 更新DUE
        updateDUE(map);
        
        // 更新玩家位置
        updatePlayer(player, map);
        
        // 显示游戏画面
        displayGame(map, player);
        
        // 控制帧率
        usleep(1000000 / TERMINAL_FPS);
        
        // 更新DUE暂停状态
        updateDUEPause();
    }
}

int main() {
    gameLoop();
    return 0;
} 