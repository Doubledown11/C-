/*

A Red-Black Tree Implementation.

Uses a set properties to ensure the tree is in proper form: 
    Root is always black.
    Red nodes can't have red kids.
    Every path from root to lead has the same number of black nodes.
    All leafs (AKA NIL Nodes) are black.
    Longest path cannot be more than 2X the length of the shortest path from root to leaf.
     

Sources:
    https://www.geeksforgeeks.org/introduction-to-red-black-tree/#implementation-of-redblack-tree
    https://www.geeksforgeeks.org/deletion-in-red-black-tree/
    https://www.eecs.umich.edu/courses/eecs380/ALG/niemann/s_rbt.htm#:~:text=A%20red%2Dblack%20tree%20is,both%20its%20children%20are%20black.
    https://brilliant.org/wiki/red-black-tree/
    Also used the google AI through a search result to help determine the cases of tree height 1 and 0.  
    https://www.cs.usfca.edu/~galles/visualization/RedBlack.html
        ABOVE IS A GREAT RED BLACK TREE VISUALIZATION TOOL.
    https://www.programiz.com/cpp-programming/library-function/cmath/log2
    https://www.geeksforgeeks.org/deletion-in-red-black-tree/
    https://www.geeksforgeeks.org/inorder-successor-in-binary-search-tree/
    https://stackoverflow.com/questions/7100889/how-can-i-access-local-variables-from-inside-a-c11-anonymous-function
    https://stackoverflow.com/questions/4324763/can-we-have-functions-inside-functions-in-c
*/


#include <iostream>
#include <vector>
#include <cmath>
#include <functional>
using namespace std;


struct Node {
    /*
    Struct for a Node in the Red-Black Tree.
    */

    int data;
    string color;
    Node *left, *right, *parent;

    // Change format of below code
    Node(int data)
        : data(data)
        , color("RED")
        , left(nullptr)
        , right(nullptr)
        , parent(nullptr)
    {
    }
};


class RedBlackTree {
    /*
    The class for the Red-Black Tree.
    */

    private:
        Node* root;
        Node* NIL;
        int num_nodes;
        int* rbt_vector_pointer;

    public:
        RedBlackTree() {
            /*
            A constructor function for the RedBlackTree class.
            */

            NIL = new Node(0);
            NIL->color = "BLACK";
            NIL->left = NIL->right = NIL;
            root = NIL;
            vector<int> rbt_vector;
            num_nodes = 0;
        }


        void swap(Node* node1, Node* node2) {
            /*
            Swaps the positions of 2 nodes in a tree.
            */

            int temp;
            temp = node1->data;
            node1->data = node2->data;
            node2->data = temp;
        }


        void leftRotate(Node* x) {
            /*
            Performs a left rotation.    
            */

            Node* y = x->right;
            x->right = y->left;
            if (y->left != NIL) {
                y->left->parent = x;
            }
            y->parent = x->parent;
            if (x->parent == nullptr) {
                root = y;
            }
            else if (x == x->parent->left) {
                x->parent->left = y;
            }
            else {
                x->parent->right = y;
            }
            y->left = x;
            x->parent = y;
        }

        
        void rightRotate(Node* x) {
            /*
            Performs a right rotation.    
            */

            Node* y = x->left;
            x->left = y->right;
            if (y->right != NIL) {
                y->right->parent = x;
            }
            y->parent = x->parent;
            if (x->parent == nullptr) {
                root = y;
            }
            else if (x == x->parent->right) {
                x->parent->right = y;
            }
            else {
                x->parent->left = y;
            }
            y->right = x;
            x->parent = y;
        }

        
        void fixInsert(Node* k) {
            /*
            Function to fix anyb discrepencies with the Red-Black 
            Tree properties after insertion.
            */

            while (k != root && k->parent->color == "RED") {
                if (k->parent == k->parent->parent->left) {
                    Node* u = k->parent->parent->right; // uncle
                    if (u->color == "RED") {
                        k->parent->color = "BLACK";
                        u->color = "BLACK";
                        k->parent->parent->color = "RED";
                        k = k->parent->parent;
                    }
                    else {
                        if (k == k->parent->right) {
                            k = k->parent;
                            leftRotate(k);
                        }
                        k->parent->color = "BLACK";
                        k->parent->parent->color = "RED";
                        rightRotate(k->parent->parent);
                    }
                }
                else {
                    Node* u = k->parent->parent->left; // uncle
                    if (u->color == "RED") {
                        k->parent->color = "BLACK";
                        u->color = "BLACK";
                        k->parent->parent->color = "RED";
                        k = k->parent->parent;
                    }
                    else {
                        if (k == k->parent->left) {
                            k = k->parent;
                            rightRotate(k);
                        }
                        k->parent->color = "BLACK";
                        k->parent->parent->color = "RED";
                        leftRotate(k->parent->parent);
                    }
                }
            }
            root->color = "BLACK";
        }

        
        void inorder(Node* node) {
            /*
            Performs an Inorder traversal.    

            TODO: Change max and min heap display functions to use a recursive method.
            I prefer how this displays the node data horizontally rather than in many lines of output.
            */

            if (node != NIL) {
                inorder(node->left);
                cout << node->data << " ";
                inorder(node->right);
            } 
        }

        Node* inorder_successor(Node* node) {
            /*
            Performs an Inorder traversal.    

            TODO: Change max and min heap display functions to use a recursive method.
            I prefer how this displays the node data horizontally rather than in many lines of output.
            
            Also try implementing another method to find the next value in the inorder traversal later. 
            Iterate through the tree and if 
            use a new inorder


            Notes on the nested function  ADD TO C++ GOOGLE DOCS: 
                We use C++ lambdas to work with nested functions.
                lambdas act as a local function that can be nested inside of another function.

                we can inherit variables (in this case a vector) declared in the outer scope by using 
                    for a specific value [x]
                    reference [&x]
                    any var in the outer scope currently [&]
                    by value [=]
            */

            vector<Node*> inorder_trav;

            function<void(Node*)> inorder_helper = [&](Node* node) {
                if (node != NIL) {
                    inorder_helper(node->left);                    
                    inorder_trav.push_back(node);
                    inorder_helper(node->right);
                }
            };
            inorder_helper(node);
            cout << inorder_trav[1]->data << " is the val at idx 2 in list, and it should be 15" << endl;
            
            // Now take 2nd value in the vector as the successor and return it to remove(). 
            return inorder_trav[1];
        }


        // Node* inorder_successor_2(Node* node, int 0, int prior_data) {
        //     /*
        //     Method 2 to find the inorder successor. 
        //     If we find the data of the prior node, we change the val of 0 to 1 then 
        //     we return the next node in the traversal.
        //     */

        //     if (node != NIL) {
        //         inorder(node->left);
        //         cout << node->data << " ";
        //         inorder(node->right);
        //     } 

        // }


        void insert(int data) {
            /*
            A function used to insert a data point into the tree as a node.    
            */

            Node* new_node = new Node(data);
            new_node->left = NIL;
            new_node->right = NIL;

            Node* parent = nullptr;
            Node* current = root;
            num_nodes++;


            // BST insert
            while (current != NIL) {
                parent = current;
                if (new_node->data < current->data) {
                    current = current->left;
                }
                else {
                    current = current->right;
                }
            }

            new_node->parent = parent;

            if (parent == nullptr) {
                root = new_node;
            }
            else if (new_node->data < parent->data) {
                parent->left = new_node;
            }
            else {
                parent->right = new_node;
            }

            if (new_node->parent == nullptr) {
                new_node->color = "BLACK";
                return;
            }

            if (new_node->parent->parent == nullptr) {
                return;
            }

            fixInsert(new_node);
        }

        
        void remove(int data) {
            /*
            Used to remove a node from the tree using a given data point.
        
        
            TODO use link: 
            https://www.geeksforgeeks.org/deletion-in-red-black-tree/ 
                USE THE SOLUTION HERE FOR THE DELETE FUNCTION.
            
            
            */


        

            // Find the node to delete from the tree by getting its pointer from the search function. 
            Node* node_to_delete;
            Node* root = getRoot();
            cout << " root data in remove " << root->data << endl;
            cout << data << " is the data we wish to remove" << endl;
            node_to_delete = search(root, data);
            cout << node_to_delete->data << " is the data of the node we wish to delete" << endl;            

            // If there is no left child.
            if (node_to_delete->left == NIL) {
                // If there is also no right child.
                if (node_to_delete->right == NIL) {
                    // Remove node by updating the parents appropriate pointer.
                    // node_to_delete->parent


                } 
                // If there is no left, but a right child
                else if (node_to_delete->right != NIL) {
                    node_to_delete->data = node_to_delete->right->data;
                    node_to_delete->right = NIL;
                }
            } 

            // If there is a left child.
            else if (node_to_delete->left != NIL) {
                // If there is also a right child.
                if (node_to_delete->right != NIL) {
                    // In this case we replace the node with its inorder successor.
                    // Which is the leftmost node in the right subtree.
                    
                    cout << "Below is the inorder traversal before the swap has been made" << endl;
                    inorder(root);
                    cout << "\n";

                    // Search for next inorder value.
                    Node* successor;
                    successor = inorder_successor(node_to_delete);

                    swap(node_to_delete, successor);
                    cout << "Below is the inorder traversal after then swap has been made." << endl;
                    inorder(root);
                    cout << "\n";

                    // Replace the prior node with a NIL node.
                    cout << node_to_delete->data << " the node to deletes data." << endl;
                    cout << successor->data << " the successors data." << endl;

                    cout << successor->parent->left->data << " left child of parents data" << endl;
                    cout << successor->parent->right->data << " right child of parents data" << endl;
                    
                    

                    // Have to ID which side the successor node (which is now holding the data to be removed) 
                    // is on relative to its parent node. (Left or Right)
                    if (successor->parent->left->data == successor->data) {
                        successor->parent->left == NIL;
                    } else if (successor->parent->right->data == successor->data) {
                        successor->parent->right == NIL;
                    }
                    
                    cout << successor->parent->right->data << " prior right child of parent data" << endl;
                    

                    cout << node_to_delete->left->data << " node on left data after removal" << endl;
                    cout << node_to_delete->right->data << " node on right data after removal" << endl;
                    return;

                }

                // If there is a left child but no right child.
                else if (node_to_delete->left == NIL) {
                    node_to_delete->data = node_to_delete->left->data;
                    node_to_delete->left = NIL;
                }
            }


            // check for parent




            // Remove value and assign pointers

            // reorganize red black tree


        }
        

        Node* search(Node* node, int data) {
            /*
            Searches for a given data point in the tree.     

            Does so recursively.
            */

            // Base Case: Reach leaf (NIL Node) or we find a node with the given data point.
            if (node == NIL || data == node->data) {
                return node;
            }
            if (data < node->data) {
                // We search the left subtree if target data is smaller than current data.
                return search(node->left, data);
            }
            // We search the right subtree if target data is greater than current data.
            return search(node->right, data);
        }


        int getNumNodes() {
            /*
            Getter function which returns the number of nodes in the tree, 
            from the private scope.
            */

            return num_nodes;
        }


        int getHeight() {
            /*
            Returns the height of the tree.
            
            Red-black trees have a max height of 2*log2(n+1).

            Returns the max height of the tree. 
            */

            int node_count = getNumNodes();

            cout << node_count << " is node count in getHeight" << endl;
            
            // If empty
            if (node_count == 0) {
                cout << "The tree is empty." << endl;
                return 0;
            } else if (node_count == 1) {
                cout << "The tree has only 1 node and thus the height is 1." << endl;
                return 1;
            } else {
                // int height <= 2 * (log2(n+1));
                int height = 2 * (log2(node_count+1));
                cout << "The max height of the tree is: " << height << endl; 
                return height;
            }
        }


        Node* getRoot() {
            /* 
            Returns a node pointer to the root node.
            */

            Node* root_node = root; 
            return root_node;
        }
};


int main() {
    /*
    Main Function.
    */

    RedBlackTree rbt;

    // Inserting elements
    rbt.insert(10);
    rbt.insert(20);
    rbt.insert(30);
    rbt.insert(15);

    // Accessing root node for the getHeight function, and displaying it's data.
    Node* root_node = rbt.getRoot();
    cout << root_node->data << " is the root node\'s data!" << endl; 

    // Check height.
    rbt.getHeight();

    // Inorder traversal to display the tree b4 changes.
    cout << "Inorder traversal:" << endl;
    
    // Need to pass root node pointer to inorder function
    rbt.inorder(root_node); // Output: 10 15 20 30
    cout << "\n\n";

    // Get root for the search functions below.
    Node* root2 = rbt.getRoot();
    int root2_data = root2->data;


    Node* search_res = rbt.search(root2, root2_data);
    int search_val1 = 15;
    int search_val2 = 25;

    // Searching for data.
    if (rbt.search(root2, search_val1) == rbt.search(root2, 0)) {
        cout << "The value of " << search_val1 << " was not found within the given tree instance." << endl; 
    } else {
        cout << "The value of " << search_val1 << " was found within the given tree instance." << endl;
    }
    
    
    if (rbt.search(root2, search_val2) == rbt.search(root2, 0)) {
        cout << "The value of " << search_val2 << " was not found within the given tree instance." << endl; 
    } else {
        cout << "The value of " << search_val2 << " was found within the given tree instance." << endl;
    }

    
    rbt.remove(20);
    Node* root3 = rbt.getRoot();
    cout << "Inorder traversal after removal of prior root below." << endl;
    rbt.inorder(root3);
    cout << "\n\n";
    
    
    return 0;
}