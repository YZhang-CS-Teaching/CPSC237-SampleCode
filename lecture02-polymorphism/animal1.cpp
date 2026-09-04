#include <iostream>
using namespace std;

class Animal {
public:
    void speak() {
        cout << "Animal speaks" << endl;
    }
};

class Dog : public Animal {
public:
    void speak() {
        cout << "Dog barks" << endl;
    }
};

int main()
{
    //create a dog object in stack
    Dog d1;
    d1.speak();

    //create a dog object in heap, use a dog pointer
    Dog* d2 = new Dog();
    d2 -> speak();

    //create a dog object in heap, use an animal pointer
    Animal* a1 = new Dog();
    a1 -> speak();

}