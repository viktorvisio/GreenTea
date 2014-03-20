/*
 * minmax.h
 *
 *  Created on: Mar 20, 2014
 *      Author: visio
 */

#ifndef MINMAX_H_
#define MINMAX_H_

#include <math.h>
#include <cmath>

namespace GT{

#define DEFAULT_RATIO 0.61803f
#define DEFAULT_RATIO_COMPLEMENT 1.0f - DEFAULT_RATIO

double func(double x){
	return cos(x);
}


/**
 *	Hladanie podla zlateho rezu, dokoncit.
 */
template<typename T>
void min(T(*func)(T), T start, T end, T epsilon = 0.00001f){
	T r = start + DEFAULT_RATIO*(end - start);
	T l = end - DEFAULT_RATIO*(end - start);
	T f1;
	T f2;
	T min;
	T minPoint;
	T err;

	do{
		f1 = func(l);
		f2 = func(r);

		if(f1 < f2){
			end = r;

			err = std::abs(f1 - min);

			if(f1 < min){
				min = f1;
				minPoint = l;
			}
		}
		else{
			start = l;
			err = std::abs(f2 - min);

			if(f2 < min){
				min = f2;
				minPoint = r;
			}
		}

		r = start + DEFAULT_RATIO*(end - start);
		l = end - DEFAULT_RATIO*(end - start);

	}while(err > epsilon);


	printf("Min: %f Point: %f\n", min, minPoint);
}

};



#endif /* MINMAX_H_ */
