#include <iostream>
#include <string>
#include <sstream>  
#include "Stack.hpp"

using namespace std;

/*
 * Purpose: To check if the two string are the same once the rule for '#' implemented  
 * @param two strings S and T
 * @return bool
 */
bool stringMatch(string S, string T) 
{  
    StackLL stack1, stack2;
    int len1 = S.length();
    int len2 = T.length();
    int stackSize1 = 0, stackSize2 = 0;

    for (int i = 0; i < len1; i++){
        if (S[i] != '#'){
            stack1.push(S[i]);
            stackSize1++;
        }
        else{
            stack1.pop();
            stackSize1--;
        }
    }
    for (int i = 0; i < len2; i++){
        if (T[i] != '#'){
            stack2.push(S[i]);
            stackSize2++;
        }
        else{
            stack2.pop();
            stackSize2--;
        }
    }
    if (stackSize1 == stackSize2){
        while((!stack1.isEmpty()) && (!stack2.isEmpty())){
            if (stack2.peek() == stack1.peek()){
                stack2.pop();
                stack1.pop();
            }
            else{
                return false;
            }
        }
        if ((stack2.isEmpty()) && (stack1.isEmpty())){
            return true;
        }
        else{
            return false;
        }
    }
    else{
        return false;
    }

}        


int main() {
    //testcase 1
    string S1 = "ab#c", T1 = "ad#c";
    bool ans1 = true;

    if (ans1 == stringMatch(S1,T1)){

        cout << "Testcase 1 Pass" << endl;    
    }
    else{

        cout << "Fail: Testcase 1 " << endl;  
    }

    //testcase 2
    string S2 = "a#c", T2 = "b";
    bool ans2 = false;
    if (ans2 == stringMatch(S2,T2)){

        cout << "Testcase 2 Pass" << endl;    
    }
    else{

        cout << "Fail: Testcase 2 " << endl;  
    }

    //testcase 3
    string S3 = "a##c", T3 = "#a#c";
    bool ans3 = true;
    if (ans3 == stringMatch(S3,T3)){

        cout << "Testcase 3 Pass" << endl;    
    }
    else{

        cout << "Fail: Testcase 3 " << endl;  
    }

    //testcase 4
    string S4 = "", T4 = "";
    bool ans4 = true;
    if (ans4 == stringMatch(S4,T4)){

        cout << "Testcase 4 Pass" << endl;    
    }
    else{

        cout << "Fail: Testcase 4 " << endl;  
    }

    //testcase 5
    string S5 = "ab", T5 = "abc";
    bool ans5 = false;
    if (ans5 == stringMatch(S5,T5)){

        cout << "Testcase 5 Pass" << endl;    
    }
    else{

        cout << "Fail: Testcase 5 " << endl;  
    }

    return 0;
}