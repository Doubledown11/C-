#include <iostream>
#include <cstring>

int main() {
    /*
    Main Function.
    */
    
    char arr[] = "This string will be reduced down to characters in length!";
    char reduced[11]; // +1 for the null terminator.

    // Copy the first 10 characters and null-terminate it
    std::strncpy(reduced, arr, 10);
    reduced[10] = '\0'; // Ensure null-termination.

    std::cout << "Reduced string: " << reduced << std::endl;

    return 0;

}