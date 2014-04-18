/*
 * PairingHeap.h
 *
 *  Created on: Mar 18, 2014
 *      Author: visio
 */

#ifndef PAIRINGHEAP_H_
#define PAIRINGHEAP_H_

#include <iostream>
#include "Exception.h"

namespace GT {

template<typename T>
int default_comparator(const T &a, const T &b){
	if(a > b)
		return -1;
	else if(a == b)
		return 0;

	return 1;
}

template<typename T>
class PairingHeap {
private:

	struct heap_node_s{
		T data;
		heap_node_s* right;
		heap_node_s* left;
	};

	typedef int (*binary_comparator_t)(const T &a, const T &b);

	unsigned int count;
	heap_node_s* root;
	binary_comparator_t comparator;

	void pair(heap_node_s* temp){
		temp->right = NULL;

		if(root == NULL){
			root = temp;
			return;
		}

		if(comparator(temp->data, root->data) == -1){
			temp->left = root;
			root = temp;

			if(temp->left == NULL)
				temp->left = root;
			else{
				root->right = temp->left;
				temp->left = root;
			}
		}else{
			temp->right = root->left;
			root->left = temp;
		}

	}

	void delete_recursive(heap_node_s* node){
		if(node == NULL)
			return;

		delete_recursive(node->left);
		delete_recursive(node->right);
		delete node;
	}

public:
	PairingHeap(){
		root = NULL;
		count = 0;
		comparator = default_comparator;
	}

	virtual ~PairingHeap(){
		delete_recursive(root);
	}

	PairingHeap(binary_comparator_t comp){
		root = NULL;
		count = 0;
		comparator = comp;
	}

	void add(T data){
		heap_node_s* temp = new heap_node_s();
		temp->data = data;
		temp->right = NULL;
		temp->left = NULL;

		if(root == NULL){
			root = temp;
			return;
		}

		if(comparator(temp->data, root->data) == -1){
			temp->left = root;
			root = temp;
		}else{
			temp->right = root->left;
			root->left = temp;
		}

		++count;
	}

	T pool(){
		heap_node_s* temp;
		heap_node_s* temp0;
		T r;

		if(root == NULL){
			throw Exception("PairingHeap: There is nothing to pool!");
		}

		r = root->data;
		temp = root->left;

		delete root;
		root = NULL;

		while(temp != NULL){
			temp0 = temp;
			temp = temp0->right;
			pair(temp0);
		}

		--count;
		return r;
	}

	const unsigned int& size(){
		return count;
	}
};

} /* namespace GT */
#endif /* PAIRINGHEAP_H_ */
