//  Created by Frank M. Carrano and Timothy M. Henry.
//  Copyright (c) 2017 Pearson Education, Hoboken, New Jersey.

#include "BinaryNodeTree.h"  // ADT binary tree operations
#include <iostream>
#include <string>


void display(std::string& anItem)
{
   std::cout << "Displaying item - " << anItem << std::endl;
}  // end display

void check(bool success)
{
   if (success)
      std::cout << "Done." << std::endl;
   else
      std::cout << " Entry not in tree." << std::endl;
}  // end check

int main()
{
   auto tree1 = std::make_unique<BinaryNodeTree<std::string>>();

//   auto tree2Ptr = std::make_shared<BinaryNodeTree<std::string>>("A");
//   auto tree3Ptr = std::make_shared<BinaryNodeTree<std::string>>("B");
//   auto tree4Ptr = std::make_unique<BinaryNodeTree<std::string>>("C", tree2Ptr, tree3Ptr);

   std::shared_ptr<BinaryTreeInterface<std::string>> tree2Ptr =
                           std::make_shared<BinaryNodeTree<std::string>>("A");
   auto tree3Ptr = std::make_shared<BinaryNodeTree<std::string>>("B");
   auto tree4Ptr = std::make_unique<BinaryNodeTree<std::string>>("C",
               std::dynamic_pointer_cast<BinaryNodeTree<std::string>>(tree2Ptr), tree3Ptr);

   
   //   std::unique_ptr<BinaryTreeInterface<std::string>> tree1Ptr(new BinaryNodeTree<std::string>>());
   
   tree1->add("10");
   tree1->add("20");
   tree1->add("30");
   tree1->add("40");
   tree1->add("50");
   tree1->add("60");
   tree1->add("70");
   tree1->add("80");
   
   std::cout<<"Tree 1 Preorder: Should be 10 20 40 70 60 30 50 80\n";
   tree1->preorderTraverse(display);
   
   std::cout<<"Tree 1 Inorder: Should be 70 40 20 60 10 50 30 80\n";
   tree1->inorderTraverse(display);
   
   std::cout<<"Tree 1 Postorder: Should be 70 40 60 20 50 80 30 10\n";
   tree1->postorderTraverse(display);
   
   std::cout << "Tree 1 height: " << tree1->getHeight() << std::endl;
   std::cout << "Tree 1 number of nodes: " << tree1->getNumberOfNodes() << std::endl;
   
   std::cout << "Remove the leaf 80: ";
   bool success = tree1->remove("80");
   check(success);
   
   std::cout << "Try to remove the leaf 80 again: ";
   success = tree1->remove("80");
   check(success);
   
   std::cout << "Remove the leaf 50: ";
   success = tree1->remove("50");
   check(success);
   
   std::cout<<"Tree 1 Preorder: Should be 10 20 40 70 60 30\n";
   tree1->preorderTraverse(display);
   
   std::cout<<"Tree 1 Inorder: Should be 70 40 20 60 10 30\n";
   tree1->inorderTraverse(display);
   
   std::cout<<"Tree 1 Postorder: Should be 70 40 60 20 30 10\n";
   tree1->postorderTraverse(display);
   
   std::cout << "Tree 1 height: " << tree1->getHeight() << std::endl;
   std::cout << "Tree 1 number of nodes: " << tree1->getNumberOfNodes() << std::endl;
   
   std::cout << "Remove the node 40 that has only a left child: ";
   success = tree1->remove("40");
   check(success);
   
   std::cout<<"Tree 1 Preorder: Should be 10 20 70 60 30\n";
   tree1->preorderTraverse(display);
   
   std::cout<<"Tree 1 Inorder: Should be 70 20 60 10 30\n";
   tree1->inorderTraverse(display);
   
   std::cout<<"Tree 1 Postorder: Should be 70 60 20 30 10\n";
   tree1->postorderTraverse(display);
   
   std::cout << "Tree 1 height: " << tree1->getHeight() << std::endl;
   std::cout << "Tree 1 number of nodes: " << tree1->getNumberOfNodes() << std::endl;
   
   std::cout << "Remove the root 10 that has both left and right subtrees: ";
   success = tree1->remove("10");
   check(success);
   
   std::cout<<"Tree 1 Preorder: Should be 20 60 70 30\n";
   tree1->preorderTraverse(display);
   
   std::cout<<"Tree 1 Inorder: Should be 70 60 20 30\n";
   tree1->inorderTraverse(display);
   
   std::cout<<"Tree 1 Postorder: Should be 70 60 30 20\n";
   tree1->postorderTraverse(display);
   
   std::cout << "Tree 1 height: " << tree1->getHeight() << std::endl;
   std::cout << "Tree 1 number of nodes: " << tree1->getNumberOfNodes() << std::endl;
   
   return 0;
}  // end main
/*
 Tree 1 Preorder: Should be 10 20 40 70 60 30 50 80
 Displaying item - 10
 Displaying item - 20
 Displaying item - 40
 Displaying item - 70
 Displaying item - 60
 Displaying item - 30
 Displaying item - 50
 Displaying item - 80
 Tree 1 Inorder: Should be 70 40 20 60 10 50 30 80
 Displaying item - 70
 Displaying item - 40
 Displaying item - 20
 Displaying item - 60
 Displaying item - 10
 Displaying item - 50
 Displaying item - 30
 Displaying item - 80
 Tree 1 Postorder: Should be 70 40 60 20 50 80 30 10
 Displaying item - 70
 Displaying item - 40
 Displaying item - 60
 Displaying item - 20
 Displaying item - 50
 Displaying item - 80
 Displaying item - 30
 Displaying item - 10
 Tree 1 height: 4
 Tree 1 number of nodes: 8
 Remove the leaf 80: Done.
 Try to remove the leaf 80 again:  Entry not in tree.
 Remove the leaf 50: Done.
 Tree 1 Preorder: Should be 10 20 40 70 60 30
 Displaying item - 10
 Displaying item - 20
 Displaying item - 40
 Displaying item - 70
 Displaying item - 60
 Displaying item - 30
 Tree 1 Inorder: Should be 70 40 20 60 10 30
 Displaying item - 70
 Displaying item - 40
 Displaying item - 20
 Displaying item - 60
 Displaying item - 10
 Displaying item - 30
 Tree 1 Postorder: Should be 70 40 60 20 30 10
 Displaying item - 70
 Displaying item - 40
 Displaying item - 60
 Displaying item - 20
 Displaying item - 30
 Displaying item - 10
 Tree 1 height: 4
 Tree 1 number of nodes: 6
 Remove the node 40 that has only a left child: Done.
 Tree 1 Preorder: Should be 10 20 70 60 30
 Displaying item - 10
 Displaying item - 20
 Displaying item - 70
 Displaying item - 60
 Displaying item - 30
 Tree 1 Inorder: Should be 70 20 60 10 30
 Displaying item - 70
 Displaying item - 20
 Displaying item - 60
 Displaying item - 10
 Displaying item - 30
 Tree 1 Postorder: Should be 70 60 20 30 10
 Displaying item - 70
 Displaying item - 60
 Displaying item - 20
 Displaying item - 30
 Displaying item - 10
 Tree 1 height: 3
 Tree 1 number of nodes: 5
 Remove the root 10 that has both left and right subtrees: Done.
 Tree 1 Preorder: Should be 20 60 70 30
 Displaying item - 20
 Displaying item - 60
 Displaying item - 70
 Displaying item - 30
 Tree 1 Inorder: Should be 70 60 20 30
 Displaying item - 70
 Displaying item - 60
 Displaying item - 20
 Displaying item - 30
 Tree 1 Postorder: Should be 70 60 30 20
 Displaying item - 70
 Displaying item - 60
 Displaying item - 30
 Displaying item - 20
 Tree 1 height: 3
 Tree 1 number of nodes: 4
 */
