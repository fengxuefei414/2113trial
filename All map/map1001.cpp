#include "map1001.h"
#include "./map_utils.h"

void generateMap1001(vector<vector<char> >& map) {
    initializeMap(map);
    int x;
    int y;
    
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
		for(x=32;x<40;x++){
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
		
		for(x=89;x<95;x++){
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
		for(x=98;x<105;x++){
			setfloor(map,x,y);
		}
	}
	
	for(y=13;y<=13;y++){
		for(x=41;x<46;x++){
			setfloor(map,x,y);
		}
		
	}

	for(y=14;y<=14;y++){
		for(x=5;x<15;x++){
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
		for(x=46;x<54;x++){
			setfloor(map,x,y);
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
	
	for(x=40;x<=40;x++){
		for(y=7;y<11;y++){
			setv(map,x,y);
		}
	}
	
	A(map,71,6);
	A(map,72,5);
	A(map,73,4);
	A(map,70,7);
	A(map,69,8);
	B(map,74,4);
	B(map,75,5);
	B(map,76,6);
	B(map,77,7);
	B(map,78,8);
	setfloor(map,72,7);
	setfloor(map,73,7);
	setfloor(map,74,7);
	setfloor(map,75,7);
	setfloor(map,82,4);
	setfloor(map,83,4);
	setfloor(map,84,4);
	setfloor(map,85,4);
	setfloor(map,86,4);
	setfloor(map,82,8);
	setfloor(map,83,8);
	setfloor(map,84,8);
	setfloor(map,85,8);
	setfloor(map,86,8);
	setwall(map,84,5);
	setwall(map,84,6);
	setwall(map,84,7);
	C(map,112,13);
	D(map,114,13);
	E(map,61,10);
	E(map,61,8);
	E(map,61,12);
	E(map,17,11);
	E(map,92,9);
	setv(map,50,9);
	setv(map,48,10);
	setv(map,47,11);
	setv(map,52,10);
	setv(map,53,11);
}
