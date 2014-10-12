/*
 * BinaryTree.h
 *
 *  Created on: Oct 12, 2014
 *      Author: visio
 */

#ifndef BINARYTREE_H_
#define BINARYTREE_H_

#include <stdlib.h>
#include <iostream>

namespace OWA {

template<class T>
class BinaryTree {
private:

	struct bintree_node_s{
		T data;
		bintree_node_s* left;
		bintree_node_s* right;
		bintree_node_s* parent;
	};

	size_t count;

	bintree_node_s* root;



	bintree_node_s* lowestleft(bintree_node_s* node){

	}

	bintree_node_s* lowestright(bintree_node_s* node){

		/*parent = temp;
		lowestNode = temp->left;

		if(lowestNode->right){
			while(lowestNode->right){
				parent = lowestNode;
				lowestNode = lowestNode->right;
			}
			parent->right = lowestNode->left;
		}else{
			parent->left = lowestNode->left;
		}*/
		return node;
	}

	int (* comparator_ptr)(const T &a, const T &b);

public:

	const size_t& size(){
		return count;
	}


	BinaryTree(int (* comparator)(const T &a, const T &b)){
			root = NULL;
			comparator_ptr = comparator;
			count = 0;
		}

	void insert(T element){
		bintree_node_s* node = new bintree_node_s;
		node->left = NULL;
		node->right = NULL;

		node->data = element;

		if(root == NULL){
			++count;
			root = node;
			return;
		}

		bintree_node_s* temp = root;

		while(temp){

			int comp = comparator_ptr(temp->data, element);

			switch(comp){
			case 0:
				delete node;
				return;
			case 1:

				if(temp->right == NULL){
					temp->right = node;
					++count;
					return;
				}else{
					temp = temp->right;
				}

				break;
			case -1:

				if(temp->left == NULL){
					temp->left = node;
					++count;
					return;
				}else{
					temp = temp->left;
				}

				break;

			}
		}

	}

	T find(T key){

		bintree_node_s* temp = root;

		while(temp){
			int comp = comparator_ptr(temp->data, key);

			switch(comp){

			case 0:
				return temp->data;
			case 1:

				if(temp->right == NULL){
					return NULL;
				}else{
					temp = temp->right;
				}

				break;
			case -1:

				if(temp->left == NULL){
					return NULL;
				}else{
					temp = temp->left;
				}


				break;
			}
		}
		return NULL;
	}

	T remove(T key){

		bintree_node_s* temp = root;
		bintree_node_s* temp_prev = NULL;
		bintree_node_s* lowestNode = NULL; // Nahrada za prvok. Moze byt aj NULL.
		bintree_node_s* parent = NULL;
		T ret_val;

		while(temp){

			int comp = comparator_ptr(temp->data, key);

			switch(comp){

			case 0:

				ret_val = temp->data;

				if(temp->right){

					parent = temp;
					lowestNode = temp->right;

					if(lowestNode->left){
						while(lowestNode->left){
							parent = lowestNode;
							lowestNode = lowestNode->left;
						}
						parent->left = lowestNode->right;
					}else{
						parent->right = lowestNode->right;
					}

				}else if(temp->left){

					parent = temp;
					lowestNode = temp->left;

					if(lowestNode->right){
						while(lowestNode->right){
							parent = lowestNode;
							lowestNode = lowestNode->right;
						}
						parent->right = lowestNode->left;
					}else{
						parent->left = lowestNode->left;
					}
				}

				// Ak je lowestNode null, znamena to, ze node nema potomkov a preto je potrebne ho Nullovat.
				if(temp_prev){
					if(temp_prev->left == temp){
						temp_prev->left = lowestNode;
					}else{
						temp_prev->right = lowestNode;
					}
				}else{
					root = lowestNode;
				}

				if(lowestNode){
					lowestNode->right = temp->right;
					lowestNode->left = temp->left;
				}

				delete temp;
				--count;
				return ret_val;
			case 1:

				if(temp->right != NULL){
					temp_prev = temp;
					temp = temp->right;
				}else{
					return NULL;
				}
				break;
			case -1:

				if(temp->left != NULL){
					temp_prev = temp;
					temp = temp->left;
				}else{
					return NULL;
				}
				break;
			}
		}

		return NULL;
	}

	void printa(){

		int t = print(root);
		std::cout << "Print:" << t << std::endl;
	}

	int print(bintree_node_s* node){

		int pocet = 0;

		if(node == NULL){
			return 0;
		}


		pocet += print(node->left);
		std::cout << node->data << ", \n";
		pocet += print(node->right);

		return pocet+1;
	}

};

} /* namespace OWA */

#endif /* BINARYTREE_H_ */
