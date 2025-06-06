/*
Leetcode Q 206 -- Reverse Linked List

*/
#include <iostream> 
#include <vector>
#include "Linked_list.cpp"
using namespace std;

class Solution {
    public:
        Node* reverseList(Node* head) {
            // Create 2 copies of the head pointer to be used after the first step.
            // and to return to the main function.
            Node* head_copy = head;
            Node* head_copy2 = head;

            // Iterate through the list and get each value and put it into a vector.
            vector<int> values;

            // we insert the values at the idx of 0, so the values are reversed.
            while (head != nullptr) {
                values.insert(values.begin(), head->data);
                head = head->next;
            }

            int values_pos = 0;
            // Now iterate through the linked list and replace values with the values 
            // held inside of the values vector. Which are the linked lists values in reverse order.
            while (head_copy != nullptr) {
                head_copy->data = values[values_pos];
                values_pos++;
                head_copy = head_copy->next;
            }

            return head_copy2;
        }
};


int main() {
    Solution solution; 

    LinkedList l1;
    l1.insertAtEnd(1);
    l1.insertAtEnd(2);
    l1.insertAtEnd(3);
    l1.insertAtEnd(4);
    l1.insertAtEnd(5);

    cout << "The linked list before being reversed: " << endl;
    l1.display();

    Node* head = l1.head;
    Node* new_head = solution.reverseList(head);

    cout << "The linked list after being reversed: " << endl;
    l1.display();
    
    return 0;
}

