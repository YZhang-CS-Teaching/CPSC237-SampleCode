//  Created by Frank M. Carrano and Timothy M. Henry.
//  Copyright (c) 2025 Pearson Education, Hoboken, New Jersey.

#include <iostream>
#include <string>

using namespace std;
typedef string ItemType;

int getLeftChildIndex(int nodeIndex)
{
   return (2 * nodeIndex) + 1;
}  // end getLeftChildIndex

int getRightChildIndex(int nodeIndex)
{
   return (2 * nodeIndex) + 2;
}  // end getRightChildIndex

int getParentIndex(int nodeIndex)
{
   return (nodeIndex - 1) / 2;
}  // end getParentIndex

bool isLeaf(const int nodeIndex, int itemCount)
{
   return (getLeftChildIndex(nodeIndex) >= itemCount);
}  // end isLeaf

void heapRebuild(const int subTreeNodeIndex, ItemType items[], int itemCount)
{
   if (!isLeaf(subTreeNodeIndex, itemCount))
   {
      // Find larger child
      int leftChildIndex = getLeftChildIndex(subTreeNodeIndex);   // A left child must exist
      int largerChildIndex = leftChildIndex;                      // Make assumption about larger child
      int rightChildIndex = getRightChildIndex(subTreeNodeIndex); // A right child might not exist
      
      // Check to see whether a right child exists
      if (rightChildIndex < itemCount)
      {
         // A right child exists; check whether it is larger
         if (items[rightChildIndex] > items[largerChildIndex])
            largerChildIndex = rightChildIndex; // Asssumption was wrong
      }  // end if
      
      // If root value is smaller that the value in the larger child, swap values
      if (items[subTreeNodeIndex] < items[largerChildIndex])
      {
         swap(items[largerChildIndex], items[subTreeNodeIndex]);
         
         // Continue with the recursion at that child
         heapRebuild(largerChildIndex, items, itemCount);
      }  // end if
   }  // end if
}  // end heapRebuild

void display(ItemType anArray[], int n)
{
   for (int i = 0; i < n; i++)
      cout << anArray[i] << " ";
}  // end display

/** Sorts the items in an array into ascending order.
 @pre  None.
 @post  anArray is sorted into ascending order; n is
 unchanged.
 @param anArray  The given array.
 @param n  The size of theArray. */
void heapSort(ItemType anArray[], int n)
{
   cout << endl;
   display(anArray, 6);
   cout << " Original array" << endl;

   // Build initial heap
   for (int index = n / 2; index >= 0; index--)
      heapRebuild(index, anArray, n);
   // The heap is anArray[0..n-1]
   // Assertion: anArray[0] is the largest entry in the array
   
   display(anArray, 6);
   cout << " Initial rebuild to form a heap" << endl;
   
   swap (anArray[0], anArray[n - 1]);
   display(anArray, 6);
   cout << " After swapping " << anArray[0]<< " and " << anArray[n - 1] << endl;
   
   int heapSize = n - 1;  // Heap region size decreases by 1
   while (heapSize > 1)
   {
      heapRebuild(0, anArray, heapSize);
      display(anArray, 6);
      cout << " rebuild(0, anArray, " << heapSize << ")" << endl;
      
      heapSize--;
      swap (anArray[0], anArray[heapSize]);
      display(anArray, 6);
      cout << " After swapping " << anArray[0]<< " and " << anArray[heapSize] << endl;
   }  // end while
}  // end heapSort

int main()
{
   string a[6] = {"D", "B", "A", "C", "F", "E"};
   heapSort(a, 6);
   for (int i = 0; i < 6; i++)
      cout << a[i] << " ";
   cout << " Sorted array" << endl;
   
   // Checkpoint Question 12
   string b[6] = {"25", "30", "20", "80", "40", "60"};
   heapSort(b, 6);
   for (int i = 0; i < 6; i++)
      cout << b[i] << " ";
   cout << " Sorted array" << endl;
}  // end main

/*
 D B A C F E  Original array
 F D E C B A  Initial rebuild to form a heap
 A D E C B F  After swapping A and F
 E D A C B F  rebuild(0, anArray, 5)
 B D A C E F  After swapping B and E
 D C A B E F  rebuild(0, anArray, 4)
 B C A D E F  After swapping B and D
 C B A D E F  rebuild(0, anArray, 3)
 A B C D E F  After swapping A and C
 B A C D E F  rebuild(0, anArray, 2)
 A B C D E F  After swapping A and B
 A B C D E F  Sorted array
 
 25 30 20 80 40 60  Original array
 80 40 60 30 25 20  Initial rebuild to form a heap
 20 40 60 30 25 80  After swapping 20 and 80
 60 40 20 30 25 80  rebuild(0, anArray, 5)
 25 40 20 30 60 80  After swapping 25 and 60
 40 30 20 25 60 80  rebuild(0, anArray, 4)
 25 30 20 40 60 80  After swapping 25 and 40
 30 25 20 40 60 80  rebuild(0, anArray, 3)
 20 25 30 40 60 80  After swapping 20 and 30
 25 20 30 40 60 80  rebuild(0, anArray, 2)
 20 25 30 40 60 80  After swapping 20 and 25
 20 25 30 40 60 80  Sorted array
 */
