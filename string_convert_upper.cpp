#include <iostream> 
#include <cstring>

using namespace std;

int main() {
    char arr[] = "this string will be turned to all uppercase";
    char newArr[strlen(arr) + 1]; // +1 for the null terminator

    cout << "Original String:\n"<< arr << endl;
    cout << "String in UPPERCASE:\n";

    // Method 1: Displays the output to the screen.
    for (int x=0; x<strlen(arr); x++) 
        putchar(toupper(arr[x]));
    
    return 0;
}