#include <iostream>;
#include <string>;

using namespace std;

int* deleteBlockAtIndex(int* arr, int size, int index, int blockSize, int& newSize) {
    if (index < 0 || index >= size || index + blockSize > size) {
        cout << "Invalid index or block size." << endl;
        return nullptr;
    }

    newSize = size - blockSize;
    int* newArr = new int[newSize];

    for (int i = 0; i < index; ++i) {
        newArr[i] = arr[i];
    }

    for (int i = index; i < newSize; ++i) {
        newArr[i] = arr[i + blockSize];
    }

    return newArr;
}

int main() {
    int size, index, blockSize;

    cout << "Enter the size of the array: ";
    cin >> size;

    int* arr = new int[size];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < size; ++i) {
        cin >> arr[i];
    }

    cout << "Enter the index to start deleting from: ";
    cin >> index;

    cout << "Enter the size of the block to delete: ";
    cin >> blockSize;

    int newSize;
    int* newArr = deleteBlockAtIndex(arr, size, index, blockSize, newSize);

    if (newArr != nullptr) {
        cout << "Array after deleting the block: ";
        for (int i = 0; i < newSize; ++i) {
            cout << newArr[i] << " ";
        }
        cout << endl;

        delete[] newArr;
    }

    delete[] arr;

	system("pause");
	return 0;
}