#include <iostream>
#include <vector>

using namespace std;

const int MAP_WIDTH = 120;  
const int MAP_HEIGHT = 20;  

void displayMap(const vector<vector<char> >& map) {
    cout << "µØÍ¼£º" << endl;
    for (int i = 0; i < MAP_HEIGHT; ++i) {
        for (int j = 0; j < MAP_WIDTH; ++j) {
            cout << map[i][j];
        }
        cout << endl;
    }
}

void initializeMap(vector<vector<char> >& map) {
    for (int i = 0 ; i < MAP_HEIGHT; ++i) {
        for (int j = 0; j < MAP_WIDTH; ++j) {
            map[i][j] = ' '; 
        }
    }
}

void setfloor(vector<vector<char> >& map, int x, int y) {
    if (x >= 0 && x < MAP_WIDTH && y >= 0 && y < MAP_HEIGHT) {
        map[y][x] = '-'; 
    } else {
        cout << "×ø±ê³¬³öµØÍ¼·¶Î§£¡" << endl;
    }
}


void setv(vector<vector<char> >& map, int x, int y) {
    if (x >= 0 && x < MAP_WIDTH && y >= 0 && y < MAP_HEIGHT) {
        map[y][x] = 'v'; 
    } else {
        cout << "×ø±ê³¬³öµØÍ¼·¶Î§£¡" << endl;
    }
}

void setwall(vector<vector<char> >& map, int x, int y) {
    if (x >= 0 && x < MAP_WIDTH && y >= 0 && y < MAP_HEIGHT) {
        map[y][x] = '|'; 
    } else {
        cout << "×ø±ê³¬³öµØÍ¼·¶Î§£¡" << endl;
    }
}

void A(vector<vector<char> >& map, int x, int y) {
    if (x >= 0 && x < MAP_WIDTH && y >= 0 && y < MAP_HEIGHT) {
        map[y][x] = '/'; 
    } else {
        cout << "×ø±ê³¬³öµØÍ¼·¶Î§£¡" << endl;
    }
}

void B(vector<vector<char> >& map, int x, int y) {
    if (x >= 0 && x < MAP_WIDTH && y >= 0 && y < MAP_HEIGHT) {
        map[y][x] = '\\'; 
    } else {
        cout << "×ø±ê³¬³öµØÍ¼·¶Î§£¡" << endl;
    }
}

void C(vector<vector<char> >& map, int x, int y) {
    if (x >= 0 && x < MAP_WIDTH && y >= 0 && y < MAP_HEIGHT) {
        map[y][x] = '['; 
    } else {
        cout << "×ø±ê³¬³öµØÍ¼·¶Î§£¡" << endl;
    }
}

void D(vector<vector<char> >& map, int x, int y) {
    if (x >= 0 && x < MAP_WIDTH && y >= 0 && y < MAP_HEIGHT) {
        map[y][x] = ']'; 
    } else {
        cout << "×ø±ê³¬³öµØÍ¼·¶Î§£¡" << endl;
    }
}

void E(vector<vector<char> >& map, int x, int y) {
    if (x >= 0 && x < MAP_WIDTH && y >= 0 && y < MAP_HEIGHT) {
        map[y][x] = '$'; 
    } else {
        cout << "×ø±ê³¬³öµØÍ¼·¶Î§£¡" << endl;
    }
}

void F(vector<vector<char> >& map, int x, int y) {
    if (x >= 0 && x < MAP_WIDTH && y >= 0 && y < MAP_HEIGHT) {
        map[y][x] = '<'; 
    } else {
        cout << "×ø±ê³¬³öµØÍ¼·¶Î§£¡" << endl;
    }
}

void G(vector<vector<char> >& map, int x, int y) {
    if (x >= 0 && x < MAP_WIDTH && y >= 0 && y < MAP_HEIGHT) {
        map[y][x] = '>'; 
    } else {
        cout << "×ø±ê³¬³öµØÍ¼·¶Î§£¡" << endl;
    }
}


int main() {
    vector<vector<char> > map(MAP_HEIGHT, vector<char>(MAP_WIDTH));
    initializeMap(map);
    int x;
    int y;
    
    for(int k=5; k <= 114; k++){
		setv(map,k,18);
    }
	for (x = 5; x <= 114; x++){ 
		if (map[2][x] == ' '){
			setfloor(map,x,2);
		}
    }
    
    for(y=6;y<=6;y++){
    	for(x=17;x<21;x++){
			setfloor(map,x,y);
		}
		for(x=41;x<48;x++){
			setfloor(map,x,y);
		}
		for(x=52;x<59;x++){
			setfloor(map,x,y);
		}
		for(x=63;x<70;x++){
			setfloor(map,x,y);
		}
    	
	}
	
	for(y=8;y<=8;y++){
		for(x=12;x<16;x++){
			setfloor(map,x,y);
		}
		for(x=22;x<26;x++){
			setfloor(map,x,y);
		}
		for(x=37;x<41;x++){
			setfloor(map,x,y);
		}
		
	}
	
	for(y=9;y<=9;y++){
		for(x=67;x<70;x++){
			F(map,x,y);
		}
		for(x=73;x<76;x++){
			F(map,x,y);
		}
		
	}
	
	for(y=10;y<=10;y++){
		for(x=5;x<11;x++){
			setfloor(map,x,y);
		}
		for(x=29;x<32;x++){
			setfloor(map,x,y);
		}
		for(x=41;x<45;x++){
			setfloor(map,x,y);
		}
		for(x=110;x<115;x++){
			setfloor(map,x,y);
		}	
	}
	
	for(y=11;y<=11;y++){
		for(x=77;x<81;x++){
			setfloor(map,x,y);
		}
    }    
	
	for(y=12;y<=12;y++){
		for(x=22;x<26;x++){
			setfloor(map,x,y);
		}
		for(x=34;x<39;x++){
			setfloor(map,x,y);
		}
		for(x=104;x<107;x++){
			setfloor(map,x,y);
		}
    	
	}
	
	for(y=13;y<=13;y++){
		for(x=60;x<64;x++){
			G(map,x,y);
		}
		for(x=69;x<74;x++){
			G(map,x,y);
		}
		
	}
	
	for(y=14;y<=14;y++){
		for(x=16;x<20;x++){
			setfloor(map,x,y);
		}
		for(x=84;x<87;x++){
			setfloor(map,x,y);
		}
		for(x=98;x<101;x++){
			setfloor(map,x,y);
		}
			
	}
	
	for(y=16;y<=16;y++){
		for(x=23;x<28;x++){
			setfloor(map,x,y);
		}
		for(x=32;x<37;x++){
			setfloor(map,x,y);
		}
		for(x=41;x<46;x++){
			setfloor(map,x,y);
		}
		for(x=51;x<56;x++){
			setfloor(map,x,y);
		}
		for(x=90;x<95;x++){
			setfloor(map,x,y);
		}
    	
	}
	for(x=16;x<=16;x++){
		for(y=6;y<=15;y++){
			setwall(map,x,y);
		}
	}
	
	for(x=5;x<=5;x++){
		for(y=5;y<=10;y++){
			setwall(map,x,y);
		}
	}
	
	for(x=76;x<=76;x++){
		for(y=7;y<=9;y++){
			setwall(map,x,y);
		}
	}
	
	for(x=36;x<=36;x++){
		for(y=7;y<=10;y++){
			setv(map,x,y);
		}
	}
	setv(map,50,2);
	setv(map,48,3);
	setv(map,47,4);
	setv(map,52,3);
	setv(map,53,4);
	setv(map,61,2);
	setv(map,59,3);
	setv(map,58,4);
	setv(map,63,3);
	setv(map,64,4);
	setv(map,71,11);
	A(map,49,6);
	A(map,60,6);
	B(map,50,6);
	B(map,61,6);
	C(map,112,9);
	D(map,114,9);
	E(map,55,8);
	E(map,55,10);
	E(map,55,12);
	
	
    
    displayMap(map);
	return 0;
}




