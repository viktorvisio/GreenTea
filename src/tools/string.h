/*
 * string.h
 *
 *  Created on: Mar 18, 2014
 *      Author: visio
 */

#ifndef STRING_H_
#define STRING_H_

#include <string>

using namespace std;


namespace GT{

char toStringIntbuffer[12]; // static buffer saves us allocations.

const char* toString(const int &input);
const char* toStringHex(const int &input);

};

#endif /* STRING_H_ */
