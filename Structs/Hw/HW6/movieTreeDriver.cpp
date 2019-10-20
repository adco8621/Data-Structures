#include "MovieTree.hpp"
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

int menu();

int main(int argc, char const *argv[]){
    ifstream infile (argv[1]);
    string line, line1, title, search, rankStr, yearStr, ratingStr, minRat, minYear;
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
        tree.addMovieNode(ranking,title,year,rating);
    }
    while (run){
        choice = menu();
        switch (choice){
            case 1:
                cout << "Enter title:" << endl;
                getline(cin,search);
                tree.findMovie(search);
                break;
            case 2:
                cout << "Enter minimum rating:" << endl;
                getline(cin,minRat);
                cout << "Enter minimum year:" << endl;
                getline(cin,minYear);
                tree.queryMovies(stof(minRat), stoi(minYear));
                break;
            case 3:
                tree.printMovieInventory();
                break;
            case 4:
                tree.averageRating();
                break;
            case 5:
                run = false;
                cout << "Goodbye!" << endl;
                break;
        }
    }
    return 0;
}

int menu(){
    string choice;
    cout << "======Main Menu======" << endl;
    cout << "1. Find a movie" << endl;
    cout << "2. Query movies" << endl;
    cout << "3. Print the inventory" << endl;
    cout << "4. Average Rating of movies" << endl;
    cout << "5. Quit" << endl;
    getline(cin,choice);
    return stoi(choice);
}