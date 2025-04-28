#include "map2014.h"
#include "./map_utils.h"

void generateMap2014(vector<vector<char> >& map) {
    initializeMap(map);
    int x;
    int y;
    
    int start_x = 5;
    int start_y = 2;
    int end_x = 114;
    int end_y = 16;

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

    for (int k = start_x; k <= end_x; k++){ 
        setv(map,k,end_y); 
    }

    for (int x = 65+5; x <= 67+5; x++){
        setfloor(map,x,8);
    }   

    for (int x = 71+5; x <= 73+5; x++){
        setfloor(map,x,8);
    }

    for (int x = 77+5; x <= 79+5; x++){
        setfloor(map,x,8);
    }

    for (int x = 83+5; x <= 85+5; x++){
        setfloor(map,x,8);
    }

    for (int x = 89+5; x <= 91+5; x++){
        setfloor(map,x,8);
    }

    for (int x = 95+5; x <= 97+5; x++){
        setfloor(map,x,8);
    }

    
    // set ground thorn and ceiling thorn

    for (int x = start_x; x <= end_x; x++){ //set floor and ceiling
        if (map[start_y][x] == ' '){
            setfloor(map,x,start_y);
        }
    }

    for (int y = 5; y <= 5; y++){
        for (int x = 0+5; x <= 5+5; x++){
            setfloor(map,x,y);
        }

        for (int x = 14+5; x <= 16+5; x++){
            setfloor(map,x,y);
        }

        for (int x = 23+5; x <= 26+5; x++){
            setfloor(map,x,y);
        }

        for (int x = 50+5; x <= 52+5; x++){
            setfloor(map,x,y);
        }
    }

    for (int y = 6; y <= 6; y++){
        for (int x = 61+5; x <= 64+5; x++){
            setfloor(map,x,y);
        }

        for (int x = 74+5; x <= 76+5; x++){
            setfloor(map,x,y);
        }

        for (int x = 86+5; x <= 88+5; x++){
            setfloor(map,x,y);
        }

        for (int x = 98+5; x <= 109+5; x++){
            setfloor(map,x,y);
        }
    }

    for (int y = 8; y <= 8; y++){
        setfloor(map,19+5,y);
        setfloors(map,20+5,y);
        setfloor(map,29+5,y);
        setfloors(map,30+5,y);
        setfloor(map,36+5,y);
        setfloors(map,37+5,y);
        setfloors(map,44+5,y);
        setfloors(map,47+5,y);
        setfloors(map,68+5,y);
        setfloors(map,80+5,y);  
        setfloors(map,92+5,y);  
    }

    setfloors(map,14+5,11);
    setfloor(map,17+5,11);
    for (int x = 24+5; x <= 54+5; x += 3){
        setfloors(map,x,12);
    }

    for (int x = 57+5; x <= 60+5; x ++){
        setfloor(map,x,12);
    }

    for (int x = 8+5; x <= 20+5; x += 3){
        setfloors(map,x,14);
    }

    // set wall
    for (int x = 5+5; x <= 5+5; x++){
        for (int y = 6; y <= 14; y++){
            setwall(map,x,y);
        }
    }

    for (int x = 13+5; x <= 13+5; x++){
        for (int y = 4; y <= 10; y++){
            setwall(map,x,y);
        }
    }

    for (int x = 23+5; x <= 23+5; x++){
        for (int y = 6; y <= 14; y++){
            setwall(map,x,y);
        }
    }

    for (int x = 50+5; x <= 50+5; x++){
        for (int y = 6; y <= 8; y++){
            setwall(map,x,y);
        }
    }

    for (int x = 61+5; x <= 61+5; x++){
        for (int y = 7; y <= 12; y++){
            setwall(map,x,y);
        }
    }
    map[9][62+5] = '@';
    //set door
    map[11][68+8] = '@';
    map[11][71+8] = '@';
    map[11][74+8] = '@';
    C(map,105,5);
    D(map,107,5);
}
