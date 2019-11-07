#ifndef NODE_H
#define NODE_H

#include <iostream>
template <class T>
class Node {
	public:
		T data;
		int posX;
		int posY;
		Node<T>* right;
		Node<T>* down;

		Node(T value, int x, int y){
			data = value;
			posX = x;
			posY = y;
			right = nullptr;
			down = nullptr;
		};

		Node(Node<T>* original){
			data = original->data;
			posX = original->posX;
			posY = original->posY;
			right = original->right;
			down = original->down;
		}
};

#endif
