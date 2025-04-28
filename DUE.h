#ifndef DUE_H
#define DUE_H

#include <vector>
#include <ctime>

// DUE相关常量
const int DUE_SPEED = 1;            // DUE推进速度（秒）
const int DUE_WIDTH = 1;            // 每次推进的宽度

// DUE相关变量
extern time_t lastDUETime;     // 上次DUE推进时间
extern int DUEPosition;        // DUE当前位置

// 相关函数
void initDUE();  // 初始化DUE
void updateDUE(std::vector<std::vector<char> >& map);  // 更新DUE
bool checkDUECollision(const std::vector<std::vector<char> >& map, int x, int y);  // 检查是否碰到DUE

#endif // DUE_H 