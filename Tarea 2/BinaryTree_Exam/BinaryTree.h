#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include <iomanip>
#include "TreeNode.h"

template <class T>
class BinaryTree {
    private:
        TreeNode<T> * root = nullptr;
        
        void recursiveInsert(TreeNode<T> * _root, TreeNode<T> * _node);
        void recursivePrintInOrder(TreeNode<T> * _root);
        void recursiveClear(TreeNode<T> * _root);
    public:
        BinaryTree () {}
        BinaryTree (TreeNode<T> * _node) { root = _node; }
        ~BinaryTree () { clear(); }
        
        void setRoot (TreeNode<T> * _node) { root = _node; }
        TreeNode<T> * getRoot () { return root; }
        void clear  ();
        void insert (T _data);
        void insert (TreeNode<T> * _node);
        bool search (T _data);
        void printInOrder ();
        TreeNode<T> * getMin();
        int countLeaves ();
        TreeNode<T> * removeData (T _data);
};

template <class T>
void BinaryTree<T>::insert(T _data)
{
    TreeNode<T> * node = new TreeNode<T> (_data);
    insert(node);
}

template <class T>
void BinaryTree<T>::insert(TreeNode<T> * _node)
{
    if (root == nullptr)
        root = _node;
    else
        recursiveInsert(root, _node);
}

template <class T>
void BinaryTree<T>::recursiveInsert(TreeNode<T> * _root, TreeNode<T> * _node)
{
    if (_root->getData() == _node->getData())
        return;
    if (_node->getData() < _root->getData())
    {
        if (_root->getLeft() == nullptr)
            _root->setLeft(_node);
        else
            recursiveInsert(_root->getLeft(), _node);
    }
    else if (_node->getData() > _root->getData())
    {
        if (_root->getRight() == nullptr)
            _root->setRight(_node);
        else
            recursiveInsert(_root->getRight(), _node);
    }
}

template <class T>
void BinaryTree<T>::printInOrder()
{
    if (root != nullptr)
    {
        recursivePrintInOrder(root);
        std::cout << std::endl;
    }
}

template <class T>
void BinaryTree<T>::recursivePrintInOrder(TreeNode<T> * _root)
{
    if (_root == nullptr)
        return;
    recursivePrintInOrder(_root->getLeft());
    std::cout << _root->getData() << " ";
    recursivePrintInOrder(_root->getRight());
}

template <class T>
void BinaryTree<T>::clear()
{
    if (root != nullptr)
    {
        recursiveClear(root);
        root = nullptr;
    }
}

template <class T>
void BinaryTree<T>::recursiveClear(TreeNode<T> * _root)
{
    if (_root == nullptr)
        return;
    // Delete the subtrees first
    recursiveClear(_root->getLeft());
    recursiveClear(_root->getRight());
    // Delete this node
    delete _root;
}

template <class T>
bool BinaryTree<T>::search(T _data)
{
    return false;
}

template <class T>
TreeNode<T> * BinaryTree<T>::getMin()
{
    return nullptr;
}

template <class T>
int BinaryTree<T>::countLeaves()
{
    return 0;
}

#endif
