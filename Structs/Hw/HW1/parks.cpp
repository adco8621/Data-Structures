#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

// This reads in a csv of national parks, their state, and their area and sorts them in an array of structs. It then writes all
// parks greater than a certain area to another csv. The infile, outfile, and minimum size are all command line inputs

// park struct definition
struct Park {
    string parkname;
    string state;
    int area;
};

// add a park to the array
void addPark(Park parks[], string parkname, string state, int area, int length){
    Park newPark;
    newPark.parkname = parkname;
    newPark.state = state;
    newPark.area = area;
    parks[length-1] = newPark;
}

// print array
void printList(const Park parks[], int length){
    for (int i = 0; i < length; i++){
        cout << parks[i].parkname << " [" << parks[i].state << "] area: " << parks[i].area << endl; 
    }
}

int main(int argc, char *argv[]){

    string iFile, oFile, maxAreaString, parkName, state, line, areaStr, line1;

    iFile = argv[1];          // input file
    oFile = argv[2];          // output file
    maxAreaString = argv[3];  // minimum size

    int maxArea = stoi(maxAreaString);

    int numParks = 0, area;

    Park parks[55]; // 55 natnl parks in US

    ifstream in (iFile);
    ofstream out (oFile);

    int j;

    while (getline(in, line)){ // read, parse, and store the parks
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

    // output any parks above a given area
    for (int i = 0; i < numParks; i++){
        if (parks[i].area >= maxArea){
            out << parks[i].parkname << "," << parks[i].state << "," << parks[i].area << endl;
        }
    }

    out.close();

    return 0;
}