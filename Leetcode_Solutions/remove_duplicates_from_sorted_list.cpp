/*
Leetcode Q 83 -- Remove Duplicates from Sorted List

NOTE:
    In python we can easily check a list for a specific member element by using 
    if x is in list, BUT in C++ there is no built in way to do this besides:
        Using a loop to iterate through the list, OR
        from <algorithm> containsElement()

    I used the find() function of the vector header file.  
        https://www.geeksforgeeks.org/check-if-vector-contains-given-element-in-cpp/



    I utilized an inplace algorithm method similar to that of the solution to leetcode 
    27 

*/
#include <iostream> 
#include <vector>
#include <algorithm>
#include "Linked_list.cpp"
using namespace std;

class Solution {
    public:
        Node* deleteDuplicates(Node* head) {
            vector<int> unique_vals;

            // We need to create a number of copy node pointers to the head node. 
            
            // The one below holds the Node pointer to the last non dupe value found.
            // We assume head to be a unique/new value so we set the pointer
            // to the next node.
            Node* non_dupe_node = head->next;

            // Init a node pointer which we will be used to iterate through the linked list 
            // to remove the duplicates after they have been moved to the end of the current list. 
            Node* ll_head = head;

            // The below head pointer will be used to return the new list after all changes have been made
            Node* return_head = head;

            // Holds the current node's data.
            int target = head->data;
            
            // We then set the head pointer to the next node 
            /// Same as the node pointer above.
            head = head->next;

            // Init var to hold num of unique vals in the list. 
            // Makes the removal of duplicate nodes easy.
            int num_unique = 1;

            while (head != nullptr) {
                cout << "Current head node data: " << head->data << endl;

                // If we find that the current node holds a unique value.
                if (head->data != target) {
                    // Increment the num_unique var.
                    num_unique++;

                    // We swap the nodes data 
                    // Swaps the last duplicate value with the new/unique value. 
                    non_dupe_node->data = head->data;

                    // Thus we can now move the non_dupe_node ahead a spot.
                    non_dupe_node = non_dupe_node->next;
                    // We also reset the target value to hold the current node's data, which was the newest/unique value.
                    target = non_dupe_node->data;
                    // Finally, we also move head a node ahead.
                    head = head->next;
                } 
                // If we find another duplicate data point of the last new/unique value we found.  
                else {
                    // we continue to iterate ahead in the Linked List.
                    head = head->next;
                }               
            }

             
            // Now that all the duplicate nodes have been moved to the back of the list, 
            // I need to remove them from the list.
            while (num_unique >= 1) {

                // If num_unique == 1, we are on the last unique val
                // thus we delete the next node to remove all duplicates.
                if (num_unique == 1) {
                    Node* deleted_node = ll_head->next; 
                    ll_head->next = nullptr;

                    // Free memory by deleting the all of the duplicate nodes
                    while (deleted_node) {
                        Node* nextNode = deleted_node->next;
                        delete deleted_node;
                        deleted_node = nextNode;
                    }                    
                }

                num_unique--;   
                ll_head = ll_head->next;
            }
 
            cout << "return_head val in deletedup func: " << return_head->data << endl;

            return return_head;
        }
};



int main() {
    Solution solution;
    
    LinkedList list1;
    list1.insertAtEnd(1);
    list1.insertAtEnd(1);
    list1.insertAtEnd(2);
    list1.insertAtEnd(3);
    list1.insertAtEnd(3);

    cout << "list1 display before changes " << endl;
    list1.display();
    cout << "\n\n";

    Node* head = list1.head;
    Node* new_head = solution.deleteDuplicates(head); 

    return 0;
}