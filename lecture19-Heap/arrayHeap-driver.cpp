//  Created by Frank M. Carrano and Timothy M. Henry.
//  Copyright (c) 2025 Pearson Education, Hoboken, New Jersey.

#include "ArrayMaxHeap.h"
#include <iostream>
//#include <string>

void display(std::string& anItem)
{
   std::cout << "Displaying item - " << anItem << std::endl;
}

int main()
{
   ArrayMaxHeap<std::string>* heap1Ptr = new ArrayMaxHeap<std::string>(); 
   heap1Ptr->add("10");
   heap1Ptr->add("20");
   heap1Ptr->add("30");
   heap1Ptr->add("40");
   heap1Ptr->add("50");
   heap1Ptr->add("60");
   heap1Ptr->add("70");
   heap1Ptr->add("80");   
   //         80
   //      /     \
   //     70     60
   //    /  \   /  \
   //   40  30 20  50
   //  /
   // 10
   
   std::cout << "Heap 1: " << std::endl;
   while (!heap1Ptr->isEmpty())
   {
      std::cout << "# of nodes: " << heap1Ptr->getNumberOfNodes() << std::endl;
      std::cout << "Height: "     << heap1Ptr->getHeight() << std::endl;
      std::cout << "max value: "  << heap1Ptr->peekTop() << std::endl;
      std::cout << "remove: "     << heap1Ptr->remove() << std::endl << std::endl;
   }  // end while

   ArrayMaxHeap<std::string>* heap2Ptr = new ArrayMaxHeap<std::string>();
   heap2Ptr->add("50");
   heap2Ptr->add("30");
   heap2Ptr->add("70");
   heap2Ptr->add("20");
   heap2Ptr->add("60");
   heap2Ptr->add("40");
   heap2Ptr->add("10");
   heap2Ptr->add("80");
   //         80
   //      /     \
   //     70     50
   //    /  \   /  \
   //   60  30 40  10
   //  /
   // 20

   std::cout << "-------------" << std::endl;
   std::cout << "Heap 2: " << std::endl;
   while (!heap2Ptr->isEmpty())
   {
      std::cout << "# of nodes: " << heap2Ptr->getNumberOfNodes() << std::endl;
      std::cout << "Height: "     << heap2Ptr->getHeight() << std::endl;
      std::cout << "max value: "  << heap2Ptr->peekTop() << std::endl;
      std::cout << "remove: "     << heap2Ptr->remove() << std::endl << std::endl;
   }  // end while

   return 0;
}  // end main
/*
 Heap 1:
 # of nodes: 8
 Height: 4
 max value: 80
 remove: 1
 
 # of nodes: 7
 Height: 3
 max value: 70
 remove: 1
 
 # of nodes: 6
 Height: 3
 max value: 60
 remove: 1
 
 # of nodes: 5
 Height: 3
 max value: 50
 remove: 1
 
 # of nodes: 4
 Height: 3
 max value: 40
 remove: 1
 
 # of nodes: 3
 Height: 2
 max value: 30
 remove: 1
 
 # of nodes: 2
 Height: 2
 max value: 20
 remove: 1
 
 # of nodes: 1
 Height: 1
 max value: 10
 remove: 1
 
 -------------
 Heap 2:
 # of nodes: 8
 Height: 4
 max value: 80
 remove: 1
 
 # of nodes: 7
 Height: 3
 max value: 70
 remove: 1
 
 # of nodes: 6
 Height: 3
 max value: 60
 remove: 1
 
 # of nodes: 5
 Height: 3
 max value: 50
 remove: 1
 
 # of nodes: 4
 Height: 3
 max value: 40
 remove: 1
 
 # of nodes: 3
 Height: 2
 max value: 30
 remove: 1
 
 # of nodes: 2
 Height: 2
 max value: 20
 remove: 1
 
 # of nodes: 1
 Height: 1
 max value: 10
 remove: 1

*/
