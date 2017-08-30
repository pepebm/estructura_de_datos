/*
    Ivan Aram Gonzalez Su
    Jose Manuel Beauregard Mendez
*/

#ifndef TREENODE_H
#define TREENODE_H

#include <iostream>

template <class T>
class TreeNode{
private:
    T data;
    int height = 1;
    TreeNode<T>* left = nullptr;
    TreeNode<T>* right = nullptr;
public:
    TreeNode(){}
    TreeNode(T _data):data(_data){}
    ~TreeNode(){ left = nullptr; right = nullptr; }
    void setData(T _data){ data = _data; }
    T getData(){ return data; }
    void setHeight(int h){ height = h; }
    int getHeight(){ return height; }
    void setLeft(TreeNode<T>* _node){ left = _node; }
    void setRight(TreeNode<T>* _node){ right = _node; }
    TreeNode<T>* getLeft(){ return left; }
    TreeNode<T>* getRight(){ return right; }
};
#endif
