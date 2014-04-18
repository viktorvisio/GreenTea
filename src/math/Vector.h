/*
 * Vector.h
 *
 *  Created on: Mar 21, 2014
 *      Author: visio
 */

#ifndef VECTOR_H_
#define VECTOR_H_

/**
 * One dimensional vector used for different mathematical purposes.
 * Implemented as array.
 */
#include <math.h>
#include "../tools/mergesort.h"

template<typename T>
class Vector{
private:
	T* data;
	int size;

public:
	Vector();

	Vector(const Vector& other){
		size = other.size;
		data = other.data;
	}

	Vector(int _size){
		size = _size;
		data = new T[size];
	}

	~Vector(){
		delete[] data;
	}

	inline T& operator[](const int i) const{
		return data[i];
	}


	inline bool operator==(const Vector &other) const{

		int s;

		if(other.size != size)
			return false;

		for(int n = 0; n < size; n++){
			if(data[n] != other[n])
				return false;
		}

		return true;
	}

	/*
	inline bool operator=(const Vector &other) const{

	}*/

	inline Vector operator*(const Vector &other) const{

		Vector v(size);

		for(int n = 0; n < size; n++){
			v[n] = data[n] * (other[n]);
		}

		return v;
	}


	float dot(const Vector &other) const{

		if(other.size != size)
			throw;

		float ret = 0.f;

		for(int n = 0; n < size; n++)
			ret += other[n]*data[n];

		return ret;
	}


	float dist(const Vector &other) const{

		if(other.size != size)
			throw;

		float ret = 0.f;
		float t;

		for(int n = 0; n < size; n++){
			t = other[n]-data[n];
			ret += t*t;
		}

		return sqrt(ret);
	}

	float dist2(const Vector &other) const{

		if(other.size != size)
			throw;

		float ret = 0.f;
		float t;

		for(int n = 0; n < size; n++){
			t = other[n]-data[n];
			ret += t*t;
		}

		return ret;
	}

	void mult(const Vector &other){
		if(other.size != size)
			throw;

		for(int n = 0; n < size; n++){
			data[n] *= other[n];
		}
	}

	Vector clone(){
		Vector v(size);
		for(int n = 0; n < size; n++)
			v[n] = data[n];

		return v;
	}

	void sort(){
		GT::merge_sort(data,size);
	}

	int getSize() const{
		return size;
	}

};



#endif /* VECTOR_H_ */
