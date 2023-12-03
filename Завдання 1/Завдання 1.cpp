#include <iostream>
#include <Windows.h>

double findMinElement(double arr[], int size) {
    if (size <= 0) {
        return 0.0; 
    }

    double minElement = arr[0];
    for (int i = 1; i < size; ++i) {
        if (arr[i] < minElement) {
            minElement = arr[i];
        }
    }

    return minElement;
}

double sumBetweenPositive(double arr[], int size) {
    int jeb = -1;
    int rov = -1;
    double sum = 0.0;

    for (int i = 0; i < size; ++i) {
        if (arr[i] > 0) {
            if (jeb == -1) {
                jeb = i;
            }
            rov = i;
        }
    }

    for (int i = jeb + 1; i < rov; ++i) {
        sum += arr[i];
    }

    return sum;
}

void transformArray(double arr[], int size) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (arr[j] != 0 && arr[j + 1] == 0) {
                double temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    const int size = 8;
    double Array[size] = { 1.5, 0.0, -2.0, 3.0, 0.0, -4.5, 2.0, 7.0 };

    double minElement = findMinElement(Array, size);
    double BOB = sumBetweenPositive(Array, size);

    std::cout << "Мінімальний елемент масиву: " << minElement << std::endl;
    std::cout << "Сума елементів масиву між першим і останнім додатними: " << BOB << std::endl;

    transformArray(Array, size);

    std::cout << "Масив після перетворення: ";
    for (int i = 0; i < size; ++i) {
        std::cout << Array[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}