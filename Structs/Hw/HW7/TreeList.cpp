#include "MovieTree.hpp"
#include <iostream>

using namespace std;

MovieTree::MovieTree(){
    root = NULL;
}

MovieTree::~MovieTree(){

}

void MovieTree::printMovieInventory(){
    if (root == NULL){
        return;
    }
    printHelper(root);
}

void MovieTree::addMovie(int ranking, string title, int year, float rating){
    LLMovieNode *nn = new LLMovieNode(ranking, title, year, rating);
    char first = title[0];
    TreeNode *node = root;
    if (root){
        while (first != node->titleChar){
            if ((first < node->titleChar) && (node->leftChild)){
                node = node->leftChild;
            }
            else if (first < node->titleChar){
                node->leftChild = new TreeNode;
                node = node->leftChild;
                node->titleChar = first;
            }
            else if ((first > node->titleChar) && (node->rightChild)){
                node = node->rightChild;
            }
            else{
                node->rightChild = new TreeNode;
                node = node->rightChild;
                node->titleChar = first;
            }
        }
    }
    else{
        root = new TreeNode;
        root->titleChar = first;
        node = root;
    }

    if (node->head == NULL){
        node->head = nn;
    }
    else if (title < node->head->title){
        nn->next = node->head;
        node->head = nn;
    }
    else{
        LLMovieNode *pres = node->head, *prev = NULL;
        while ((pres->title < title) && (pres->next)){
            prev = pres;
            pres = pres->next;
        }
        if (pres->title > title){
            prev->next = nn;
            nn->next = pres;
        }
        else{
            pres->next = nn;
        }
    }
}

void MovieTree::deleteMovie(string title){
    if (root){
        char first = title[0];
        TreeNode *node = root;
        while (first != node->titleChar){
            if ((first < node->titleChar) && (node->leftChild)){
                node = node->leftChild;
            }
            else if ((first > node->titleChar) && (node->rightChild)){
                node = node->rightChild;
            }
            else{
                cout << "Movie: " << title << " not found, cannot delete." << endl;
                return;
            }
        }

        if (!node->head){
            cout << "Movie: " << title << " not found, cannot delete." << endl;
            return;
        }
        else if (node->head->title == title){
            LLMovieNode *temp = node->head->next;
            delete node->head;
            node->head = temp;
            if (!node->head){
                deleteNode(node);
            }
        }
        else{
            LLMovieNode *pres = node->head, *prev = NULL;
            while ((pres->title != title) && (pres->next)){
                prev = pres;
                pres = pres->next;
            }
            if (pres->title == title){
                prev->next = pres->next;
                delete pres;
            }
            else{
                cout << "Movie: " << title << " not found, cannot delete." << endl;
                return;
            }
        }
    }
    else{
        cout << "Movie: " << title << " not found, cannot delete." << endl;
        return;
    }
}

void deconHelper(TreeNode *node){

}

void printHelper(TreeNode *node){
    if (node == NULL){
        return;
    }
    LLMovieNode *crawl = node->head;
    printHelper(node->leftChild);
    cout << "Movies starting with letter: " << node->titleChar << endl;
    cout << " >> " << crawl->title << " " << crawl->rating << endl;
    while (crawl->next != NULL){
        crawl = crawl->next;
        cout << " >> " << crawl->title << " " << crawl->rating << endl;
    }
    printHelper(node->rightChild);
}

void deleteNode(TreeNode *node){
    if(node->leftChild == NULL && node->rightChild == NULL)
    {
        delete node;
        return;
    }
    else if(node->leftChild == NULL)
    {
        TreeNode *temp = node;
        delete node;
        node = temp->rightChild;
    }
    else if(node->rightChild == NULL)
    {
        TreeNode *temp = node;
        delete node;
        node = temp->leftChild;
    }
    else
    {
      TreeNode *temp = node, *crawl = node->rightChild, *temp2;
      while(crawl->leftChild != NULL){
          if (crawl->leftChild->leftChild = NULL){
              temp2 = crawl->leftChild;
          }
          crawl = node->leftChild;
          temp2->leftChild = NULL;
      }
      delete node;
      node = crawl;
      crawl->rightChild = temp->rightChild;
      crawl->leftChild = temp->leftChild;
      return;
      
    }
}
