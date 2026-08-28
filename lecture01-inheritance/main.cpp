#include <iostream>
#include <string>
#include "PlainBox.h"
#include "ToyBox.h"
#include "MagicBox.h"

using namespace std;

int main()
{
   // Test PlainBox
   cout << "=== PlainBox Tests ===" << endl;

   PlainBox<int> intBox;
   intBox.setItem(42);
   cout << "PlainBox<int> item: " << intBox.getItem() << endl;

   PlainBox<string> strBox("Hello");
   cout << "PlainBox<string> item: " << strBox.getItem() << endl;

   strBox.setItem("World");
   cout << "After setItem: " << strBox.getItem() << endl;

   // Test ToyBox
   cout << "\n=== ToyBox Tests ===" << endl;

   ToyBox<string> defaultToy;
   cout << "Default ToyBox color: " << defaultToy.getColor() << endl;

   ToyBox<string> redToy(RED);
   cout << "Red ToyBox color: " << redToy.getColor() << endl;

   ToyBox<string> fullToy("Teddy Bear", BLUE);
   cout << "Full ToyBox item: " << fullToy.getItem()
        << ", color: " << fullToy.getColor() << endl;

   // Test MagicBox
   cout << "\n=== MagicBox Tests ===" << endl;

   MagicBox<string> magic1;
   magic1.setItem("First");
   cout << "MagicBox after first setItem: " << magic1.getItem() << endl;

   magic1.setItem("Second");
   cout << "MagicBox after second setItem (should still be First): "
        << magic1.getItem() << endl;

   MagicBox<int> magic2(100);
   cout << "MagicBox<int> initial item: " << magic2.getItem() << endl;

   magic2.setItem(200);
   cout << "MagicBox<int> after setItem (should still be 100): "
        << magic2.getItem() << endl;

   return 0;
}
