/* 

A Binary Trie Implementation. 

Sources: 
    https://www.geeksforgeeks.org/trie-insert-and-search/
    https://www.geeksforgeeks.org/trie-delete/
    https://www.geeksforgeeks.org/trie-display-content/ 
*/


#include <iostream>
#include <cstring>

#define alpha_size 26
#define ARRAY_SIZE(a) sizeof(a) / sizeof(a[0])
// ARRAY_SIZE calculates the number of existing slots in this array.
//We could have just counted a subtotal for each node, and save the grand total at the root node. 
// TODO


using namespace std;



class TrieNode {
    /*
    A class for a node in the Trie.
    */

    public:
    
        // pointer array for child nodes of each node
        TrieNode* children[26];
    
        // Used for indicating ending of string
        bool isLeaf;
    
        TrieNode() {
            /*
            A constructor function that builds a node in the Trie structure.
            */
          
            // initialize the wordEnd variable with false
            // initialize every index of childNode array with NULL
            isLeaf = false;
            for (int i = 0; i < 26; i++) {
                children[i] = nullptr;
            }
        }
};


class BinaryTrie {
    /* 
    A class for the BinaryTrie.
    */
    
    public: 
        void insert(TrieNode*, const string& key);
        bool search(TrieNode* root, const string& key);
        bool isPrefix(TrieNode *root, string &key);
        bool isEmpty(TrieNode* root);
        TrieNode* isPrefix(TrieNode *root, string &key);
        bool isLeafNode(struct TrieNode* root);
        void display(struct TrieNode* root, char str[], int level);   
}


BinaryTrie::insert(TrieNode* root, const string& key) {
    /* 
    Insert Function for the Binary Trie.


    
    change TrieNode arg to Node later!!! TODO 
    Change key args in all data structs to data
    */
    

    // Initialize the curr pointer with the root node
    TrieNode* curr = root;

    // Iterate across the length of the string
    for (char c : key) {
      
        // Check if the node exists for the 
        // current character in the Trie
        if (curr->children[c - 'a'] == nullptr) {
          
            // If node for current character does 
            // not exist then make a new node
            TrieNode* newNode = new TrieNode();
          
            // Keep the reference for the newly
            // created node
            curr->children[c - 'a'] = newNode;
        }
      
        // Move the curr pointer to the
        // newly created node
        curr = curr->children[c - 'a'];
    }

    // Mark the end of the word
    curr->isLeaf = true;
}


BinaryTrie::search(TrieNode* root, const string& key) {
    /* 
    Searches for a key in the Trie structure.    
    */

    // Initialize the curr pointer with the root node
    TrieNode* curr = root;

    // Iterate across the length of the string
    for (char c : key) {
      
        // Check if the node exists for the 
        // current character in the Trie
        if (curr->children[c - 'a'] == nullptr) 
            return false;
        
        // Move the curr pointer to the 
        // already existing node for the 
        // current character
        curr = curr->children[c - 'a'];
    }

    // Return true if the word exists 
    // and is marked as ending
    return curr->isLeaf;
}


BinaryTrie::isPrefix(TrieNode *root, string &key) {
    /*
    Searches for a prefix data point in Trie structure.    
    */
    
    TrieNode *current = root;
    for (char c : key)
    {
        int index = c - 'a';

        // If character doesn't exist, return false
        if (current->children[index] == nullptr)
        {
            return false;
        }
        current = current->children[index];
    }

    return true;
}


BinaryTrie::isEmpty(TrieNode* root) {
    /*
    Returns true if root has no children, else returns false.    
    */

    for (int i = 0; i < ALPHABET_SIZE; i++)
        if (root->children[i])
            return false;
    return true;
}


BinaryTrie::remove(TrieNode* root, string key, int depth = 0) {
    /*
    A function to delete a key from given Trie.    
    */

    // If tree is empty
    if (!root)
        return NULL;
 
    // If last character of key is being processed
    if (depth == key.size()) {
 
        // This node is no more end of word after
        // removal of given key
        if (root->isEndOfWord)
            root->isEndOfWord = false;
 
        // If given is not prefix of any other word
        if (isEmpty(root)) {
            delete (root);
            root = NULL;
        }
 
        return root;
    }
 
    // If not last character, recur for the child
    // obtained using ASCII value
    int index = key[depth] - 'a';
    root->children[index] = 
          remove(root->children[index], key, depth + 1);
 
    // If root does not have any child (its only child got 
    // deleted), and it is not end of another word.
    if (isEmpty(root) && root->isEndOfWord == false) {
        delete (root);
        root = NULL;
    }
 
    return root;
}


// How do I implement this in out of class format? 
// Is there a need to change anything? 
// Seems to be an embedded struct/class inside the BinaryTrie class.
struct TrieNode* getNode(void) {
    /*
    Get's a node from the Trie structure.  
    */

    struct TrieNode* pNode = new TrieNode;
 
    pNode->isEndOfWord = false;
 
    for (int i = 0; i < ALPHABET_SIZE; i++)
        pNode->children[i] = NULL;
 
    return pNode;
}



BinaryTrie::isLeafNode(TrieNode* root) {
    /*
    Function to check if current node is a leaf node or not.    
    */
    
    return root->isLeaf != false;
}
 

BinaryTrie::display(TrieNode* root, char str[], int level) {
    /* 
    This algorithm displays the contents of the tree in Alphabetical order.
    */

    // If node is leaf node, it indicates end
    // of string, so a null character is added
    // and string is displayed
    if (isLeafNode(root)) 
    {
        str[level] = '\0';
        cout << str << endl;
    }
 
    int i;
    for (i = 0; i < alpha_size; i++) 
    {
        // if NON NULL child is found
        // add parent key to str and
        // call the display function recursively
        // for child node
        if (root->children[i]) 
        {
            str[level] = i + 'a';
            display(root->children[i], str, level + 1);
        }
    }
}


int main() {
    /*
    Main Function.
    */

    // Create am example Trie
    TrieNode *root = new TrieNode();
    vector<string> arr = {"and", "ant", "do", "dad"};
    for (const string &s : arr)
    {
        insert(root, s);
    }

    // One by one search strings
    vector<string> searchKeys = {"do", "gee", "bat"};
    for (string &s : searchKeys){
        
        if(search(root, s))
            cout << "true ";
        else
            cout << "false ";
    } 
    cout<<"\n";

    // One by one search for prefixes
    vector<string> prefixKeys = {"ge", "ba", "do", "de"};
    for (string &s : prefixKeys){
        
        if (isPrefix(root, s))
            cout << "true ";
        else
            cout << "false ";
    }

    return 0;
}