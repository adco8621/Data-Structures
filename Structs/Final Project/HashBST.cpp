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
    if (table[key]->data == -1){
        cout << 2 << endl;
        table[key] = new BSTNode;
        cout << 3 << endl;
        table[key]->data = data;
        cout << 4 << endl;
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
    if (table[key] == NULL){
        return 0;
    }
    // looking for entry
    else{
        BSTNode *crawl = table[key];
        while (crawl->data != data && crawl != NULL){
            if (crawl -> data > data){
                crawl = crawl->left;
            }
            else{
                crawl = crawl->right;
            }
        }
        // not found
        if (crawl == NULL){
            return 0;
        }
        // found
        else{
            return 1;
        }
    }
}

float HashBST::getLoad(){
    // annoying to round load to one decimal
    load = (occupied/tableSize)*10;
    int temp = (int)load;
    load = (float)temp/10;
    return load;
}

bool HashBST::remove(int data){
    return 1;
}

// TODO: create remove func and do load stuff for it