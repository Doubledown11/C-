#include <iostream> 

int average_three() {
    std::cout << "Please enter 3 numbers in the following prompts: \n" << std::endl;

    int x; 
    int y; 
    int z; 

    std::cout << "Enter character one in the following space: ";
    std::cin >> x;
    std::cout << "Character 1 is: " << x << "\n" << std::endl;
    system("pause");
    std::cout << "\n\n";

    
    std::cout << "Please input the second character: ";
    std::cin >> y;
    std::cout << "Character 2 is: " << y << "\n" << std::endl;
    system("pause");
    std::cout << "\n\n";


    std::cout << "Please input the third character: ";
    std::cin >> z;
    std::cout << "Character 3 is: " << z << "\n" << std::endl;
    system("pause");
    std::cout << "\n\n";

    std::cout << "Press enter to view the average of all three numbers inputted. \n\n";

    int average;
    average = ((x + y + z) / 3);
    
    return average;
}


int main() {
    int average;
    average = average_three();
    std::cout << "The average is: " << average << std::endl;

    return 0;
}