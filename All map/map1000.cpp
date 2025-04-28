#include "map1000.h"
#include "./map_utils.h"

void generateMap1000(vector<vector<char> >& map) {
    initializeMap(map);
    int x;
    int y;
	
	for(int k=5; k <= 114; k++){
		setv(map,k,14);
	}
	
	for (int x = 5; x <= 114; x++){ 
		if (map[2][x] == ' '){
			setfloor(map,x,2);
		}
		if (map[14][x] == ' '){
			setfloor(map,x,14);
		}
	}
	
	for(x=4;x<=4;x++){
		for(y=2;y<=14;y++){
			side(map,x,y);
		}
	}
	for(x=115;x<=115;x++){
		for(y=2;y<=14;y++){
			side(map,x,y);
		}
	}
	
	for (y = 6; y <= 6 ; y++){
		for(x=25;x<35;x++){
			setfloor(map,x,y);
		}
		for(x=39;x<43;x++){
			setfloor(map,x,y);
		}
		for(x=47;x<57;x++){
			setfloor(map,x,y);
		}
		for(x=87;x<92;x++){
			setfloor(map,x,y);
		}
			
	}
	for (y = 8; y <= 8 ; y++){
		for(x=11;x<15;x++){
			setfloor(map,x,y);
		}
		for(x=20;x<24;x++){
			setfloor(map,x,y);
		}
		for(x=57;x<61;x++){
			setfloor(map,x,y);
		}
		for(x=82;x<86;x++){
			setfloor(map,x,y);
		}
		for(x=93;x<97;x++){
			setfloor(map,x,y);
		}
		
		
	}
	for (y = 10; y <= 10 ; y++){
		for(x=15;x<19;x++){
			setfloor(map,x,y);
		}
		for(x=25;x<31;x++){
			setfloor(map,x,y);
		}
		for(x=35;x<39;x++){
			setfloor(map,x,y);
		}
		for(x=43;x<47;x++){
			setfloor(map,x,y);
		}
		for(x=61;x<65;x++){
			setfloor(map,x,y);
		}
		for(x=77;x<80;x++){
			setfloor(map,x,y);
		}
		for(x=99;x<102;x++){
			setfloor(map,x,y);
		}
	}
		
	for (y = 12; y <= 12 ; y++){
		for(x=11;x<15; x++){
			setfloor(map,x,y);
		}
		for(x=57;x<61;x++){
			setfloor(map,x,y);
		}
		for(x=65;x<77;x++){
			setfloor(map,x,y);
		}
		for(x=104;x<=114;x++){
			setfloor(map,x,y);
		}
		
	}
	for (y = 11; y <= 11 ; y++){
		for(x=87;x<92;x++){
			setfloor(map,x,y);
		}
	}
	for (int y = 13; y <= 13 ; y++){
		for(x=81;x<85;x++){
			setfloor(map,x,y);
		}
		for(x=94;x<98;x++){
			setfloor(map,x,y);
		}
	}
	for (y = 14; y <= 14 ; y++){
		for(x=5;x<15;x++){
			setfloor(map,x,y);
		}
		
	}
	
	for (x=19;x<=19;x++){
		for(y=8;y<=10;y++){
			setwall(map,x,y);
		}
	}
	
	for (x=15;x<=15;x++){
		for(y=12;y<=14;y++){
			setwall(map,x,y);
		}
	}
	for (x=65;x<=65;x++){
		for(y=9;y<=10;y++){
			setwall(map,x,y);
		}
	}
	
	A(map,70,12);
	B(map,71,12);
	C(map,112,11);
	D(map,114,11);
	E(map,70,10);
	E(map,89,5);
	E(map,26,9);
}
