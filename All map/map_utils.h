#ifndef MAP_UTILS_H
#define MAP_UTILS_H

#include <vector>
#include <iostream>

using namespace std;

// 地图常量
const int MAP_WIDTH = 120;
const int MAP_HEIGHT = 20;

// 地图工具函数声明
void displayMap(const vector<vector<char> >& map);
void initializeMap(vector<vector<char> >& map);
void setfloor(vector<vector<char> >& map, int x, int y);
void setfloors(vector<vector<char> >& map, int x, int y);
void setv(vector<vector<char> >& map, int x, int y);
void setwall(vector<vector<char> >& map, int x, int y);
void A(vector<vector<char> >& map, int x, int y);
void B(vector<vector<char> >& map, int x, int y);
void C(vector<vector<char> >& map, int x, int y);
void D(vector<vector<char> >& map, int x, int y);
void E(vector<vector<char> >& map, int x, int y);
void F(vector<vector<char> >& map, int x, int y);
void G(vector<vector<char> >& map, int x, int y);
void side(vector<vector<char> >& map, int x, int y);
void setleftv(vector<vector<char> >& map, int x, int y);
void setrightv(vector<vector<char> >& map, int x, int y);

#endif 