#include "random_events.h"
#include "pause_DUE.h"
#include "reverse_DUE.h"
#include "reduce_time.h"
#include "add_time.h"
#include <cstdlib>
#include <ctime>

// 初始化随机数生成器
void initRandomEvents() {
    srand(time(nullptr));
}

// 触发随机事件
void triggerRandomEvent(std::vector<std::vector<char> >& map, int& time, int& DUEPosition) {
    int event = rand() % 4;  // 生成0-3的随机数
    
    switch(event) {
        case 0:
            pauseDUE();  // 暂停DUE
            break;
        case 1:
            reverseDUE(DUEPosition);  // DUE倒退
            break;
        case 2:
            reduceLevelTime(time);  // 减少时间
            break;
        case 3:
            addLevelTime(time);  // 增加时间
            break;
    }
} 