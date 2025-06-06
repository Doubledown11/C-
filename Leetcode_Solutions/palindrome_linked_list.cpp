/*
Leetcode Q 234 -- Palindrome Linked List

*/
#include <iostream> 
#include <vector>
#include "Linked_list.cpp"

using namespace std;

class Solution {
    public:
        bool isPalindrome(Node* head) {
            vector<int> vals; 

            // Iterate through the linked list and add each node's data
            // to a vector. 
            while (head != nullptr) {
                vals.push_back(head->data);
                head = head->next;
            }

            // Iterate through the vector with 2 pointers.
            int left = 0;
            int right = vals.size() - 1;

            while (left < right) {
                if (vals[left] != vals[right]) {
                    return false;
                }
                left++;
                right--;
            }

            // If we can fully iterate through the vals vector with both pointers,
            // we can safely assume that the linked list was a palindrome.
            return true;

        }
};

int main() {
    LinkedList l1;
    l1.insertAtEnd(1);
    l1.insertAtEnd(2);
    l1.insertAtEnd(2);
    l1.insertAtEnd(1);

    Solution solution; 

    Node* head = l1.head;
    bool is_palin = solution.isPalindrome(head);


    if (is_palin == true) {
        cout << "The linked list is a palindrome!" << endl;
    } else {
        cout << "The linked list is not a palidrome!" << endl;
    }
    
    return 0;
}