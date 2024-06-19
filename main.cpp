#include <iostream>;
#include <string>;

using namespace std;

void math_work(int* arr, int* size, int* negative_number, int* positive_number, int* zero_number) {
	*negative_number = 0;
	*zero_number = 0;
	*positive_number = 0;
	for (int i = 0; i < *size; i++) {
		if (arr[i] < 0) {
			*negative_number += 1;
		}
		else if (arr[i] == 0) {
			*zero_number += 1;
		}
		else {
			*positive_number += 1;
		}
	}
}

int main() {
	int size;

	cout << "Enter the size of the array: ";
	cin >> size;

	int* arr = new int[size];
	
	cout << "Enter the elements of the array: ";
	for (int i = 0; i < size; ++i) {
		cin >> *(arr + i);
	}

	int negative_number, positive_number, zero_number;
	math_work(arr, &size, &negative_number, &positive_number, &zero_number);

	cout << "Number of negative numbers: " << negative_number << endl;
	cout << "Number of positive numbers: " << positive_number << endl;
	cout << "Number of zeros: " << zero_number << endl;

	system("pause");
	return 0;
}