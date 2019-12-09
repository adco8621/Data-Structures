#include "hash.h"
#include <string>
#include <iostream>

using namespace std;

int HashBST::hash(int data){
    return data % tableSize;
}

BSTNode* insertHelper(BSTNode* currNode, int data){
    if(currNode == NULL){
        BSTNode* newNode = new BSTNode;
        newNode->data = data;
        newNode->left = NULL;
        newNode->right = NULL;
        return newNode;
    }
    else if(currNode->data < data){
        currNode->right = insertHelper(currNode->right,data);
    }
    else if(currNode->data > data){
        currNode->left = insertHelper(currNode->left,data);
    }
    return currNode;
}

void HashBST::insert(int data){

    int key = hash(data);
    if(table[key] == NULL){
        occupied++;
    }
    table[key] = insertHelper(table[key], data);
    return;
}

bool HashBST::lookup(int data){
    int key  = hash(data);

    // empty member
    if (!table[key]){
        return 0;
    }
    // looking for entry
    else{
        BSTNode *crawl = table[key];
        while (crawl->data != data && crawl){
            if ((crawl -> data > data) && crawl -> left){
                crawl = crawl->left;
            }
            else if (((crawl -> data > data) && !crawl -> left)){
                return 0;
            }
            else if (((crawl -> data < data) && crawl -> right)){
                crawl = crawl->right;
            }
            else if (((crawl -> data < data) && !crawl -> right)){
                return 0;
            }
        }
        // not found
        if (!crawl){
            return 0;
        }
        // found
        else{
            return 1;
        }
    }
}

float HashBST::getLoad(){
    // annoying to round load to two decimals
    load = ((float)occupied/(float)tableSize)*100;
    int temp = (int)load;
    load = (float)temp/100;
    return load;
}

BSTNode* HashBST::remove(BSTNode *currNode, int data){
    if(currNode == NULL)
  {
    return NULL;
  }
  else if(data < currNode->data)
  {
    currNode->left = remove(currNode->left, data);
  }
  else if(data > currNode->data)
  {
    currNode->right = remove(currNode->right, data);
  }
  // We found the node with the value
  else
  {
    //TODO Case : No child
    if(currNode->left == NULL && currNode->right == NULL)
    {
        delete currNode;
        return NULL;
    }
    //TODO Case : Only right child
    else if(currNode->left == NULL)
    {
        BSTNode *temp = currNode;
        delete currNode;
        return temp->right;

    }
    //TODO Case : Only left child
    else if(currNode->right == NULL)
    {
        BSTNode *temp = currNode;
        delete currNode;
        return temp->left;
    }
    //TODO Case: Both left and right child
    else
    {
      BSTNode *temp = currNode, *crawl = currNode->right, *temp2;
      while(crawl->left != NULL){
          if (crawl->left->left = NULL){
              temp2 = crawl->left;
              temp2->left = NULL;
          }
          crawl = currNode->left;
      }
      delete currNode;
      currNode = crawl;
      crawl->right = temp->right;
      crawl->left = temp->left;
      return currNode;
      
    }

  }
return currNode;
}