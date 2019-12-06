#include "hash.h"
#include <string>
#include <iostream>

using namespace std;

int HashBST::hash(int data){
    return data % tableSize;
}

void HashBST::insert(int data){
    int key = hash(data);

    // check if element empty and insert
    if (!table[key]){
        table[key] = new BSTNode;
        table[key]->data = data;
        occupied++;
        return;
    }
    // inserting along BST
    else{
        BSTNode *crawl = table[key];
        while (1){
            if (crawl->data > data && crawl->left){
                crawl = crawl->left;
            }
            else if (crawl->data < data && crawl->right){
                crawl = crawl->right;
            }
            else if (crawl->data > data && !crawl->left){
                crawl->left = new BSTNode;
                crawl->left->data = data;
                break;
            }
           else if (crawl->data < data && !crawl->right){
                crawl->right = new BSTNode;
                crawl->right->data = data;
                break;
            }
        }
        return;
    }
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

BSTNode* removeHelper(int data, BSTNode* currNode){
    if(!currNode){
        return NULL;
    }
    else if(data < currNode->data){
        currNode->left = removeHelper(data, currNode->left);
    }
    else if(data > currNode->data){
        currNode->right = removeHelper(data, currNode->right);
    }
    else{
        //No child
        if(!currNode->left && !currNode->right){
            delete currNode;
            return NULL;
        }
        //Only right child
        else if(!currNode->left){
            BSTNode *temp = currNode->right;
            delete currNode;
            return temp;

        }
        //Only left child
        else if(!currNode->right){
            BSTNode *temp = currNode->left;
            delete currNode;
            return temp;
        }
        //Both left and right child
        else{
            BSTNode *temp = currNode, *crawl = currNode->right, *temp2;
            while(crawl->left){
                if (!crawl->left->left){
                    temp2 = crawl->left;
                }
                crawl = currNode->left;
                temp2->left = NULL;
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

void HashBST::remove(int data){
    int key  = hash(data);

    table[key] = removeHelper(data, table[key]);

    return;
}