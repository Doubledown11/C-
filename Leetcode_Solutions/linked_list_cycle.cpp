/*
Leetcode Q 141 -- Linked List Cycle

Given the head of a linked list ID if there is a cycle in it.

Utilized a tortoise and hare algorithm.

pos IDs the nodes the node that the tail's next pointer is connected too.

*/

#include <iostream>

#include "Linked_list.cpp"


using namespace std;


class Solution {
    public:
        bool hasCycle(Node *head) {

            Node* slow = head;
            Node* fast = head;

            while (fast && fast->next) {
                // If fast reaches the tail (fast would not be true anymore and thus loop would stop)
                // the loop ends and thus no cycle.
                slow = slow->next;
                // If slow reaches the tail, it will equal None and thus return false and end the loop.

                fast = fast->next->next;

                if (slow == fast) {
                    return true;
                }
            }
            return false;
        }
};



int main() {

    LinkedList list;
    list.insertAtEnd(1);
    list.insertAtEnd(2);

    int pos = 0;
    // Thus I need to create a cycle in the list where tail's next is the node at 0th idx
    Node* current = list.head;
    Node* cycle_destination;
    int x = 0;
    while (current) {
        cout << "Current node we on: " << current->data << endl;

        // Need to assign a node pointer to the node in the idx IDd by pos:
        if (x == pos) {
            cycle_destination = current;
        }

        if (current->next == nullptr) {
            current->next = cycle_destination;
            break;
        }

        x++;
        current = current->next;
    }


    Solution solution;

    Node* head = list.head;

    bool cycle = solution.hasCycle(head);

    if (cycle ==  false) {
        cout << "There is no cycle in the linked list!" << endl;
    } else {
        cout << "There is a cycle in the linked list!" << endl;
    }

    return 0;
}