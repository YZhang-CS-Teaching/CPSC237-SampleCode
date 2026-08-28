//  Created by Frank M. Carrano and Timothy M. Henry.
//  Copyright (c) 2017 Pearson Education, Hoboken, New Jersey.

// Section C2.4

#include <iostream>
#include <string>
#include "PlainBox.h"
#include "MagicBox.h"

void placeInBox(PlainBox<std::string>* theBox, std::string theItem)
{
   theBox->setItem(theItem);
} // end placeInBox

int main()
{
  std::string firstItem = "first item";
  std::string secondItem = "second item";
   
  PlainBox<std::string>* myPlainBoxPtr = new PlainBox<std::string>();
  placeInBox(myPlainBoxPtr, firstItem);
  placeInBox(myPlainBoxPtr, secondItem);
  std::cout << myPlainBoxPtr->getItem() << std::endl;

   
  MagicBox<std::string>* myMagicBoxPtr = new MagicBox<std::string>();
  placeInBox(myMagicBoxPtr, firstItem);
  placeInBox(myMagicBoxPtr, secondItem);

  std::cout << myMagicBoxPtr->getItem() << std::endl;

   
   delete myPlainBoxPtr;
   myPlainBoxPtr = nullptr;
   delete myMagicBoxPtr;
   myMagicBoxPtr = nullptr;     
   
   return 0;
}  // end main


