
#include <iostream>
#include <string>
#include <iomanip>
#include "ArrayStack.h"

using namespace std;

void stackTester(StackInterface<string>* stackPtr)
{
    string items[] = {"zero", "one", "two",
                      "three", "four", "five"};

    cout << "\n1. Testing an empty stack\n";
    cout << "   Is empty? "
         << (stackPtr->isEmpty() ? "Yes" : "No") << endl;

    // Test push()
    cout << "\n2. Testing push()\n";

    for (int i = 0; i < 6; i++)
    {
        bool success = stackPtr->push(items[i]);

        cout << "   Push " << left << setw(8) << items[i]
             << (success ? "Success" : "Failed (stack full)")
             << endl;
    }

    cout << "\n   Is empty? "
         << (stackPtr->isEmpty() ? "Yes" : "No") << endl;

    // Test peek() and pop()
    cout << "\n3. Testing peek() and pop()\n";

    while (!stackPtr->isEmpty())
    {
        string top = stackPtr->peek();
        bool success = stackPtr->pop();

        cout << "   Top: " << left << setw(8) << top
             << "Pop: " << (success ? "Success" : "Failed")
             << endl;
    }

    // Test operations on an empty stack
    cout << "\n4. Testing an empty stack again\n";

    cout << "   Is empty? "
         << (stackPtr->isEmpty() ? "Yes" : "No") << endl;

    cout << "   Pop from empty stack: "
         << (stackPtr->pop() ? "Success" : "Failed")
         << endl;

    // Do not call peek() on an empty stack.
    // It would trigger an assertion failure.
}

int main()
{
    cout << "========== Array-Based Stack Test ==========\n";

    StackInterface<string>* stackPtr = new ArrayStack<string>();

    stackTester(stackPtr);

    delete stackPtr;

    cout << "\n========== Testing Complete ==========\n";

    return 0;
}
