#include <iostream>
using namespace std;


int main() {
    /* 
    Main Function
    */

    cout << "\n\n";
    cout << "------------------------------------------\n";
    cout << "Welcome to my Rectangle perimeter program!\n";
    cout << "------------------------------------------";
    cout << "\n\n";


    // Get Length
    float length;
    cout << "Please enter the rectangle's length value on the following line: ";
    cin >> length;


    // Get Width 
    float width;
    cout << "Please enter the rectangle's width value on the following line: ";
    cin >> width;


    // Calculate the perimeter of the rectangle.
    float perimeter;
    perimeter = (length + width + length + width);
    
    cout << "The perimeter of the rectangle formed from the given 2 values is " << perimeter << endl;
    return 0;
}   



