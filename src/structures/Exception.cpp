/*
 * Exception.cpp
 *
 *  Created on: Mar 19, 2014
 *      Author: visio
 */

#include "Exception.h"

namespace GT {

Exception::Exception(const char *text) {
	// TODO Auto-generated constructor stub
	msg = text;
}

Exception::~Exception() throw(){
}

const char* Exception::what() const throw(){
	return msg.c_str();
}

} /* namespace GT */
