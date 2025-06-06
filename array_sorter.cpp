#include <iostream>
#include <cstring>


int main() {
    /*
    Main Function
    */
   
    std::cout << "This program asks for the user for 10 different integer values to be placed in an array. " << endl;
    std::cout << "It then sorts the list in ascending order";

    // Initialize the array with 10 empty spaces.
    int array[10];

    for (int x=0; x<10; x++) {
        std::cout << "Please enter a value to be entered in the list. ";
        int input;
        std::cin >> input;
        array[x] = input; 
        std::cout << "\n\n";
    }


    return 0;
}