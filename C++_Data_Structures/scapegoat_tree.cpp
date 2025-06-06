/* 
A Scapegoat Tree implementation.

Used to help me learn C++.

Dalice Dieckman 

Date:
    2025-04-25

Sources:
    https://www.geeksforgeeks.org/scapegoat-tree-set-1-introduction-insertion/
    https://www.geeksforgeeks.org/deletion-in-binary-search-tree/

    TODO add function comments explaining utility of each function

*/

#include <iostream>
#include <cmath>
using namespace std; 
  

static int const log32(int n) { 
    /*
    Returns the value of log32(n). 
    */

    double const log23 = 2.4663034623764317; 
    return (int)ceil(log23 * log(n)); 
} 
  

class Node { 
  /* 
  A class for the Node in the tree.
  */


  public: 
      Node *left, *right, *parent; 
      float data; 
      Node() { 
          data = 0; 
          left = right = parent = NULL; 
      } 

      Node (float v) { 
          data = v; 
          left = right = parent = NULL; 
      } 
}; 
 

int storeInArray(Node *ptr, Node *arr[], int i) { 
  /* 
  Stores the inorder traversal of a tree rooted with ptr in an arr[]
  */

  if (ptr == NULL) 
    return i; 
  
  i = storeInArray(ptr->left, arr, i); 
  arr[i++] = ptr; 
  return storeInArray(ptr->right, arr, i); 
} 
  
 
class SGTree { 
  /*
  Class for the ScapeGoat Tree.
  */
  
    private: 
        Node *root; 
        int n; // Number of nodes in Tree 
    
    public: 
        void preorder(Node *); 
        int size(Node *); 
        bool insert(float x); 
        void rebuildTree(Node *u); 
        Node* remove(Node* root, float y);
        void preorder() { preorder(root); } 
        
        // Function to built tree with balanced nodes 
        Node *buildBalancedFromArray(Node **a, int i, int n); 
        
        // Height at which element is to be added 
        int BSTInsertAndFindDepth(Node *u); 

        // Getter function which allows me to retrieve the root node value
        // from outside of the private scope.
        SGTree() : root(nullptr), n(0) {}; 
        Node* getRoot() {return root;}
}; 
  

void SGTree::preorder(Node *node) { 
  /*
  Preorder traversal of the tree.
  */
  
  if (node != NULL) { 
    cout << node->data << " "; 
    preorder(node -> left); 
    preorder(node -> right); 
  } 
} 
  
 
int SGTree::size(Node *node) { 
  /*
  Counts the number of nodes in the tree.
  Does so recursively.
  */
 
  if (node == NULL) 
    return 0; 
  return 1 + size(node->left) + size(node->right); 
} 
  
 
bool SGTree::insert(float x) { 
  /*
  Inserts a new element in the tree.  
  */

  // Create a new node 
  Node *node = new Node(x); 
  
  // Perform BST insertion and find depth of 
  // the inserted node. 
  int h = BSTInsertAndFindDepth(node); 
  
  // If tree becomes unbalanced 
  if (h > log32(n)) { 
    // Find Scapegoat 
    Node *p = node->parent; 
    while (3*size(p) <= 2*size(p->parent)) 
      p = p->parent; 
  
    // Rebuild tree rooted under scapegoat 
    rebuildTree(p->parent); 
  } 
  
  return h >= 0; 
} 
  

Node* getNext(Node* current) {
    /* 
    Gets the next node in the tree.
    */
    
    current = current->right;

    while (current != nullptr && current->left != nullptr) {
        current = current->left;
    }

    return current;
}


Node* SGTree::remove(Node* root,float y) {
    /*
    
    
    TODO: Fix remove function!
    Currently I am removing more than just the target
    */
    
    
    // Base Case: If we reach the bottom of tree and encounter a nullptr
    if (root == nullptr) {
        return root;
    } 

    // If key to be searched is in a subtree
    if (root->data > y) {
        root->left = remove(root->left, y);
    } else if (root->data < y) {
        root->right = remove(root->left, y);
    } else { // If root matches with the given key 
        // Cases when root has 0 children, or only right child.
        if (root->left == nullptr) {
            Node* current = root->right;
            delete root;
            return current;
        }

        // Case when root has only left child
        if (root->right == nullptr) {
            Node* current = root->left;
            delete root;
            return current;
        }


        // Case when both children are present -- 
        Node* next = getNext(root);
        root->data = next->data;
        root->right = remove(root->right, next->data);
    }

}

 
void SGTree::rebuildTree(Node *u) { 
  /*
  Function to rebuilt tree from new node.

  Uses storeInArray() to 
  first store inorder traversal of BST rooted 
  with u in an array. 
  Then it converts array to the most possible 
  balanced BST using buildBalancedFromArray()

  */

  int n = size(u); 
  Node *p = u->parent; 
  Node **a = new Node* [n]; 
  storeInArray(u, a, 0); 
  if (p == NULL) { 
    root = buildBalancedFromArray(a, 0, n); 
    root->parent = NULL; 
  } else if (p->right == u) { 
    p->right = buildBalancedFromArray(a, 0, n); 
    p->right->parent = p; 
  } else { 
    p->left = buildBalancedFromArray(a, 0, n); 
    p->left->parent = p; 
  } 
} 
  
 
Node * SGTree::buildBalancedFromArray(Node **a, int i, int n) { 
  /*
  Builds a tree with balanced nodes.  
  */

  if (n== 0) 
    return NULL; 
  int m = n / 2; 
  
  // Now a[m] becomes the root of the new 
  // subtree a[0],.....,a[m-1] 
  a[i+m]->left = buildBalancedFromArray(a, i, m); 
  
  // elements a[0],...a[m-1] gets stored 
  // in the left subtree 
  if (a[i+m]->left != NULL) 
    a[i+m]->left->parent = a[i+m]; 
  
  // elements a[m+1],....a[n-1] gets stored 
  // in the right subtree 
  a[i+m]->right = 
    buildBalancedFromArray(a, i+m+1, n-m-1); 

  if (a[i+m]->right != NULL) 
    a[i+m]->right->parent = a[i+m]; 
  
  return a[i+m]; 
} 
  
 
int SGTree::BSTInsertAndFindDepth(Node *u) {
  /*
  Performs standard BST insert and returns depth of the inserted node.  
  */
  
  // If tree is empty 
  Node *w = root; 
  if (w == NULL) { 
    root = u; 
    n++; 
    return 0; 
  } 
  
  // While the node is not inserted 
  // or a node with same key exists. 
  bool done = false; 
  int d = 0; 
  do { 
    if (u->data < w->data) { 
      if (w->left == NULL) { 
        w->left = u; 
        u->parent = w; 
        done = true; 
      } else {
        w = w->left;
        }
    } else if (u->data > w->data) { 
      if (w->right == NULL) { 
        w->right = u; 
        u->parent = w; 
        done = true; 
      } else {
        w = w->right; 
      }
    } else {
      return -1;
    }
    d++; 
  } 
  while (!done); 
  
  n++; 
  return d; 
} 


Node* search(Node* root, int new_value) {
  /*
  Searches for a node with a given data point in the tree.  
  */

  
    // Base Cases: root is null or key 
    // is present at root
    if (root == NULL || root->data == new_value) {
        return root;
    }

    // Key is greater than root's key
    if (root->data < new_value)
        return search(root->right, new_value);

    // Key is smaller than root's key
    return search(root->left, new_value);
}

 
int main() { 
  /*
  Main Function.
  */

    SGTree sgt; 
    sgt.insert(7); 
    sgt.insert(6); 
    sgt.insert(3); 
    sgt.insert(1); 
    sgt.insert(0); 
    sgt.insert(8); 
    sgt.insert(9); 
    sgt.insert(4); 
    sgt.insert(5); 
    sgt.insert(2); 
    sgt.insert(3.5); 

    printf("Preorder traversal of the"
        " constructed ScapeGoat tree is \n"); 
    sgt.preorder(); 


    // Initialize a pointer to the root node as the search function is recursive.
    // We can access the root node of the tree using the getRoot() getter function.
    Node* root = sgt.getRoot();

    (search(root, 5) != NULL)? cout << "\nFound: " << 5 << endl: 
                               cout << "\nNot Found: " << 5 << endl;

  
    (search(root, 80) != NULL)? cout << "Found: " << 80 << endl: 
                               cout << "Not Found: " << 80 << endl;


    sgt.remove(root, 5);
    printf("Preorder traversal of the constructed ScapeGoat tree after removal of value 5 is \n"); 
    sgt.preorder(); 

    return 0; 
} 