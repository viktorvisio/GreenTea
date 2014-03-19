/*
 * Exception.h
 *
 *  Created on: Mar 19, 2014
 *      Author: visio
 */

#ifndef EXCEPTION_H_
#define EXCEPTION_H_

#include <string>

namespace GT {

class Exception : public std::exception{
	std::string msg;
public:
	Exception(const char *text);
	virtual const char* what() const throw();
	~Exception() throw();
};

} /* namespace GT */

#endif /* EXCEPTION_H_ */
