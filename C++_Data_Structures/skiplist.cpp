/* 
A skip list implementation. 

Used to help me learn C++.

Dalice Dieckman 

Date:
    2025-04-25


Sources: 
    https://www.geeksforgeeks.org/skip-list-set-2-insertion/



    TODO add function comments explaining utility of each function

*/


#include <cstring>
#include <ctime>
#include <iostream>
using namespace std;


// Class to implement node
class Node {
    public:
        //// TODOTODO TODO TODO TODO replace all 'key's with data  
        int key;
    
        // Array to hold pointers to node of different level 
        Node** next;
        Node(int, int);
};


Node::Node(int key, int level) {
    this->key = key;
 
    // Allocate memory for an array of node pointers. 
    next = new Node*[level+1];
 
    // Fill the array with 0(NULL)
    // Setting to 0 ensures that all forward pointers are null and point to nothing.
    memset(next, 0, sizeof(Node*)*(level+1));
};
 

// Class for Skip list
class SkipList {
    // Maximum level for this skip list
    int MAXLVL;
 
    // P is the fraction of the nodes with level 
    // i pointers also having level i+1 pointers
    float P;
 
    // current level of skip list
    int level;
 
    // pointer to header node
    Node* header;

    public:
        SkipList(int, float);
        int randomLevel();
        Node* createNode(int, int);
        void insertElement(int);
        void displayList();
};
 

SkipList::SkipList(int MAXLVL, float P) {
    this->MAXLVL = MAXLVL;
    this->P = P;
    level = 0;
 
    // create header node and initialize key to -1
    header = new Node(-1, MAXLVL);
};


// create random level for node
///// TODO TODO TODO TODO --> Try to find another implementation 
///// for the coin flipping technique below 

int SkipList::randomLevel() {
    float r = (float)rand()/RAND_MAX;
    int lvl = 0;
    while (r < P && lvl < MAXLVL) {
        lvl++;
        r = (float)rand()/RAND_MAX;
    }
    return lvl;
};
 

// create new node
Node* SkipList::createNode(int key, int level) {
    Node* n = new Node(key, level);
    return n;
};


// Insert given key in skip list
void SkipList::insertElement(int key) {
    Node* current = header;
 
    // create update array and initialize it
    Node* update[MAXLVL+1];
    memset(update, 0, sizeof(Node*)*(MAXLVL+1));
 
    /*  
        start from highest level of skip list
        move the current pointer forward while key 
        is greater than key of node next to current
        Otherwise inserted current in update and 
        move one level down and continue search
    */
    for (int i = level; i >= 0; i--) {
        while (current->next[i] != NULL &&
              current->next[i]->key < key)
            current = current->next[i];
        update[i] = current;
    }
 
    /* reached level 0 and forward pointer to 
       right, which is desired position to 
       insert key. 
    */
    current = current->next[0];
 
    /* 
        If current is NULL that means we have reached
        to end of the level or current's key is not equal
        to key to insert that means we have to insert
        node between update[0] and current node 
    */
    if (current == NULL || current->key != key) {
        // Generate a random level for node
        int rlevel = randomLevel();
 
        // If random level is greater than list's current
        // level (node with highest level inserted in 
        // list so far), initialize update value with pointer
        // to header for further use
        if (rlevel > level) {
            for (int i=level+1;i<rlevel+1;i++)
                update[i] = header;
 
            // Update the list current level
            level = rlevel;
        }
 
        // create new node with random level generated
        Node* n = createNode(key, rlevel);
 
        // insert node by rearranging pointers 
        for (int i=0;i<=rlevel;i++) {
            n->next[i] = update[i]->next[i];
            update[i]->next[i] = n;
        }

        cout << "Successfully Inserted key " << key << "\n";
    }
};
 

// Display skip list level wise
void SkipList::displayList() {
    cout<<"\n*****Skip List*****"<<"\n";
    for (int i=0;i<=level;i++) {
        Node *node = header->next[i];
        cout << "Level " << i << ": ";
        while (node != NULL) {
            cout << node->key<<" ";
            node = node->next[i];
        }
        cout << "\n";
    }
};
 

// Driver to test above code
int main() {
    // Seed random number generator
    srand((unsigned)time(0));
 
    // create SkipList object with MAXLVL and P 
    SkipList lst(3, 0.5);
 
    lst.insertElement(3);
    lst.insertElement(6);
    lst.insertElement(7);
    lst.insertElement(9);
    lst.insertElement(12);
    lst.insertElement(19);
    lst.insertElement(17);
    lst.insertElement(26);
    lst.insertElement(21);
    lst.insertElement(25);
    lst.displayList();

    return 0;
}