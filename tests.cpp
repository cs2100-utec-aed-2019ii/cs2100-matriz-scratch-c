#include "circular_list.h"

int main(){
	circular_list<int>* list = new circular_list<int>();
	list->insert_value(10);
	list->insert_value(15);
	list->insert_value(45);
	list->print_values();
	return 0;
}
