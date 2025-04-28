#include "map2601.h"
#include "./map_utils.h"

void generateMap2601(vector<vector<char> >& map) {
    initializeMap(map);
    int x;
    int y;
    
    int start_x = 5;
    int start_y = 2;
    int end_x = 114;
    int end_y = 16;

    // 设置一些障碍物和行距示例
    // 函数中的坐标为（x,y） 
   
    for (int x = 0; x < 120; x++){       //设置边界
        setfloor(map,x,0);
    }

    for (int x = 0; x < 120; x++){
        setfloor(map,x,19);
    }

    for(x=4;x<=4;x++){
		for(y=2;y<=18;y++){
			side(map,x,y);
		}
	}
	for(x=115;x<=115;x++){
		for(y=2;y<=18;y++){
			side(map,x,y);
		}
	}
    for (int k = 13 + start_x; k <= end_x; k++){ // 放置地刺v和天花板刺v
        setv(map,k,end_y); 
    }


    for (int x = start_x; x <= end_x; x++){ //设置地板和天花板
        if (map[start_y][x] == ' '){
            setfloor(map,x,start_y);
        }
        if (map[end_y][x] == ' '){
            setfloor(map,x,end_y);
        }
    }

    for (int y = 6; y <= 6; y++){
        for (int x = 22+5; x <= 27+5; x++){
            setfloor(map,x,y);
        }

        for (int x = 33+5; x <= 38+5; x++){
            setfloor(map,x,y);
        }

        for (int x = 58+5; x <= 60+5; x++){
            setfloor(map,x,y);
        }

        for (int x = 65+5; x <= 69+5; x++){
            setfloor(map,x,y);
        }

        for (int x = 73+5; x <= 79+5; x++){
            setfloor(map,x,y);
        }

        for (int x = 83+5; x <= 114; x++){
            setfloor(map,x,y);
        }
    }

    for (int y = 8; y <= 8; y++){
        for (int x = 22+5; x <= 30+5; x++){
            setfloor(map,x,y);
        }
        for (int x = 41+5; x <= 43+5; x++){
            setfloor(map,x,y);
        }
        for (int x = 63+5; x <= 65+5; x++){
            setfloor(map,x,y);
        }
    }

    for (int y = 10; y <= 10; y++){
        for (int x = 4+5; x <= 6+5; x++){
            setfloor(map,x,y);
        }
        for (int x = 11+5; x <= 16+5; x++){
            setfloor(map,x,y);
        }
        for (int x = 32+5; x <= 39+5; x++){
            setfloor(map,x,y);
        }
        for (int x = 58+5; x <= 60+5; x++){
            setfloor(map,x,y);
        }
    }

    for (int y = 12; y <= 12; y++){
        for (int x = 9+5; x <= 11+5; x++){
            setfloor(map,x,y);
        }
        for (int x = 17+5; x <= 20+5; x++){
            setfloor(map,x,y);
        }
        for (int x = 23+5; x <= 26+5; x++){
            setfloor(map,x,y);
        }
        for (int x = 29+5; x <= 31+5; x++){
            setfloor(map,x,y);
        }
        for (int x = 41+5; x <= 48+5; x++){
            setfloor(map,x,y);
        }
        for (int x = 53+5; x <= 56+5; x++){
            setfloor(map,x,y);
        }
    }
    
    for (int y = 14; y <= 14; y++){
        for (int x = 4+5; x <= 6+5; x++){
            setfloor(map,x,y);
        }
    }
    
    // 设置墙壁
    for (int x = 3+5; x <= 3+5; x++){
        for (int y = 10; y <= 14; y++){
            setwall(map,x,y);
        }
    }

    for (int x = 12+5; x <= 12+5; x++){
        for (int y = 12; y <= 16; y++){
            setwall(map,x,y);
        }
    }

    setwall(map,22+5,7);
    setwall(map,27+5,7);

    for (int x = 32+5; x <= 32+5; x++){
        for (int y = 11; y <= 12; y++){
            setwall(map,x,y);
        }
    }

    for (int x = 36+5; x <= 36+5; x++){
        for (int y = 11; y <= 12; y++){
            setwall(map,x,y);
        }
        for (int y = 7; y <= 9; y++){
            setwall(map,x,y);
        }
    }

    for (int x = 44+5; x <= 44+5; x++){
        for (int y = 5; y <= 9; y++){
            setwall(map,x,y);
        }
    }

    for (int x = 59+5; x <= 59+5; x++){
        for (int y = 7; y <= 8; y++){
            setwall(map,x,y);
        }
    }

    for (int x = 64+5; x <= 64+5; x++){
        for (int y = 9; y <= 10; y++){
            setwall(map,x,y);
        }
    }

    //设置墙刺

    A(map,50+5,11);
    B(map,51+5,11);

    A(map,49+5,12);
    B(map,52+5,12);

    //设置随机事件
    E(map, 24+5, 11);
    E(map, 34+5, 5);
    E(map, 45+5, 11);
    for (int x = 13+5; x <= 114; x += 3){
        map[14][x] = '@';  // 替换船的表情符号
    }
    //设置门

    C(map,105,5);
    D(map,107,5);
    
}
