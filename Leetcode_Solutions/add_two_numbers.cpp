/* 
   
    Leetcode Q 2 -- Add Two Numbers


    Need to iterate through both linked list 
    add the numbers at each node to a vector 
    one for vector for each list 

    then iterate through the vectors backwards appending 
    each number to a string, which when finished we will convert 
    to an integer. 

    the 2 integers formed from the strings of both linked list will be added 
    together and converted back to a string. 

    We convert this string back to an integer and create a new linked list 
    with each node a char in the string.
*/

#include <iostream> 
#include <vector>
#include <cstring>

#include "Linked_list.cpp"

using namespace std;


class Solution {
    public:
        LinkedList add2nums(Node* l1, Node* l2) {
            
            // Init a string for l1
            string l1_string = "";

            // Iterate through LinkedList 1.
            // A loop that runs till head is nullptr
            while (l1 != nullptr) {
                // Convert the each val to a string and append to the l1_string string.
                l1_string += to_string(l1->data);
                l1 = l1->next;
            }


            // Init a string for l2
            string l2_string = "";


            // Iterate through LinkedList 1.
            // A loop that runs till head is nullptr
            while (l2 != nullptr) {
                // Convert the each val to a string and append to the l1_string string.
                l2_string += to_string(l2->data);
                l2 = l2->next;
            }


            // Iterate through both string backwards and append their values to a new string 
            string l1_str_fix = "";
            for (int i = l1_string.size() - 1; i >= 0; i--) {
                l1_str_fix += l1_string[i];
            }   
            

            string l2_str_fix = "";
            for (int i = l2_string.size() - 1; i >= 0; i--) {
                l2_str_fix += l2_string[i];
            }
            

            // Convert both strings back to ints, and then add them.
            int sum = stoi(l1_str_fix) + stoi(l2_str_fix);


            // Since the return object is defined as a linkedlist
            // in main() we must return a linked list instance.
            LinkedList answerList;


            // Convert int back to a string 
            string string_sum = to_string(sum);


            // NOTE: when you iterate through a string in C++ and want to access each char.
            // they are no longer considered a string type but instead 
            // they are considered to be a char type.

            // Iterate through the string and add each value to a node in a linkedlist.
            for (int i = 0; i < string_sum.size(); i++) {
                
                // Since the chars in a string are not strings, they are instead chars we now have to convert 
                // chars to ints.
                int num = string_sum[i] - '0';  // Convert char to integer
                answerList.insertAtEnd(num);
                }


            // Return the new list object
            // return answerList;
            // NOTE this didnt work I need to return a Node* not a 
            // Linked list object since

            cout << " Reached end of add2nums " << endl;
            return answerList;
        }
};


int main() {
    /* 
    Main Function.
    */

    // Init solution class
    Solution solution;

    // Init LinkedLists
    LinkedList l1;
    l1.insertAtStart(3);
    l1.insertAtStart(4);
    l1.insertAtStart(2);

    LinkedList l2;
    l2.insertAtStart(4);
    l2.insertAtStart(6);
    l2.insertAtStart(5);
    
    cout << " Here is l1: " << endl;
    l1.display();

    cout << " Here is l2: " << endl;
    l2.display();

    cout << "\n\n\n" << endl;
    
    // Init 2 pointers; Both repr the heads of the linkedlist.

    // NOTE we use the dot notation to access the attribute of the object 
    // we only use the -> notation when accessing the attribute from a pointer.
    Node* l1_head = l1.head;
    Node* l2_head = l2.head;

    // NOTE -- since the pointers are defined here are Node*, 
    // the function in the solution class must be defined as Node* aswell.
    // I tried to use ListNode* just as in the leetcode answer template, but I was getting errors.

    // call add2nums and def the return object as a linked list.
    LinkedList answerList = solution.add2nums(l1_head, l2_head);
 
 
    // cout << answerList.head->data << endl;

    // Display the list
    answerList.display();

    return 0;
}