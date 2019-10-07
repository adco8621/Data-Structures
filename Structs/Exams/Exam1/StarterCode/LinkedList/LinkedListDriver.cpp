#include <iostream>
#include "LinkedList.hpp"

using namespace std;

void  testcase(int ans, Node* result)
{
 if (ans == result->key){
     cout << "Testcase Pass " << ans << " "<< result->key<<endl;
 }
 else{
     cout << "Fail: Testcase " << ans << " "<< result->key<<endl;
 }
}
int main()
 {
   //Test case 1
     LinkedList li1;
   int prev = 100;
   li1.insert(NULL,10);
   for (int i=1; i< 5; i++)
   {
     int val = 20*i - 7;
     li1.insert(li1.searchList(prev),val);
     prev = val;
   }
   li1.printList();
   int ans1 = 53;
   Node* mid1 = li1.getMiddle();
   cout << "Testing getMiddle function: " ;
   testcase(ans1, mid1);
   
   //Test case 2
   LinkedList li2;
   cout<<"Adding 15 nodes to List"<<endl;
   int prev2 = 30;
   li2.insert(NULL,30);
   for (int i=1; i< 16; i++)
   {
     int val = (200*i) - (i*i);
     li2.insert(li2.searchList(prev2),val);
     prev2 = val;
   }
   li2.printList();
   int ans2 = 1536;
   Node* mid2 = li2.getMiddle();
   cout << "Testing getMiddle function: ";
   testcase(ans2, mid2);

   //Test case 3
   LinkedList li3;
   li3.insert(NULL,10);
   li3.printList();
   int ans3 = 10;
   Node* mid3 = li3.getMiddle();
   cout << "Testing getMiddle function: " ;
   testcase(ans3, mid3);

   //Test case 4
   LinkedList li4;
   Node* mid4 = li4.getMiddle();
   cout << "Testing getMiddle function: " ;
   if (mid4 == NULL){
     cout << "Pass" << endl;
   }
   else{
     cout << "Fail" << endl;
   }
   
   return 0;
}