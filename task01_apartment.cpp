#include <iostream>
#include <string>

int main() {
    const int NUM_FLATS = 10;
    const int NUM_QUERIES = 3;

    std::string surnames[NUM_FLATS];

    std::cout << "Enter Alexey " << NUM_FLATS << " flats:" << std::endl;
    for (int i = 0; i < NUM_FLATS; ++i) {
        std::cin >> surnames[i]; 
    }

    std::cout << "Enter " << NUM_QUERIES << " flat numbers to query:" << std::endl;
    for (int i = 0; i < NUM_QUERIES; ++i) {
        int apartment_number;
        std::cin >> apartment_number;
        if (std::cin.fail()) {
            std::cin.clear();  
            std::cin.ignore(100, '\n');  
            std::cout << "Invalid input. Please enter a valid number from 1 to ten." << std::endl;
            --i; 
            continue;
        }

        if (apartment_number > NUM_FLATS || apartment_number < 1) {
            std::cout << "There is no flat with this number." << std::endl;
        } else {
            std::cout << surnames[apartment_number - 1] << std::endl;
        }
    }

    return 0;
}