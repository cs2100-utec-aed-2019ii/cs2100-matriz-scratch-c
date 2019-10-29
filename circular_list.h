#ifndef CIRCULAR_LIST_H
#define CIRCULAR_LIST_H

#include "node.h"
template <class T>
class circular_list{
	private:
		Node<T>* head;
	public:
		circular_list(){
			head = nullptr;
		};

		Node<T>* get_head(){
			return head;
		};

		Node<T>* get_last(){
			if (head != nullptr){
				Node<T>* curr = head;
				while (curr->next != head){
					curr = curr->next;
				}
				return curr;
			}else{

			}
		};

		void set_head(T value){
			if (head == nullptr){
				Node<T>* new_head = new Node<T>(value);
				head = new_head;
				head->next = head;
			}else{
				std::cout << "WARNING: head already set\n continue?(Y/N)\n";
				char input;
				std::cin >> input;
				if (input == 'Y' || input == 'y'){
					Node<T>* new_head = new Node<T>(value);
					head = new_head;
				}
			}
		};

		void insert_value(T value){
			if (head == nullptr){
				set_head(value);
			}else{
				Node<T>* new_node = new Node<T>(value);
				Node<T>* last = get_last();
				last->next = new_node;
				new_node->next = head;
			}
		};

		void print_values(){
			Node<T>* curr = head;
			if (head != nullptr){
				bool last_listed = false;
				do{
					std::cout << curr->data; ;
					if (curr->next == head){
						last_listed = true;
					}else{
						std::cout << " -> ";
						curr = curr->next;
					}
				}while (last_listed == false);
				
				std::cout << "\n print finished\n";
			}else{
				std::cout << "ERROR: head = nullptr\n";
			}
		};
};

#endif
