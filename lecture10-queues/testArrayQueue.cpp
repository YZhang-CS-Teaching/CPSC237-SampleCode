
#include <iostream>
#include <string>
#include <iomanip>
#include "ArrayQueue.h"

using namespace std;

void queueTester(QueueInterface<string>* queuePtr)
{
    string items[] = {"one", "two", "three",
                      "four", "five", "six"};

    // Test 1: Empty queue
    cout << "\n1. Testing an empty queue\n";
    cout << "   Is empty? "
         << (queuePtr->isEmpty() ? "Yes" : "No") << endl;

    // Test 2: Enqueue
    cout << "\n2. Testing enqueue()\n";

    for (int i = 0; i < 6; i++)
    {
        bool success = queuePtr->enqueue(items[i]);

        cout << "   Enqueue " << left << setw(8) << items[i]
             << (success ? "Success" : "Failed (queue full)")
             << endl;
    }

    cout << "\n   Is empty? "
         << (queuePtr->isEmpty() ? "Yes" : "No") << endl;

    // Test 3: Peek and dequeue
    cout << "\n3. Testing peekFront() and dequeue()\n";

    while (!queuePtr->isEmpty())
    {
        string front = queuePtr->peekFront();
        bool success = queuePtr->dequeue();

        cout << "   Front: " << left << setw(8) << front
             << "Dequeue: "
             << (success ? "Success" : "Failed")
             << endl;
    }

    // Test 4: Empty queue again
    cout << "\n4. Testing an empty queue again\n";

    cout << "   Is empty? "
         << (queuePtr->isEmpty() ? "Yes" : "No") << endl;

    cout << "   Dequeue from empty queue: "
         << (queuePtr->dequeue() ? "Success" : "Failed")
         << endl;

    // Do not call peekFront() on an empty queue.
}

int main()
{
    cout << "========== Testing Array-Based Queue ==========\n";

    ArrayQueue<string> queue;
    queueTester(&queue);

    cout << "\n========== Testing Complete ==========\n";

    return 0;
}
