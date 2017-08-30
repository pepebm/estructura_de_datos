#include <iostream>
#include "BinaryTree.h"

void menu()
{
    BinaryTree<int> tree;
    TreeNode<int> * node;
    int number;
    char ans = 'a';
    bool found = false;
    int preset_data[] = {9, 2, 5, 12, 7, 18, 13, 14, 1, 29, 16};
    int preset_size = sizeof preset_data / sizeof preset_data[0];

    while (ans != 'q')
    {
        std::cout << "\n== Binary Tree Test Menu ==\n";
        std::cout << "\tf. Fill the tree with preset data\n";
        std::cout << "\ti. Insert a new number to the tree\n";
        std::cout << "\ts. Search for a number in the tree\n";
        std::cout << "\tr. Remove a number from the tree\n";
        std::cout << "\tc. Clear the tree\n";
        std::cout << "\tp. Print the data in the tree In-order\n";
        std::cout << "\tt. Print the data as a tree\n";
        std::cout << "\tm. Get the smallest number in the tree\n";
        std::cout << "\tl. Get the number of leaves in the tree\n";
        std::cout << "\tq. Quit the program\n";
        std::cout << "Enter your selection: ";
        std::cin >> ans;

        switch (ans)
        {
            case 'f':
                std::cout << "\tInserting: ";
                for (int i=0; i<preset_size; i++)
                {
                    std::cout << preset_data[i] << " ";
                    tree.insert(preset_data[i]);
                }
                std::cout << std::endl;
                break;
            case 'i':
                std::cout << "\tEnter the new number to insert: ";
                std::cin >> number;
                tree.insert(number);
                break;
            case 's':
                std::cout << "\tEnter the number to search for: ";
                std::cin >> number;
                found = tree.search(number);
                std::cout << "\tNumber: " << number << " was " << (found ? "found" : "NOT found") << " in the tree" << std::endl;
                break;
            case 'r':
                std::cout << "\tEnter the new number to remove: ";
                std::cin >> number;
                tree.remove(number);
                break;
            case 'c':
                tree.clear();
                break;
            case 'p':
                tree.printInOrder();
                break;
            case 't':
                tree.printTree();
                break;
            case 'm':
                node = tree.getMin();
                std::cout << "\tSmallest number: " << node->getData() << std::endl;
                break;
            case 'l':
                number = tree.countLeaves();
                std::cout << "\tNumber of leaves: " << number << std::endl;
                break;
            case 'q':
                std::cout << "See you later" << std::endl;
                break;
            default:
                std::cout << "Invalid option. Try again ..." << std::endl;
                break;
        }
    }
}

int main()
{
    menu();
    
    return 0;
}
