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
#include <fstream>
#include "../structures/Exception.h"
//typedef (double)(func*)();

namespace GT{

template<typename T>
class Matrix {

private:
	T** data;
	int rows;
	int columns;
public:

	Matrix(){
		data = NULL;
		rows = -1;
		columns = -1;
	}

	Matrix(int x, int y){
		rows = x;
		columns = y;
		data = new T*[x];

		// Jednoducha inicializacia matice.
		for(int n = 0; n < rows; n++){
			data[n] = new T[columns];
		}
	}

	Matrix(const Matrix<T>& b){
		init(b.rows,b.columns);
		T** d = b.data;
		for(int n = 0; n < rows; n++){
			for(int m = 0; m < columns; m++){
				data[n][m] += d[n][m];
			}
		}
	}

	~Matrix(){
		//printf("Dealokacia\n");
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

	T& getVal(int x, int y) const{
		return data[x][y];
	}

	void setVal(int x, int y, T val){
		data[x][y] = val;
	}

	void mult(T scalar){
		for(int m = 0; m < rows; m++)
			for(int n = 0; n < columns; n++)
				data[m][n] *= scalar;
	}

	Matrix<T>* multTrans(Matrix* source, Matrix* destination){
		if(columns != source->columns){

			throw Exception("Matrix multTrans: Dimension missmatch!");

			//return NULL;
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

	void setAll(T val){
		for(int n = 0; n < rows; n++){
			for(int m = 0; m < columns; m++){
				data[n][m] = val;
			}
		}
	}

	Matrix<T>* mult(Matrix* source, Matrix* destination) const{

		if(columns != source->rows){
			throw Exception("Matrix mult: Dimension missmatch!");
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

	Matrix<T>* mult(Matrix* source, Matrix* destination, unsigned int offset_rows, unsigned int offset_columns) const{

			if(columns != source->rows){
				throw Exception("Matrix mult: Dimension missmatch!");
			}

			if(destination == NULL){
				destination = new Matrix(rows, source->columns);
			}
			else{
				 if(destination->getRows() < rows || destination->getColumns() < source->columns){
					 printf("Error:\tTarget Matrix(%d,%d), Destination Matrix(%d,%d)\n", rows, columns, destination->getRows(), destination->getColumns());
					 throw Exception("Matrix mult: Destination matrix dimension missmatch!");
				 }
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

					dd[offset_rows+m][offset_columns+n] = val;
				}
			}

			return destination;
	}

	Matrix<T> mult(const Matrix& source, unsigned int offset_rows = 0, unsigned int offset_columns = 0) const{

				if(columns != source.rows){
					printf("Error:\tA(%d,%d), B(%d,%d)\n", rows, columns, source.getRows(), source.getColumns());
					throw Exception("Matrix mult: Dimension missmatch!");
				}

				Matrix<T> destination(rows, source.columns);
				//	source
				T** sd = source.data;
				T** dd = destination.data;

				int byc = source.columns;

				double val = 0;

				for(int m = 0; m < rows; m++){
					for(int n = 0; n < byc; n++){
						val = 0;
						for(int ay = 0; ay < columns; ay++)
							val += getVal(m, ay) * sd[ay][n];

						dd[offset_rows+m][offset_columns+n] = val;
					}
				}

				return destination;
	}

	/**
	 * Multiplikacia. Offset urcuje od kade sa zacne zapisovat do cielovej matice.
	 * Parameter func je funkcia, ktora je vykonana nad kazdou vypocitanou hodnotou. Je to na zrychlenie.
	 */
	Matrix<T>* multLambda(Matrix* source, Matrix* destination, unsigned int offset_rows, unsigned int offset_columns, T (*func)(T)) const{

				if(columns != source->rows){
					throw Exception("Matrix mult: Dimension missmatch!");
				}

				if(destination == NULL){
					destination = new Matrix(rows, source->columns);
				}
				else{
					if(destination->getRows() < rows || destination->getColumns() < source->columns){
						printf("Error:\tTarget Matrix(%d,%d), Destination Matrix(%d,%d)\n", rows, columns, destination->getRows(), destination->getColumns());
						throw Exception("Matrix mult: Destination matrix dimension missmatch!");
					}
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

						dd[offset_rows+m][offset_columns+n] = func(val);
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
		printf("\n");
	}

	Matrix<T>* lambda(T (*func)(T)){
		for(int n = 0; n < rows; n++){
			for(int m = 0; m < columns; m++){
				data[n][m] = func(data[n][m]);
			}
		}

		return this;
	}

	static Matrix<T> lambda(const Matrix<T> &source, T (*func)(T)){
		Matrix<T> r(source.getRows(), source.getColumns());
		for(int n = 0; n < source.getRows(); n++){
			for(int m = 0; m < source.getColumns(); m++){
				r.data[n][m] = func(source.data[n][m]);
			}
		}

		return r;
	}

	Matrix<T>* lambda(int from_row, int from_column, T (*func)(T)){
			for(int n = from_row; n < rows; n++){
				for(int m = from_column; m < columns; m++){
					data[n][m] = func(data[n][m]);
				}
			}

			return this;
	}

	void lambda(int from_row, int from_column, T (*func)(T), Matrix<T>* dest){

		T** d = dest->data;

				for(int n = from_row; n < rows; n++){
					for(int m = from_column; m < columns; m++){
						d[n][m] = func(data[n][m]);
					}
				}
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

	const int& getRows() const{
		return rows;
	}

	const int& getColumns() const{
		return columns;
	}

	//TODO Gauss Matrix
	void gauss(){

	}
	//TODO Jordan Matrix
	void jordan(){

	}

	Matrix<T> row(int p){
		Matrix<float> r(1,columns);

		for(int n =0; n < columns; n++){
			r.setVal(0,n, data[p][n]);
		}

		return r;
	}

	Matrix<T> row(int p, int from){
			Matrix<float> r(1,columns-from);

			int t = 0;
			for(int n = from; n < columns; n++){
				r.setVal(0,t, data[p][n]);
				++t;
			}

			return r;
	}


	Matrix<T> cloneMatrix(){
			Matrix<float> r(rows,columns);

			for(int m =0; m < rows; m++)
			for(int n =0; n < columns; n++){
				r.setVal(m,n, data[m][n]);
			}

			return r;
	}


	Matrix<T> operator-(const Matrix<T> &b){

		if(b.rows != rows || b.columns != columns)
			throw Exception("Matrices don't have same size.");

		Matrix<T> nt = Matrix<T>(rows,columns);

		for(int n = 0; n < rows; n++){
			for(int m = 0; m < columns; m++){
				nt.setVal(n,m, (data[n][m] - b.data[n][m]));
			}
		}

		return nt;
	}

	Matrix<T> operator*(const Matrix<T> &b) const{
		return mult(b);
	}

	Matrix<T> dotMult(const Matrix<T> &b){
		if(rows != b.rows || columns != b.columns){
			printf("Error:\tA(%d,%d), B(%d,%d)\n", rows, columns, b.getRows(), b.getColumns());
			throw Exception("Error:\t dotMult Matrices are not same!");
		}

		Matrix<T> r(rows,columns);
		T** d = b.data;
		T** dest = r.data;

		for(int n = 0; n < rows; n++){
			for(int m = 0; m < columns; m++){
				dest[n][m] = data[n][m]*d[n][m];
			}
		}

		return r;
	}

	Matrix<T> operator!(void) const{

		Matrix<T> r(columns, rows);
		T** dest = r.data;

		for(int n = 0; n < rows; n++){
			for(int m = 0; m < columns; m++){
				dest[m][n] = data[n][m];
			}
		}
		return r;
	}

	void operator+=(const Matrix<T> &b){

		if(rows != b.rows || columns != b.columns){

			if(/*rows == -1 && columns == -1 && */data == NULL){
				init(b.rows, b.columns);
				setAll(0);
			}
			else{

				printf("Error:\tA(%d,%d), B(%d,%d)\n", rows, columns, b.getRows(), b.getColumns());
				throw Exception("Error:\t += Matrices are not same!");
			}
		}

		T** d = b.data;

		for(int n = 0; n < rows; n++){
			for(int m = 0; m < columns; m++){
				data[n][m] += d[n][m];
			}
		}

	}

	void operator-=(const Matrix<T> &b){

			if(rows != b.rows || columns != b.columns){

				if(/*rows == -1 && columns == -1 && */data == NULL){
					init(b.rows, b.columns);
					setAll(0);
				}
				else{

					printf("Error:\tA(%d,%d), B(%d,%d)\n", rows, columns, b.getRows(), b.getColumns());
					throw Exception("Error:\t += Matrices are not same!");
				}
			}

			T** d = b.data;

			for(int n = 0; n < rows; n++){
				for(int m = 0; m < columns; m++){
					data[n][m] -= d[n][m];
				}
			}

	}



	void operator=(const Matrix<T> &b){
		init(b.rows,b.columns);

		T** d = b.data;
		for(int n = 0; n < rows; n++){
			for(int m = 0; m < columns; m++){
						data[n][m] = d[n][m];
			}
		}
	}


	void printInfo(const char* name){

		printf("Matrix %s(%d,%d)\n",name,rows,columns);

	}

	void trimColumns(int howmuch){
		columns -= howmuch;
	}


	void initFromFile(std::string filename){

		std::string name;

		std::ifstream myInFile;
		//std::ifstream::in
		myInFile.open(filename.c_str(), std::ifstream::in);

		int p = 0;
		char buffer[1024];

		while(!myInFile.eof() && p < 20)
		{
			myInFile.getline(buffer,1024);
			p++;
		     //   myInFile >> name;
		//   //     a[x][y] = value;
		        printf("N: %s\n", buffer);
		}

		myInFile.close();


	}

	void setRow(int r, T t[]){

		for(int m = 0; m < columns; m++){
			data[r][m] = t[m];
		}
	}

};

};

#endif /* MATRIX_H_ */
