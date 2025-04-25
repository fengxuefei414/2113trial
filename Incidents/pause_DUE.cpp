#include "pause_DUE.h"
#include <ctime>

// 定义暂停DUE相关变量
time_t DUEPauseStartTime;
bool isDUEPaused = false;

// 暂停DUE
void pauseDUE() {
    DUEPauseStartTime = time(nullptr);
    isDUEPaused = true;
}

// 更新DUE暂停状态
void updateDUEPause() {
    if (isDUEPaused) {
        time_t currentTime = time(nullptr);
        if (currentTime - DUEPauseStartTime >= 5) {  // 改为5秒后恢复
            isDUEPaused = false;
        }
    }
}

// 检查DUE是否处于暂停状态
bool isDUECurrentlyPaused() {
    return isDUEPaused;
}

// 减少关卡时间
void reduceLevelTime(int& time) {
    time -= 5;  // 减少5秒
    if (time < 0) time = 0;  // 确保时间不会变成负数
}