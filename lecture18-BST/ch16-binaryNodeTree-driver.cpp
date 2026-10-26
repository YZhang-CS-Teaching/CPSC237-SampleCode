// Demonstration driver for the link-based BinaryNodeTree.
// This tree is NOT a binary search tree; values are added to keep the tree
// reasonably balanced, not in sorted order.

#include "BinaryNodeTree.h"
#include <iostream>

void display(int& item)
{
   std::cout << item << " ";
}

void showTree(const BinaryNodeTree<int>& tree)
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
   BinaryNodeTree<int> tree;

   std::cout << "Adding 40, 20, 60, 10, 30, 50, 70\n";
   tree.add(40);
   tree.add(20);
   tree.add(60);
   tree.add(10);
   tree.add(30);
   tree.add(50);
   tree.add(70);

   showTree(tree);

   std::cout << "\nContains 30? " << (tree.contains(30) ? "yes" : "no") << "\n";
   std::cout << "Contains 99? " << (tree.contains(99) ? "yes" : "no") << "\n";

   std::cout << "\nRemoving 20: ";
   std::cout << (tree.remove(20) ? "success" : "not found") << "\n";
   showTree(tree);

   std::cout << "\nRemoving 99: ";
   std::cout << (tree.remove(99) ? "success" : "not found") << "\n";

   std::cout << "\nCopying the tree, then clearing the original.\n";
   BinaryNodeTree<int> copy(tree);
   tree.clear();

   std::cout << "Original tree is empty? " << (tree.isEmpty() ? "yes" : "no") << "\n";
   std::cout << "Copied tree remains:\n";
   showTree(copy);

   return 0;
}
