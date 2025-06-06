/*
Leetcode Q 203 -- Remove Linked List Elements


This Q didnt say we cant create a new linked list to solve it.

shows us how to remove linked list elements in a separate scope given only a Node pointer 
By reset the next pointer of prior node to the current nodes next node.

*/
#include <iostream> 
#include <vector>
#include <cstring>
#include "Linked_list.cpp"
using namespace std;

class Solution {
    public:
        Node* removeElements(Node* head, int val) {
            Node* return_head;
            
            // Check head node:
            if (head->data == val) {
                // iterate ahead and check for following nodes with the target val
                while (head->data == val) {
                    Node* current = head; 
                    head = head->next;
                    delete current;
                }  
            }

            return_head = head;
            Node* prior; 

            while (head != nullptr) {
                if (head->data != val) {
                    prior = head;
                    head = head->next;
                }

                else {
                    // If the head node has the target value.
                    // Adjust the prior nodes next pointer to point to the current nodes next node.
                    prior->next = head->next;
                    head = head->next;
                }
            }

            return return_head;
        }
};



int main() {

    int val = 6;

    LinkedList l1;
    l1.insertAtEnd(1);
    l1.insertAtEnd(2);
    l1.insertAtEnd(6);
    l1.insertAtEnd(3);
    l1.insertAtEnd(4);
    l1.insertAtEnd(5);
    l1.insertAtEnd(6);

    Solution solution;

    Node* head = l1.head;
    Node* new_head;
    new_head = solution.removeElements(head, val);
    cout << "new_head->data in main " << new_head->data << endl;
    while (new_head != nullptr) {
        cout << "New data list: " << new_head->data << endl;
        new_head = new_head->next;
    }

    return 0;
}


