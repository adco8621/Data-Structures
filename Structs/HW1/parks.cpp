#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

struct Park {
    string parkname;
    string state;
    int area;
};


void addPark(Park parks[], string parkname, string state, int area, int length){
    Park newPark;
    newPark.parkname = parkname;
    newPark.state = state;
    newPark.area = area;
    parks[length-1] = newPark;
}


void printList(const Park parks[], int length){
    for (int i = 0; i < length; i++){
        cout << parks[i].parkname << " [" << parks[i].state << "] area: " << parks[i].area << endl; 
    }
}

int main(int argc, char *argv[]){

    string iFile, oFile, maxAreaString, parkName, state, line, areaStr, line1;

    iFile = argv[1];
    oFile = argv[2];
    maxAreaString = argv[3];

    int maxArea = stoi(maxAreaString);

    int numParks = 0, area;

    Park parks[55];

    ifstream in (iFile);
    ofstream out (oFile);

    int j;

    while (getline(in, line)){
        j = 0;

        stringstream ss (line);
        while (getline(ss, line1, ',')){
            if (j == 0){
                parkName = line1;
                j++;
            }
            else if (j == 1){
                state = line1;
                j++;
            }
            else{
                areaStr = line1;
                area = stoi(areaStr);
            }
        }

        numParks++;

        addPark(parks, parkName, state, area, numParks);

    }

   printList(parks, numParks);

    for (int i = 0; i < numParks; i++){
        if (parks[i].area >= maxArea){
            out << parks[i].parkname << "," << parks[i].state << "," << parks[i].area << endl;
        }
    }

    out.close();

    return 0;
}