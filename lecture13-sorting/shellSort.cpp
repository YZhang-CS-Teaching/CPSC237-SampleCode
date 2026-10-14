//  Created by Frank M. Carrano and Tim Henry.
//  Copyright (c) 2016 __Pearson Education__. All rights reserved.

// for Programming Problem 8.

#include <iostream>
#include <string>

template<class ItemType>
void shellSort(ItemType theArray[], int n)
{
   for (int h = n / 2; h > 0; h = h / 2)
   {
      for (int unsorted = h; unsorted < n; unsorted++)
      {
         ItemType nextItem = theArray[unsorted];
         int loc = unsorted;
         while ( (loc >= h) && (theArray[loc - h] > nextItem) )
         {
            theArray[loc] = theArray[loc - h];
            loc = loc - h;
         } // end while
         theArray[loc] = nextItem;
      }  // end for
   }  // end for
}  // end shellSort

int main()
{
   std::string a[6] = {"Z", "X", "R", "K", "F", "B"};
   shellSort(a, 6);
   for (int i = 0; i < 6; i++)
      std::cout << a[i] << " ";
   std::cout << std::endl;
   
   std::string b[26] = {"Z", "Y", "X", "W", "V", "U", "T", "S", "R", "Q", "P", "O", "N", "M", "L", "K", "J", "I", "H", "G", "F", "E", "D", "C", "B", "A"};
   shellSort(b, 26);
   for (int i = 0; i < 26; i++)
      std::cout << b[i] << " ";
   std::cout << std::endl;
}  // end main

/*
 
 B F K R X Z
 A B C D E F G H I J K L M N O P Q R S T U V W X Y Z
 
 */