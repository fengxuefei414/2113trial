#include <iostream>
#include <vector>
#include <thread>
#include <chrono>

using namespace std; 

const int MAP_WIDTH = 120;  // 地图宽度
const int MAP_HEIGHT = 20;  // 地图高度

void displayMap(const vector<vector<char> >& map) {
    cout << "MAP：" << endl;
    for (int i = 0; i < MAP_HEIGHT; ++i) {
        for (int j = 0; j < MAP_WIDTH; ++j) {
            cout << map[i][j];
        }
        cout << endl;
    }
}

void initializeMap(vector<vector<char> >& map) { //初始化全部为空格
    for (int i = 0; i < MAP_HEIGHT; ++i) {
        for (int j = 0; j < MAP_WIDTH; ++j) {
            map[i][j] = ' '; 
        }
    }
}

void setfloor(vector<vector<char> >& map, int x, int y) { // 放置地板
    if (x >= 0 && x < MAP_WIDTH && y >= 0 && y < MAP_HEIGHT) {
        map[y][x] = '-'; 
    } else {
        cout << "坐标超出地图范围！" << endl;
    }
}

void setfloors(vector<vector<char> >& map, int x, int y) { // 放置三块地板
    if (x >= 0 && x < MAP_WIDTH && y >= 0 && y < MAP_HEIGHT) {
		map[y][x] = '-';
		map[y][x+1] = '-';
 		map[y][x+2] = '-';
    } else {
        cout << "坐标超出地图范围！" << endl;
    }
}

void setwall(vector<vector<char> >& map, int x, int y) { // 放置墙
    if (x >= 0 && x < MAP_WIDTH && y >= 0 && y < MAP_HEIGHT) {
        map[y][x] = '|'; 
    } else {
        cout << "坐标超出地图范围！" << endl;
    }
}

void setv(vector<vector<char> >& map, int x, int y) { // 放置天花板/地刺
    if (x >= 0 && x < MAP_WIDTH && y >= 0 && y < MAP_HEIGHT) {
        map[y][x] = 'v'; 
    } else {
        cout << "坐标超出地图范围！" << endl;
    }
}

void setleftv(vector<vector<char> >& map, int x, int y) { // 放置墙刺
    if (x >= 0 && x < MAP_WIDTH && y >= 0 && y < MAP_HEIGHT) {
        map[y][x] = '/'; 
    } else {
        cout << "坐标超出地图范围！" << endl;
    }
}

void setrightv(vector<vector<char> >& map, int x, int y) { // 放置墙刺
    if (x >= 0 && x < MAP_WIDTH && y >= 0 && y < MAP_HEIGHT) {
        map[y][x] = '\\'; 
    } else {
        cout << "坐标超出地图范围！" << endl;
    }
}

void A(vector<vector<char> >& map, int x, int y) {
    if (x >= 0 && x < MAP_WIDTH && y >= 0 && y < MAP_HEIGHT) {
        map[y][x] = '['; 
    } else {
        cout << "坐标超出地图范围！" << endl;
    }
}

void B(vector<vector<char> >& map, int x, int y) {
    if (x >= 0 && x < MAP_WIDTH && y >= 0 && y < MAP_HEIGHT) {
        map[y][x] = ']'; 
    } else {
        cout << "坐标超出地图范围！" << endl;
    }
}

void C(vector<vector<char> >& map, int x, int y) {
    if (x >= 0 && x < MAP_WIDTH && y >= 0 && y < MAP_HEIGHT) {
        map[y][x] = '*'; 
    } else {
        cout << "坐标超出地图范围！" << endl;
    }
}

void setVerticalLine(vector<vector<char> >& map, int x) {
    for (int y = 0; y < MAP_HEIGHT; ++y) {
        map[y][x] = '|'; // '|' 表示竖直线
    }
}

void clearVerticalLine(vector<vector<char> >& map, int x) {
    for (int y = 0; y < MAP_HEIGHT; ++y) {
        map[y][x] = ' '; // 清空竖直线位置
    }
}

void clearScreen() {
    std::cout << "\033[2J\033[1;1H"; 
}

int main() {
	vector<vector<char> > map(MAP_HEIGHT, vector<char>(MAP_WIDTH));
	initializeMap(map);

	const int start_x = 5;
	const int start_y = 2;
	const int end_x = 114;
	const int end_y = 16;


	// 设置一些障碍物和行距示例\\
   // 函数中的坐标为（x,y） 
   

	for (int k = start_x; k <= end_x; k++){ // 放置地刺v和天花板刺v
		setv(map,k,end_y); 
	}

	for (int x = 65+5; x <= 67+5; x++){
		setv(map,x,8);
	}	

	for (int x = 71+5; x <= 73+5; x++){
		setv(map,x,8);
	}

	for (int x = 77+5; x <= 79+5; x++){
		setv(map,x,8);
	}

	for (int x = 83+5; x <= 85+5; x++){
		setv(map,x,8);
	}

	for (int x = 89+5; x <= 91+5; x++){
		setv(map,x,8);
	}

	for (int x = 95+5; x <= 97+5; x++){
		setv(map,x,8);
	}

	for (int x = 29+5; x <= 32+5; x++){
		setv(map,x,9);
	}

	for (int x = 37+5; x <= 39+5; x++){
		setv(map,x,9);
	}

	for (int x = 44+5; x <= 46+5; x++){
		setv(map,x,8);
	}
// 地刺和天花板刺放置完毕

	for (int x = start_x; x <= end_x; x++){ //设置地板和天花板
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
		for (int x = 47+5; x <= 49+5; x++){
			setfloor(map,x,y);
		}

		for (int x = 14+5; x <= 16+5; x++){
			setfloor(map,x,y);
		}

		for (int x = 58+5; x <= 64+5; x++){
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
		setfloors(map,20+5,y);
		setfloor(map,29+5,y);
		setfloors(map,30+5,y);
		setfloors(map,37+5,y);
		setfloors(map,44+5,y);
		setfloors(map,54+5,y);
		setfloors(map,68+5,y);
		setfloors(map,80+5,y);	
		setfloors(map,92+5,y);	
	}

	setfloors(map,58+5,10);
	setfloors(map,14+5,11);
	
	for (int x = 24+5; x <= 54+5; x += 6){
		setfloors(map,x,12);
	}

	for (int x = 8+5; x <= 20+5; x += 6){
		setfloors(map,x,14);
	}

// 设置墙壁
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

	for (int x = 61+5; x <= 44+5; x++){
		for (int y = 7; y <= 10; y++){
			setwall(map,x,y);
		}
	}


//设置门

	A(map,105,5);
	B(map,107,5);
	int linePosition = 0; // 竖直线的位置
	bool isLineVisible = false; // 竖直线是否可见
	const int interval = 1000;  // 间隔时间（毫秒）


	while (linePosition <= MAP_WIDTH) {
    	clearScreen();
		// 根据标志变量决定是否绘制竖直线
		setVerticalLine(map, linePosition);

		displayMap(map); // 显示地图

		// 等待1秒
		std::this_thread::sleep_for(std::chrono::milliseconds(interval));        
      clearVerticalLine(map, linePosition);
		//切换竖直线的显示状态
		linePosition ++;
	}

	return 0;
}