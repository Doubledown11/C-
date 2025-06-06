/*
Leetcode Q 160-- Intersection of Two Linked Lists 



*/

#include <iostream>
#include <unordered_map>

#include "Linked_list.cpp"


using namespace std;


class Solution {
    public:
        Node* getIntersectionNode(Node *head1, Node *head2) {
            
            unordered_map<Node*, int> hashmap;

            while (head1 != nullptr) {
                hashmap[head1]++;
                head1 = head1->next;
            }

            while (head2 != nullptr) {
                if (hashmap[head2] > 0) {
                    return head2;
                }
                head2 = head2->next;
            }
            return nullptr;

        }
};




int main() {

    LinkedList list;
    list.insertAtEnd(4);
    list.insertAtEnd(1);
    list.insertAtEnd(8);
    list.insertAtEnd(4);
    list.insertAtEnd(5);

    
    LinkedList list2;
    list2.insertAtEnd(5);
    list2.insertAtEnd(6);
    list2.insertAtEnd(1);
    list2.insertAtEnd(8);
    list2.insertAtEnd(4);
    list2.insertAtEnd(5);

    Solution solution;

    Node* head1 = list.head;
    Node* head2 = list2.head; 

    Node* new_list_head = solution.getIntersectionNode(head1, head2);

    cout << "The value at the new list head: " << new_list_head->data << endl;

    return 0;
}