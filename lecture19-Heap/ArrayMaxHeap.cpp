//  Created by Frank M. Carrano and Timothy M. Henry.
//  Copyright (c) 2025 Pearson Education, Hoboken, New Jersey.

/** Array-based implementation of the ADT heap.
 @file ArrayMaxHeap.cpp */ 
 
#include <cmath> // for log2
#include "ArrayMaxHeap.h"
#include "PrecondViolatedExcept.h"

template<class ItemType>
int ArrayMaxHeap<ItemType>::getLeftChildIndex(const int nodeIndex) const
{
   return (2 * nodeIndex) + 1;
}  // end getLeftChildIndex

template<class ItemType>
int ArrayMaxHeap<ItemType>::getRightChildIndex(const int nodeIndex) const
{
   return (2 * nodeIndex) + 2;
}  // end getRightChildIndex

template<class ItemType>
int ArrayMaxHeap<ItemType>::getParentIndex(const int nodeIndex) const
{
   return (nodeIndex - 1) / 2;
}  // end getParentIndex

template<class ItemType>
bool ArrayMaxHeap<ItemType>::isLeaf(const int nodeIndex) const
{
   return (getLeftChildIndex(nodeIndex) >= itemCount);
}  // end isLeaf

template<class ItemType>
void ArrayMaxHeap<ItemType>::heapRebuild(const int subTreeNodeIndex)
{
   if (!isLeaf(subTreeNodeIndex))
   {
      // Find larger child
      int leftChildIndex = getLeftChildIndex(subTreeNodeIndex);
      int rightChildIndex = getRightChildIndex(subTreeNodeIndex);
      int largerChildIndex = rightChildIndex; // make assumption
      
      // Check to see if has rightChild and then check if left is larger
      if ( (largerChildIndex >= itemCount) || (items[leftChildIndex] > items[rightChildIndex]))
      {
         largerChildIndex = leftChildIndex; // Asssumption was wrong
      }  // end if
      
      // Swap with larger child if node value is smaller
      if (items[largerChildIndex] > items[subTreeNodeIndex])
      {
         swap(items[largerChildIndex], items[subTreeNodeIndex]);
         
         // Continue with the recursion at that child
         heapRebuild(largerChildIndex);
      }  // end if
   }  // end if
}  // end heapRebuild


template<class ItemType>
void ArrayMaxHeap<ItemType>::heapCreate()
{
   for (int index = itemCount / 2 - 1; index >= 0; index--)
   {
      heapRebuild(index);  
   }  // end for
}  // end heapCreate

//******************************************************************
// 
// Public methods start here
//
//******************************************************************

template<class ItemType>
ArrayMaxHeap<ItemType>::ArrayMaxHeap(): itemCount(0), maxItems(DEFAULT_CAPACITY)
{  
   items = std::make_unique<ItemType[]>(DEFAULT_CAPACITY);
}  // end default constructor

template<class ItemType>
ArrayMaxHeap<ItemType>::ArrayMaxHeap(const ItemType someArray[], const int arraySize):
             itemCount(arraySize), maxItems(2 * arraySize)
{
   // Allocate the array
   items = std::make_unique<ItemType[]>(2 * arraySize);

   
   // Copy given values into the array
   for (int i = 0; i < itemCount; i++)
      items[i] = someArray[i];
   
   // Reorganize the array into a heap
   heapCreate();
} // end constructor

template<class ItemType>
ArrayMaxHeap<ItemType>::~ArrayMaxHeap()
{  
   items.reset();
}  // end destructor

template<class ItemType>
bool ArrayMaxHeap<ItemType>::isEmpty() const noexcept
{
   return itemCount == 0;
}  // end isEmpty

template<class ItemType>
int ArrayMaxHeap<ItemType>::getHeight() const noexcept
{
   return ceil(log2(itemCount + 1));
}  // end getHeight

template<class ItemType>
int ArrayMaxHeap<ItemType>::getNumberOfNodes() const noexcept
{
   return itemCount;
}  // end getNumberOfNodes

template<class ItemType>
void ArrayMaxHeap<ItemType>::clear() noexcept
{
   itemCount = 0;
}  // end clear

template<class ItemType>
ItemType ArrayMaxHeap<ItemType>::peekTop() const
{
   if (isEmpty())
      throw PrecondViolatedExcept("Attempted peek into an empty heap.");
   
   return items[0];
} // end peekTop

template<class ItemType>
bool ArrayMaxHeap<ItemType>::add(const ItemType& newData)
{
   bool isSuccessful = false;
   if (itemCount < maxItems)
   {
      items[itemCount] = newData;

      bool inPlace = false;
      int newDataIndex = itemCount;
      while ((newDataIndex > 0) && !inPlace)
      {
         int parentIndex = getParentIndex(newDataIndex);
         if (items[newDataIndex] < items[parentIndex]) 
         {
            inPlace = true;
         }
         else
         {
            swap(items[newDataIndex], items[parentIndex]);
            newDataIndex = parentIndex;
         }  // end if
      }  // end while

      itemCount++;
      isSuccessful = true;
   }  // end if
  
   return isSuccessful;
}  // end add

template<class ItemType>
bool ArrayMaxHeap<ItemType>::remove()
{
   bool isSuccessful = false;
   if (!isEmpty()) 
   {
      items[ROOT_INDEX] = items[itemCount - 1];
      itemCount--;
      heapRebuild(ROOT_INDEX);
      isSuccessful = true;
   }  // end if
   
   return isSuccessful;
}  // end remove


