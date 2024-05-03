#include <iostream>
#include <cassert>


float travelTime(float distance, float speed) {
    assert(speed > 0);
    return distance / speed;
}

int main() {
    float distance, speed;

    std::cout << "Enter the distance(km): ";
    std::cin >> distance;

    std::cout << "Enter the speed(km/h): ";
    std::cin >> speed;

    // Попытка вызвать функцию, которая вызовет assert при неправильных данных
    std::cout << "Time: " << travelTime(distance, speed) << " hours" << std::endl;

    return 0;
}