#include "circular_list.h"
#include "sparse_matrix.h"

int main(){
	Sparse_matrix<int>* matrix = new Sparse_matrix<int>();
	//std::cout << "row_q ==> " << matrix->get_row_q() << "\n";
	//std::cout << "column_q ==> " << matrix->get_column_q() << "\n";

	matrix->insert(10,0,0);
	matrix->insert(3,0,0);
	auto root = matrix->get_root();

	std::cout << root->data << " " << root->posX << " " <<
		root->posY << "\n\n";
	//std::cout << "row_q ==> " << matrix->get_row_q() << "\n";
	//std::cout << "column_q ==> " << matrix->get_column_q() << "\n";

	return 0;
}
