#include <iostream> 

void InputFromUser(double array[], int array_size);
void PrintArray(const std::string prompt, double array[], int array_size);
void BubbleSort (double array[], const int array_size);
void MergeSort(double array[], int begin_array, int end_array);
void MergeArray(double array[], const int begin_array, const int mid, const int end_array);
void HeapSort(double array[], int array_size);
void Heapify(double array[], int array_size, int index);


int main() {
    const int ARRAY_SIZE = 15;
    double numbers[ARRAY_SIZE];

    InputFromUser(numbers, ARRAY_SIZE);

    BubbleSort(numbers, ARRAY_SIZE);
    PrintArray("Bubble sort: ", numbers, ARRAY_SIZE);

    MergeSort(numbers, 0, ARRAY_SIZE-1);
    PrintArray("Merge sort: ", numbers, ARRAY_SIZE);

    HeapSort(numbers, ARRAY_SIZE);
    PrintArray("Heap sort: ", numbers, ARRAY_SIZE);
    
    return 0;
}

void InputFromUser(double array[], int array_size) {
    std::cout << "Input " << array_size << " float numbers:" << std::endl;
    for (int i = 0; i < array_size; ++i) {
        std::cin >> array[i];
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(100, '\n');
            std::cout << "Invalid input. Please enter a valid number." << std::endl;
            --i; 
            continue;
        }
    }
}

void PrintArray(const std::string prompt, double array[], int array_size) {
    std::cout << prompt;
    bool space = true;
    for (int i = 0; i < array_size; ++i) {
        if (!space) {
            std:: cout << " ";
        }
            std::cout << array[i];
            space = false;
    }
    std::cout <<std::endl;

}
    
void BubbleSort (double array[], const int array_size) {
    for (int i = 0; i < array_size - 1; ++i) {
        for (int j = i; j < array_size; ++j) {
            if (array[i] < array[j]) {
                double temp = array[i];
                array[i] = array[j];
                 array[j] = temp;
            }
        }
    }
}

void MergeSort(double array[], int begin_array, int end_array) {
    if (begin_array >= end_array) return;

    int mid = begin_array + (end_array - begin_array) / 2;
    MergeSort(array, begin_array, mid);
    MergeSort(array, mid + 1, end_array);
    MergeArray(array, begin_array, mid, end_array);
}

void MergeArray(double array[], const int begin_array, const int mid, const int end_array) {
    const int first_array_size = mid - begin_array + 1;
    const int second_array_size = end_array - mid;

    double *first_array = new double[first_array_size];
    double *second_array = new double[second_array_size];

    for (int i = 0; i < first_array_size; ++i) {
        first_array[i] = array[begin_array + i];
    }

    for (int i = 0; i < second_array_size; ++i) {
        second_array[i] = array[mid + i + 1];
    }

    int first_array_index = 0;
    int second_array_index = 0;
    int merged_array_index = begin_array;

    while (first_array_index < first_array_size && second_array_index < second_array_size) {
        if (first_array[first_array_index] <= second_array[second_array_index]) {
            array[merged_array_index] = first_array[first_array_index];
            ++first_array_index;
        } else {
            array[merged_array_index] = second_array[second_array_index];
            ++second_array_index;
        }
        ++merged_array_index;
    }

    while (first_array_index < first_array_size) {
        array[merged_array_index] = first_array[first_array_index];
        ++first_array_index;
        ++merged_array_index;
    }

     while (second_array_index < second_array_size) {
        array[merged_array_index] = second_array[second_array_index];
        ++second_array_index;
        ++merged_array_index;
    }

    delete[] first_array;
    delete[] second_array;
}

void HeapSort(double array[], int array_size) {
    for (int i = array_size / 2 - 1; i >= 0; --i) {
        Heapify(array, array_size, i);
    }

    for (int i = array_size - 1; i > 0; --i) {
        std::swap(array[0], array[i]);
        Heapify(array, i, 0);
    }

}
void Heapify(double array[], int array_size, int index) {
    int largest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < array_size && array[left] < array[largest]) {
        largest = left;
    }

    if (right < array_size && array[right] < array[largest]) {
        largest = right;
    }

    if (largest != index) {
        std::swap(array[index], array[largest]);
        Heapify(array, array_size, largest);
    }
}