#include <iostream>


int main() {
    /* 
    Main function
    */

    std::cout << "\n\nThis program takes a user defined number of input float values\n";
    std::cout << "and then asks the user for that amount of input numbers, which are stored in an array.\n\n";
    std::cout << "It then multiplies  them by each other and returns the product as output.\n";
    
    // Get the number of input values to be accepted by the user.
    int inputCount;
    std::cout << "Please enter the number of float values you wish to multiply on the following line: " << std::endl; 
    std::cin >> inputCount;

    std::cout << "\n\n";

    float array[inputCount];

    // Builds the array of inputCount length, and fills it with the user inputted values using a For loop.
    for (int x = 0; x < inputCount; x++) {
        std::cout << "Please enter value " << x + 1 << " to be added to the array!" << std::endl;
        float input;
        std::cin >> input;
        array[x] = input;
        std::cout << "\n\n";
    }


    // Iterates over the array and multiplies each value with a running product of the total product!
    float tot;
    tot = 1; 
    for (int x = 0; x < inputCount; x++) {
        tot = array[x] * tot;  
    } 

    std::cout << "The total product of the array is " << tot << std::endl;
    return 0;
}



