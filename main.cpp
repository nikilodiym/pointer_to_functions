#include <iostream>;
#include <string>;

using namespace std;

int* removeNegativeNumbers(int* arr, int size, int& newSize) {
    newSize = 0;

    for (int i = 0; i < size; ++i) {
        if (arr[i] >= 0) {
            ++newSize;
        }
    }

    int* newArr = new int[newSize];
    int index = 0;

    for (int i = 0; i < size; ++i) {
        if (arr[i] >= 0) {
            newArr[index++] = arr[i];
        }
    }

    return newArr;
}

int main() {
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;

    int* arr = new int[size];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < size; ++i) {
        cin >> arr[i];
    }

    int newSize;
    int* newArr = removeNegativeNumbers(arr, size, newSize);

    cout << "Array without negative numbers: ";
    for (int i = 0; i < newSize; ++i) {
        cout << newArr[i] << " ";
    }
    cout << endl;

    delete[] arr;
    delete[] newArr;

	system("pause");
	return 0;
}