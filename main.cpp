#include <iostream>;
#include <string>;

using namespace std;

bool isPrime(int number) {
    if (number <= 1) return false;
    if (number == 2) return true;
    if (number % 2 == 0) return false;
    for (int i = 3; i <= sqrt(number); i += 2) {
        if (number % i == 0) return false;
    }
    return true;
}

int* removePrimes(int* array, int& size) {
    int primeCount = 0;
    for (int i = 0; i < size; ++i) {
        if (isPrime(array[i])) {
            ++primeCount;
        }
    }

    int newSize = size - primeCount;
    int* newArray = new int[newSize];
    int index = 0;
    for (int i = 0; i < size; ++i) {
        if (!isPrime(array[i])) {
            newArray[index++] = array[i];
        }
    }

    size = newSize;

    return newArray;
}

void printArray(int* array, int size) {
    for (int i = 0; i < size; ++i) {
        cout << array[i] << " ";
    }
    cout << endl;
}

int main() {
    int size = 10;
    int* myArray = new int[size] {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    cout << "Original array: ";
    printArray(myArray, size);

    int* newArray = removePrimes(myArray, size);

    cout << "Array after removing primes: ";
    printArray(newArray, size);

    delete[] myArray;
    delete[] newArray;
    
	system("pause");
	return 0;
}