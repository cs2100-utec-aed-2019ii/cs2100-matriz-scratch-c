#ifndef SPARSE_MATRIX_H
#define SPARSE_MATRIX_H

#include <vector>
#include "node.h"
#include <iostream>

using namespace std;

template <class T>
class Sparse_matrix{
	private:
		int column_q, row_q; // columns and rows quantity.
		Node<T>* root;
	public:
		Sparse_matrix(){
			column_q = -1;
			row_q = -1;
			root = nullptr;
		}

		Sparse_matrix(T value, int x, int y){
			column_q = x;
			row_q = y;
			root = new Node<T>(value,x,y);
			root->right = root;
			root->down = root;
		}

		void set_root(T value, int x, int y){
			if (root != nullptr){
				char input;
				std::cout << "WARNING: root already set.\n" << 
					"Value:" << root->data << " posX: " << root->posX <<
					" posY: " << root->posY << "\nwant to continue?(Y/N)\n";
				std::cin >> input;
				if (input == 'y' || input == 'Y'){
					Node<T>* new_node = new Node<T>(value, x, y);
					root = new_node;
				}else if (input == 'n' || input == 'N')
					return;
			}
			Node<T>* new_node = new Node<T>(value, x, y);
			root = new_node;
		};

		Node<T>* get_root(){
			return root;
		};

		void set_column_q(int value){
			if (column_q != -1){
				char input;
				std::cout << "WARNING: column quantity already set.\n" <<
					"want to continue?(Y/N)\n";
				std::cin >> input;
				if (input == 'y' || input == 'Y')
					column_q = value;
				else if (input == 'n' || input == 'N')
					return;
			}
			column_q = value;
		};
		
		void set_row_q(int value){
			if (row_q != -1){
				char input;
				std::cout << "WARNING: row quantity already set.\n" <<
					"want to continue?(Y/N)\n";
				std::cin >> input;
				if (input == 'y' || input == 'Y')
					row_q = value;
				else if (input == 'n' || input == 'N')
					return;
			}
			row_q = value;
		};

		int get_row_q(){
			return row_q;
		};

		int get_column_q(){
			return column_q;
		};

		bool find_x(int x){
		};

		void insert(T value, int x, int y){
			if(!root){
				cout<<"Root inserted.\n";
				root = new Node<T>(value,x,y);
				root->down = root;
				root->right = root;
			}else{

				if (row_q < y) row_q = y;
				if (column_q < x) column_q = x;

				Node<T>* col_root = nullptr;
				Node<T>* prev = nullptr;
				Node<T>* prev_col = nullptr;
				Node<T>* curr = root;


				//----------------------look for posX
				while (curr->posX < x){
					if (curr->right == root)
						break;
					prev = curr;
					curr = curr->right;

					std::cout <<"Inserting: "<<value<<" - xprev: (" << prev->posX << ", " <<
						prev->posY << ")";
					std::cout << "curr: (" << curr->posX << ", " <<
						curr->posY << ")\n";
				}

				if(curr->posX == x){
					col_root = curr;
				
				//----------------------look for posY
				while (curr->posY < y){
					if (curr->down == col_root)
						break;
					prev_col = curr;
					curr = curr->down;

					std::cout <<"Inserting: "<<value<<" - yprev: (" << prev_col->posX << ", " <<
						prev_col->posY << ")";
					std::cout << "curr: (" << curr->posX << ", " <<
						curr->posY << ")\n";
				}

				if (curr->posY == y){//Data overwrite
				cout<<"Data overwrite!\n";
						curr->data = value;
						
				}
				else if(curr->posY > y && prev_col){//new row
					cout<<"New row inserted.\n";
					Node<T>* new_node = new Node<T>(value,x,y);
					prev_col->down = new_node;
					new_node->down = curr;
					
				}
				else if(curr->posY > y && prev_col == nullptr){//insert at begining of column
					cout<<"Inserted at begining of column.\n";
					Node<T>* new_node = new Node<T>(value, x, y);
					new_node->right = col_root->right;
					new_node->down = col_root;
					if(col_root->right == col_root){
						new_node->right = new_node;
					}
					col_root->right = nullptr;
					if(col_root == root){
						cout<<"Root swapped.\n";
						root = new_node;
					}
					if(col_root->down == col_root){
						col_root->down = new_node;
					}
					else{
						while(curr->down != col_root){
							curr = curr->down;
						}
						curr->down = new_node;
					}
				}
				else if(curr->down == col_root){//new greater value
				cout<<"New greater value in col "<<x<<"\n";
					Node<T>* new_node = new Node<T>(value, x, y);
					curr->down = new_node;
					new_node->down = col_root;
					
				}

			}
			else if(curr->posX > x && prev){//new column insert
					cout<<"New column inserted.\n";
					Node<T>* new_node = new Node<T>(value, x, y);
					prev->right = new_node;
					new_node->right = curr;
					new_node->down = new_node;
					return;
				}
				else if (curr->posX > x && prev == nullptr){//al inicio
					cout<<"New root.\n";
					Node<T>* new_node = root;
					root = new Node<T>(value, x, y);
					root->right = new_node;
					root->down = root;
					if(new_node->right == new_node){
						new_node->right = root;
					}
					else{
						while(curr->right != new_node){
							curr = curr->right;
						}
						curr->right = root;
					}
					return;
				}
				else if (curr->right == root){ //case: new greater posX value.
					cout<<"New greater posX.\n";
					Node<T>* new_node = new Node<T>(value, x, y);
					new_node->right = root;
					new_node->down = new_node;
					curr->right = new_node;
					
					return;
				}
			}
		};

		void print_in_console(){
			int i,j;
			Node<T>* col_root = nullptr;

			for (i = 0; i <= column_q; ++i){
				if (col_root == nullptr)
					col_root = root;
				else
					col_root = col_root->right;

				auto curr = col_root;

				for (j = 0; j <= row_q; ++j){
					if (curr->posX != i || curr->posY != j)
						std::cout << "  0  ";
					else
						std::cout << "  " << curr->data << "  ";

					curr = curr->down;
				}

				std::cout << "\n";
			}
					
		};
		
		void print2_in_console(){
			int i,j;
			Node<T>* row_root = nullptr;

			for (i = 0; i <= row_q; ++i){
				if (row_root == nullptr)
					row_root = root;
				else
					row_root = row_root->down;

				auto curr = row_root;

				for (j = 0; j <= column_q; ++j){
					if (curr->posX == j && curr->posY == i)
						std::cout << "  " << curr->data << "  ";
					else
						std::cout << "  0  ";
					curr = curr->right;
				}

				std::cout << "\n";
			}
					
		}

		void print(){
			Node<T>* cur1 = root;
			Node<T>* col_root = nullptr;

		}

		static Sparse_matrix<T>* identity(int x, int y){
			Sparse_matrix<T>* id = new Sparse_matrix<T>();
			int diag = 0;
			while(diag < x && diag < y){
				id->insert(1,diag,diag);
				diag++;
			}

			return id;
		}

	T get_val(int x, int y){
		if(!root) return 0;
		Node<T>* cur = root;
		Node<T>* col_root = nullptr;
		
		do{
			if(cur->posX == x){

				col_root = cur;

				do{
					if(cur->posY == y){
						return cur->data;
					}
					cur = cur->down;
				}while(cur != col_root && cur->posY <= y);

				return 0;
			}
			cur = cur->right;
		}
		while(cur != root && cur->posX <= x);

		return 0;
	}


};


template<typename T>
Sparse_matrix<T>* add(Sparse_matrix<T>* m1, Sparse_matrix<T>* m2){
	if(m1->get_column_q() == m2->get_column_q() && m1->get_row_q() == m2->get_row_q()){
		Sparse_matrix<T>* result = new Sparse_matrix<T>();
		Node<T>* cur1 = m1->get_root();
		Node<T>* cur2 = m2->get_root();
		Node<T>* res = nullptr;
		Node<T>* col_root = nullptr;
		Node<T>* col_res = nullptr;

		if(cur1){
			do{
				col_root = cur1;

				do{
					result->insert(cur1->data,cur1->posX,cur1->posY);
					cur1 = cur1->down;
				}while(cur1 != col_root);

				cur1 = cur1->right;

			}while(cur1 != m1->get_root());
		}
		else{
			return nullptr;
		}

		res = result->get_root();

		do{
			//Si no se encuentra el x del root de la columna de cur2, insertar toda la columna. sino iterar.
			while(cur2->posX > res->posX){
				res = res->right;
			}
			if(cur2->posX < res->posX){//insert col
				cout<<"Inserting new column.\n";
				col_root = cur2;

				do{
					result->insert(cur2->data,cur2->posX,cur2->posY);
					cur2 = cur2->down;
				}while(cur2 != col_root);

			}
			else if(cur2->posX == res->posX){//Column found, add

				col_root = cur2;
				col_res = res;

				do{
					while(cur2->posY > res->posY){
						res = res->down;
					}

					if(cur2->posY == res->posY){//Add to existing value
					cout<<"Value found, adding!\n";
						res->data += cur2->data;
						res = res->down;
					}
					else if(cur2->posY < res->posY){//Insert new value in column
						cout<<"Inserting new value in column.\n";
						result->insert(cur2->data,cur2->posX,cur2->posY);
					}
					
					cur2 = cur2->down;

					
				}while(cur2 != col_root);
			}

			cur2 = cur2->right;
			res = col_res;

		}while(cur2 != m2->get_root());
			


		return result;
			
	}
	else{
		return nullptr;
	}

}

template<typename T>
Sparse_matrix<T>* mult(Sparse_matrix<T>* m1, Sparse_matrix<T>* m2){
	
}

#endif
