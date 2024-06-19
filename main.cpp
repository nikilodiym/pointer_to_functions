#include <iostream>;
#include <string>;

using namespace std;

void my_fun(int* arr, int* size, int* sum, int* pr){
	*sum = 0;
	*pr = 1;

	for (int i = 0; i < *size; i++) {
		*sum += arr[i];
		*pr *= arr[i];

	}
}

int main() {
	int size, sum, pr;
	cout << "Enter the size of the array: ";
	cin >> size;

	int* arr = new int[size];

	cout << "Enter the elements of the array: ";
	for (int i = 0; i < size; ++i) {
		cin >> *(arr + i);
	}

	my_fun(arr, &size, &sum, &pr);

	cout << "Sum of the elements of the array: " << sum << endl;
	cout << "Product of the elements of the array: " << pr << endl;

	delete[] arr;

	system("pause");
	return 0;
}