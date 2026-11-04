//  Created by Frank M. Carrano and Timothy M. Henry.
//  Copyright (c) 2025 Pearson Education, Hoboken, New Jersey.

 /** Heap-based implementation of the ADT priority queue.
  @file Heap_PriorityQueue.cpp */

#include "Heap_PriorityQueue.h"

template<class ItemType>
Heap_PriorityQueue<ItemType>::Heap_PriorityQueue()
{
   ArrayMaxHeap<ItemType>();
}  // end constructor

template<class ItemType>
bool Heap_PriorityQueue<ItemType>::isEmpty() const noexcept
{
   return ArrayMaxHeap<ItemType>::isEmpty();
}  // end isEmpty

template<class ItemType>
bool Heap_PriorityQueue<ItemType>::enqueue(const ItemType& newEntry)
{
   return ArrayMaxHeap<ItemType>::add(newEntry);
}  // end add

template<class ItemType>
bool Heap_PriorityQueue<ItemType>::dequeue()
{
   return ArrayMaxHeap<ItemType>::remove();
}  // end remove

template<class ItemType>
ItemType Heap_PriorityQueue<ItemType>::peek() const
{
   try
   {
      return ArrayMaxHeap<ItemType>::peekTop();
   }
   catch (PrecondViolatedExcept e)
   {
      throw PrecondViolatedExcept("Attempted peek into an empty priority queue.");
   }  // end try/catch
}  // end peek
