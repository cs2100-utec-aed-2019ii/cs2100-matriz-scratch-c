#include "circular_list.h"
#include "sparse_matrix.h"
#include <fstream>

int main(){
	Sparse_matrix<int>* matrix = new Sparse_matrix<int>();
	std::cout << "row_q ==> " << matrix->get_row_q() << "\n";
	std::cout << "column_q ==> " << matrix->get_column_q() << "\n";

	//matrix->insert(0,0,0);
//	matrix->insert(8,1,1);
//	matrix->insert(9,1,0);
//	matrix->insert(5,4,0);
//	matrix->insert(3,1,2);
//	matrix->insert(2,3,2);
//	matrix->insert(4,1,1);

	matrix->insert(1,0,0);
	matrix->insert(2,3,2);
	matrix->insert(3,1,2);
	matrix->insert(4,2,1);
	matrix->insert(5,4,0);

	auto root = matrix->get_root();

	cout<<*matrix;

	cout<<"\n\nAdd tests:\n";

	Sparse_matrix<int>* matrix2 = add(matrix,matrix);

	cout<<*matrix2;

	//cout<<"\n\n"<<matrix2->get_val(0,4)<<"\n\n";

	cout<<"\n\nIdentity test:\n";

	Sparse_matrix<int>* matrix3 = Sparse_matrix<int>::identity(5,5);

	cout<<*matrix3;

	cout<<"\n\nMult test\n\n";

	cout<<*mult(matrix,matrix3);

	
	// std::cout << root->data << " " << root->posX << " " <<
	// 	root->posY << "\n\n";
	// std::cout << "row_q ==> " << matrix->get_row_q() << "\n";
	// std::cout << "column_q ==> " << matrix->get_column_q() << "\n";

	std::cout << "\n";
	matrix->print();

	auto trans = matrix->transpose();
	std::cout << "\n";

	trans.print();

	std::ofstream x("xx.txt");
	x <<* matrix;


	return 0;
}
