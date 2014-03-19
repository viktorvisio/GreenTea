/*
 * PairingHeap.h
 *
 *  Created on: Mar 18, 2014
 *      Author: visio
 */

#ifndef PAIRINGHEAP_H_
#define PAIRINGHEAP_H_

#include <iostream>

namespace GT {

template<typename T>
class PairingHeap {

	struct heap_node_s{
		T data;
		heap_node_s* right;
		heap_node_s* left;
	};

	unsigned int count;
	heap_node_s* root;

private:
	void pair(heap_node_s* temp){
		temp->right = NULL;

		if(root == NULL){
			root = temp;
			return;
		}

		if(temp->data < root->data){
			temp->left = root;
			root = temp;
		}else{
			temp->right = root->left;
			root->left = temp;
		}
	}

public:
	PairingHeap(){
		root = NULL;
		count = 0;
	}
	virtual ~PairingHeap(){

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

		if(temp->data < root->data){
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
			throw new std::exception; // TODO Vratit nieco ine.
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

	unsigned int size(){
		return count;
	}

};

} /* namespace GT */
#endif /* PAIRINGHEAP_H_ */
