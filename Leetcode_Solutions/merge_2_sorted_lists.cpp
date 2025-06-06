/*
Leetcode Q 21 -- Merge Two Sorted Lists

*/
#include <iostream>
#include <vector>
#include "Linked_list.cpp"

using namespace std;

class Solution {
    public:
        Node* mergeLists(Node* l1, Node* l2) {
    
            LinkedList answer_list;


            // Case: When both lists are empty
            if (l1 == nullptr && l2 == nullptr) {
                cout << "case called" << endl;
                // Return a nullptr
                return l1;
            }

            // Case: Both lists have values inside them
            while (l1 != nullptr && l2 != nullptr) {
                
                cout << "l1 " << l1->data;
                cout << "l2 " << l2->data;

                // Check to ensure current data is not null. 
                // If not add to answer_list and move up a pos.
                if (l1 != nullptr) {
                    cout << " adding 1st if " << l1->data << endl;

                    answer_list.insertAtEnd(l1->data);
                    l1 = l1->next;
                } 


                if (l2 != nullptr) {
                    cout << " adding 2nd if " << l2->data << endl;
                    answer_list.insertAtEnd(l2->data);
                    l2 = l2->next;
                } 

            } 

            // Case: Only l1 has values
            while (l2 == nullptr && l1 != nullptr) {
                answer_list.insertAtEnd(l1->data);
                l1 = l1->next;
            }
            
            
            // Case: Only l2 has values
            while (l1 == nullptr && l2 != nullptr) {
                answer_list.insertAtEnd(l2->data);
                l2 = l2->next;
            }


            Node* head_solution_list = answer_list.head;
            cout << "return list " << endl; 
            answer_list.display();
            return head_solution_list;
        }
};



int main() {

    // Init solution class
    Solution solution;

    // Init LinkedLists
    LinkedList l1;
    l1.insertAtStart(4);
    // l1.insertAtStart(2);
    // l1.insertAtStart(1);

    LinkedList l2;
    // l2.insertAtStart(4);
    // l2.insertAtStart(3);
    // l2.insertAtStart(1);

    // Heads of lists
    Node* l1_head = l1.head;
    Node* l2_head = l2.head;

    Node* head_solution_list;
    head_solution_list = solution.mergeLists(l1_head, l2_head);

    if (head_solution_list == nullptr) {
        // Both lists were empty
        cout << "Both lists were empty, and therefore the head of the new list is a nullptr." << endl;
    }
    else{
        cout << head_solution_list->data << " final list head data." << endl;
    }
}

