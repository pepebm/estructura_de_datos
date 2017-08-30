#ifndef BINARY_TREE_H
#define BINARY_TREE_H
//Jose manuel beauregard a01021716
#include <iomanip>
#include "TreeNode.h"

template <class T>
class BinaryTree {
    private:
        TreeNode<T> * root = nullptr;
        
        void recursiveInsert(TreeNode<T> * _root, TreeNode<T> * _node);
        void recursivePrintInOrder(TreeNode<T> * _root);
        void recursiveClear(TreeNode<T> * _root);
        TreeNode<T> * recursiveMin(TreeNode<T> * _root);
        int recursiveLeave(TreeNode<T> * _root);
        bool recursiveSearch(TreeNode<T> * _root, T _data);
        void recursiveDelete(TreeNode<T> * _root, T _data);

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
        void deleteNode(T _data);
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
bool BinaryTree<T>::search(T _data){
    if(root == nullptr) 
        return false;
    else 
        return recursiveSearch(root, _data);
}

template <class T>
bool BinaryTree<T>::recursiveSearch(TreeNode<T> * _root, T _data)
{
    if(_root == nullptr)
        return false;
    if(_root->getData() == _data) 
        return true;
    else if(_data > _root->getData()) 
        return recursiveSearch(_root->getRight(), _data);
    else 
        return recursiveSearch(_root->getLeft(), _data);
}


template <class T>
TreeNode<T> * BinaryTree<T>::getMin()
{
    if (root == nullptr)
        return nullptr;
    else 
        return recursiveMin(root);
}

template <class T>
TreeNode<T> * BinaryTree<T>::recursiveMin(TreeNode<T> * _root)
{
    if(_root->getLeft() == nullptr)
        return _root;
    else 
        return recursiveMin(_root->getLeft());
}

template <class T>
int BinaryTree<T>::countLeaves()
{
    if(root == nullptr)
        return 0;
    else 
        return recursiveLeave(root);
}

template <class T>
int BinaryTree<T>::recursiveLeave(TreeNode<T> * _root)
{
    if(_root == nullptr)
        return 0;
    else if(_root->getRight() == nullptr && _root->getLeft() == nullptr)
        return 1;
    else
        return recursiveLeave(_root->getLeft()) + recursiveLeave(_root->getRight());
}

template <class T>
void BinaryTree<T>::deleteNode(T _data)
{
    root = recursiveDelete(root, _data);
}

template <class T>
TreeNode<T> * BinaryTree<T>::recursiveDelete(TreeNode<T> * _root, T _data)
{
    if(root == nullptr)
        return;    
    else if(_data < _root->getData())
    {
        _root->getLeft(recursiveDelete(_root->getLeft(), _data));
        return _root;
    }
    else if(_data > _root->getData())
    {
        _root->setRight(recursiveDelete(_root->getRight(), _data));
        return _root;
    }
    else
    {
        // Case 1: Leaf
        if(_root->getLeft() == nullptr && _root->getRight() == nullptr)
        {
            delete _root;
            return nullptr;
        }
        // Case 2: Right child only
        else if(_root->getLeft() == nullptr)
        {
            TreeNode<T> * tmp = _root->getRight();
            delete _root;
            return tmp;
        }
        // Case 3: Left child only
        else if(_root->getRight() == nullptr)
        {
            TreeNode<T> * tmp = _root->getLeft();
            delete _root;
            return tmp;
        }
        // Case 4: Two children
        else
        {
            TreeNode<T> * tmp = recursiveMin(_root->getRight());
            _root->setData(tmp->getData());
            _root->setRight(recursiveDelete(_root->getRight(), tmp->getData()));
            return _root;
        }
    }
}
#endif
