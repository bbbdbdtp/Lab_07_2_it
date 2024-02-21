#include <iostream>
#include <iomanip>
#include <time.h>
#include <Windows.h>

using namespace std;

void Create(int** a, const int rowCount, const int colCount, const int Low, const int High);
void Print(int** a, const int rowCount, const int colCount);
void theMinimumElementOfTheMainDiagonal(int** a, const int k, const int n);
void Swap(int& a, int& b);
void DeleteMatrix(int** a, const int k);

int main() {
    int Low = 7;
    int High = 65;
    int k;
    int n;
    int minElement = -1;

    cout << "k = "; cin >> k;
    cout << "n = "; cin >> n;

    int** a = new int* [k];
    for (int i = 0; i < k; i++)
        a[i] = new int[n];
    Create(a, k, n, Low, High);
    Print(a, k, n);

    theMinimumElementOfTheMainDiagonal(a, k, n);
    Print(a, k, n);

    DeleteMatrix(a, k);
    return 0;
}

void Create(int** a, const int k, const int n, const int Low, const int High) {
    srand(time(0));
    for (int i = 0; i < k; i++)
        for (int j = 0; j < n; j++)
            a[i][j] = Low + rand() % (High - Low + 1);
}

void Print(int** a, const int k, const int n) {
    cout << endl;
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < n; j++)
            cout << setw(4) << a[i][j];
        cout << endl;
    }
    cout << endl;
}

void theMinimumElementOfTheMainDiagonal(int** a, const int k, const int n) {
    if (k != n) {
        cout << "the matrix isn't square" << endl;
        return;
    }

    int minElement = a[0][0];

    for (int i = 1; i < k; i++) {
        if (a[i][i] < minElement) {
            minElement = a[i][i];
        }
    }
}

void Swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

void DeleteMatrix(int** a, const int k) {
    for (int i = 0; i < k; i++)
        delete[] a[i];
    delete[] a;
}