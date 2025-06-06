#include <iostream>
using namespace std;


int get_feet() {
    int feet; 

    cout << "Please enter an integer value for a given length in feet:  "; 
    cin >> feet;    
    cout << "\n\n";        
    return feet; 
}


int convert_to_meters(int feet) {
    int meters;
    meters = (feet * 0.3048);
    return meters;    
}


main() {
    cout << "Welcome to my 'Feet to Meters' converter program." << endl;
    int feet;
    feet = get_feet();

    int meters;
    meters = convert_to_meters(feet);

    cout << "Here is the value for the amount of feet converted to integers: " << meters << " feet" << endl;

    return 0;
}








