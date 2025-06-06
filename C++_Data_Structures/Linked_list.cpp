/*
A Linked List Implementation. 

Implemented the LinkedList object using a class.

Used to learn C++.

Dalice Dieckman 

Date: 2025-04-18


Sources: 
    https://www.geeksforgeeks.org/cpp-linked-list/ 
    https://medium.com/@RobuRishabh/beginners-guide-to-linked-list-in-c-d8445ef906ab
    and also used copilot to aid with understanding, though no code came from it. 

*/

#include <iostream>
using namespace std;


class Node {
    /*
    Linked List Node class.
    */
    
    public:
        int data;
        Node* next;
    
        Node(int value) {
            /*
            A constructor function for the linked list node class.
            */
            
            data = value;
            next = nullptr;
        }
    };


class LinkedList {
    /*
    Class for the Linked List.    
    */

    public: 
        // Pointer to the first node in the list.
        Node* head;
        
        LinkedList() {
            /* 
            Constructor function for the linked list class.
            */
            
            head = nullptr;
        }
         

        void insertAtEnd(int value) {
            /* 
            Function to insert a node at the end.
            */

            Node* newNode = new Node(value);

            if (head == nullptr) {
                head = newNode; // If list is empty, make newNode the head.
            } else {
                Node* temp = head;
                while (temp->next != nullptr) {
                    temp = temp->next; // Traverse the list to the last node.
                }
                temp->next = newNode; // Link the last node to newNode.
            }
        }


        void insertAtStart(int value) {
            /*
            Insert a value at the start of the linkedlist.
            */

            // Create a new node with the given value and set its next to null.
            Node* newNode = new Node(value);
            newNode->next = NULL;
            head = newNode;
        }


        void insertAtPosition(int value, int position) {
            /* 
            Insert a value at a given position.
            */

            if (position < 1) {
                cout << "Please enter a valid position to insert at." << endl;
                // TODO implement a size() method for the class which returns the length of the linked list. 
                return; 
            }

            // If the given position is the first one, we call the insertAtStart method.
            if (position == 1) {
                insertAtStart(value);
                return;
            }

            Node* newNode = new Node(value);
            newNode->data = value; // Is this line really needed? I dont think so! CHECK!!

            // Traverse to the node before the desired position.
            // Target position is ID'd when the i variable is 1 step before it.
            Node* temp = head; 
            for (int i = 1; i < position - 1 && temp; ++i;) {
                temp = temp->next;
            }

            // Insert the new node at the desired position.
            newNode->next = temp->next;
            temp->next = newNode;
        }
        

        void deleteFromStart() {
            /*
            Delete the first node of the list.
            */

            // If the list is empty, display an error.
            if (!head) {
                cout << "List is empty." << endl;
                return;
            }

            Node* temp = head; // Initialize a pointer at the head node.
            head = head->next; 
            // Set the prior head's next pointer as the new head node.
            // Thus effectively removing the node from the linkedlist.
            delete temp; // Free up the dynamic memory associated with the prior temp pointer. 
        }


        void deleteFromEnd() {
            /*
            Delete the last node of the list.
            */

            // If the list is empty, display an error. 
            if (!head) {
                cout << "List is empty." << endl;
            }

            // If the head is the only node in the list.
            if (!head->next) {
                delete head;
                head = NULL;
                return;
            }

            // If there is more than 1 node in the list, traverse to the 2nd last node.
            Node* temp = head; // Initialize a pointer at the head node.
            while (temp->next->next) { 
                temp = temp->next;
            }

            // Delete the last node.
            delete temp->next;

            // Set the 2nd last node's next to NULL.
            temp->next = NULL;
        } 


        void deleteFromPosition(int position) {
            /*
            Delete a node from a given positoin in the list.
            */

            // If the given position is negative, display an error.
            if (position < 1) {
                cout << "Position should be >= 1." << endl;
                return;
            }

            // If the given position is the first node.
            if (position == 1) {
                deleteFromStart();
                return;
            }

            // Iterate until 1 step before the given position.
            Node* temp = head; // Initialize a pointer at the head node.
            for (int i; i < position - 1 && temp; ++i) {
                temp = temp->next;
            }

            // If the given position is too big.
            if (!temp || !temp->next) {
                cout << "Position out of range." << endl;
                return;
            }

            // Save the node to be deleted.
            Node* nodeToDelete = temp-> next; 

            // Update the next pointer.
            temp->next = temp->next->next;

            // Delete the node.
            delete nodeToDelete;
        }


        void deleteByValue(int value) {
            /* 
            Delete a node by value.
            */

            if (head == nullptr) {
                return;
            }

            if (head->data == value) {
                Node* temp = head; 
                head = head->next; // Move head to the next node.
                delete temp; // Free memory of the deleted node.
                return;
            } 

            Node* temp = head; 
            while (temp->next && temp->next->data != value) {
                temp = temp->next; // Traverse to find the node to delete.
            }

            if (temp->next) {
                Node* nodeToDelete = temp->next;
                // Set the current next pointer to the next pointer of the node we are removing. 
                temp->next = temp->next->next; 
                delete nodeToDelete; // Free memory.
            } 
        }

        
        bool search(int value) {
            /*
            Searches for a given data point in the node. 
            */

            // Initialize curr with the head of linked list.
            Node* curr = head; 

            // Iterate until the tail node, which is NULL.
            while (curr != nullptr) {
                // If the current node's value is equal to key, return True.
                if (curr->data == value) {
                    return true; 
                }
                 
                // Move to the next node.
                curr = curr->next;
            }

            // If there is no node with value as key, return false.
            return false;
        }


        void display() {
            /* 
            Function to display the list.
            */

            if (!head) {
                cout << "List is empty." << endl;
                return;
            }   

            Node* temp = head; 
            while (temp != nullptr) {
                cout << temp->data << "->";
                temp = temp->next;
            }
            cout << "NULL" <<endl;
        }


        ~LinkedList() {
            /* 
            Destructor to free all unused dynamically allocated memory.
            */

            Node* current = head;

            while (current) {
                current = head;
                head = head->next;
                delete current; 
            }
        }
};


int main() { 
    /* 
    Main Function.
    */

    // Initialize an empty LinkedList.
    LinkedList list; 

    list.insertAtEnd(10);
    list.insertAtEnd(20);
    list.insertAtEnd(30);

    cout << "Linked List: " << endl; 
    list.display();

    list.deleteByValue(20);

    cout << "After deleting 20: " << endl;
    list.display();

    cout << "Searching for 30..." << endl; 
    bool x = list.search(30);
    if (x == true) {
        cout << "30 is in the list" << endl;
    } else {
        cout << "30 is not in the list" << endl;
    }


    return 0;
}
    



















