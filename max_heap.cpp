/* 

An implementation of the max heap data structure.


Sources: 
    https://www.geeksforgeeks.org/binary-heap/
    https://medium.com/@allan.sioson/max-heapify-build-max-heap-and-heapsort-algorithm-in-python-42c4dec70829
    
*/

#include <iostream>
#include <climits>

using namespace std;

// Prototype of a utility function to swap two integers
// Allows for methods inside the MaxHeap class to use the 
// swap class, as the swap class is located under the class definition.
void swap(int *x, int *y);


class MaxHeap {
    /*
    A class for Max Heap.    
    */

    int *heap_arr; // pointer to array of elements in heap
    int capacity; // maximum possible size of min heap
    int heap_size; // Current number of elements in min heap
    public:
        MaxHeap(int cap) {
            /*
            A constructor function that builds a heap from a given array a[] of given size.    
            */

            heap_size = 0;
            capacity = cap;
            heap_arr = new int[cap];
        }


        
        void MaxHeapify(int i) {
            /*
            A recursive method to heapify a subtree with the root at given index
            This method assumes that the subtrees are already heapified.    
            */
            
            int l = left(i);
            int r = right(i);
            int biggest = i;

            // Check if left child is greater than the current root.
            // reassign to root if it is.  
            if (l < heap_size && heap_arr[l] > heap_arr[i])
                biggest = l;
            
            // Check if right child is greater than the current root.
            // reassign to root if it is. 
            if (r < heap_size && heap_arr[r] > heap_arr[biggest])
                biggest = r;
            
                
            // Check if the bigest value is still equal to our given root node idx.
            // If it isnt, we swap the value at idx of i with the value at the idx of biggest.
            // We then call MaxHeapify to ensure the heap is still valid and in line with the heap principle.
            if (biggest != i) {
                swap(&heap_arr[i], &heap_arr[biggest]);
                MaxHeapify(biggest);
            }
        }


        // returns the index of the parent of a node at a given index.
        int parent(int i) { return (i-1)/2; }

        // to get index of left child of node at index i
        int left(int i) { return (2*i + 1); }

        // to get index of right child of node at index i
        int right(int i) { return (2*i + 2); }

        
        int extractMax() {
            /*
            Method to remove maximum element (or root) from min heap.    
            */

            if (heap_size <= 0) {
                cout << "Heap is empty, cannot extract a minimum value." << endl;
                return 0;
            }
            if (heap_size == 1) {
                heap_size--;
                return heap_arr[0];
            }


            // Store the maximum value, and remove it from heap
            int root = heap_arr[0];
            heap_arr[0] = heap_arr[heap_size-1];
            heap_size--;
            MaxHeapify(0);

            return root;
        }


        void decreaseKey(int i, int new_val) {
            /*
            Decreases value of node's data at index i to new_val.            
            
            TODO HEAP WONT ORGANIZE AFTER KEY AT ROOT IS DECREASED.
            
            
            */
            

            if (new_val >= heap_arr[i]) {
                cout << "New value must be less than the current value at the node with index of " << i << "!" << endl;
                return;
            }


            heap_arr[i] = new_val;


            if (i == 0) {
                MaxHeapify(i);
            }

            while (i != 0 && heap_arr[parent(i)] < heap_arr[i]) {
                swap(&heap_arr[i], &heap_arr[parent(i)]);
                i = parent(i);
            }
        }

 
        void increaseKey(int i, int new_val) {
            /*
            Increases value of key at index 'i' to new_val.            
            */

            if (new_val <= heap_arr[i]) {
                cout << "New value must be strictly greater than the current value!" << endl; 
                return; 
            } 


            heap_arr[i] = new_val;


            while (i > 1 && heap_arr[parent(i)] < heap_arr[i]) {
                swap(&heap_arr[i], &heap_arr[parent(i)]);
                i = parent(i);
            }
        }


        // Returns the minimum key (key at root) from min heap
        int getMax() { return heap_arr[0]; }


        void deleteKey(int i) {
            /*
            This function deletes key at index i. 
            */

            decreaseKey(i, INT_MIN);
            extractMax();
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

            // Fix the max heap property if it is violated
            while (i != 0 && heap_arr[parent(i)] < heap_arr[i]) {
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
    A utility function to swap two elements.    
    */
    
    int temp = *x;
    *x = *y;
    *y = temp;
}


int main() {
    /*
    Driver program to test above functions.    
    */

    MaxHeap heap(11);
    heap.insertKey(3);
    heap.insertKey(543);
    heap.insertKey(15);
    heap.insertKey(5);
    heap.insertKey(4);
    heap.insertKey(45);

    heap.display();
    cout << " end display 1." << endl; 

    int a = heap.GetSize();
    cout << a << " is heap size after inserting all values." << endl;

    cout << heap.getMax() << " is from get getMax b4 extracting the max value" << endl;
    cout << heap.extractMax() << " is from extract max" << endl;
    cout << heap.getMax() << " is from getMax after extracting the prior max node" << endl;
    
    heap.display();
    cout << " end display 2." << endl; 

    // Currently unable to use negative numbers in vscode.  
    heap.decreaseKey(0, 1);
    // Heap not reoganizing itself after a key is reduced far enough to break the heap principle.

    heap.display();
    cout << " end display 3." << endl;
    cout << heap.getMax() << " is the max after decreasing the root value to 1" << endl;

    heap.increaseKey(0, 1000);
    cout << heap.getMax() << " is the max after increasing the root value to 1000" << endl;

    int x = heap.left(0);
    cout << x << " Is the left child idx of root." << endl;
    
    int y = heap.right(0);
    cout << y << " Is the right child idx of root." << endl;

    int z = heap.parent(y);
    cout << z << " Is the parent of the left node child node of root." << endl; 

    heap.peek(x);
    cout << " The val at the left child node of root." << endl; 

    heap.display();
    cout << " end display 2" << endl;
    
    return 0;
}





