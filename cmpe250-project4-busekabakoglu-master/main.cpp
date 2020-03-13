#include <iostream>
#include <fstream>
#include <vector>
#include "Station.h"
#include <queue>
using namespace std;


int main(int argc, char* argv[]) {
    if (argc != 3) {
        cout << "Run the code with the following command: ./project1 [input_file] [output_file]" << endl;
        return 1;
    }
    cout << "input file: " << argv[1] << endl;
    cout << "output file: " << argv[2] << endl;
    ifstream inputFile(argv[1]);
    priority_queue<Station*,vector<Station*>,Priority> pq;
    int columns;
    int rows;
    inputFile>>rows;
    inputFile>>columns;
    int numQuery;
    int x1,y1,x2,y2;
    int height;
    Station* matrix[columns][rows];
    ofstream myFile;
    myFile.open(argv[2]);
    for(int i = 0; i<rows ; i++){
        for(int j = 0 ; j<columns ; j++){
            inputFile>>height;
            matrix[i][j] = new Station(height,i,j);
        }
    }

    inputFile>>numQuery;

        inputFile >> x1;
        inputFile >> y1;
        inputFile >> x2;
        inputFile >> y2;
        x1 = x1 - 1;
        x2 = x2 - 1;
        y1 = y1 - 1;
        y2 = y2 - 1;
        matrix[x1][y1]->smallestLadder = 0;
        pq.push(matrix[x1][y1]);
        int i;
        int j;
        while (!pq.empty()) {
            Station *temp;
            temp = pq.top();
            pq.pop();
            temp->isVisited = true;
            i = temp->x;
            j = temp->y;
            if (temp->parX >= 0 && temp->parY >= 0) {
                if (matrix[temp->parX][temp->parY]->smallestLadder > temp->smallestLadder) {

                    temp->smallestLadder = matrix[temp->parX][temp->parY]->smallestLadder;
                }
            }
            if (i + 1 <= columns - 1 && !matrix[i + 1][j]->isVisited) {
                if (abs(matrix[i][j]->height - matrix[i + 1][j]->height) < matrix[i + 1][j]->smallestLadder) {

                    matrix[i + 1][j]->smallestLadder = abs(matrix[i][j]->height - matrix[i + 1][j]->height);
                    pq.push(matrix[i + 1][j]);
                    matrix[i + 1][j]->parX = i;
                    matrix[i + 1][j]->parY = j;
                }
            }
            if (j + 1 <= rows - 1 && !matrix[i][j + 1]->isVisited) {
                if (abs(matrix[i][j]->height - matrix[i][j + 1]->height) < matrix[i][j + 1]->smallestLadder) {

                    matrix[i][j + 1]->smallestLadder = abs(matrix[i][j]->height - matrix[i][j + 1]->height);
                    pq.push(matrix[i][j + 1]);
                    matrix[i][j + 1]->parX = i;
                    matrix[i][j + 1]->parY = j;
                }

            }
            if (i - 1 >= 0 && !matrix[i - 1][j]->isVisited) {
                if (abs(matrix[i][j]->height - matrix[i - 1][j]->height) < matrix[i - 1][j]->smallestLadder) {

                    matrix[i - 1][j]->smallestLadder = abs(matrix[i][j]->height - matrix[i - 1][j]->height);
                    pq.push(matrix[i - 1][j]);
                    matrix[i - 1][j]->parX = i;
                    matrix[i - 1][j]->parY = j;
                }
            }
            if (j - 1 >= 0 && !matrix[i][j - 1]->isVisited) {
                if (abs(matrix[i][j]->height - matrix[i][j - 1]->height) < matrix[i][j - 1]->smallestLadder) {

                    matrix[i][j - 1]->smallestLadder = abs(matrix[i][j]->height - matrix[i][j - 1]->height);
                    pq.push(matrix[i][j - 1]);
                    matrix[i][j - 1]->parX = i;
                    matrix[i][j - 1]->parY = j;
                }
            }

        }

        myFile<<matrix[x2][y2]->smallestLadder<<endl;


    return 0;
}