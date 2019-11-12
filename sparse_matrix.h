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
						curr->data = value;
						cout<<"Data overwrite!\n";
				}
				else if(curr->posY > y){//new row
					Node<T>* new_node = new Node<T>(value,x,y);
					prev_col->down = new_node;
					new_node->down = curr;
					cout<<"New row inserted.\n";
				}
				else if(curr->down == col_root){//new greater value
					Node<T>* new_node = new Node<T>(value, x, y);
					curr->down = new_node;
					new_node->down = col_root;
					cout<<"New greater value in col "<<x<<"\n";
				}
				else if(prev_col == nullptr){//insert at begining of column
					Node<T>* new_node = new Node<T>(value, x, y);
					prev_col->right = new_node;
					new_node->right = col_root->right;
					new_node->down = col_root;
					col_root->right = nullptr;
					cout<<"Inserted at begining of column.\n";
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

			}
			else if(curr->posX > x){//new column insert
					Node<T>* new_node = new Node<T>(value, x, y);
					prev->right = new_node;
					new_node->right = curr;
					new_node->down = new_node;
					cout<<"New column inserted.\n";
					return;
				}
				else if (curr->right == root ){ //case: new greater posX value.
					Node<T>* new_node = new Node<T>(value, x, y);
					new_node->right = root;
					new_node->down = new_node;
					curr->right = new_node;
					cout<<"New grater posX.\n";
					return;
				}
				
				else if (prev == nullptr){//al inicio
					Node<T>* new_node = root;
					root = new Node<T>(value, x, y);
					root->right = new_node;
					root->down = root;
					cout<<"New root.\n";
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
			Node<T>* cur = root;
			int prev_ind = 0;
			for(int col = 0; col < column_q; col++){
				cout<<cur->data<<" ";
			}
		}

};

#endif
