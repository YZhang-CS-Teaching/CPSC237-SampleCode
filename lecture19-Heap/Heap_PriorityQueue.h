//  Created by Frank M. Carrano and Timothy M. Henry.
//  Copyright (c) 2025 Pearson Education, Hoboken, New Jersey.

/** ADT priority queue: Heap-based implementation.
 @file Heap_PriorityQueue.h */

#ifndef _HEAP_PRIORITY_QUEUE
#define _HEAP_PRIORITY_QUEUE

#include "ArrayMaxHeap.h"
#include "PriorityQueueInterface.h"

template<class ItemType>
class Heap_PriorityQueue : public PriorityQueueInterface<ItemType>,
                              private ArrayMaxHeap<ItemType>
{
public:
   Heap_PriorityQueue();
   bool isEmpty() const noexcept;
   bool enqueue(const ItemType& newEntry);
   bool dequeue();
   
   /** @pre The priority queue is not empty. */
   ItemType peek() const;
}; // end Heap_PriorityQueue

#include "Heap_PriorityQueue.cpp"
#endif
