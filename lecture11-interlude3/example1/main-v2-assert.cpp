//  Created by Frank M. Carrano and Timothy M. Henry.
//  Copyright (c) 2017 Pearson Education, Hoboken, New Jersey.

#include <cassert>
#include <string>
#include <iostream>
#include "PlainBox.h"

using namespace std;

PlainBox<string> findBox(PlainBox<std::string> boxes[], int size, std::string target)
{
   int index = 0;
   bool found = false;
   while (!found && (index < size))
   {
     found = (target == boxes[index].getItem());
     if(!found)
        index++;
   } // end while
   assert(found);     // Verify that there is a box to return
   return boxes[index];
} // end findBox


int main()
{
   // Listing C3-4
   // Create and initialize an array of boxes
  PlainBox< string> myBoxes[5]; // Array of PlainBox objects
   myBoxes[0] = PlainBox< string>("ring");
   myBoxes[1] = PlainBox< string>("hat");
   myBoxes[2] = PlainBox< string>("shirt");
   myBoxes[3] = PlainBox< string>("sock");
   myBoxes[4] = PlainBox< string>("shoe");
   PlainBox< string> foundBox;
   

   foundBox = findBox(myBoxes, 5, "glasses");
   

   cout << foundBox.getItem();
   
   return 0;
}

