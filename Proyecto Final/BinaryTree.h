/*
    Ivan Aram Gonzalez Su
    Jose Manuel Beauregard Mendez
*/

#ifndef BINARYTREE_H
#define BINARYTREE_H

#include "TreeNode.h"
#include <iomanip>

template <class T>
class BinaryTree{
protected:
    int indent_increase = 10;
    TreeNode<T>* root = nullptr;
    void recursiveInsert(TreeNode<T>* _root, TreeNode<T>* _node);
    void recursivePrintInOrder(TreeNode<T>* _root);
    void recursiveClear(TreeNode<T>* _root);
    void recursivePrintTree(TreeNode<T> * _root, int indent, char branch);
    bool recursiveSearch(TreeNode<T>* _root, int _data);
    int recursiveCountLeaves(TreeNode<T>* _root);
    TreeNode<T>* recursiveDelete(TreeNode<T>* _root, T _data);
    TreeNode<T>* recursiveGetMin(TreeNode<T>* _root);
public:
    BinaryTree(){}
    BinaryTree(TreeNode<T>* _node):root(_node){}
    ~BinaryTree(){ clear(); }
    void setRoot(TreeNode<T>* _node){ root = _node; }
    TreeNode<T>* getRoot(){ return root; }
    void insert(T _data);
    void insert(TreeNode<T>* _node);
    bool search(T _data);
    TreeNode<T>* getMin();
    int countLeaves();
    void deleteNode(T _data);
    void printInOrder();
    void printTree();
    void clear();
};

template <class T>
void BinaryTree<T>::insert(T _data){
    TreeNode<T>* node = new TreeNode<T> (_data);
    insert(node);
}

template <class T>
void BinaryTree<T>::insert(TreeNode<T>* _node){
    if(root==nullptr) root = _node;
    else recursiveInsert(root,_node);
}

template <class T>
void BinaryTree<T>::recursiveInsert(TreeNode<T>* _root, TreeNode<T>* _node){
    if(_node->getData() == _root->getData()) return;
    else if(_node->getData() < _root->getData()){
        if(_root->getLeft() == nullptr) _root->setLeft(_node);
        else recursiveInsert(_root->getLeft(),_node);
    }
    else{
        if(_root->getRight() == nullptr) _root->setRight(_node);
        else recursiveInsert(_root->getRight(),_node);
    }
}

template <class T>
bool BinaryTree<T>::search(T _data){
    if(root!=nullptr) return recursiveSearch(root, _data);
    else return false;
}

template <class T>
bool BinaryTree<T>::recursiveSearch(TreeNode<T>* _root,int _data){
    if(_root == nullptr) return false;
    else if(_root->getData() == _data) return true;
    else if(_data < _root->getData()) return recursiveSearch(_root->getLeft(), _data);
    else return recursiveSearch(_root->getRight(), _data);
}

template <class T>
TreeNode<T>* BinaryTree<T>::getMin(){
    if(root==nullptr) return root;
    else{
        TreeNode<T>* tmp = root;
        while(tmp->getLeft()!=nullptr){
            tmp = tmp->getLeft();
        }
        return tmp;
    }
}

template <class T>
TreeNode<T>* BinaryTree<T>::recursiveGetMin(TreeNode<T>* _root){
    if(_root->getLeft()==nullptr) return _root;
    return recursiveGetMin(_root->getLeft());
}

template <class T>
int BinaryTree<T>::countLeaves(){
    if(root == nullptr) return 0;
    int count = recursiveCountLeaves(root);
    return count;
}

template <class T>
int BinaryTree<T>::recursiveCountLeaves(TreeNode<T>* _root){
    if(_root->getLeft()==nullptr && _root->getRight()==nullptr) return 1;
    else if(_root->getLeft()!=nullptr && _root->getRight()==nullptr) return recursiveCountLeaves(_root->getLeft());
    else if(_root->getLeft()==nullptr && _root->getRight()!=nullptr) return recursiveCountLeaves(_root->getRight());
    else return (recursiveCountLeaves(_root->getLeft()) + recursiveCountLeaves(_root->getRight()));
}

template <class T>
void BinaryTree<T>::deleteNode(T _data){
    root = recursiveDelete(root, _data);
}

template <class T>
TreeNode<T>* BinaryTree<T>::recursiveDelete(TreeNode<T>* _root,T _data){
    if(_root==nullptr) return nullptr;
    else if(_data < _root->getData()){
        _root->setLeft(recursiveDelete(_root->getLeft(),_data));
        return _root;
    }
    else if(_data > _root->getData()){
        _root->setRight(recursiveDelete(_root->getRight(),_data));
        return _root;
    }
    else{
        if(_root->getLeft() == nullptr && _root->getRight() == nullptr){
            delete _root;
            return nullptr;
        }
        else if(_root->getLeft() == nullptr){
            TreeNode<T>* tmp = _root->getRight();
            delete _root;
            return tmp;
        }
        else if(_root->getRight() == nullptr){
            TreeNode<T>* tmp = _root->getleft();
            delete _root;
            return tmp;
        }
        else{
            TreeNode<T>* tmp = recursiveGetMin(_root->getRight());
            _root->setData(tmp->getData());
            _root->setRight(recursiveDelete(_root->getRight(),tmp->getData()));
        }
    }
}

template <class T>
void BinaryTree<T>::printInOrder(){
    if(root!=nullptr) recursivePrintInOrder(root);
}

template <class T>
void BinaryTree<T>::recursivePrintInOrder(TreeNode<T>* _root){
    if(_root == nullptr) return;
    recursivePrintInOrder(_root->getLeft());
    std::cout<<_root->getData()<<" ";
    recursivePrintInOrder(_root->getRight());
}

template <class T>
void BinaryTree<T>::printTree(){
    std::cout << "Tree printed vertically:" << std::endl;
    recursivePrintTree(root, indent_increase, '-');
}

template <class T>
void BinaryTree<T>::recursivePrintTree(TreeNode<T> * _root, int indent, char branch){
    if (_root){
        recursivePrintTree(_root->getRight(), indent + indent_increase, '/');
        std::cout << std::setw(indent) << branch << " " << _root->getData() << std::endl;
        recursivePrintTree(_root->getLeft(), indent + indent_increase, '\\');
    }
}

template <class T>
void BinaryTree<T>::clear(){
    if(root!=nullptr) recursiveClear(root);
    root = nullptr;
}

template <class T>
void BinaryTree<T>::recursiveClear(TreeNode<T>* _root){
    if(_root == nullptr) return;
    recursiveClear(_root->getLeft());
    recursiveClear(_root->getRight());
    delete _root;
}

#endif
