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

struct func_ret_s{
	double value;
	double input;
};

/**
 *	Hladanie podla zlateho rezu, dokoncit.
 */
inline void min(double(*func)(double), double start, double end, double epsilon = 0.00000000000001){
	double r = start + DEFAULT_RATIO*(end - start);
	double l = end - DEFAULT_RATIO*(end - start);
	double f1;
	double f2;

	func_ret_s ret;
	ret.value = 9999999999;
	double err;

	do{
		f1 = func(l);
		f2 = func(r);

		if(f1 < f2){
			end = r;
			err = std::abs(f1 - ret.value);

			if(f1 < ret.value){
				ret.value = f1;
				ret.input = l;
			}
		}
		else{
			start = l;
			err = std::abs(f2 - ret.value);

			if(f2 < ret.value){
				ret.value = f2;
				ret.input = r;
			}
		}

		r = start + DEFAULT_RATIO*(end - start);
		l = end - DEFAULT_RATIO*(end - start);

	}while(err > epsilon);

	printf("Min: %f Point: %f\n", ret.value, ret.input);
}

};



#endif /* MINMAX_H_ */
