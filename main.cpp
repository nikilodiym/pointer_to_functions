#include <iostream>
#include <string>;

using namespace std;

int* allocateArray(int size) {
    return new int[size];
}

void initializeArray(int* array, int size) {
    for (int i = 0; i < size; ++i) {
        array[i] = 0;
    }
}

void printArray(int* array, int size) {
    for (int i = 0; i < size; ++i) {
        cout << array[i] << " ";
    }
    cout << endl;
}

void deleteArray(int* array) {
    delete[] array;
}

void appendElement(int*& array, int& size, int element) {
    int* newArray = new int[size + 1];
    for (int i = 0; i < size; ++i) {
        newArray[i] = array[i];
    }
    newArray[size] = element;
    delete[] array;
    array = newArray;
    ++size;
}

void insertElement(int*& array, int& size, int index, int element) {
    if (index < 0 || index > size) {
        cout << "Invalid index" << endl;
        return;
    }
    int* newArray = new int[size + 1];
    for (int i = 0; i < index; ++i) {
        newArray[i] = array[i];
    }
    newArray[index] = element;
    for (int i = index; i < size; ++i) {
        newArray[i + 1] = array[i];
    }
    delete[] array;
    array = newArray;
    ++size;
}

void deleteElement(int*& array, int& size, int index) {
    if (index < 0 || index >= size) {
        cout << "Invalid index" << endl;
        return;
    }
    int* newArray = new int[size - 1];
    for (int i = 0; i < index; ++i) {
        newArray[i] = array[i];
    }
    for (int i = index + 1; i < size; ++i) {
        newArray[i - 1] = array[i];
    }
    delete[] array;
    array = newArray;
    --size;
}

int main() {
    int size = 5;
    int* myArray = allocateArray(size);
    initializeArray(myArray, size);

    cout << "Initial array: ";
    printArray(myArray, size);

    appendElement(myArray, size, 10);
    cout << "After appending 10: ";
    printArray(myArray, size);

    insertElement(myArray, size, 2, 20);
    cout << "After inserting 20 at index 2: ";
    printArray(myArray, size);

    deleteElement(myArray, size, 3);
    cout << "After deleting element at index 3: ";
    printArray(myArray, size);

    deleteArray(myArray);

    return 0;
}
