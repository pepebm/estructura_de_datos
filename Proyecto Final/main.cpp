/*
	Ivan Aram Gonzalez Su
	Jose Manuel Beauregard Mendez
*/

#include "fibTree.h"
#include <iostream>

int main(){
	int n;
	std::cout<<"Enter until what fibonacci number do you want the tree: ";
	std::cin>>n;
	fibTree tree(n);
	tree.mainDraw();
}
