/*
 * fuzzyDefinitions.h
 *
 *  Created on: Oct 15, 2012
 *      Author: visio
 */

#ifndef FUZZYDEFINITIONS_H_
#define FUZZYDEFINITIONS_H_
#include <stdlib.h>
//#include <math.h>
typedef float fuzzy;

namespace GT{
namespace fuzzy{
/* Minimum function */
float min(const float &a, const float &b);
/* Maximum function */
float max(const float &a, const float &b);
/* Disjunction */
float add(const float &a,const float &b);
/* Conjuction */
float mul(const float &a, const float &b);
/* Fuzzy equality */
float equals(const float &a, const float &b);
/* Fuzzy Inv*/
float inv(const float &a);
float abs(const float &a);
float diff(const float &a, const float &b);

}
}

#endif /* FUZZYDEFINITIONS_H_ */
