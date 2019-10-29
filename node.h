#ifndef NODE_H
#define NODE_H

#include <iostream>
template <class T>
class Node {
	public:
		T data;
		int posX;
		int posY;
		Node<T>* next;
		Node<T>* down;
		Node(T value){
			this->data = value;
			next = nullptr;
			down = nullptr;
		};
};

#endif
