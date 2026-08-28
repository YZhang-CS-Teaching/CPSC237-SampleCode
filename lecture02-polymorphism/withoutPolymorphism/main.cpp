//  Created by Frank M. Carrano and Timothy M. Henry.
//  Copyright (c) 2017 Pearson Education, Hoboken, New Jersey.

// Section C2.2

#include <iostream>
#include <string>
#include "PlainBox.h"
#include "MagicBox.h"


void placeInBox(PlainBox<std::string>& theBox, std::string theItem)
{
   theBox.setItem(theItem);
} // end placeInBox


int main()
{
  std::string firstItem = "first item";
  std::string secondItem = "second item";
   
   PlainBox<std::string> myPlainBox;
   placeInBox(myPlainBox, firstItem);
   placeInBox(myPlainBox, secondItem);
   std::cout << myPlainBox.getItem() << std::endl; 
   
   MagicBox<std::string> myMagicBox;
   placeInBox(myMagicBox, firstItem);
   placeInBox(myMagicBox, secondItem); 
   
   std::cout << myMagicBox.getItem() << std::endl; 
   
   
   return 0;
}  // end main


