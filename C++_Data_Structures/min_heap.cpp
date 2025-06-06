/* 

An implementation of the min heap data structure.

<climits> provides some useful tooling for the defining of limits 
of fundamental integral types.


Sources: 
    https://www.geeksforgeeks.org/binary-heap/
    https://courses.csail.mit.edu/6.006/fall10/handouts/recitation10-8.pdf
*/

#include <iostream>
#include <climits>

using namespace std;

// Prototype of a utility function to swap two integers
// Allows for methods inside the MinHeap class to use the 
// swap class, as the swap class is located under the class definition.
void swap(int *x, int *y);


class MinHeap {
    /*
    A class for Min Heap.    
    */

    int *heap_arr; // pointer to array of elements in heap
    int capacity; // maximum possible size of min heap
    int heap_size; // Current number of elements in min heap
    public:
        MinHeap(int cap) {
            /*
            Constructor: Builds a heap from a given array a[] of given size.    
            */
            
            heap_size = 0;
            capacity = cap;
            heap_arr = new int[cap];
        }


        void MinHeapify(int i) {
            /*
            A recursive method to heapify a subtree with the root at given index
            This method assumes that the subtrees are already heapified.            
            */
            
            int l = left(i);
            int r = right(i);
            int smallest = i;

            // Check if left child is less then the current root.
            // reassign to root if it is. 
            if (l < heap_size && heap_arr[l] < heap_arr[i])
                smallest = l;
           
            // Check if right child is less than the current root.
            // reassign to root if it is. 
            if (r < heap_size && heap_arr[r] < heap_arr[smallest])
                smallest = r;
           
            // Check if the smallest value is still equal to our given root node idx.
            // If it isnt, we swap the value at idx of i with the value at the idx of smallest.
            // We then call MinHeapify to ensure the heap is still valid and in line with the heap principle.
            if (smallest != i) {
                swap(&heap_arr[i], &heap_arr[smallest]);
                MinHeapify(smallest);
            }
        }


        // returns the parent of the given node.
        int parent(int i) { return (i-1)/2; }


        // to get index of left child of node at index i
        int left(int i) { return (2*i + 1); }


        // to get index of right child of node at index i
        int right(int i) { return (2*i + 2); }

        
        int extractMin() {
            /*
            Method to remove minimum element (or root) from min heap.    
            */

            if (heap_size <= 0)
                cout << "Heap is empty, cannot extract a minimum value." << endl;
                return 0;
            if (heap_size == 1) {
                heap_size--;
                return heap_arr[0];
            }

            // Store the minimum value, and remove it from heap
            int root = heap_arr[0];
            heap_arr[0] = heap_arr[heap_size-1];
            heap_size--;
            MinHeapify(0);

            return root;
        }


        void decreaseKey(int i, int new_val) {
            /*
                Decreases the value associated with a key.
                Decreases value of key at index 'i' to new_val.
            */


            if (new_val >= heap_arr[i]) {
                cout << "New value must be less than the current value at the node with index of " << i << "!" << endl;
                return;
            }

            
            heap_arr[i] = new_val;


            while (i != 0 && heap_arr[parent(i)] > heap_arr[i]) {
                swap(&heap_arr[i], &heap_arr[parent(i)]);
                i = parent(i);
            }

        }

 
        void increaseKey(int i, int new_val) {
            /*
            Increases value of the node's data at index i to new_val.            
            */


            if (new_val <= heap_arr[i]) {
                cout << "New value must be strictly greater than the current value!" << endl; 
                return; 
            } 

            heap_arr[i] = new_val;

            if (i == 0) {
                MinHeapify(i);
            }

            while (i > 1 && heap_arr[parent(i)] < heap_arr[i]) {
                swap(&heap_arr[i], &heap_arr[parent(i)]);
                i = parent(i);
            }

        }


        // Returns the minimum data point from the root of the min heap
        int getMin() { return heap_arr[0]; }

        
        void deleteKey(int i) {
            /*
            This function deletes key at index i. 
            It first reduces value to minus
            infinite, then calls extractMin().
            */
            
            decreaseKey(i, INT_MIN);
            extractMin();
        }


        void insertKey(int k) {
            /*
            Inserts a new node with data k.
            */

            if (heap_size == capacity) {
                cout << "\nOverflow: Could not insertKey\n";
                return;
            }

            // First insert the new key at the end
            heap_size++;
            int i = heap_size - 1;
            heap_arr[i] = k;

            // Fix the min heap property if it is violated
            while (i != 0 && heap_arr[parent(i)] > heap_arr[i]) {
                swap(&heap_arr[i], &heap_arr[parent(i)]);
                i = parent(i);
            }
        }


        void peek(int i) {
            /*
            Displays the data value for a given node idx to output.
            */
            
            cout << heap_arr[i] << " is the value at idx " << i << endl;
        }


        void display() {
            /*
            Prints out the value of the nodes in the heap
            */


            for (int i = 0; i < heap_size; i++) {
                cout << heap_arr[i] << endl;
            }
            cout << " \n\n";
        }


        int GetSize() {
            return heap_size;
        }

};  


void swap(int *x, int *y) {
    /*
    Swaps two elements.   
    */

    int temp = *x;
    *x = *y;
    *y = temp;
}


// Driver program to test above functions
int main() {  
    /*
    Main Function.
    */  
    
    // Test to see if Negative number will cout -- ASK LATER ON HOW TO FIX THIS 
    // I believe it to be a vscode problem as it will work from windows cmd
    // cout << 5 * -1 << endl;

    MinHeap heap(11);
    
    heap.insertKey(3);
    heap.insertKey(543);
    heap.insertKey(15);
    heap.insertKey(5);
    heap.insertKey(4);
    heap.insertKey(45);

    heap.display();
    cout << " end display." << endl;


    cout << heap.getMin() << " is from getMin b4 extracting min value" << endl;
    cout << heap.extractMin() << " is from extract min " << endl;
    cout << heap.getMin() << " is from getMin " << endl;

    heap.display();

    // Currently unable to use negative numbers. in VSCODE
    heap.decreaseKey(2, 1);
    cout << heap.getMin() << " is the min after decreasing to 1" << endl;

    heap.increaseKey(1,400);
    cout << heap.getMin() << " is the min after incresing root to 400" << endl;


    heap.deleteKey(0);
    cout << heap.getMin() << " is the min after removing the prior min value." << endl;
    
    int x = heap.left(0);
    cout << x << " Is the idx of the left child node of the root node." << endl;
    
    int y = heap.right(0);
    cout << y << " Is the idx of the right child node of the root node." << endl;

    int z = heap.parent(y);
    cout << z << " Is the idx of the parent node of the right child node of root." << endl;

    heap.peek(x);

    heap.display();
    cout << " end display 2" << endl;

    return 0;
}