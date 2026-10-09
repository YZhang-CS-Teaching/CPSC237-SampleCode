
#include <iostream>
#include <string>
#include <iomanip>
#include "LinkedStack.h"

using namespace std;

// Test the copy constructor
void copyConstructorTester()
{
    cout << "\n========== Testing Copy Constructor ==========\n";

    LinkedStack<string> stack;

    string items[] = {"zero", "one", "two",
                      "three", "four", "five"};

    cout << "\n1. Pushing items onto the original stack\n";

    for (int i = 0; i < 6; i++)
    {
        bool success = stack.push(items[i]);

        cout << "   Push " << left << setw(8) << items[i]
             << (success ? "Success" : "Failed")
             << endl;
    }

    // Create a copy of the stack
    LinkedStack<string> copyOfStack(stack);

    cout << "\n2. Removing items from the copied stack\n";
    cout << "   Top to bottom: ";

    while (!copyOfStack.isEmpty())
    {
        cout << copyOfStack.peek() << " ";
        copyOfStack.pop();
    }

    cout << endl;

    // The original stack should remain unchanged
    cout << "\n3. Checking the original stack\n";
    cout << "   Top to bottom: ";

    while (!stack.isEmpty())
    {
        cout << stack.peek() << " ";
        stack.pop();
    }

    cout << endl;

    cout << "\n========== Copy Constructor Test Complete ==========\n";
}

// Test basic stack operations
void stackTester()
{
    cout << "\n========== Testing Link-Based Stack ==========\n";

    StackInterface<string>* stackPtr = new LinkedStack<string>();

    string items[] = {"zero", "one", "two",
                      "three", "four", "five"};

    // Test empty stack
    cout << "\n1. Testing an empty stack\n";
    cout << "   Is empty? "
         << (stackPtr->isEmpty() ? "Yes" : "No") << endl;

    // Test push()
    cout << "\n2. Testing push()\n";

    for (int i = 0; i < 6; i++)
    {
        bool success = stackPtr->push(items[i]);

        cout << "   Push " << left << setw(8) << items[i]
             << (success ? "Success" : "Failed")
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

    // Test empty stack again
    cout << "\n4. Testing an empty stack again\n";

    cout << "   Is empty? "
         << (stackPtr->isEmpty() ? "Yes" : "No") << endl;

    cout << "   Pop from empty stack: "
         << (stackPtr->pop() ? "Success" : "Failed")
         << endl;

    // Do not call peek() on an empty stack.
    // It would trigger an assertion failure.

    delete stackPtr;

    cout << "\n========== Stack Test Complete ==========\n";
}

int main()
{
    copyConstructorTester();
    stackTester();

    return 0;
}
