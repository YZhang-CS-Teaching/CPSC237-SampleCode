//  Created by Frank M. Carrano and Timothy M. Henry.
//  Copyright (c) 2017 Pearson Education, Hoboken, New Jersey.

/** @file BinarySearchTree.cpp */
#include <iostream>

#include "BinarySearchTree.h" 
#include "BinaryNode.h" 

//////////////////////////////////////////////////////////////
//
//      Protected Utility Methods Section
//
//////////////////////////////////////////////////////////////

template<class ItemType>
BinaryNode<ItemType>* BinarySearchTree<ItemType>::placeNode(BinaryNode<ItemType>* subTreePtr,
                                                                BinaryNode<ItemType>* newNodePtr)
{
   if (subTreePtr == nullptr)
      return newNodePtr;
   else
   {
      if (subTreePtr->getItem() > newNodePtr->getItem())
         subTreePtr->setLeftChildPtr(placeNode(subTreePtr->getLeftChildPtr(), newNodePtr));
      else 
         subTreePtr->setRightChildPtr(placeNode(subTreePtr->getRightChildPtr(), newNodePtr));
      
      return subTreePtr;
   }  // end if
}  // end placeNode

template<class ItemType>
BinaryNode<ItemType>* BinarySearchTree<ItemType>::removeValue(BinaryNode<ItemType>* subTreePtr,
                                                              const ItemType target, 
                                                              bool& success)
{
   if (subTreePtr == nullptr)           
   {
      // Not found here
      success = false;
      return subTreePtr;
   }
   if (subTreePtr->getItem() == target)
   {
      // Item is in the root of some subtree
      subTreePtr = removeNode(subTreePtr);
      success = true;
      return subTreePtr;
   }
   else 
   {
      if (subTreePtr->getItem() > target)
      {
         // Search the left subtree
         subTreePtr->setLeftChildPtr(removeValue(subTreePtr->getLeftChildPtr(), target, success));
      }
      else
      {
         // Search the right subtree
         subTreePtr->setRightChildPtr(removeValue(subTreePtr->getRightChildPtr(), target, success));
      }
      return subTreePtr;
   }  // end if
}  // end removeValue

template<class ItemType>
BinaryNode<ItemType>* BinarySearchTree<ItemType>::removeNode(BinaryNode<ItemType>* nodePtr)
{
   if (nodePtr->getLeftChildPtr() == nullptr && nodePtr->getRightChildPtr() == nullptr)
   {
      delete nodePtr;
      return nullptr;
   }
   else if (nodePtr->getLeftChildPtr() == nullptr)
   {
      BinaryNode<ItemType>* rightChildPtr = nodePtr->getRightChildPtr();
      nodePtr->setRightChildPtr(nullptr);
      delete nodePtr;
      return rightChildPtr;
   }
   else if (nodePtr->getRightChildPtr() == nullptr)
   {
      BinaryNode<ItemType>* leftChildPtr = nodePtr->getLeftChildPtr();
      nodePtr->setLeftChildPtr(nullptr);
      delete nodePtr;
      return leftChildPtr;
   }
   else
   {
      ItemType successorValue;
      nodePtr->setRightChildPtr(removeLeftmostNode(nodePtr->getRightChildPtr(), successorValue));
      nodePtr->setItem(successorValue);
      return nodePtr;
   }
}

template<class ItemType> 
BinaryNode<ItemType>* BinarySearchTree<ItemType>::removeLeftmostNode(BinaryNode<ItemType>* nodePtr,
                                                                     ItemType& inorderSuccessor)
{
   if (nodePtr->getLeftChildPtr() == nullptr)
   {
      inorderSuccessor = nodePtr->getItem();
      return removeNode(nodePtr);
   }
   else 
   {
      nodePtr->setLeftChildPtr(removeLeftmostNode(nodePtr->getLeftChildPtr(), inorderSuccessor));
      return nodePtr;
   }  // end if      
}  // end removeLeftmostNode

/*
template<class ItemType>
ItemType BinarySearchTree<ItemType>::findSuccessorValue(BinaryNode<ItemType>* subTreePtr)
{
   BinaryNode<ItemType>* myLeftChildPtr = subTreePtr->getLeftChildPtr();
   if (myLeftChildPtr->getLeftChildPtr() == nullptr) {
      ItemType nodeItemValue = myLeftChildPtr->getItem();
      subTreePtr->setLeftChildPtr(removeNode(myLeftChildPtr));
      return nodeItemValue;
   }
   else 
   {
      return findSuccessorValue(subTreePtr->getLeftChildPtr());
   }  // end if  
}  // end findSuccessorValue 
*/

// Override findNode because now we can use a binary search:
template<class ItemType>
BinaryNode<ItemType>* BinarySearchTree<ItemType>::findNode(BinaryNode<ItemType>* subTreePtr,
                                                           const ItemType& target) const 
{
   // Uses a binary search 
   if (subTreePtr == nullptr)
      return subTreePtr;                        // Not found
   else if (subTreePtr->getItem() == target)  
      return subTreePtr;                     // Found
   else if (subTreePtr->getItem() > target)
      // Search left subtree
      return findNode(subTreePtr->getLeftChildPtr(), target);
   else
      // Search right subtree
      return findNode(subTreePtr->getRightChildPtr(), target);
}  // end findNode


//////////////////////////////////////////////////////////////
//      PUBLIC METHODS BEGIN HERE
//////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////
//      Constructor and Destructor Section
//////////////////////////////////////////////////////////////

template<class ItemType>
BinarySearchTree<ItemType>::BinarySearchTree()
{   }  // end default constructor

template<class ItemType>
BinarySearchTree<ItemType>::BinarySearchTree(const ItemType& rootItem)
: rootPtr(new BinaryNode<ItemType>(rootItem, nullptr, nullptr))
{  }  // end constructor

template<class ItemType>
BinarySearchTree<ItemType>::BinarySearchTree(const BinarySearchTree<ItemType>& treePtr)
{
   rootPtr = this->copyTree(treePtr.rootPtr); // Call inherited method
}  // end copy constructor

template<class ItemType>
BinarySearchTree<ItemType>::~BinarySearchTree()
{
   this->destroyTree(rootPtr); // Call inherited method
}  // end destructor


//////////////////////////////////////////////////////////////
//      Public BinaryTreeInterface Methods Section
//////////////////////////////////////////////////////////////

template<class ItemType>
bool BinarySearchTree<ItemType>::isEmpty() const
{
   return rootPtr == nullptr;
}  // end isEmpty

template<class ItemType>
int BinarySearchTree<ItemType>::getHeight() const
{
   return this->getHeightHelper(rootPtr); // Call inherited method
}  // end getHeight

template<class ItemType>
int BinarySearchTree<ItemType>::getNumberOfNodes() const
{
   return this->getNumberOfNodesHelper(rootPtr); // Call inherited method
}  // end getNumberOfNodes

template<class ItemType>
void BinarySearchTree<ItemType>::clear()
{
   this->destroyTree(rootPtr); // Call inherited method
   rootPtr = nullptr;
}  // end clear

template<class ItemType>
ItemType BinarySearchTree<ItemType>::getRootData() const
{
   if (isEmpty())
      throw PrecondViolatedExcep("getRootData() called with empty tree."); 
   
   return rootPtr->getItem();
}  // end getRootData

// Must override setRootData to disable its affect:
template<class ItemType>
void BinarySearchTree<ItemType>::setRootData(const ItemType& newItem) const
{
   throw PrecondViolatedExcep("Cannot change root value in a BST!");
}  // end setRootData

template<class ItemType>
bool BinarySearchTree<ItemType>::add(const ItemType& newData)
{
   BinaryNode<ItemType>* newNodePtr = new BinaryNode<ItemType>(newData);
   rootPtr = placeNode(rootPtr, newNodePtr);
   
   return true;
}  // end add

template<class ItemType>
bool BinarySearchTree<ItemType>::remove(const ItemType& target)
{
   bool isSuccessful = false;
   // call may change isSuccessful
   rootPtr = removeValue(rootPtr, target, isSuccessful);
   return isSuccessful; 
}  // end remove

// Override getEntry to use our improved findNode:
template<class ItemType>
ItemType BinarySearchTree<ItemType>::getEntry(const ItemType& anEntry) const
{
   BinaryNode<ItemType>* nodeWithEntry = findNode(rootPtr, anEntry);
   if (nodeWithEntry == nullptr)
      throw NotFoundException("Entry not found in tree.");
   else
      return nodeWithEntry->getItem();
}  // end getEntry

// Override contains to use our improved findNode:
template<class ItemType>
bool BinarySearchTree<ItemType>::contains(const ItemType& anEntry) const
{

   return (findNode(rootPtr, anEntry) != nullptr);  // true when found
}  // end contains

//////////////////////////////////////////////////////////////
//      Public Traversals Section
//////////////////////////////////////////////////////////////

template<class ItemType>
void BinarySearchTree<ItemType>::preorderTraverse(void visit(ItemType&)) const
{
   this->preorder(visit, rootPtr); // Call inherited method
}  // end preorderTraverse

template<class ItemType>
void BinarySearchTree<ItemType>::inorderTraverse(void visit(ItemType&)) const
{
   this->inorder(visit, rootPtr); // Call inherited method
}  // end inorderTraverse

template<class ItemType>
void BinarySearchTree<ItemType>::postorderTraverse(void visit(ItemType&)) const
{
   this->postorder(visit, rootPtr); // Call inherited method
}  // end postorderTraverse


//////////////////////////////////////////////////////////////
//      Overloaded Operator 
//////////////////////////////////////////////////////////////

template<class ItemType>
BinarySearchTree<ItemType>& BinarySearchTree<ItemType>::operator=(const BinarySearchTree<ItemType>& rightHandSide)
{
   if (this != &rightHandSide)
   {
      clear();
      rootPtr = this->copyTree(rightHandSide.rootPtr);
   }
   return *this;
}
