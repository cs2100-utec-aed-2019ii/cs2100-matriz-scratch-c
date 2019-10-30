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
			if (head != nullptr)
				return head->prev;
		};

		void set_head(T value){
			if (head == nullptr){
				Node<T>* new_head = new Node<T>(value);
				head = new_head;
				head->next = head;
				head->prev = head;
			}else{
				std::cout << "WARNING: head already set\n continue?(Y/N)\n";
				char input;
				std::cin >> input;
				if (input == 'Y' || input == 'y'){
					head->data = value;
				}
			}
		};

		void push_back(T value){
			if (head == nullptr){
				set_head(value);
			}else{
				auto new_node = new Node<T>(value);
				auto last = get_last();
				new_node->next = head;
				new_node->prev = last;
				last->next = new_node;
				head->prev = new_node;
			}
		};

		void push_front(T value){
			if (head == nullptr){
				set_head(value);
			}else{
				Node<T>* new_node = new Node<T>(head->data);
				head->data = value;
				new_node->next = head->next;
				head->next = new_node;
			}
		};

		void pop_front(){
			if (head == nullptr){
				std::cout << "WARNING: head already set\n continue?(Y/N)\n";
				return;
			}else{
				auto temp = head;
				auto new_head = head->next;
				auto last = get_last();
				last->next = new_head;
				new_head->prev = last;
				delete temp;
				head = new_head;
			}
		};
		
		void pop_back(){
			if (head == nullptr){
				std::cout << "WARNING: head already set\n continue?(Y/N)\n";
				return;
			}else{
				auto last = get_last();
				auto new_last = last->prev;
				new_last->next = head;
				head->prev = new_last;
				delete last;
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
