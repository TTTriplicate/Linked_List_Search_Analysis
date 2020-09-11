#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <iterator>
#include "LinkedList.h"


void swap(int& first, int& second);

//You might want to remove the console ouput of all numbers in each list
//if testing with large numbers of generated integers

int main()
{
    const int SIZE = 1000;
    int a[SIZE];
    int i;
    LinkedList list;

    srand(time(NULL));

    for (i = 0; i < SIZE; i++)
    {
        a[i] = rand() % (SIZE * 10);
        std::cout << a[i] << std::endl;//comment this line to reduce output
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
    vector<int> and pass by reference to a function, but the assignment specifically
    stated to use an array.
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

    for (int i : a)//comment this block to reduce output
        std::cout << i << std::endl;

    list.print();//comment this to reduce output


    int input = 0;

    while (input != -1) {
        std::cout << "Enter a number between 1 and " << SIZE
            << " to search for a number in the list and the array." << std::endl;
        std::cout << "enter -1 ot exit." << std::endl;

        std::cin >> input;
        std::cout << "Finding the " << input << "th generated number in list:" << std::endl;
        Node* number;
        /*By taking a timestamp before and after each search, I get the exact time of 
        start and end of execution and could calculate duration in nanoseconds. Not super 
        helpful for the analysis portion, but it gives a good at-a-glance runtime difference.*/
        auto start = std::chrono::high_resolution_clock::now();
        try {
            number = list.search(input);
        }
        catch (std::invalid_argument e) {
            std::cout << e.what() << std::endl;
            continue;
        }
        auto end = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
        std::cout << "Found item in " << duration << " nanoseconds." << std::endl;
        std::cout << "Searching array for the same number: " << number->getData() << std::endl;
        int toFind = number->getData();
        start = std::chrono::high_resolution_clock::now();
        
        int low = 0;//1 operation
        int high = sizeof(a)/sizeof(int);//4 operations
        int guess = -1;//1 operation
        while (guess != toFind) {
            /*Binary search takes n possibilities, and reduces it to n/2
            and each successive iteration has half as many again until there 
            is only the correct answer.
            n/2 -> (n/2)/2 -> ((n/2)/2)/2 -> log_2(n) maximum iterations*/
            guess = a[(high + low) / 2];//4 operations
            if (guess > toFind) {       //1 operation
                high = (high + low) / 2;//3(log_2(N)-1) operations when abstracted with the else
            }
            else {
                low = (high + low) / 2;//3 operations
            }
        }//totals to 4(log_2 n) + 6 operations

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

