#ifndef INCIDENTS_H
#define INCIDENTS_H

#include "pause_DUE.h"
#include "reverse_DUE.h"
#include <string>

// 随机事件类型
enum IncidentType {
    REDUCE_TIME,    // 减少时间
    PAUSE_DUE,      // 暂停DUE
    REVERSE_DUE,    // DUE倒退
    ADD_TIME        // 增加时间
};

// 触发随机事件
IncidentType triggerRandomIncident(int& currentLevelTime);

// 获取事件名称
std::string getIncidentName(IncidentType incident);

#endif // INCIDENTS_H 