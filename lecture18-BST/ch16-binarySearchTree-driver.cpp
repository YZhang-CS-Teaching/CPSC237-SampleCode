// Demonstration driver for the link-based BinarySearchTree.
// Inorder traversal of a binary search tree visits values in sorted order.

#include "BinarySearchTree.h"
#include <iostream>

void display(int& item)
{
   std::cout << item << " ";
}

void showTree(const BinarySearchTree<int>& tree)
{
   std::cout << "Preorder:  ";
   tree.preorderTraverse(display);
   std::cout << "\nInorder:   ";
   tree.inorderTraverse(display);
   std::cout << "\nPostorder: ";
   tree.postorderTraverse(display);
   std::cout << "\nHeight: " << tree.getHeight()
             << ", nodes: " << tree.getNumberOfNodes() << "\n";
}

int main()
{
   BinarySearchTree<int> tree;
   int values[] = {50, 30, 70, 20, 40, 60, 80, 65};
   int count = sizeof(values) / sizeof(values[0]);

   std::cout << "Inserting: ";
   for (int i = 0; i < count; ++i)
   {
      std::cout << values[i] << " ";
      tree.add(values[i]);
   }
   std::cout << "\n\nInitial tree:\n";
   showTree(tree);

   std::cout << "\nContains 40? " << (tree.contains(40) ? "yes" : "no") << "\n";
   std::cout << "Contains 99? " << (tree.contains(99) ? "yes" : "no") << "\n";
   std::cout << "getEntry(60): " << tree.getEntry(60) << "\n";

   std::cout << "\nRemove leaf 20: ";
   std::cout << (tree.remove(20) ? "success" : "not found") << "\n";
   showTree(tree);

   std::cout << "\nRemove 60 (node with one child, 65): ";
   std::cout << (tree.remove(60) ? "success" : "not found") << "\n";
   showTree(tree);

   std::cout << "\nRemove 70 (node with two children): ";
   std::cout << (tree.remove(70) ? "success" : "not found") << "\n";
   showTree(tree);

   std::cout << "\nCopy the tree. Then remove 50 from the original.\n";
   BinarySearchTree<int> copy(tree);
   tree.remove(50);

   std::cout << "Original tree:\n";
   showTree(tree);
   std::cout << "Copy (unchanged):\n";
   showTree(copy);

   return 0;
}
