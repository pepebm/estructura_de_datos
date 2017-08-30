/*
    Ivan Aram Gonzalez Su
    Jose Manuel Beauregard Mendez
*/

#ifndef FIBTREE_H
#define FIBTREE_H

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>
#include "BinaryTree.h"
#include "fibNode.h"

class fibTree : public BinaryTree<fibNode>{
private:
    int number;
    int space_increase = 40;

    sf::RenderWindow window;
    sf::CircleShape circle;
    sf::Font font;
    sf::Text texto;
    sf::RectangleShape vertical;
    sf::RectangleShape horizontal;
    sf::Event event;
    sf::View view;

    int fibonacci(int n);
    void fillTree();
    void recursiveFillTree(TreeNode<fibNode>* _root, int n);

    void configure();
    void drawTree();
    void recursiveDrawTree(TreeNode<fibNode>* _root, int x, int y, int space);
    void displayWindow();
public:
    fibTree() : window(sf::VideoMode(800,600),"Fibonacci Tree") { window.setPosition(sf::Vector2i(200, 100)); font.loadFromFile("Arctik 1.ttf"); configure(); }
    fibTree(int n) : number(n), window(sf::VideoMode(800,600),"Fibonacci Tree") { fillTree(); window.setPosition(sf::Vector2i(200, 100)); font.loadFromFile("Arctik 1.ttf"); configure(); }

    void setNumber(int n){ number = n; clear(); fillTree(); }
    int getNumber(int n){ return number; }

 	void mainDraw();
};

int fibTree::fibonacci(int n){
    if(n==0 || n==1) return n;
    else return fibonacci(n - 1) + fibonacci(n - 2);
}

void fibTree::fillTree(){
    TreeNode<fibNode>* node = new TreeNode<fibNode>(fibNode(fibonacci(number),number));
    root = node;
    recursiveFillTree(root,number);
}

void fibTree::recursiveFillTree(TreeNode<fibNode>* _root, int n){
    if(n>1){
        TreeNode<fibNode>* nodeLeft = new TreeNode<fibNode>(fibNode(fibonacci(n-1),n-1));
        TreeNode<fibNode>* nodeRight = new TreeNode<fibNode>(fibNode(fibonacci(n-2),n-2));
        _root->setLeft(nodeLeft);
        _root->setRight(nodeRight);
        recursiveFillTree(_root->getLeft(),n-1);
        recursiveFillTree(_root->getRight(),n-2);
    }
}

void fibTree::configure(){
    texto.setFont(font);
    texto.setCharacterSize(9);
    texto.setColor(sf::Color::Red);

    circle.setRadius(20);
    circle.setPointCount(50);
    circle.setFillColor(sf::Color::White);
    circle.setOutlineThickness(2.f);
    circle.setOutlineColor(sf::Color::Black);

    vertical.setFillColor(sf::Color::Black);
    vertical.setSize(sf::Vector2f(2,20));

    horizontal.setFillColor(sf::Color::Black);

    view.setCenter(sf::Vector2f(20*pow(2,number-1),100));
    view.setSize(sf::Vector2f(800,600));
}

void fibTree::drawTree(){
    int posX = 20*pow(2,number-1);
    recursiveDrawTree(root, posX, 30, posX/2);
}

void fibTree::recursiveDrawTree(TreeNode<fibNode>* _root, int x, int y, int space){
    if(_root){
        recursiveDrawTree(_root->getLeft(), x - space, y + space_increase, space/2);
        circle.setPosition(sf::Vector2f(x, y));
        texto.setPosition(sf::Vector2f(x + 2, y + 15));
        texto.setString("Fib(" + std::to_string(_root->getData().getCall()) + ") = " + std::to_string(_root->getData().getNum()));
        window.draw(circle);
        window.draw(texto);
        if(_root->getLeft()){
            vertical.setPosition(x + 20, y + 40);
            horizontal.setSize(sf::Vector2f(2 * space, 2));
            horizontal.setPosition(x - space + 40, y + 60);
            window.draw(vertical);
            window.draw(horizontal);
        }
        recursiveDrawTree(_root->getRight(), x + space, y + space_increase, space/2);
    }
}

void fibTree::displayWindow(){
    window.clear(sf::Color::White);
    window.setView(view);
    drawTree();
    window.display();
}

void fibTree::mainDraw(){
	while(window.isOpen()){
		static int x = 20*pow(2,number-1);
		static int y = 100;
        while(window.pollEvent(event)){
        	switch(event.type){
        	case sf::Event::Closed:
        		window.close();
        		break;
        	case sf::Event::KeyPressed:
        		if(event.key.code == sf::Keyboard::Left){
        			x-=50;
        			view.setCenter(sf::Vector2f(x,y));
        			window.setView(view);
        		}
        		else if(event.key.code == sf::Keyboard::Right){
        			x+=50;
        			view.setCenter(sf::Vector2f(x,y));
        			window.setView(view);
        		}
        		else if(event.key.code == sf::Keyboard::Up){
        			y-=50;
        			view.setCenter(sf::Vector2f(x,y));
        			window.setView(view);
        		}
        		else if(event.key.code == sf::Keyboard::Down){
        			y+=50;
        			view.setCenter(sf::Vector2f(x,y));
        			window.setView(view);
        		}
        		break;
        	default:
        		break;
        	}
            if(event.type ==  sf::Event::Closed) window.close();
        }
        displayWindow();
    }
}

#endif
