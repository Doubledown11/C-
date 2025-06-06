#include <iostream>


int get_celsius() {
    /*
    Gets a Celsius float value from the user.
    */

    std::cout << "Please enter a float value for a celsius temperature on the following line: " << std::endl;

    float celsius;
    std::cin >> celsius;

    return celsius;
}


int convert_to_F(float celsius) {
    /* 
    Converts a given celsius float value to 
    its Fahrenheit representation.
    */
    
    float fahrenheit;
    fahrenheit = ((celsius * (9.0/5.0)) + 32.0);

    float x = (celsius * (9.0/5.0));

    return fahrenheit;
}


int get_fahrenheit() {
    /* 
    Gets a Fahrenheit value from the user.
    */

    std::cout << "Please enter a float value for a fahrenheit temperature on the following line: " << std::endl;

    float fahrenheit;
    std::cin >>  fahrenheit;
    
    return fahrenheit;
}


int convert_to_C(float fahrenheit) {
    /* 
    Converts a given Fahrenheit float value to its 
    Celsius representation.
    */

    float celsius;
    celsius = ((fahrenheit - 32.0) * (5.0/9.0));

    return celsius;
}


int main() {
    /* 
    Main Function 
    */

    std::cout << "\n\n-------------------------------------------------------\n";
    std::cout << "Welcome to my 'Celsius / Fahrenheit' converter program." << std::endl;
    std::cout << "-------------------------------------------------------";
    std::cout << "\n\n\n";

    char valid = true;

    // Ask what the user wishes to convert.    
    while (valid) {
        char choice;  
        std::cout << "Enter what you wish to convert on the following line. Please choose 'c' or 'f', in lowercase. " << std::endl;
        std::cin >> choice;
        char c = 'c';
        char f = 'f';

        
        if (choice == c) {
            // If the user chose to convert Celsius.
            valid = false;

            float celsius; 
            celsius = get_celsius();
        
            float fahrenheit;
            fahrenheit = convert_to_F(celsius);
            
            std::cout << "The given Celsius value of " << celsius << " when converted to Fahrenheit is: "  << fahrenheit << std::endl;

        } else if (choice == f) {
            // If the user chose to convert Fahrenheit.
            valid = false;

            float fahrenheit;
            fahrenheit = get_fahrenheit();

            float celsius;
            celsius = convert_to_C(fahrenheit);

            std::cout << "The given Fahrenheit value of " << fahrenheit << " when converted to Celsius is: " << celsius << std::endl;


        } else {
            // If user entered invalid input.
            std::cout << "Please enter a either a 'c' or a 'f' character only. " << std::endl;
            std::cout << "\n\n\n";
        }
    }
    
    return 0;  
}