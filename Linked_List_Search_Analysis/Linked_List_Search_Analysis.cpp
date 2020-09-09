#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <iterator>
#include "LinkedList.h"


int* bubbleSort(int toSort[]);

void swap(int& first, int& second);

int binarySearch(int array[], int toFind);

int main()
{
    const int SIZE = 1000;
    int a[SIZE];
    int i;
    LinkedList list;

    srand(time(NULL));

    for (i = 0; i < SIZE; i++)
    {
        a[i] = rand() % 10000;
        std::cout << a[i] << std::endl;
    }

    std::cout << std::endl;

    int key = 0;
    for (int i : a) {
        list.newNode(++key, i);
    }

    bool changes;
    /*
    I really wasn't liking how the parameters had to be passed to do this as a function,
    so I just chose to do it in-line.  Same with the binary search.  Normally I would use a 
    vector<int> and pass by reference to a function.
    */
    for (int j = 0; j < sizeof(a) / sizeof(int); j++) {
        changes = false;
        for (int i = 0; i < sizeof(a)/sizeof(int) - 1; i++) {
            if (a[i] > a[i + 1]) {
                swap(a[i], a[i + 1]);
                changes = true;
            }
        }
        if (!changes) {
            break;
        }
    }

    for (int i : a)
        std::cout << i << std::endl;

    list.print();


    int input = 0;

    while (input != -1) {
        std::cout << "Enter a number between 1 and " << SIZE
            << " to search for a number in the list and the array." << std::endl;
        std::cout << "enter -1 ot exit." << std::endl;

        std::cin >> input;
        std::cout << "Finding the " << input << "th generated number in list:" << std::endl;
        Node* number;
        auto start = std::chrono::high_resolution_clock::now();
        try {
            number = list.find(input);
        }
        catch (std::invalid_argument e) {
            std::cout << e.what() << std::endl;
            continue;
        }
        auto end = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
        /*By taking a timestamp before and after each search, I get the 
        exact time of execution in microseconds.  Not super helpful for the analysis
        portion, but it gives a good at-a-glance difference.*/
        std::cout << "Found item in " << duration << " nanoseconds." << std::endl;
        std::cout << "Searching array for the same number: " << number->getData() << std::endl;
        int toFind = number->getData();
        start = std::chrono::high_resolution_clock::now();
        
        int low = 0;
        int high = sizeof(a)/sizeof(int);
        int guess = -1;
        while (guess != toFind) {
            guess = a[(high + low) / 2];
            if (guess > toFind) {
                high = (high + low) / 2;
            }
            else {
                low = (high + low) / 2;
            }
        }

        end = std::chrono::high_resolution_clock::now();
        duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();

        std::cout << "found " << guess << " in " << duration << " nanoseconds." << std::endl;
    }

    return(0);
}

void swap(int& first, int& second) {
    int temp = first;
    first = second;
    second = temp;
}

