#include "circular_list.h"

int main(){
	circular_list<int>* list = new circular_list<int>();
	list->push_back(10);
	list->print_values();
	list->push_back(15);
	list->print_values();
	list->push_back(45);
	list->print_values();
	list->push_front(69);
	list->print_values();
	list->pop_front();
	list->print_values();
	list->pop_back();
	list->print_values();

	return 0;
}
