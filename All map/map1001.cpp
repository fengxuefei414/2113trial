#include "map1001.h"
#include "./map_utils.h"

void generateMap1001(vector<vector<char> >& map) {
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
		for(x=10;x<22;x++){
			setfloor(map,x,y);
		}
		for(x=32;x<39;x++){
			setfloor(map,x,y);
		}
		for(x=58;x<65;x++){
			setfloor(map,x,y);
		}	
	}
	
	for(y=8;y<=8;y++){
		for(x=5;x<10;x++){
			setfloor(map,x,y);
		}
		for(x=20;x<29;x++){
			setfloor(map,x,y);
		}	
	}
	
	for(y=10;y<=10;y++){
		for(x=10;x<15;x++){
			setfloor(map,x,y);
		}
		for(x=22;x<26;x++){
			setfloor(map,x,y);
		}
		for(x=30;x<34;x++){
			setfloor(map,x,y);
		}
		
		for(x=90;x<95;x++){
			setfloor(map,x,y);
		}
		
	}
	
	for(y=11;y<=11;y++){
		for(x=77;x<80;x++){
			setfloor(map,x,y);
		}
	}
	
	for(y=12;y<=12;y++){
		for(x=5;x<10;x++){
			setfloor(map,x,y);
		}
		for(x=15;x<25;x++){
			setfloor(map,x,y);
		}
		for(x=70;x<74;x++){
			setfloor(map,x,y);
	    }
	    for(x=83;x<87;x++){
			setfloor(map,x,y);
	    }
		for(x=99;x<104;x++){
			setfloor(map,x,y);
		}
	}

	for(y=14;y<=14;y++){
		for(x=5;x<15;x++){
			setfloor(map,x,y);
		}
		for(x=43;x<46;x++){
			setfloor(map,x,y);
		}
		for(x=56;x<59;x++){
			setfloor(map,x,y);
		}
		for(x=63;x<67;x++){
			setfloor(map,x,y);
		}
		for(x=108;x<=114;x++){
			setfloor(map,x,y);
		}
		
	}
	for(y=15;y<=15;y++){
		for(x=75;x<82;x++){
			setfloor(map,x,y);
		}
	}
	
	for(y=16;y<=16;y++){
		for(x=35;x<42;x++){
			setfloor(map,x,y);
		}
		for(x=47;x<54;x++){
			setfloor(map,x,y);
		}
		
	}
	
	
	for(x=5;x<=5;x++){
		for(y=9;y<14;y++){
			setwall(map,x,y);
		}
	}
	
	for(x=15;x<=15;x++){
		for(y=8;y<17;y++){
			setv(map,x,y);
		}
	}
	
	for(x=25;x<=25;x++){
		for(y=6;y<9;y++){
			setwall(map,x,y);
		}
	}
	setwall(map,46,13);
	
	C(map,71,6);
	C(map,72,5);
	C(map,73,4);
	C(map,74,9);
	C(map,75,8);
	C(map,76,7);
	C(map,80,6);
	C(map,81,5);
	C(map,82,4);
	C(map,83,9);
	C(map,84,8);
	C(map,85,7);
	D(map,74,4);
	D(map,75,5);
	D(map,76,6);
	D(map,71,7);
	D(map,72,8);
	D(map,73,9);
	D(map,83,4);
	D(map,84,5);
	D(map,85,6);
	D(map,80,7);
	D(map,81,8);
	D(map,82,9);
	C(map,112,13);
	D(map,114,13);
	E(map,61,10);
	E(map,61,8);
	E(map,61,12);
	setv(map,50,10);
	setv(map,48,11);
}	