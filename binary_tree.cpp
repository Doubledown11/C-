/*
A Binary Tree Implementation in C++.


TODO:   
    Need a function which rearranges the nodes in the tree so it is balanced.


Sources:
    https://www.geeksforgeeks.org/binary-tree-in-cpp/

*/
#include <iostream>
#include <queue>
#include <functional>

using namespace std;


class Node {
    /*
    A class for a node in the binary tree.
    */
    
    public: 
        int data;
        Node* left;
        Node* right; 


        Node(int data) {
            /*
            Constructor used to build a node in the Binary Tree structure.
            */


            this->data = data;
            /*
            I have to use the this-> pointer to assign the value of data to the data attribute.
            It is used to clarify that we are accessing member variables of functions within the object itself.
            */
            
            
            /* 
            
            
            NOTE: I MIGHT HAVE TO USE this-> before left & right attribute assignments as I did with the data attribute. 
            
            
            */
            left = nullptr;
            right = nullptr;
        } 
};


class Tree {
    /*
    A class for the binary tree itself. 
    */

    private:
        Node* root;
        int size;


        Node* removeRecursive(Node* current, int data) {
            /*
            Used to remove a node from the binary tree, using a given data point.    
            */
        
            if (current == nullptr) {
                return nullptr;
            }

            // If the current node has the target data point.
            if (current->data == data) {
                // current node is a leaf node.
                if (current->left == nullptr && current->right == nullptr) {
                    delete current;
                    return nullptr;
                } 

                // If the current node has a right sided child.
                if (current->left == nullptr) {
                    Node* temp = current->right;
                    delete current;
                    return temp;
                }

                // If the current node has a left sided child.
                if (current->right == nullptr) {
                    Node* temp = current->left;
                    delete current;
                    return temp;
                }

                
                Node* successor = findMin(current->right);
                current->data = successor->data;
                current->right = removeRecursive(current->right, successor->data);
            }

            else {
                current->left = removeRecursive(current->left, data);
                current->right = removeRecursive(current->right, data);
            }

            return current;
        }
    


    public:

        Tree() {
            /*
            A constructor used to initialize the tree.    
            */
            
            root = nullptr;
            size = 0;
        }



        void remove(int data) {
            /*
            Calls the recursive remove function to remove a node from the tree.    
            */
            
            root = removeRecursive(root, data);
        }


        Node* findMin(Node* node) {
            /*
            Returns a pointer to the node with the smallest value in a given subtree.
            */

            while (node->left != nullptr) {
                node = node->left;
                return node;
            }
        }


        bool search(Node* current, int data) {
            /*
            Searches the tree for a given data point, returns true if found, false if not found.
            */
            
            if (current == nullptr) {
                return false;
            }

            if (current->data == data) {
                return true;
            }

            return search(current->left, data) || search(current->right, data);
        }


        void inorderTraversal(Node* current) {
            /*
            Displays the values of the nodes in the tree from an inorder traversal.
            */
            
            cout << current->data << "Current data inside of inorder." << endl;
            cout << current->left->data << "Current left data inside of inorder" << endl;
            cout << current->right->data << "Current right data inside of inorder" << endl;

            if (current != nullptr) {
                inorderTraversal(current->left);
                cout << current->data << " ";
                inorderTraversal(current->right);
            }
        }


        void preorderTraversal(Node* current) {
            /*
            Displays the values of the nodes in the tree from an preorder traversal.
            */
        
            if (current != nullptr) {
                cout << current->data << " ";
                preorderTraversal(current->left);
                preorderTraversal(current->right);
            }
        }

        
        void postorderTraversal(Node* current) {
            /*
            Displays the values of the nodes in the tree from an postorder traversal.
            */
        
            if (current != nullptr) {
                postorderTraversal(current->left);
                postorderTraversal(current->right);
                cout << current->data << " ";
            }

        }


        void levelorderTraversal(Node* current) {
            /* 
            Displats the values of the nodes in the tee from a levelorder traversal.
            */
        
            if (root == nullptr) {
                return;
            }

            queue<Node*> q;
            q.push(root);

            while (q.empty() == false) {
                Node* current = q.front();
                q.pop();

                cout << current->data << " ";

                if (current->left != nullptr) {
                    q.push(current->left);
                }

                if (current->right != nullptr) {
                    q.push(current->right);
                }
            } 
            cout << endl;
        }


        void add(int data) {
            /*
            A binary tree implementation that uses a nested recursive function to add a node to the tree.    
            */
            
            function<void(int, Node*)> add_recursive = [&](int data, Node* current) {
                /*
                A nested function used to add a node to the tree using a recursive method.
                */
                
                cout << "data in add_recursive " << data << endl;
                cout << "Current->data in add_recursive " << current->data << endl;

                cout << "Current->right in add_recursive " << current->right << endl;
                cout << "Current->left in add_recursive " << current->left << endl;

                

                if (data < current->data) {
                    if (current->left) {
                        current = current->left;
                        return add_recursive(data, current);
                    }

                    else {
                        current->left = new Node(data);
                        size++;
                        return;
                    }
                }

                else if (data > current->data) {
                    if (current->right) {
                        current = current->right;
                        return add_recursive(data, current);
                    }

                    else {
                        cout << "No current->right thus called here. " << endl;
                        current->right = new Node(data);
                        cout << "after adding new val current->right->data " << current->right->data << endl; 
                        size++;
                        return;
                    }
                }

                else if (current->data == data) {
                    cout << "Error: Cannot add duplicate data. " << current->data << " already exists in the given binary tree instance." << endl;
                    return;
                }

            };


            if (root == nullptr) {
                cout << "Root null check hit!" << endl;
                root = new Node(data);
                size++;
            }

            else {
                cout << "Root has been added past root null check in add() " << endl;
                Node* current = root;
                return add_recursive(data, current);
            }
        }





        void insertNode(int data) {
            /*
            Creates a new node in the tree with a given data point as its value.
            */
            
            Node* newNode = new Node(data);

            // If there is no root in the tree.
            if (root == nullptr) {
                root = newNode;
            }

            else {
                Node* current = root;

                // Iterate through tree until we reach the home of our new node.
                while (true) {
                    // Try to search left side first, if data is smaller than the data at 
                    // the current node we try to insert it in the left child node of the current node.
                    if (data < current->data) {
                        // If there already exists a left subchild we iterate to there and start the process again!
                        if (current->left != nullptr) {
                            current = current->left;
                        }

                        // If there is no left subchild, this is where the new node will live.
                        else {
                            current->left = new Node(data);
                            size++;
                            break;
                        }
                    }

                    // If it is bigger than the current nodes data, we try to insert it at the right subchild.
                    else if (data > current->data) {
                        if (current->right) {
                            current = current->right;
                        }

                        else {
                            current->right = new Node(data);
                            size++;
                            break;
                        }
                    }

                    // If it is equal to the current nodes data, we print an error and break.
                    else if (data == current->data) {
                        cout << "Error: Cannot add duplicate data. " << current->data << " already exists in the given binary tree instance." << endl;
                        break;
                    }
                }
            }

            // Initialize a queue to hold the value of the nodes which need to be re-arranged
            // after inserting the new node in the tree.
            queue<Node*> q;
            q.push(root);

            // Iterate through tree until we reach the home of our new node.
            while (q.empty() == false) {
                // We create a node pointer to the node which is at the front of the queue.
                Node* current = q.front();
                // We then remove this node from the queue.
                q.pop();

                // Now we iterate until we reach the newNodes home.
                if (current->left == nullptr) {
                    current->left = newNode;
                    return;
                } else {
                    q.push(current->left);
                }


                if (current->right == nullptr) {
                    current->right = newNode;
                    return;
                } else {
                    q.push(current->right);
                }
            }
        }

        Node* getRoot() {
            /*
            Returns a pointer to the root node from the private context.
            */
            
            return root;
        }
};


int main() {
    /*
    Main Function.
    */

    Tree bin_tree;

    cout << "Couting a nullptr " << 'nullptr' << endl;
 
    bin_tree.add(1);
    bin_tree.add(2);
    bin_tree.add(3);
    bin_tree.add(4);
    bin_tree.add(5);
    bin_tree.add(6);

    Node* root = bin_tree.getRoot();

    cout << "Data at root in main: " << root->data << endl;

    Node* root1 = bin_tree.getRoot();
    // cout << "data at root l child " << root1->left->data << endl;
    cout << "Data at root r child " << root1->right->data << endl;


    /*
    My current bug:
        Since my values are being added in with an ascending order, they keep being placed in the right child position.
        So whenever a current->left->data is called it results in a segmentation fault, 
            and current->left always returns 0 for false. 
    */


    cout << root->data << " Is the val at root;" << endl;


    cout << "Inorder traversal: ";
    bin_tree.inorderTraversal(root);

    cout << "Preorder traversal: ";
    bin_tree.preorderTraversal(root);

    cout << "Postorder traversal: ";
    bin_tree.postorderTraversal(root);

    cout << "Levelorder Traversal: ";
    bin_tree.levelorderTraversal(root);

    
    bin_tree.remove(3);
    cout << "Inorder traversal after removing 3: ";
    bin_tree.inorderTraversal(root);

    return 0;
}