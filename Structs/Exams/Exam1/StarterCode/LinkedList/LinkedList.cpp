#include "LinkedList.hpp"

using namespace std;
/*
 * Purpose: To find the middle element of the linked list
 * @param Use head to traverse the Linked List
 * @return Middle Node
 */
Node* LinkedList::getMiddle()
{
  Node *fast = head, *slow = head;
  if (head != NULL){
    int i = 1;
    while (1){
      if(fast == NULL || fast->next == NULL){
        break;
      }
      else{
        fast = fast->next->next;
        slow = slow->next;
      }
    }
    return slow;
  }
  else{
    return NULL;
  }
}

// Add a new node to the list
void LinkedList::insert(Node* prev, int newKey){

  //Check if head is Null i.e list is empty
  if(head == NULL){
    head = new Node;
    head->key = newKey;
    head->next = NULL;
  }

  // if list is not empty, look for prev and append our node there
  else if(prev == NULL)
  {
      Node* newNode = new Node;
      newNode->key = newKey;
      newNode->next = head;
      head = newNode;
  }

  else{

      Node* newNode = new Node;
      newNode->key = newKey;
      newNode->next = prev->next;
      prev->next = newNode;

    }
  }


// Print the keys in your list
void LinkedList::printList(){
  Node* temp = head;

  while(temp->next != NULL){
    cout<< temp->key <<" -> ";
    temp = temp->next;
  }

  cout<<temp->key<<endl;
}

// Search for a specified key and return a pointer to that node
Node* LinkedList::searchList(int key) {

    Node* ptr = head;
    while (ptr != NULL && ptr->key != key)
    {
        ptr = ptr->next;
    }
    return ptr;
}
