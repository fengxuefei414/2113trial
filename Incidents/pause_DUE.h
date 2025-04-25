#ifndef PAUSE_DUE_H
#define PAUSE_DUE_H

// DUE暂停相关函数
void pauseDUE();  // 暂停DUE
void updateDUEPause();  // 更新DUE暂停状态
bool isDUECurrentlyPaused();  // 检查DUE是否处于暂停状态
void reduceLevelTime(int& time);  // 减少关卡时间

#endif // PAUSE_DUE_H