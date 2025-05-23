#include "incidents.h"
#include "add_time.h"
#include "reduce_time.h"
#include <cstdlib>
#include <ctime>
#include <string>

// 声明外部变量
extern int DUEPosition;

// 触发随机事件
IncidentType triggerRandomIncident(int& currentLevelTime) {
    // 随机选择一个事件
    int eventCount = 4;  // 现在有4种事件
    int randomEvent = rand() % eventCount;
    
    IncidentType incident = static_cast<IncidentType>(randomEvent);
    
    // 根据事件类型执行相应操作
    switch(incident) {
        case REDUCE_TIME:
            reduceLevelTime(currentLevelTime);
            break;
        case PAUSE_DUE:
            pauseDUE();
            break;
        case REVERSE_DUE:
            reverseDUE(DUEPosition);
            break;
        case ADD_TIME:
            addLevelTime(currentLevelTime);
            break;
    }
    
    return incident;
}

// 获取事件名称
std::string getIncidentName(IncidentType incident) {
    switch(incident) {
        case REDUCE_TIME:
            return "减少时间5秒";
        case PAUSE_DUE:
            return "暂停DUE 5秒";
        case REVERSE_DUE:
            return "DUE倒退3格";
        case ADD_TIME:
            return "增加时间10秒";
        default:
            return "未知事件";
    }
} 