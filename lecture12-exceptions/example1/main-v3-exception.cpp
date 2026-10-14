//  Created by Frank M. Carrano and Timothy M. Henry.
//  Copyright (c) 2017 Pearson Education, Hoboken, New Jersey.

#include <exception>
#include <string>
#include <iostream>
#include "PlainBox.h"

using namespace std;

// Listing C3-3
PlainBox<string> findBox(PlainBox<string> boxes[], int size,
                          string target) 
{
   int index = 0;
   bool found = false;
   while (!found && (index < size))
   {
      found = (target == boxes[index].getItem());
      if(!found)
         index++;
   }  // end while
   
   if (!found)
      throw  logic_error("Target not found in a box!");
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
   
   // Try to find a box containing glasses
   try
   {
      foundBox = findBox(myBoxes, 5, "glasses");
      
   }
   catch( logic_error logErr)
   {
      cout << logErr.what() <<  endl;          // Display error message to user
      foundBox = PlainBox<string>("nothing"); // Fix problem
   } // end try-catch
     // Because we catch the exception and fix the problem, the following
     // statement should work even if the target is not found
   cout << foundBox.getItem()<< endl;

   return 0;
}

