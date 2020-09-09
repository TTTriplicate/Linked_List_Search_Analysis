#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include "LinkedList.h"


void bubbleSort(int* toSort);

void swap(int& first, int& second);

int main()
{
    const int SIZE = 10;
    int a[SIZE];
    int i;
    int key = 0;
    LinkedList list;

    srand(time(NULL));

    for (i = 0; i < SIZE; i++)
    {
        a[i] = rand() % 100;
        std::cout << a[i] << std::endl;
    }

    std::cout << std::endl;

    for (int i : a) {
        list.newNode(++key, i);
    }

    bubbleSort(a);

    std::sort(a, a+SIZE);

    for (int i : a)
        std::cout << i << std::endl;

    list.print();

    std::cout << "The End\n";



    return(0);
}

void bubbleSort(int* toSort) {
    bool changes;
    for (int j = 0; j < sizeof(toSort); j++) {
        changes = false;
        for (int i = 1; i < sizeof(toSort) - 1; i++) {
            if (toSort[i] < toSort[i - 1]) {
                swap(toSort[i], toSort[i - 1]);
                changes = true;
            }
        }
        if (!changes) {
            break;
        }
    }
}

void swap(int& first, int& second) {
    int temp = first;
    first = second;
    second = temp;
}