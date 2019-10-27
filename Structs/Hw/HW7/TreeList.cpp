#include "MovieTree.hpp"
#include <iostream>

using namespace std;

TreeNode* deleteNode(TreeNode *, TreeNode *);
void printHelper(TreeNode *);
void deconHelper(TreeNode *);


MovieTree::MovieTree(){
    root = NULL;
}

MovieTree::~MovieTree(){
    deconHelper(root);
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
                root = deleteNode(node, root);
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
    if (!node) {
        return;
    }
    deconHelper(node->leftChild);
    deconHelper(node->rightChild);
    while (node->head){
        LLMovieNode *temp = node->head;
        delete node->head;
        node->head = temp->next;
        delete temp;
    }
    delete node;
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

TreeNode* deleteNode(TreeNode *node, TreeNode *currNode){

  if(currNode == NULL)
  {
    return NULL;
  }
  else if(node->titleChar < currNode->titleChar)
  {
    currNode->leftChild = deleteNode(node, currNode->leftChild);
  }
  else if(node->titleChar > currNode->titleChar)
  {
    currNode->rightChild = deleteNode(node, currNode->rightChild);
  }
  // We found the node with the value
  else
  {
    //TODO Case : No child
    if(currNode->leftChild == NULL && currNode->rightChild == NULL)
    {
        delete currNode;
        return NULL;
    }
    //TODO Case : Only right child
    else if(currNode->leftChild == NULL)
    {
        TreeNode *temp = currNode;
        delete currNode;
        currNode = temp->rightChild;
        return currNode;

    }
    //TODO Case : Only left child
    else if(currNode->rightChild == NULL)
    {
        TreeNode *temp = currNode;
        delete currNode;
        currNode = temp->leftChild;
        return currNode;
    }
    //TODO Case: Both left and right child
    else
    {
      TreeNode *temp = currNode, *crawl = currNode->rightChild, *temp2 = crawl;
      while(crawl->leftChild != NULL){
          if (crawl->leftChild->leftChild = NULL){
              temp2 = crawl->leftChild;
          }
          crawl = crawl->leftChild;
          temp2->leftChild = NULL;
      }
      delete currNode;
      currNode = crawl;
      crawl->rightChild = temp->rightChild;
      crawl->leftChild = temp->leftChild;
      return currNode;
      
    }

  }
return currNode;
}
