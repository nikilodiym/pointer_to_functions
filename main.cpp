#include <iostream>;
#include <string>;

using namespace std;

int* my_fun(int* A, int sizeA, int* B, int sizeB) {
    for (int i = 0; i <= sizeA - sizeB; ++i) {
        bool found = true;
        for (int j = 0; j < sizeB; ++j) {
            if (A[i + j] != B[j]) {
                found = false;
                break;
            }
        }
        if (found) {
            return &A[i];
        }
    }
    return 0;
}

int main() {
    int M, N;

    cout << "Enter the size of array A: ";
    cin >> M;
    int* A = new int[M];
    cout << "Enter elements of array A: ";
    for (int i = 0; i < M; ++i) {
        cin >> A[i];
    }

    cout << "Enter the size of array B: ";
    cin >> N;
    int* B = new int[N];
    cout << "Enter elements of array B: ";
    for (int i = 0; i < N; ++i) {
        cin >> B[i];
    }

    int* result = M, N;
    
    cout << "Enter the size of array A: ";
    cin >> M;
    int* A = new int[M];
    cout << "Enter elements of array A: ";
    for (int i = 0; i < M; ++i) {
        cin >> A[i];
    }
    
    cout << "Enter the size of array B: ";
    cin >> N;
    int* B = new int[N];
    cout << "Enter elements of array B: ";
    for (int i = 0; i < N; ++i) {
        cin >> B[i];
    }
    
    int* result = my_fun(A, M, B, N);
    
    if (result != 0) {
        cout << "Array B is a subset of array A starting at index: " << (result - A) << endl;
    } else {
        cout << "Array B is not a subset of array A" << endl;
    }
    
    

    if (result != 0) {
        cout << "Array B is a subset of array A starting at index: " << (result - A) << endl;
    }
    else {
        cout << "Array B is not a subset of array A" << endl;
    }

    delete[] A;
    delete[] B;

	system("pause");
	return 0;
}