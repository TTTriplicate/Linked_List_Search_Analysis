#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include "LinkedList.h"


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

    for (int i : a) {
        list.newNode(++key, i);
    }

 //   std::sort(a, SIZE);

    list.print();

    std::cout << "The End\n";



    return(0);
}

