#include "map1013.h"
#include "./map_utils.h"

void generateMap1013(vector<vector<char> >& map) {
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
    
    A(map,71,6);
    A(map,72,5);
    A(map,73,4);
    A(map,74,9);
    A(map,75,8);
    A(map,76,7);
    A(map,80,6);
    A(map,81,5);
    A(map,82,4);
    A(map,83,9);
    A(map,84,8);
    A(map,85,7);
    B(map,74,4);
    B(map,75,5);
    B(map,76,6);
    B(map,71,7);
    B(map,72,8);
    B(map,73,9);
    B(map,83,4);
    B(map,84,5);
    B(map,85,6);
    B(map,80,7);
    B(map,81,8);
    B(map,82,9);
    C(map,112,13);
    D(map,114,13);
    E(map,61,10);
    E(map,61,8);
    E(map,61,12);
    setv(map,50,10);
    setv(map,48,11);
    setv(map,47,12);
    setv(map,52,11);
    setv(map,53,12);
    setv(map,40,12);
}

    
