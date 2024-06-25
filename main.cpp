#include <iostream>;
#include <string>;

using namespace std;

int* insertBlockAtIndex(int* arr, int size, int* block, int blockSize, int index, int& newSize) {
    if (index < 0 || index > size) {
        cout << "Invalid index." << endl;
        return nullptr;
    }

    newSize = size + blockSize;
    int* newArr = new int[newSize];

    for (int i = 0; i < index; ++i) {
        newArr[i] = arr[i];
    }

    for (int i = 0; i < blockSize; ++i) {
        newArr[index + i] = block[i];
    }

    for (int i = index; i < size; ++i) {
        newArr[blockSize + i] = arr[i];
    }

    return newArr;
}

int main() {
    int size, blockSize, index;

    cout << "Enter the size of the array: ";
    cin >> size;

    int* arr = new int[size];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < size; ++i) {
        cin >> arr[i];
    }

    cout << "Enter the size of the block to insert: ";
    cin >> blockSize;

    int* block = new int[blockSize];
    cout << "Enter the elements of the block: ";
    for (int i = 0; i < blockSize; ++i) {
        cin >> block[i];
    }

    cout << "Enter the index to insert the block at: ";
    cin >> index;

    int newSize;
    int* newArr = insertBlockAtIndex(arr, size, block, blockSize, index, newSize);

    if (newArr != nullptr) {
        cout << "Array after inserting the block: ";
        for (int i = 0; i < newSize; ++i) {
            cout << newArr[i] << " ";
        }
        cout << endl;

        delete[] newArr;
    }

    delete[] arr;
    delete[] block;

	system("pause");
	return 0;
}