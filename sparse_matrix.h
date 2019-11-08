#ifndef SPARSE_MATRIX_H
#define SPARSE_MATRIX_H

#include <vector>
#include "node.h"

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
		};

		Sparse_matrix(T value, int x, int y){
			column_q = x;
			row_q = y;
			root = new Node<T>(value,x,y);
		};

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
			if (root == nullptr){
				row_q = x; column_q = y;
				root = new Node<T>(value, x, y);
				root->right = root;
				root->down = root;
			}else{
				if (row_q < y) row_q = y;
				if (column_q < x) column_q = x;

				std::cout << "root != null\n";
				Node<T>* col_root = nullptr;
				auto prev = root;
				auto curr = root->right;

				//----------------------look for posX
				while (curr->posX < x){
					if (curr->right == root)
						break;
					prev = prev->right;
					curr = curr->right;

					std::cout << "prev: (" << prev->posX << ", " <<
						prev->posY << ")";
					std::cout << "curr: (" << curr->posX << ", " <<
						curr->posY << ")\n";
				}

				if (prev->posX > x){
					auto new_node = new Node<T>(root);
					root = new Node<T>(value, x, y);
					root->right = new_node;
					root->down = root;
				}else if (prev->posX == x){
						col_root = new Node<T>(root);
						prev = root;
						curr = root->down;
					}else if (curr->posX == x){
							col_root = new Node<T>(curr);
							prev = curr;
							curr = curr->down;
				}

				if (col_root == nullptr){ //case: new greater posX value.
					Node<T>* new_node = new Node<T>(value, x, y);
					new_node->right = curr;
					new_node->down = new_node;
					prev->right = new_node;
				}else{//----------------------look for posY
					while (curr->posY < y){
						if (curr->right == col_root)
							break;
						prev = prev->down;
						curr = curr->down;

						std::cout << "prev: (" << prev->posX << ", " <<
							prev->posY << ")";
						std::cout << "curr: (" << curr->posX << ", " <<
							curr->posY << ")\n";
					}

					if (curr->posY == y)
						curr->data = value;

				if (prev->posY > y){
					auto new_node = new Node<T>(col_root);
					col_root = new Node<T>(value, x, y);
				}
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
			

};

#endif
