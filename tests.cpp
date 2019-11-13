#include "circular_list.h"
#include "sparse_matrix.h"

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



	cout<<root->data<<" ";
	cout<<root->right->data<<" ";
	cout<<root->right->right->data<<" ";
	//cout<<root->right->right->right->data;
	cout<<"\n";
	cout<<root->down->data<<" ";
	cout<<root->down->down->data<<" ";
	cout<<"\n";

	Sparse_matrix<int>* matrix2 = add(matrix,matrix);

	root = matrix2->get_root();

	cout<<"\n\nAdd tests:\n";

	cout<<root->data<<" ";
	cout<<root->right->data<<" ";
	cout<<root->right->right->data<<" ";
	//cout<<root->right->right->right->data;
	cout<<"\n";
	cout<<root->down->data<<" ";
	cout<<root->down->down->data<<" ";
	cout<<"\n";

	cout<<"\n\nIdentity test:\n";

	Sparse_matrix<int>* matrix3 = Sparse_matrix<int>::identity(3,3);
	
	root = matrix3->get_root();

	cout<<root->data<<" ";
	cout<<root->right->data<<" ";
	cout<<root->right->right->data<<" ";
	cout<<"\n";
	cout<<matrix3->get_val(3,3);

	// std::cout << root->data << " " << root->posX << " " <<
	// 	root->posY << "\n\n";
	// std::cout << "row_q ==> " << matrix->get_row_q() << "\n";
	// std::cout << "column_q ==> " << matrix->get_column_q() << "\n";

	std::cout << "\n";
	matrix->print_in_console();

	auto trans = matrix->transpose();
	std::cout << "\n";

	trans.print_in_console();



	return 0;
}
