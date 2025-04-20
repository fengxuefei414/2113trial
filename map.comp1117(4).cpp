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


int main() {
    vector<vector<char> > map(MAP_HEIGHT, vector<char>(MAP_WIDTH));
    initializeMap(map);
    int x;
    int y;
    
    for(int k=5; k <= 114; k++){
		setv(map,k,16);
	}
	
	for (x = 5; x <= 114; x++){ 
		if (map[2][x] == ' '){
			setfloor(map,x,2);
		}
    }
    
    for(y=6;y<=6;y++){
    	for(x=5;x<16;x++){
			setfloor(map,x,y);
		}
		for(x=34;x<38;x++){
			setfloor(map,x,y);
		}
		for(x=108;x<115;x++){
			setfloor(map,x,y);
		}
    }
	
	for(y=8;y<=8;y++){
		for(x=26;x<30;x++){
			setfloor(map,x,y);
		}
		for(x=42;x<46;x++){
			setfloor(map,x,y);
		}
		for(x=63;x<67;x++){
			setfloor(map,x,y);
		}
		for(x=71;x<75;x++){
			setfloor(map,x,y);
		}
		for(x=104;x<108;x++){
			setfloor(map,x,y);
		}	
	}
	
	for(y=10;y<=10;y++){
		for(x=6;x<11;x++){
			setfloor(map,x,y);
		}
		for(x=18;x<22;x++){
			setfloor(map,x,y);
		}
		for(x=50;x<54;x++){
			setfloor(map,x,y);
		}
		for(x=60;x<65;x++){
			setfloor(map,x,y);
		}
		for(x=73;x<78;x++){
			setfloor(map,x,y);
		}
		for(x=100;x<104;x++){
			setfloor(map,x,y);
	    }
	}
	
	for(y=12;y<=12;y++){
		for(x=12;x<16;x++){
			setfloor(map,x,y);
		}
		for(x=26;x<30;x++){
			setfloor(map,x,y);
		}
		for(x=42;x<46;x++){
			setfloor(map,x,y);
		}
		for(x=63;x<67;x++){
			setfloor(map,x,y);
		}
		for(x=71;x<75;x++){
			setfloor(map,x,y);
		}
		for(x=96;x<100;x++){
			setfloor(map,x,y);
		}
		
	}
	
	for(y=13;y<=13;y++){
		for(x=55;x<59;x++){
			setfloor(map,x,y);
		}	
	}
	
	for(y=14;y<=14;y++){
		for(x=5;x<16;x++){
			setfloor(map,x,y);
		}
		for(x=34;x<38;x++){
			setfloor(map,x,y);
		}
		for(x=67;x<71;x++){
			setfloor(map,x,y);
		}
		for(x=78;x<82;x++){
			setfloor(map,x,y);
		}
		for(x=85;x<88;x++){
			setfloor(map,x,y);
		}
		for(x=91;x<96;x++){
			setfloor(map,x,y);
		}
	}
	
	for(x=68;x<=68;x++){
		for(y=8;y<=13;y++){
			setwall(map,x,y);
		}
	}
	for(x=69;x<=69;x++){
		for(y=8;y<=13;y++){
			setwall(map,x,y);
		}
	}
	for(x=5;x<=5;x++){
		for(y=7;y<=13;y++){
			setwall(map,x,y);
		}
	}
	setwall(map,59,8);
	setwall(map,59,9);
	setwall(map,78,8);
	setwall(map,78,9);
	
	A(map,67,8);
	A(map,68,7);
	A(map,66,9);
	B(map,69,7);
	B(map,70,8);
	B(map,71,9);
	C(map,112,5);
	D(map,114,5);
	E(map,33,10);
	E(map,36,10);
	E(map,39,10);
	setv(map,14,6);
	setv(map,12,7);
	setv(map,11,8);
	setv(map,16,7);
	setv(map,17,8);

    displayMap(map);
	return 0;
}
    
    
    
    
    
    
    
    
    
    
    
    
    
    
 
