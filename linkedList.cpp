#include "linkedList.h"
#include <iostream>

LinkedList::LinkedList() : head(nullptr), tail(nullptr) {}

LinkedList::~LinkedList()
{
    // Node *current = head;
    // while (current)
    // {
    //     Node *temp = current;
    //     current = current->next;
    //     delete temp;
    // }
    // // Set head to nullptr to indicate that the list is empty
    // head = nullptr;
}

void LinkedList::insert(int data)
{
    Node *newNode = new Node;
    newNode->data = data;
    newNode->next = nullptr;

    if (head == nullptr)
    {
        head = newNode;
        tail = newNode;
    }
    else
    {
        tail->next = newNode;
        tail = newNode;
    }
}

void LinkedList::remove(int data)
{
    Node *current = head;
    Node *previous = nullptr;

    while (current != nullptr)
    {
        if (current->data == data)
        {
            if (previous == nullptr)
            {
                head = current->next;
            }
            else
            {
                previous->next = current->next;
            }
            delete current;
            return;
        }
        previous = current;
        current = current->next;
    }
}

void LinkedList::deleteList()
{
    Node *current = head;
    Node *next = nullptr;

    while (current != nullptr)
    {
        next = current->next;
        delete current;
        current = next;
    }

    head = nullptr;
    tail = nullptr;
}

void LinkedList::display()
{
    Node *temp = head;
    while (temp != nullptr)
    {
        std::cout << temp->data << " ";
        temp = temp->next;
    }
    std::cout << std::endl;
}

bool LinkedList::search(int data)
{
    return false;
}

void LinkedList::insertionSort()
{
    Node *first_unsorted, //  the first unsorted node to be inserted
        *last_sorted,     //  tail of the sorted sublist
        *current,         //  used to traverse the sorted sublist
        *trailing;        //  one position behind current

    if (head != NULL)
    {                       //  Otherwise, the empty list is already sorted.
        last_sorted = head; //  The first node alone makes a sorted sublist.
        while (last_sorted->next != NULL)
        {
            first_unsorted = last_sorted->next;
            if (first_unsorted->data < head->data)
            {
                //  Insert *first_unsorted at the head of the sorted list:
                last_sorted->next = first_unsorted->next;
                first_unsorted->next = head;
                head = first_unsorted;
                assignmentCounter += 3;
            }
            else
            {
                //  Search the sorted sublist to insert *first_unsorted:
                trailing = head;
                current = trailing->next;
                while (first_unsorted->data > current->data)
                {
                    comparisonCounter++;
                    assignmentCounter++;
                    trailing = current;
                    current = trailing->next;
                }

                //  *first_unsorted now belongs between *trailing and *current.

                if (first_unsorted == current)

                    last_sorted = first_unsorted; //  already in right position
                else
                {
                    last_sorted->next = first_unsorted->next;
                    first_unsorted->next = current;
                    trailing->next = first_unsorted;
                    assignmentCounter += 3;
                }
            }
        }
    }
}

void LinkedList::resetCounters()
{
    comparisonCounter = 0;
    assignmentCounter = 0;
}

void LinkedList::splitList(Node *head, Node **front, Node **back)
{
    Node *slow = head;
    Node *fast = head->next;

    // Advance 'fast' two nodes, and advance 'slow' one node
    while (fast != nullptr)
    {
        comparisonCounter++; // Increment comparison counter for each iteration of the loop
        fast = fast->next;
        if (fast != nullptr)
        {
            slow = slow->next;
            fast = fast->next;
        }
    }

    // 'slow' is before the midpoint in the list
    // Split the list into two halves at the midpoint
    *front = head;
    *back = slow->next;
    slow->next = nullptr;   // Break the link between the two halves
    assignmentCounter += 3; // Counting assignments
}

Node *LinkedList::mergeSortedLists(Node *a, Node *b)
{
    Node *result = nullptr;

    // Base cases
    if (a == nullptr)
        return b;
    else if (b == nullptr)
        return a;

    // Recursively merge two sorted lists
    if (a->data <= b->data)
    {
        result = a;
        result->next = mergeSortedLists(a->next, b);
    }
    else
    {
        result = b;
        result->next = mergeSortedLists(a, b->next);
    }
    assignmentCounter += 2; // Counting assignments
    comparisonCounter++;    // Increment comparison counter

    return result;
}

void LinkedList::mergeSort(Node **headRef)
{
    Node *head = *headRef;
    Node *a;
    Node *b;

    // Base case: If the list is empty or has only one node, it is already sorted
    if (head == nullptr || head->next == nullptr)
        return;

    // Split the list into two halves
    splitList(head, &a, &b);

    // Recursively sort the two halves
    mergeSort(&a);
    mergeSort(&b);

    // Merge the sorted halves
    *headRef = mergeSortedLists(a, b);
    assignmentCounter++; // Counting assignment
    comparisonCounter++; // Increment comparison counter
}

// Public wrapper function for mergeSort
void LinkedList::mergeSort()
{
    mergeSort(&head);
}

void LinkedList::bubbleSort()
{
    Node *current = head;
    while (current != nullptr)
    {
        comparisonCounter++; // Increment comparison counter for each iteration of the outer loop
        Node *nextNode = head;
        while (nextNode->next != nullptr)
        {
            if (nextNode->data > nextNode->next->data)
            {
                // Swap data
                int temp = nextNode->data;
                nextNode->data = nextNode->next->data;
                nextNode->next->data = temp;
                assignmentCounter += 3; // Counting assignments
                comparisonCounter++;    // Increment comparison counter for each swap
            }
            nextNode = nextNode->next;
        }
        current = current->next;
    }
}

void LinkedList::selectionSort()
{
    Node *current = head;
    while (current != nullptr)
    {
        Node *min = current;
        Node *nextNode = current->next;

        while (nextNode != nullptr)
        {
            comparisonCounter++; // Increment comparison counter only for inner loop
            if (nextNode->data < min->data)
            {
                min = nextNode;
            }
            nextNode = nextNode->next;
        }

        // Swap data between current and min
        int temp = current->data;
        current->data = min->data;
        min->data = temp;
        assignmentCounter += 3; // Counting assignments for swap
        current = current->next;
    }
}

void LinkedList::heapSort() {
    // Build the max-heap
    for (Node *current = tail; current != nullptr; current = current->prev) {
        heapify(current); // Maintain max-heap property for each node
    }

    Node *lastHeapNode = tail; // Keep track of the last node in the heap

    // Extract elements one by one
    while (lastHeapNode != nullptr) {
        // Swap root (head) with the last element
        int temp = head->data;
        head->data = lastHeapNode->data;
        lastHeapNode->data = temp;
        assignmentCounter += 3; // Counting assignments for swap

        // Reduce the heap size
        lastHeapNode = lastHeapNode->prev;

        // Heapify the reduced heap (excluding the last swapped element)
        if (head != nullptr && head != lastHeapNode) {
            heapify(head);
        }
    }
}



// Heapify function to maintain max-heap property
void LinkedList::heapify(Node *parent)
{
    Node *left = parent->next;
    Node *right = left ? left->next : nullptr;
    Node *largest = parent;

    // Find the largest element among parent, left child, and right child
    comparisonCounter++; // Comparing parent with left child
    if (left && left->data > parent->data)
    {
        largest = left;
    }
    comparisonCounter++; // Comparing parent (or left) with right child
    if (right && right->data > largest->data)
    {
        largest = right;
    }

    // If largest is not the parent, swap and recursively heapify the subtree
    if (largest != parent)
    {
        int temp = parent->data;
        parent->data = largest->data;
        largest->data = temp;
        assignmentCounter += 3; // Counting assignments for swap
        heapify(largest);
    }
}