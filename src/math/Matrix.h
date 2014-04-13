/*
 * Matrix.h
 *
 *  Created on: Dec 19, 2013
 *      Author: visio
 */

#ifndef MATRIX_H_
#define MATRIX_H_

//#include <unistd.h>
//#include <stdlib.h>
#include <stdio.h>
#include <math.h>
//typedef (double)(func*)();

namespace GT{

template<typename T>
class Matrix {

private:
	T** data;
	int rows;
	int columns;
public:

	Matrix(int x, int y){
		rows = x;
		columns = y;
		data = new T*[x];

		// Jednoducha inicializacia matice.
		for(int n = 0; n < rows; n++){
			data[n] = new T[columns];
		}
	}

	~Matrix(){
		for(int n = 0; n < rows; n++){
			delete data[n];
		}
		delete[] data;
	}

	void init(int x, int y){
		if(data != NULL){
			for(int n = 0; n < rows; n++){
				delete data[n];
			}
			delete[] data;
		}

		rows = x;
		columns = y;
		data = new T*[x];

		// Jednoducha inicializacia matice.
		for(int n = 0; n < rows; n++){
			data[n] = new T[columns];
		}
	}

	T* getRowPtr(int x){
		return data[x];
	}

	T& getVal(int x, int y){
		return data[x][y];
	}

	void setVal(int x, int y,const T& val){
		data[x][y] = *val;
	}

	void mult(T scalar){
		for(int m = 0; m < rows; m++)
			for(int n = 0; n < columns; n++)
				data[n][m] *= scalar;
	}

	Matrix<T>* multSimple(Matrix<T>* source){

		return this;
	}

	Matrix<T>* multTrans(Matrix* source, Matrix* destination){
		if(columns != source->columns){
			return NULL;
		}

		if(destination == NULL){
			destination = new Matrix(rows, source->rows);
		}
				//	source
		T** sd = source->data;
		T** dd = destination->data;

		int byc = source->rows;
		double val = 0;

		for(int m = 0; m < rows; m++){
			for(int n = 0; n < byc; n++){
				val = 0;
				for(int ay = 0; ay < columns; ay++)
					val += getVal(m, ay) * sd[n][ay];

				dd[m][n] = val;
			}
		}

		return destination;
	}

	void mult(int x, int y, T val){
		data[x][y] *= val;
	}

	Matrix<T>* mult(Matrix* source, Matrix* destination){

		if(columns != source->rows){
			return NULL;
		}

		if(destination == NULL){
			destination = new Matrix(rows, source->columns);
		}
		//	source
		T** sd = source->data;
		T** dd = destination->data;

		int byc = source->columns;

		double val = 0;

		for(int m = 0; m < rows; m++){
			for(int n = 0; n < byc; n++){
				val = 0;
				for(int ay = 0; ay < columns; ay++)
					val += getVal(m, ay) * sd[ay][n];

				dd[m][n] = val;
			}
		}

		return destination;
	}

	void printS(int fd){
		for(int n = 0; n < rows; n++){
			for(int m = 0; m < columns; m++){

				printf("%F\t", data[n][m]);
			}

			printf("\n");

		}
	}

	Matrix<T>* lambda(T (*func)(T)){
		for(int n = 0; n < rows; n++){
			for(int m = 0; m < columns; m++){
				data[n][m] = func(data[n][m]);
			}
		}

		return this;
	}

	void sub(Matrix<T>* b){
		for(int n = 0; n < rows; n++){
			for(int m = 0; m < columns; m++){
				data[n][m] = data[n][m] - b->getVal(n,m);   //nt.setVal(n,m, &(data[n][m] - b.getVal(n,m)));
			}
		}

	}

	double length(){

		double l = 0.0;
		for(int n = 0; n < rows; n++){
			for(int m = 0; m < columns; m++){
				l += data[n][m]*data[n][m];
			}
		}
		return sqrt(l);
	}

	double length2(){
		double l = 0.0;
		for(int n = 0; n < rows; n++){
			for(int m = 0; m < columns; m++){
				l += data[n][m]*data[n][m];
			}
		}
		return l;
	}

	void add(Matrix<T>* b){
		for(int n = 0; n < rows; n++){
			for(int m = 0; m < columns; m++){
				data[n][m] = data[n][m] + b->getVal(n,m);   //nt.setVal(n,m, &(data[n][m] - b.getVal(n,m)));
			}
		}
	}

	Matrix<T> clone(){
		Matrix<T> mat(rows,columns);
		for(int n = 0; n < rows; n++){
			for(int m = 0; m < columns; m++){
				mat.setVal(n,m, &data[n][m]);
			}
		}
		return mat;
	}

	const int& getRows(){
		return rows;
	}

	const int& getColumns(){
		return columns;
	}

	//TODO Gauss Matrix
	void gauss(){

	}
	//TODO Jordan Matrix
	void jordan(){

	}

	/*
	Matrix<T>& operator-(Matrix<T> &b){

		//if(b.xc != xc && b.yc != yc)
		//	return NULL;

		Matrix<T> nt = Matrix<T>(xc,yc);

		for(int n = 0; n < xc; n++){
			for(int m = 0; m < yc; m++){
				//nt.setVal(n,m, &(data[n][m] - b.getVal(n,m)));
			}
		}

		return nt;
	}
	*/
};

};

#endif /* MATRIX_H_ */
