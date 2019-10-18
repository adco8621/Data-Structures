#include "MovieTree.hpp"
#include <iostream>
#include <string>
#include<fstream>
#include <sstream>

using namespace std;

// MovieNode: node struct that will be stored in the MovieTree BST

MovieTree::MovieTree() {
  root = NULL;
}

MovieTree::~MovieTree() {
  if (root != NULL){
    deleteTree(root);
  }
}

void MovieTree::printMovieInventory() {   
   if (root == NULL){
     cout << "Tree is Empty. Cannot print" << endl;
     return;
   }
   traversePrintTree(root);
   return;
}


void MovieTree::addMovieNode(int ranking, string title, int year, float rating) {
  MovieNode *node = root;
  if (root == NULL){
    root = new MovieNode(ranking, title, year, rating);
    return;
  }
  while (true){
    if ((title < node->title) && (node->left != NULL)){
      node = node->left;
    }
    else if ((title > node->title) && (node->right != NULL)){
      node = node->right;
    }
    else if ((title < node->title) && (node->left == NULL)){
      node->left = new MovieNode(ranking, title, year, rating);
      break;
    }
    else if ((title > node->title) && (node->right == NULL)){
      node->right = new MovieNode(ranking, title, year, rating);
      break;
    }
  }
  return;
}

void MovieTree::findMovie(string title) {
  MovieNode *node = root;
  while (true){
    if ((title < node->title) && (node->left != NULL)){
      node = node->left;
    }
    else if ((title > node->title) && (node->right != NULL)){
      node = node->right;
    }
    else if (node->title == title){
      cout ​<<​​"Movie Info:"​​<<​ endl;
      cout ​<<​​"=================="​​<<​ endl;
      cout ​<<​​"Ranking:"​​<< node->ranking <<​ endl;
      cout ​<<​​"Title  :"​​<< node->title <<​ endl;
      cout ​<<​​"Year   :"​​<< node->year <<​ endl;
      cout ​<<​​"rating :"​​<< node->rating <<​ endl;
      break;
    }
    else {
      cout << "Movie not found." << endl;
      break;
    }
  }
  return;
}

void MovieTree::queryMovies(float rating, int year) {
  if (root == NULL){
    cout << "Tree is Empty. Cannot query Movies" << endl;
    return;
  }
  cout​ << ​"Movies that came out after " ​<< year <<​ " with rating atleast " ​<< rating <<​ ":"​ << ​endl​;
  queryHelper(root);
  return;
}

void MovieTree::averageRating() {
  //write your code
}

void deleteTree(MovieNode *node){
  if (node == NULL) return;

  if (node->left != NULL){
    deleteTree(node->left);
  }
  if (node->right != NULL){
    deleteTree(node->right);
  }

  /* TODO then delete the node */
  node->left = NULL;
  node->right = NULL;
  delete node;
}

void traversePrintTree(MovieNode *node){
  if (node == NULL) return;

  if (node->left != NULL){
    traversePrintTree(node->left);
  }
  cout << "Movie: " << node->title << " " << node->rating << endl;
  if (node->right != NULL){
    traversePrintTree(node->right);
    }
}

void queryHelper(MovieNode *node){
  if (node == NULL){
    return
  }
  cout << node->title << "(" << node->year << ")" << node->rating << endl;

  queryHelper(node->left);
  queryHelper(node->right);
  return;
}