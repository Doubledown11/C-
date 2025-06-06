/*
Leetcode 24 - Swap Nodes in Pairs

*/
#include <iostream>
#include "Linked_list.cpp"
using namespace std;


class Solution {
    public:
        Node* swapPairs(Node* head) {
            if (!head || !head->next) return head; // Base case: no swap needed if the list is empty or has one node
        
            Node* dummy = new Node(0); // Dummy node to simplify edge cases
            dummy->next = head;
            Node* prev = dummy;

            while (head && head->next) {
                Node* first = head;
                Node* second = head->next;

                // Swapping pointers
                prev->next = second;
                first->next = second->next;
                second->next = first;

                // Moving forward
                prev = first;
                head = first->next;
            }

            return dummy->next; // Return the new head
        }
};



int main () {
    Solution solution; 

    LinkedList list1;
    list1.insertAtEnd(1);
    list1.insertAtEnd(2);
    list1.insertAtEnd(3);
    list1.insertAtEnd(4);

    Node* head = list1.head; 

    Node* new_head = solution.swapPairs(head);

    cout << "The values in the new list: " << endl;

    // while (new_head != nullptr) {
    //     cout << new_head->data << " ";
    // }
    // cout << endl;

    return 0;
}