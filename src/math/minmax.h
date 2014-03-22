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
#include <limits>

namespace GT{

#define DEFAULT_RATIO 0.61803f
#define DEFAULT_RATIO_COMPLEMENT 1.0f - DEFAULT_RATIO

double func(double x){
	return cos(x);
}

struct func_ret_s{
	double value;	// minimum value
	double input;	// input for function to get minimum value
	int	iterations; // Good to know how many iterations occured.
};

/**
 *	Hladanie podla zlateho rezu, dokoncit.
 */
inline const func_ret_s min(double(*func)(double), double start, double end, double epsilon = 0.00000000000001){
	double r = start + DEFAULT_RATIO*(end - start);
	double l = end - DEFAULT_RATIO*(end - start);
	double f1;
	double f2;

	func_ret_s ret;
	ret.value = std::numeric_limits<double>::max();
	ret.iterations = 0;
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

		++ret.iterations;

	}while(err > epsilon);

	return ret;
}


inline const func_ret_s maxGoldenRatioSearch(double(*func)(double), double start, double end, double epsilon = 0.00000000000001){
	double r = start + DEFAULT_RATIO*(end - start);
	double l = end - DEFAULT_RATIO*(end - start);
	double f1;
	double f2;

	func_ret_s ret;
	ret.value = std::numeric_limits<double>::min();
	ret.iterations = 0;
	double err;

	do{
		f1 = func(l);
		f2 = func(r);

		if(f1 >= f2){
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

		++ret.iterations;

	}while(err > epsilon);

	return ret;
}

};



#endif /* MINMAX_H_ */
