#include <iostream>
using namespace std;

class Animal {
public:
    virtual void speak() {
        cout << "Animal speaks" << endl;
    }
};

class Dog : public Animal {
public:
    void speak() override {
        cout << "Dog barks" << endl;
    }
};

class Cat : public Animal {
public:
    void speak() override {
        cout << "Cat meows" << endl;
    }
};

int main()
{
    // Animal pointer pointing to a Dog object
    Animal* a1 = new Dog();
    a1->speak();

    // Animal pointer pointing to a Cat object
    Animal* a2 = new Cat();
    a2->speak();

    delete a1;
    delete a2;

    return 0;
}