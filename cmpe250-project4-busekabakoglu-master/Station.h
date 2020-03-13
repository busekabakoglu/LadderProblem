//
// Created by Buse Kabakoğlu on 12.12.2018.
//

#ifndef STATION_H
#define STATION_H

class Station {
public:
    int x;
    int y;
    int parX;
    int parY;
    int height;
    bool isVisited;
    int smallestLadder;
    Station(int height, int x, int j);
    Station();
};
class Priority{
public:
    bool operator()(Station* n1,Station* n2){
        return n1->smallestLadder > n2->smallestLadder;
    }
};

#endif //STATION_H
