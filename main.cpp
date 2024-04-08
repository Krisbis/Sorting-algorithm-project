#include <iostream>
#include <random>
#include "linkedList.h"
#include "TIMER.H"
#include <fstream>
#include <string>
#include <sstream>

#define ANSI_COLOR_BLUE "\x1b[34m"
#define ANSI_COLOR_YELLOW "\x1b[33m"
#define ANSI_COLOR_PURPLE "\x1b[35m"
#define ANSI_COLOR_RESET "\x1b[0m"
#define ANSI_COLOR_GREEN "\x1b[32m"
#define ANSI_COLOR_RED "\x1b[31m"

using namespace std;

void mainMenuText()
{
    std::cout << endl;
    std::cout << "1. increment - Sequential search" << endl;
    std::cout << "2. increment - Binary search" << endl;
    std::cout << "3. increment - Insertion sort" << endl;
    std::cout << "4. increment - Merge sort" << endl;
    std::cout << "5. increment - Bubble, Insertion," << 
    "Merge, Selection & Heapsort performance test" << endl;
    std::cout << endl;
}

int randomNumGenerator(int min, int max);
int sequentialSearch(Node *head, int searchableValue, Timer &timer);
int binarySearch(Node *head, int searchableValue, Timer &timer);
void formatter(int runs, LinkedList *bubbleSortData, LinkedList *insertionSortData, LinkedList *mergeSortData, LinkedList *selectionSortData, LinkedList *heapSortData, int n, int incr);
void csvWriter(int runs, LinkedList *bubbleSortData, LinkedList *insertionSortData, LinkedList *mergeSortData, LinkedList *selectionSortData, LinkedList *heapSortData, int n, int incr);

void increment1();
void increment2();
void increment3();
void increment4();
void increment5();

int main()
{
    char choice;
    mainMenuText();

    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice)
    {
    case '1':
        increment1();
        break;
    case '2':
        increment2();
        break;
    case '3':
        increment3();
        break;
    case '4':
        increment4();
        break;
    case '5':
        increment5();
        break;

    default:
        break;
    }

    return 0;
}

int randomNumGenerator(int min, int max)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(min, max);
    return dis(gen);
}

int sequentialSearch(Node *head, int searchableValue, Timer &timer)
{
    timer.reset();
    Node *temp = head;
    int index = 0;
    while (temp != nullptr)
    {
        if (temp->data == searchableValue)
        {
            return index;
        }
        temp = temp->next;
        index++;
    }
    cout << ANSI_COLOR_RED << "The value is not found in the list." << ANSI_COLOR_RESET << endl;
    return -1;
}

int binarySearch(Node *head, int searchableValue, Timer &timer)
{
    timer.reset();
    int low = 0;
    int high = 0;

    // Find the length of the list
    Node *temp = head;
    while (temp != nullptr)
    {
        high++;
        temp = temp->next;
    }

    while (low <= high)
    {
        int mid = low + (high - low) / 2; // Calculate mid
        temp = head;
        for (int i = 0; i < mid; ++i)
        {
            if (temp == nullptr)
            {
                // Handle the case where the list is shorter than expected
                std::cout << "The value is not found in the list." << std::endl;
                return -1;
            }
            temp = temp->next;
        }

        if (temp->data == searchableValue)
        {
            return mid;
        }
        else if (temp->data < searchableValue)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    std::cout << ANSI_COLOR_RED << "The value is not found in the list." << ANSI_COLOR_RESET << std::endl;
    return -1;
}

void formatter(int runs, LinkedList *bubbleSortData, LinkedList *insertionSortData, LinkedList *mergeSortData, LinkedList *selectionSortData, LinkedList *heapSortData, int elements, int incr)
{
    std::cout << "| " << ANSI_COLOR_BLUE << "Bubble Sort " << ANSI_COLOR_RESET << "|" << ANSI_COLOR_YELLOW << " Insertion Sort " << ANSI_COLOR_RESET <<
     "|" << ANSI_COLOR_PURPLE << " Merge Sort " << ANSI_COLOR_RESET << "|" << ANSI_COLOR_RED << " Selection sort " << ANSI_COLOR_RESET << "|" << ANSI_COLOR_GREEN <<
     " Heap sort " << ANSI_COLOR_RESET << " | " << std::endl;
    std::cout << "| Run No. | Time (ms) - Comparisons - Assignments | No. of elements |" << std::endl;

    Node *bubbleNode = bubbleSortData->getHead();
    Node *insertionNode = insertionSortData->getHead();
    Node *mergeNode = mergeSortData->getHead();
    Node *selectionNode = selectionSortData->getHead();
    Node *heapNode = heapSortData->getHead();

    for (int i = 0; i < runs; ++i)
    {
        // Print timing information for Bubble Sort
        // --------------------------------------------------------------
        std::cout << i + 1 << " | ";
        std::cout << ANSI_COLOR_BLUE;
        if (bubbleNode)
        {
            std::cout << bubbleNode->data << " millis - ";
            bubbleNode = bubbleNode->next;
        }
        else
        {
            std::cout << "N/A - ";
        }

        if (bubbleNode)
        {

            std::cout << bubbleNode->data << " - ";
            bubbleNode = bubbleNode->next;
        }
        else
        {
            std::cout << "N/A - ";
        }

        if (bubbleNode)
        {
            std::cout << bubbleNode->data << " ";
            bubbleNode = bubbleNode->next;
        }
        else
        {
            std::cout << "N/A";
        }
        std::cout << ANSI_COLOR_RESET;
        std::cout << " | ";

        // Print timing information for Insertion Sort
        // --------------------------------------------------------------
        std::cout << ANSI_COLOR_YELLOW;
        if (insertionNode)
        {
            std::cout << insertionNode->data << " millis - ";
            insertionNode = insertionNode->next;
        }
        else
        {
            std::cout << "N/A - ";
        }

        if (insertionNode)
        {
            std::cout << insertionNode->data << " - ";
            insertionNode = insertionNode->next;
        }
        else
        {
            std::cout << "N/A - ";
        }

        if (insertionNode)
        {
            std::cout << insertionNode->data << " ";
            insertionNode = insertionNode->next;
        }
        else
        {
            std::cout << "N/A";
        }
        std::cout << ANSI_COLOR_RESET;
        std::cout << " | ";

        // Print timing information for Merge Sort
        // --------------------------------------------------------------
        std::cout << ANSI_COLOR_PURPLE;
        if (mergeNode)
        {
            std::cout << mergeNode->data << " micros - ";
            mergeNode = mergeNode->next;
        }
        else
        {
            std::cout << "N/A - ";
        }

        if (mergeNode)
        {
            std::cout << mergeNode->data << " - ";
            mergeNode = mergeNode->next;
        }
        else
        {
            std::cout << "N/A - ";
        }

        if (mergeNode)
        {
            std::cout << mergeNode->data << "  ";
            mergeNode = mergeNode->next;
        }
        else
        {
            std::cout << "N/A";
        }

        std::cout << ANSI_COLOR_RESET;
        std::cout << " | ";

        // Print timing information for Selection Sort
        // --------------------------------------------------------------
        std::cout << ANSI_COLOR_RED;
        if (selectionNode)
        {
            std::cout << selectionNode->data << " millis - ";
            selectionNode = selectionNode->next;
        }
        else
        {
            std::cout << "N/A - ";
        }

        if (selectionNode)
        {
            std::cout << selectionNode->data << " - ";
            selectionNode = selectionNode->next;
        }
        else
        {
            std::cout << "N/A - ";
        }

        if (selectionNode)
        {
            std::cout << selectionNode->data << "  ";
            selectionNode = selectionNode->next;
        }
        else
        {
            std::cout << "N/A";
        }
        std::cout << ANSI_COLOR_RESET;
        std::cout << " | ";

        // Print timing information for Heap Sort
        // --------------------------------------------------------------
        std::cout << ANSI_COLOR_GREEN;
        if (heapNode)
        {
            std::cout << heapNode->data << " micros - ";
            heapNode = heapNode->next;
        }
        else
        {
            std::cout << "N/A - ";
        }

        if (heapNode)
        {
            std::cout << heapNode->data << " - ";
            heapNode = heapNode->next;
        }
        else
        {
            std::cout << "N/A - ";
        }

        if (heapNode)
        {
            std::cout << heapNode->data << "  ";
            heapNode = heapNode->next;
        }
        else
        {
            std::cout << "N/A";
        }
        std::cout << ANSI_COLOR_RESET;

        // Elements count
        // --------------------------------------------------------------
        std::cout << " | ";
        if (i == 0)
        {
            std::cout << elements;
        }
        else
        {
            elements += incr;
            std::cout << elements;
        }
        std::cout << std::endl;
    }
}

void csvWriter(int runs, LinkedList *bubbleSortData, LinkedList *insertionSortData, LinkedList *mergeSortData, LinkedList *selectionSortData, LinkedList *heapSortData, int n, int incr)
{
    std::ofstream file;
    file.open("sorts.csv");
    file << "Run No., Bubble Sort Time (ms), Bubble Sort Comparisons, Bubble Sort Assignments, Insertion Sort Time (ms), Insertion Sort Comparisons, Insertion Sort Assignments, Merge Sort Time (µs), Merge Sort Comparisons, Merge Sort Assignments, Selection Sort Time (ms), Selection Sort Comparisons, Selection Sort Assignments, Heap Sort Time (µs), Heap Sort Comparisons, Heap Sort Assignments, No. of elements" << std::endl;

    Node *bubbleNode = bubbleSortData->getHead();
    Node *insertionNode = insertionSortData->getHead();
    Node *mergeNode = mergeSortData->getHead();
    Node *selectionNode = selectionSortData->getHead();
    Node *heapNode = heapSortData->getHead();

    for (int i = 0; i < runs; ++i)
    {
        file << i + 1 << ", ";
        if (bubbleNode)
        {
            file << bubbleNode->data << ", ";
            bubbleNode = bubbleNode->next;
        }

        if (bubbleNode)
        {
            file << bubbleNode->data << ", ";
            bubbleNode = bubbleNode->next;
        }
        else
        {
            file << "N/A, ";
        }

        if (bubbleNode)
        {
            file << bubbleNode->data << ", ";
            bubbleNode = bubbleNode->next;
        }
        else
        {
            file << "N/A, ";
        }

        if (insertionNode)
        {
            file << insertionNode->data << ", ";
            insertionNode = insertionNode->next;
        }
        else
        {
            file << "N/A, ";
        }

        if (insertionNode)
        {
            file << insertionNode->data << ", ";
            insertionNode = insertionNode->next;
        }
        else
        {
            file << "N/A, ";
        }

        if (insertionNode)
        {
            file << insertionNode->data << ", ";
            insertionNode = insertionNode->next;
        }
        else
        {
            file << "N/A, ";
        }

        if (mergeNode)
        {
            file << mergeNode->data << ", ";
           mergeNode = mergeNode->next;
        }
        else
        {
            file << "N/A, ";
        }
        if( mergeNode)
        {
            file << mergeNode->data << ", ";
            mergeNode = mergeNode->next;
        }
        else
        {
            file << "N/A, ";
        }
        if( mergeNode)
        {
            file << mergeNode->data << ", ";
            mergeNode = mergeNode->next;
        }
        else
        {
            file << "N/A, ";
        }
        if( selectionNode)
        {
            file << selectionNode->data << ", ";
            selectionNode = selectionNode->next;
        }
        else
        {
            file << "N/A, ";
        }
        if( selectionNode)
        {
            file << selectionNode->data << ", ";
            selectionNode = selectionNode->next;
        }
        else
        {
            file << "N/A, ";
        }
        if( selectionNode)
        {
            file << selectionNode->data << ", ";
            selectionNode = selectionNode->next;
        }
        else
        {
            file << "N/A, ";
        }
        if( heapNode)
        {
            file << heapNode->data << ", ";
            heapNode = heapNode->next;
        }
        else
        {
            file << "N/A, ";
        }
        if( heapNode)
        {
            file << heapNode->data << ", ";
            heapNode = heapNode->next;
        }
        else
        {
            file << "N/A, ";
        }
        if( heapNode)
        {
            file << heapNode->data << ", ";
            heapNode = heapNode->next;
        }
        else
        {
            file << "N/A, ";
        }
        if (i == 0)
        {
            file << n << std::endl;
        }
        else
        {
            n += incr;
            file << n << std::endl;
        }
    }
    file.close();
    std::cout << ANSI_COLOR_GREEN << "CSV file created successfully." << ANSI_COLOR_RESET << std::endl;
}

void increment1()
{
    int n;
    int min;
    int max;
    LinkedList myList;
    Timer timer;
    std::cout << "Enter the number of elements: ";
    std::cin >> n;
    std::cout << "Enter the minimum value of generated numbers: ";
    std::cin >> min;
    std::cout << "Enter the maximum value of generated numbers: ";
    std::cin >> max;

    // Fill the list with random numbers
    for (int i = 0; i < n; ++i)
    {
        int randomNumber = randomNumGenerator(min, max);
        myList.insert(randomNumber);
    }

    // Print the elements of the list
    std::cout << "Random numbers in the list: ";
    myList.display();

    // Search for a number
    int searchableValue;
    std::cout << "Enter a number to search: ";
    std::cin >> searchableValue;
    int index = sequentialSearch(myList.getHead(), searchableValue, timer);
    if (index != -1)
    {
        std::cout << ANSI_COLOR_GREEN << "The value is found at index " << ANSI_COLOR_RESET << index << std::endl;
    }
    std::cout << "Elapsed time (ms): " << timer.elapsed_time() << std::endl;
    std::cout << "Number of comparisons: " << index << std::endl;
}

void increment2()
{
    int n;
    int min;
    int max;
    LinkedList myList;
    Timer timer;
    std::cout << "Enter the number of elements: ";
    std::cin >> n;
    std::cout << "Enter the minimum value of generated numbers: ";
    std::cin >> min;
    std::cout << "Enter the maximum value of generated numbers: ";
    std::cin >> max;

    // Fill the list with random numbers
    for (int i = 0; i < n; ++i)
    {
        int randomNumber = randomNumGenerator(min, max);
        myList.insert(randomNumber);
    }

    // Print the elements of the unorganized and organized list
    // since binary sort is meant to be used on sorted lists
    std::cout << "Random numbers in the list: ";
    myList.display();
    timer.reset();
    myList.insertionSort();
    std::cout << std::endl;
    std::cout << "Sorted list (insertion sort): ";
    myList.display();

    // Search for a number
    int searchableValue;
    std::cout << "Enter a number to search (binary search): ";
    std::cin >> searchableValue;

    int index = binarySearch(myList.getHead(), searchableValue, timer);
    if (index != -1)
    {
        std::cout << ANSI_COLOR_GREEN << "The value is found at index " << ANSI_COLOR_RESET << index << std::endl;
    }
    std::cout << "Elapsed time (ms): " << timer.elapsed_time() << std::endl;
    std::cout << "Number of comparisons (insertion sort): " << myList.getComparisonCounter() << std::endl;
    std::cout << "Number of assignments (insertion sort): " << myList.getAssignmentCounter() << std::endl;
}

void increment3()
{
    int n;
    int min;
    int max;
    LinkedList myList;
    Timer timer;
    std::cout << "Enter the number of elements: ";
    std::cin >> n;
    std::cout << "Enter the minimum value of generated numbers: ";
    std::cin >> min;
    std::cout << "Enter the maximum value of generated numbers: ";
    std::cin >> max;

    // Fill the list with random numbers
    for (int i = 0; i < n; ++i)
    {
        int randomNumber = randomNumGenerator(min, max);
        myList.insert(randomNumber);
    }

    // Print the elements of the list
    std::cout << "Unsorted list: " << std::endl;
    myList.display();
    std::cout << std::endl;

    timer.reset();
    myList.insertionSort();
    std::cout << "Sorted list: " << std::endl;
    myList.display();
    std::cout << std::endl;
    std::cout << "Time elapsed for sort (ms): " << timer.elapsed_time() << std::endl;
    std::cout << "Comparisons: " << myList.getComparisonCounter() << std::endl;
    std::cout << "Assignments: " << myList.getAssignmentCounter() << std::endl;
}

void increment4()
{
    int n;
    int min;
    int max;
    LinkedList *myList = nullptr;
    myList = new LinkedList();
    Timer timer;
    std::cout << "Enter the number of elements: ";
    std::cin >> n;
    std::cout << "Enter the minimum value of generated numbers: ";
    std::cin >> min;
    std::cout << "Enter the maximum value of generated numbers: ";
    std::cin >> max;

    // Fill the list with random numbers
    for (int i = 0; i < n; ++i)
    {
        int randomNumber = randomNumGenerator(min, max);
        myList->insert(randomNumber);
    }

    // Print the elements of the list
    std::cout << "Unsorted list: " << std::endl;
    myList->display();
    std::cout << std::endl;

    myList->resetCounters();
    timer.reset();
    myList->mergeSort();
    double finished_time = timer.elapsed_time();
    std::cout << "Sorted list (mergesort): " << std::endl;
    myList->display();
    std::cout << std::endl;
    std::cout << "Time elapsed for sort (ms): " << finished_time << std::endl;
    std::cout << "Comparisons: " << myList->getComparisonCounter() << std::endl;
    std::cout << "Assignments: " << myList->getAssignmentCounter() << std::endl;
    delete myList;
}

void increment5()
{
    int n;
    int min, max;
    int runs, totalRuns;
    int incr;
    Timer timer;
    std::cout << "This increment will run all the sorts and compare them" << std::endl
              << "Program will ask for the number of elements, minimum and " << std::endl
              << "maximum value of the elements, and the number of runs. " << std::endl
              << "In addition, program will ask start size of the elements, and " << std::endl
              << " increment the size with user defined value." << std::endl
              << std::endl;

    std::cout << "Enter the number of starting elements: ";
    std::cin >> n;
    std::cout << "Enter the value to increment the elements each run with: ";
    std::cin >> incr;
    std::cout << "Enter the minimum value of generated numbers: ";
    std::cin >> min;
    std::cout << "Enter the maximum value of generated numbers: ";
    std::cin >> max;
    std::cout << "How many runs do you want to do: ";
    std::cin >> runs;
    totalRuns = runs;
    int elements = n; // passable variable that stores original state of n

    // Lists to store the data for each sort - formatting purposes
    LinkedList *bubbleSortData = nullptr;
    LinkedList *insertionSortData = nullptr;
    LinkedList *mergeSortData = nullptr;
    LinkedList *selectionSortData = nullptr;
    LinkedList *heapSortData = nullptr;
    bubbleSortData = new LinkedList();
    insertionSortData = new LinkedList();
    mergeSortData = new LinkedList();
    selectionSortData = new LinkedList();
    heapSortData = new LinkedList();

    while (runs--)
    {
        LinkedList myList;
        Timer timer2;
        myList.deleteList(); // Delete lists data IF there is a existing list

        // increase the list size with each run, is user chooses to increment elements by some value
        if (totalRuns - runs == 1)
        {
            n = n;
        }
        else
        {
            n += incr;
        }
        // Fill the list with random numbers
        for (int i = 0; i < n; ++i)
        {
            int randomNumber = randomNumGenerator(min, max);
            myList.insert(randomNumber);
        }

        LinkedList myList2 = myList; // Copy the unsorted list for the other sorts

        // Bubble sort runs
        timer.reset();
        myList.bubbleSort();
        // std::cout << ANSI_COLOR_BLUE << "Bubblesort No. " << totalRuns - runs << std::endl;
        // std::cout << "Time elapsed for sort (ms): " << timer.elapsed_time() << std::endl;
        // std::cout << "Comparisons: " << myList.getComparisonCounter() << std::endl;
        // std::cout << "Assignments: " << myList.getAssignmentCounter() << std::endl;
        // Formatting- test
        bubbleSortData->insert(timer.elapsed_time());
        bubbleSortData->insert(myList.getComparisonCounter());
        bubbleSortData->insert(myList.getAssignmentCounter());
        myList.resetCounters();
        myList2.resetCounters();
        myList = myList2; // Reset the list to same unsorted state used previously

        // Insertion sort runs
        timer.reset();
        myList.insertionSort();
        // std::cout << ANSI_COLOR_YELLOW << "Insertion sort No. " << totalRuns - runs << std::endl;
        // std::cout << "Time elapsed for sort (ms): " << timer.elapsed_time() << std::endl;
        // std::cout << "Comparisons: " << myList.getComparisonCounter() << std::endl;
        // std::cout << "Assignments: " << myList.getAssignmentCounter() << std::endl;
        // Formatting- test
        insertionSortData->insert(timer.elapsed_time());
        insertionSortData->insert(myList.getComparisonCounter());
        insertionSortData->insert(myList.getAssignmentCounter());
        myList.resetCounters();
        myList2.resetCounters();
        myList = myList2;

        // Merge sort runs
        timer.reset();
        myList.mergeSort();
        // std::cout << ANSI_COLOR_PURPLE << "Merge sort No. " << totalRuns - runs << std::endl;
        // std::cout << "Time elapsed for sort (ms): " << timer.elapsed_time() << std::endl;
        // std::cout << "Comparisons: " << myList.getComparisonCounter() << std::endl;
        // std::cout << "Assignments: " << myList.getAssignmentCounter() << std::endl;
        // Formatting- test
        mergeSortData->insert(timer.elapsed_time() * 1000); // Mergesort is so fast, that i need to display it in µs (ms/1000)
        mergeSortData->insert(myList.getComparisonCounter());
        mergeSortData->insert(myList.getAssignmentCounter());
        myList.resetCounters();
        myList2.resetCounters();
        myList = myList2;

        // Selection sort runs
        timer.reset();
        myList.selectionSort();
        selectionSortData->insert(timer.elapsed_time());
        selectionSortData->insert(myList.getComparisonCounter());
        selectionSortData->insert(myList.getAssignmentCounter());
        myList.resetCounters();
        myList2.resetCounters();
        myList = myList2;

        // Heap Sort runs
        timer.reset();
        myList.heapSort();
        heapSortData->insert(timer.elapsed_time()); // Heapsort is so fast, that i need to display it in µs (ms/1000)
        heapSortData->insert(myList.getComparisonCounter());
        heapSortData->insert(myList.getAssignmentCounter());
        myList.resetCounters();
        myList2.resetCounters();
        myList = myList2;

        std::cout << totalRuns - runs << ". run ready.." << " | Laptime: " << timer2.elapsed_time() << " millis" << std::endl;
    }

    // Function to display the results of each sort in comparable format
    formatter(totalRuns, bubbleSortData, insertionSortData, mergeSortData, selectionSortData, heapSortData, elements, incr);
    csvWriter(totalRuns, bubbleSortData, insertionSortData, mergeSortData, selectionSortData, heapSortData, elements, incr);
    std::cout << ANSI_COLOR_RESET;
    delete bubbleSortData;
    delete insertionSortData;
    delete mergeSortData;
    delete selectionSortData;
    delete heapSortData;
}
