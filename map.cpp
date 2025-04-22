#include "map.h"

// 定义地图常量
const int MAP_WIDTH = 120;
const int MAP_HEIGHT = 20;

void displayMap(const vector<vector<char> >& map) {
    cout << "游戏地图：" << endl;
    for (int i = 0; i < MAP_HEIGHT; ++i) {
        for (int j = 0; j < MAP_WIDTH; ++j) {
            cout << map[i][j];
        }
        cout << endl;
    }
}

void initializeMap(vector<vector<char> >& map) {
    for (int i = 0; i < MAP_HEIGHT; ++i) {
        for (int j = 0; j < MAP_WIDTH; ++j) {
            map[i][j] = ' ';
        }
    }
}

void setfloor(vector<vector<char> >& map, int x, int y) {
    if (x >= 0 && x < MAP_WIDTH && y >= 0 && y < MAP_HEIGHT) {
        map[y][x] = '-';
    }
}

void setv(vector<vector<char> >& map, int x, int y) {
    if (x >= 0 && x < MAP_WIDTH && y >= 0 && y < MAP_HEIGHT) {
        map[y][x] = 'v';
    }
}

void setwall(vector<vector<char> >& map, int x, int y) {
    if (x >= 0 && x < MAP_WIDTH && y >= 0 && y < MAP_HEIGHT) {
        map[y][x] = '|';
    }
}

void A(vector<vector<char> >& map, int x, int y) {
    if (x >= 0 && x < MAP_WIDTH && y >= 0 && y < MAP_HEIGHT) {
        map[y][x] = '/';
    }
}

void B(vector<vector<char> >& map, int x, int y) {
    if (x >= 0 && x < MAP_WIDTH && y >= 0 && y < MAP_HEIGHT) {
        map[y][x] = '\\';
    }
}

void C(vector<vector<char> >& map, int x, int y) {
    if (x >= 0 && x < MAP_WIDTH && y >= 0 && y < MAP_HEIGHT) {
        map[y][x] = '[';
    }
}

void D(vector<vector<char> >& map, int x, int y) {
    if (x >= 0 && x < MAP_WIDTH && y >= 0 && y < MAP_HEIGHT) {
        map[y][x] = ']';
    }
}

void E(vector<vector<char> >& map, int x, int y) {
    if (x >= 0 && x < MAP_WIDTH && y >= 0 && y < MAP_HEIGHT) {
        map[y][x] = '$';
    }
}

void generateMap(vector<vector<char> >& map) {
    initializeMap(map);
    int x, y;
    
    // 生成底部地面
    for(int k = 5; k <= 114; k++) {
        setv(map, k, 16);
    }
    
    // 生成第一层平台
    for (x = 5; x <= 114; x++) {
        if (map[2][x] == ' ') {
            setfloor(map, x, 2);
        }
    }
    
    // 生成第二层平台
    for(y = 6; y <= 6; y++) {
        for(x = 5; x < 16; x++) {
            setfloor(map, x, y);
        }
        for(x = 34; x < 38; x++) {
            setfloor(map, x, y);
        }
        for(x = 108; x < 115; x++) {
            setfloor(map, x, y);
        }
    }
    
    // 生成第三层平台
    for(y = 8; y <= 8; y++) {
        for(x = 26; x < 30; x++) {
            setfloor(map, x, y);
        }
        for(x = 42; x < 46; x++) {
            setfloor(map, x, y);
        }
        for(x = 63; x < 67; x++) {
            setfloor(map, x, y);
        }
        for(x = 71; x < 75; x++) {
            setfloor(map, x, y);
        }
        for(x = 104; x < 108; x++) {
            setfloor(map, x, y);
        }
    }
    
    // 生成第四层平台
    for(y = 10; y <= 10; y++) {
        for(x = 6; x < 11; x++) {
            setfloor(map, x, y);
        }
        for(x = 18; x < 22; x++) {
            setfloor(map, x, y);
        }
        for(x = 50; x < 54; x++) {
            setfloor(map, x, y);
        }
        for(x = 60; x < 65; x++) {
            setfloor(map, x, y);
        }
        for(x = 73; x < 78; x++) {
            setfloor(map, x, y);
        }
        for(x = 100; x < 104; x++) {
            setfloor(map, x, y);
        }
    }
    
    // 生成第五层平台
    for(y = 12; y <= 12; y++) {
        for(x = 12; x < 16; x++) {
            setfloor(map, x, y);
        }
        for(x = 26; x < 30; x++) {
            setfloor(map, x, y);
        }
        for(x = 42; x < 46; x++) {
            setfloor(map, x, y);
        }
        for(x = 63; x < 67; x++) {
            setfloor(map, x, y);
        }
        for(x = 71; x < 75; x++) {
            setfloor(map, x, y);
        }
        for(x = 96; x < 100; x++) {
            setfloor(map, x, y);
        }
    }
    
    // 生成第六层平台
    for(y = 13; y <= 13; y++) {
        for(x = 55; x < 59; x++) {
            setfloor(map, x, y);
        }
    }
    
    // 生成第七层平台
    for(y = 14; y <= 14; y++) {
        for(x = 5; x < 16; x++) {
            setfloor(map, x, y);
        }
        for(x = 34; x < 38; x++) {
            setfloor(map, x, y);
        }
        for(x = 67; x < 71; x++) {
            setfloor(map, x, y);
        }
        for(x = 78; x < 82; x++) {
            setfloor(map, x, y);
        }
        for(x = 85; x < 88; x++) {
            setfloor(map, x, y);
        }
        for(x = 91; x < 96; x++) {
            setfloor(map, x, y);
        }
    }
    
    // 生成墙壁
    for(x = 68; x <= 69; x++) {
        for(y = 8; y <= 13; y++) {
            setwall(map, x, y);
        }
    }
    for(x = 5; x <= 5; x++) {
        for(y = 7; y <= 13; y++) {
            setwall(map, x, y);
        }
    }
    setwall(map, 59, 8);
    setwall(map, 59, 9);
    setwall(map, 78, 8);
    setwall(map, 78, 9);
    
    // 生成斜坡
    A(map, 67, 8);
    A(map, 68, 7);
    A(map, 66, 9);
    B(map, 69, 7);
    B(map, 70, 8);
    B(map, 71, 9);
    
    // 生成特殊元素
    C(map, 112, 5);
    D(map, 114, 5);
    E(map, 33, 10);
    E(map, 36, 10);
    E(map, 39, 10);
    setv(map, 14, 6);
    setv(map, 12, 7);
    setv(map, 11, 8);
    setv(map, 16, 7);
    setv(map, 17, 8);
} 