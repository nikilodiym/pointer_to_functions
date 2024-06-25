#include <iostream>;
#include <string>;

using namespace std;

void splitArray(int* array, int size, int*& positives, int& positiveSize, int*& negatives, int& negativeSize, int*& zeros, int& zeroSize) {
    positiveSize = negativeSize = zeroSize = 0;

    for (int i = 0; i < size; ++i) {
        if (array[i] > 0) {
            ++positiveSize;
        }
        else if (array[i] < 0) {
            ++negativeSize;
        }
        else {
            ++zeroSize;
        }
    }

    positives = new int[positiveSize];
    negatives = new int[negativeSize];
    zeros = new int[zeroSize];

    int pIndex = 0, nIndex = 0, zIndex = 0;

    for (int i = 0; i < size; ++i) {
        if (array[i] > 0) {
            positives[pIndex++] = array[i];
        }
        else if (array[i] < 0) {
            negatives[nIndex++] = array[i];
        }
        else {
            zeros[zIndex++] = array[i];
        }
    }
}

void printArray(int* array, int size) {
    for (int i = 0; i < size; ++i) {
        cout << array[i] << " ";
    }
    cout << endl;
}

int main() {
    int size = 10;
    int staticArray[10] = { 1, -2, 3, 0, -5, 6, 0, -8, 9, 0 };

    int* positives = nullptr;
    int* negatives = nullptr;
    int* zeros = nullptr;
    int positiveSize, negativeSize, zeroSize;

    splitArray(staticArray, size, positives, positiveSize, negatives, negativeSize, zeros, zeroSize);

    cout << "Positive elements: ";
    printArray(positives, positiveSize);

    cout << "Negative elements: ";
    printArray(negatives, negativeSize);

    cout << "Zero elements: ";
    printArray(zeros, zeroSize);

    // Звільнення виділеної пам'яті
    delete[] positives;
    delete[] negatives;
    delete[] zeros;

    return 0;
}