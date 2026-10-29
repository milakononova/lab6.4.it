
#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;

// Створення масиву
void Create(int a[], int n)
{
    for (int i = 0; i < n; i++)
        a[i] = rand() % 21 - 10;
}

// Виведення масиву
void Print(const int a[], int n)
{
    for (int i = 0; i < n; i++)
        cout << setw(5) << a[i];
    cout << endl;
}

// Мінімальний за модулем елемент
int MinAbs(const int a[], int n)
{
    int result = a[0];

    for (int i = 1; i < n; i++)
        if (abs(a[i]) < abs(result))
            result = a[i];

    return result;
}

// Сума модулів після першого нуля
int SumAfterZero(const int a[], int n)
{
    int firstZero = -1;

    for (int i = 0; i < n; i++)
        if (a[i] == 0)
        {
            firstZero = i;
            break;
        }

    if (firstZero == -1)
        return 0;

    int sum = 0;

    for (int i = firstZero + 1; i < n; i++)
        sum += abs(a[i]);

    return sum;
}

// Перестановка елементів
void Rearrange(int a[], int n)
{
    int* temp = new int[n];
    int k = 0;

    // Парні позиції: 2, 4, 6...
    for (int i = 1; i < n; i += 2)
        temp[k++] = a[i];

    // Непарні позиції: 1, 3, 5...
    for (int i = 0; i < n; i += 2)
        temp[k++] = a[i];

    for (int i = 0; i < n; i++)
        a[i] = temp[i];

    delete[] temp;
}

#ifndef UNIT_TEST
int main()
{
    srand(static_cast<unsigned>(time(nullptr)));

    int n;
    cout << "Enter n: ";
    cin >> n;

    if (!cin || n <= 0)
    {
        cout << "Invalid size!" << endl;
        return 1;
    }

    int* a = new int[n];

    Create(a, n);

    cout << "Original array:" << endl;
    Print(a, n);

    cout << "Min abs element = "
        << MinAbs(a, n) << endl;

    cout << "Sum after first zero = "
        << SumAfterZero(a, n) << endl;

    Rearrange(a, n);

    cout << "Modified array:" << endl;
    Print(a, n);

    delete[] a;

    return 0;
}
#endif
