/*
 * string.h
 *
 *  Created on: Mar 18, 2014
 *      Author: visio
 */

#ifndef STRING_H_
#define STRING_H_

#include <string>
#include <vector>

using namespace std;

namespace GT{

#define BUFFSIZE 32
#define LAST_BUFF_INDEX BUFFSIZE - 1

char toStringIntbuffer[BUFFSIZE]; // static buffer, no other allocations needed

const char* toString(const int &input);
const char* toStringHex(const int &input);

vector<string> 	split(const string &src, const string &delimiters);
vector<string> 	splitWithEmpty(const string &src, const string &delimiters);
};

#endif /* STRING_H_ */
