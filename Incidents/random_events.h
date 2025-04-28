#ifndef REDUCE_TIME_H
#define REDUCE_TIME_H
#include <vector>
#include <ctime>    

// 初始化随机事件
void initRandomEvents();  
// 触发随机事件
void triggerRandomEvent(std::vector<std::vector<char> >& map, int& time, int& DUEPosition);

#endif // REDUCE_TIME_H 