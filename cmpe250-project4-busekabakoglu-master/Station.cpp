//
// Created by Buse Kabakoğlu on 12.12.2018.
//

#include "Station.h"
#include <climits>

Station::Station(int height,int x ,int y){
    this->smallestLadder = INT_MAX;
    this->height = height ;
    this->x = x;
    this->y = y;
    this->parX = -1;
    this->parY = -1;
    this->isVisited = false;
}
Station::Station(){

}