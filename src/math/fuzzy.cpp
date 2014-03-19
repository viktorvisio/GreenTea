/*
 * fuzzyDefinitions.cpp
 *
 *  Created on: Oct 22, 2012
 *      Author: visio
 */

#include "fuzzy.h"

namespace GT{
namespace fuzzy{
/* Minimum function */
float min(const float &a, const float &b){
	if(a < b)
		return a;
	else
		return b;
}
/* Maximum function */
float max(const float &a, const float &b){
	if(a > b)
		return a;
	else
		return b;
}
/* Disjunkcia */
float add(const float &a,const float &b){
	return min(1.0f,(a+b));
}

/* Konjukcia */
float mul(const float &a, const float &b){
	return max(0.0f, (a + b - 1.0f));
}

/* Fuzzy equality */
float equals(const float &a, const float &b){
	return 1.0f - min(1.0f,(a - b));
}

float inv(const float &a){
	return 1.0f - a;
}

float abs(const float &a){
	if(a < 0.0f)
		return a*-1.0f;
	else
		return a;
}

float diff(const float &a, const float &b){
	return abs(a - b);

}


}}
