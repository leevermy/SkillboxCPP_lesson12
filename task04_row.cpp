#include <iostream>

int main() {
    int numbers[15] = {114, 111, 106, 107, 108, 105, 115, 108, 110, 109, 112, 113, 116, 117, 118};
    int size = sizeof(numbers)/sizeof(numbers[0]);
    
    int min = numbers[0];
    int max = numbers[0];
    int sum = 0;
    for (int i = 0; i < size; ++i) {
        if (min > numbers[i]) min = numbers[i];
        if (max < numbers[i]) max = numbers[i];
        sum += numbers[i];
    }

    int expected_sum = (max + min) * (max - min + 1) / 2;

    if (sum - expected_sum) {
        std::cout << sum - expected_sum;
    } else {
        std::cout << "There is no duplicates";
    };
    return 0;
}