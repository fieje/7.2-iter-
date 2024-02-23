#include <iostream>
#include <iomanip>
#include <cstdlib>

using namespace std;

void Create(int** a, const int n, const int m, const int Low, const int High);
void Print(int** a, const int n, const int m);
void SwapMinWithMax(int** a, const int n, const int m);

int main()
{
    srand((unsigned)time(NULL));
    int n, m;
    cout << "Enter the number of rows (n): ";
    cin >> n;
    cout << "Enter the number of columns (m): ";
    cin >> m;

    const int Low = 7;
    const int High = 65;

    int** matrix = new int* [n];
    for (int i = 0; i < n; ++i)
        matrix[i] = new int[m];

    Create(matrix, n, m, Low, High);
    cout << "Original Matrix:\n";
    Print(matrix, n, m);

    SwapMinWithMax(matrix, n, m);
    cout << "Matrix after swapping:\n";
    Print(matrix, n, m);

    for (int i = 0; i < n; ++i)
        delete[] matrix[i];
    delete[] matrix;

    return 0;
}

void Create(int** a, const int n, const int m, const int Low, const int High)
{
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            a[i][j] = Low + rand() % (High - Low + 1);
}

void Print(int** a, const int n, const int m)
{
    for (int i = 0; i < n; ++i) 
    {
        for (int j = 0; j < m; ++j)
            cout << setw(4) << a[i][j];
        cout << endl;
    }
}

void SwapMinWithMax(int** a, const int n, const int m)
{
    for (int j = 1; j < m; j += 2)
    {
        int minElement = a[0][j];
        int maxElement = a[0][j - 1];
        int minElementRow = 0;
        int maxElementRow = 0;

        for (int i = 1; i < n; ++i)
        {
            if (a[i][j] < minElement)
            {
                minElement = a[i][j];
                minElementRow = i;
            }
            if (a[i][j - 1] > maxElement) 
            {
                maxElement = a[i][j - 1];
                maxElementRow = i;
            }
        }

        int temp = a[minElementRow][j];
        a[minElementRow][j] = a[maxElementRow][j - 1]; 
        a[maxElementRow][j - 1] = temp; 
    }
}
