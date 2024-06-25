#include <iostream>;
#include <string>;

using namespace std;

int* addBlockToEnd(int* arr, int size, int* block, int blockSize, int& newSize) {
    newSize = size + blockSize;

    int* newArr = new int[newSize];

    for (int i = 0; i < size; ++i) {
        newArr[i] = arr[i];
    }

    for (int i = 0; i < blockSize; ++i) {
        newArr[size + i] = block[i];
    }

    return newArr;
}

int main() {
    int size, blockSize;

    cout << "Enter the size of the array: ";
    cin >> size;

    int* arr = new int[size];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < size; ++i) {
        cin >> arr[i];
    }

    cout << "Enter the size of the block to add: ";
    cin >> blockSize;

    int* block = new int[blockSize];
    cout << "Enter the elements of the block: ";
    for (int i = 0; i < blockSize; ++i) {
        cin >> block[i];
    }

    int newSize;
    int* newArr = addBlockToEnd(arr, size, block, blockSize, newSize);

    cout << "Array after adding the block: ";
    for (int i = 0; i < newSize; ++i) {
        cout << newArr[i] << " ";
    }
    cout << endl;

    delete[] arr;
    delete[] block;
    delete[] newArr;

	system("pause");
	return 0;
}