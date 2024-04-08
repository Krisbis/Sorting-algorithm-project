#pragma once
#include "TIMER.H"

struct Node {
    int data = 0;
    Node* next; // Pointer to the next node
    Node* prev; // Pointer to the previous node
};

class LinkedList {
    private:
        Node* head; // Pointer to the first node
        Node* tail; // Pointer to the last node
        int comparisonCounter = 0;
        int assignmentCounter = 0;
    public:
        LinkedList(); // Constructor
        ~LinkedList(); // Destructor
        Node* getHead() { return head; } // Getter for head
        void insert(int data); // Insert a new node
        void remove(int data); // Remove a node
        void deleteList(); // Delete the linked list
        void display(); // Display the linked list
        bool search(int data); // Search for a node
        void insertionSort(); // Sort the linked list
        int getComparisonCounter() { return comparisonCounter; } // Getter for comparisonCounter
        int getAssignmentCounter() { return assignmentCounter; } // Getter for assignmentCounter
        void resetCounters(); // Reset the counters
        void splitList(Node* head, Node** front, Node** back);
        Node* mergeSortedLists(Node* a, Node* b);
        void mergeSort(Node** headRef);
        void mergeSort();
        void bubbleSort();
        void selectionSort();
        void heapSort();
        void heapify(Node* parent);

};