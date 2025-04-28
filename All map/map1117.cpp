#include "map1117.h"
#include "map_utils.h"

void generateMap1117(vector<vector<char> >& map) {
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
    
    for(x=4;x<=4;x++){
		for(y=2;y<=16;y++){
			side(map,x,y);
		}
	}
	
	for(x=115;x<=115;x++){
		for(y=2;y<=16;y++){
			side(map,x,y);
		}
	}
    
    // 生成第二层平台
    for(y = 6; y <= 6; y++) {
        for(x = 5; x < 16; x++) {
            setfloor(map, x, y);
        }
        for(x = 33; x < 39; x++) {
            setfloor(map, x, y);
        }
        for(x = 108; x < 115; x++) {
            setfloor(map, x, y);
        }
    }
    
    // 生成第三层平台
    for(y = 8; y <= 8; y++) {
        for(x = 26; x < 31; x++) {
            setfloor(map, x, y);
        }
        for(x = 41; x < 46; x++) {
            setfloor(map, x, y);
        }
        for(x = 63; x < 67; x++) {
            setfloor(map, x, y);
        }
        for(x = 71; x < 75; x++) {
            setfloor(map, x, y);
        }
        for(x = 104; x < 109; x++) {
            setfloor(map, x, y);
        }
    }
    
    // 生成第四层平台
    for(y = 10; y <= 10; y++) {
        for(x = 5; x < 11; x++) {
            setfloor(map, x, y);
        }
        for(x = 18; x < 24; x++) {
            setfloor(map, x, y);
        }
        for(x = 48; x < 54; x++) {
            setfloor(map, x, y);
        }
        for(x = 60; x < 65; x++) {
            setfloor(map, x, y);
        }
        for(x = 73; x < 78; x++) {
            setfloor(map, x, y);
        }
        for(x = 100; x < 105; x++) {
            setfloor(map, x, y);
        }
    }
    
    // 生成第五层平台
    for(y = 12; y <= 12; y++) {
        for(x = 12; x < 17; x++) {
            setfloor(map, x, y);
        }
        for(x = 26; x < 31; x++) {
            setfloor(map, x, y);
        }
        for(x = 41; x < 46; x++) {
            setfloor(map, x, y);
        }
        for(x = 62; x < 67; x++) {
            setfloor(map, x, y);
        }
        for(x = 71; x < 76; x++) {
            setfloor(map, x, y);
        }
        for(x = 96; x < 101; x++) {
            setfloor(map, x, y);
        }
    }    
    
    // 生成第七层平台
    for(y = 14; y <= 14; y++) {
        for(x = 5; x < 16; x++) {
            setfloor(map, x, y);
        }
        for(x = 33; x < 39; x++) {
            setfloor(map, x, y);
        }
        for(x = 55; x < 59; x++) {
            setfloor(map, x, y);
        }
        for(x = 67; x < 71; x++) {
            setfloor(map, x, y);
        }
        for(x = 78; x < 82; x++) {
            setfloor(map, x, y);
        }
        for(x = 85; x < 89; x++) {
            setfloor(map, x, y);
        }
        for(x = 92; x < 96; x++) {
            setfloor(map, x, y);
        }
    }
    
    // 生成墙壁
    for(x = 68; x <= 69; x++) {
        for(y = 8; y <= 13; y++) {
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
    E(map, 75, 9);
    E(map, 90, 12);
    setv(map, 14, 6);
    setv(map, 12, 7);
    setv(map, 11, 8);
    setv(map, 16, 7);
    setv(map, 17, 8);
} 
