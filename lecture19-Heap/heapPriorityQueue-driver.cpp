//  Created by Frank M. Carrano and Timothy M. Henry.
//  Copyright (c) 2025 Pearson Education, Hoboken, New Jersey.

#include "Heap_PriorityQueue.h" // ADT Priority Queue operations
#include <iostream>
#include <string>

void pqTester(PriorityQueueInterface<std::string>* pqPtr)
{
   std::string items[] = {"one", "two", "three", "four", "five", "six"};
   std::cout << "Empty: " << pqPtr->isEmpty() << std::endl;

   for (int i = 0; i < 6; i++)
   {
      std::cout << "Adding " << items[i] << std::endl;
      bool success = pqPtr->enqueue(items[i]);
      if (!success)
         std::cout << "Failed to add " << items[i] << " to the priority queue." << std::endl;
   }

   std::cout << "Empty?: " << pqPtr->isEmpty() << std::endl;

   for (int i = 0; i < 6; i++)
   {
      std::cout << "Loop " << i << std::endl;

      try
      {
         std::cout << "peek: " << pqPtr->peek() << std::endl;
      }
      catch (const PrecondViolatedExcept& e)
      {
         std::cout << e.what() << std::endl;
      }

      std::cout << "Empty: " << pqPtr->isEmpty() << std::endl;
      std::cout << "Remove: " << pqPtr->dequeue() << std::endl;
   }

   std::cout << "remove with an empty priority queue: " << std::endl;
   std::cout << "Empty: " << pqPtr->isEmpty() << std::endl;
   std::cout << "Remove: " << pqPtr->dequeue() << std::endl;

   try
   {
      std::cout << "peek with an empty priority queue: " << std::endl;
      std::cout << "peek: " << pqPtr->peek() << std::endl;
   }
   catch (const PrecondViolatedExcept& e)
   {
      std::cout << e.what();
   }
}

int main()
{
   PriorityQueueInterface<std::string>* pqPtr = new Heap_PriorityQueue<std::string>();
   std::cout << "Testing the priority queue:" << std::endl;
   pqTester(pqPtr);
   delete pqPtr;
   return 0;
}
