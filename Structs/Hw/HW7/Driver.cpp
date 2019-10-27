#include "MovieTree.hpp"
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

int menu();

int main(int argc, char const *argv[]){
    ifstream infile (argv[1]);
    string line, line1, title, rankStr, yearStr, ratingStr;
    MovieTree tree;
    int ranking, year, choice;
    float rating;
    bool run = true;
    while (getline(infile, line)){
        int j = 0;
        stringstream ss (line);
        while (getline(ss,line1,',')){
            if (j == 0){
                rankStr = line1;
                ranking = stoi(rankStr);
                j++;
            }
            else if (j == 1){
                title = line1;
                j++;
            }
            else if (j == 2){
                yearStr = line1;
                year = stoi(yearStr);
                j++;
            }
            else{
                ratingStr = line1;
                rating = stof(ratingStr);
            }
        }
        tree.addMovie(ranking,title,year,rating);
    }
    while (run){
        choice = menu();
        switch (choice){
            case 1:
                tree.printMovieInventory();
                break;
            case 2:
                cout << "Enter a movie title: " << endl;
                getline(cin, line);
                tree.deleteMovie(line);
                break;
            case 3:
                cout << "Goodbye!" << endl;
                run = false;
                break;
            default:
                break;
        }
    }
    return 0;
}

int menu(){
    string choice;
    cout << "======Main Menu======" << endl;
    cout << "1. Print the inventory" << endl;
    cout << "2. Delete a movie" << endl;
    cout << "3. Quit" << endl;
    getline(cin,choice);
    return stoi(choice);
}