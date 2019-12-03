#include "hash.h"

using namespace std;

HashBST::HashBST(){
    tableSize = 1019;
}

float HashBST::getLoad(){
    return load;
}

int HashBST::hash(int data){
    return data % tableSize;
}

void HashBST::insert(int data){
    int key = hash(data);

    // check if element empty and insert
    if (table[key].data == -1){
        table[key].data = data;
        return;
    }
    // inserting along BST
    else{
        BSTNode *crawl = table[key];
        while (crawl->data != -1){
            if (crawl->data > data){
                crawl = crawl->left;
            }
            else{
                crawl = crawl->right;
            }
        }
        crawl->data = data;
        return;
    }
}

bool HashBST::lookup(int data){
    int key  = hash(data);

    // empty member
    if (table[key].data == -1){
        return 0;
    }
    // looking for entry
    else{
        BSTNode *crawl = table[key].data;
        while (crawl->data != data && crawl->data != -1){
            if (crawl ->data > data){
                crawl = crawl->left;
            }
            else{
                crawl = crawl->right;
            }
        }
        // not found
        if (crawl->data == -1){
            return 0;
        }
        // found
        else{
            return 1;
        }
    }
}

// TODO: add load stuff to insert
//       create remove func and do load stuff for it