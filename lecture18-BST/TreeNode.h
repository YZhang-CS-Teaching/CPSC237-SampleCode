//  Created by Frank M. Carrano and Timothy M. Henry.
//  Copyright (c) 2017 Pearson Education, Hoboken, New Jersey.

/** A class of nodes for an array-based binary tree.
 Listing 16-1.
 @file TreeNode.h */

#ifndef TREE_NODE_
#define TREE_NODE_

template<class ItemType>
class TreeNode
{
   
private:
   ItemType item;        // Data portion
   int      leftChild;   // Index to left child
   int      rightChild;  // Index to right child

public:
   TreeNode();
   TreeNode(const ItemType& nodeItem, int left, int right);
   
   // Declarations of the methods setItem, getItem, setLeft, getLeft,
   // setRight, and getRight are here.
   void setItem(const ItemType& anItem);
   ItemType getItem() const;

   void setLeft(TreeNode<ItemType> leftChild);
   TreeNode<ItemType> getLeft() const;
   
   void setRight(TreeNode<ItemType> rightChild);
   TreeNode<ItemType> getRight() const;
}; // end TreeNode

#include "TreeNode.cpp"

#endif 
