/*
 * Vector2.h
 *
 *  Created on: Mar 19, 2014
 *      Author: visio
 */

#ifndef VECTOR2_H_
#define VECTOR2_H_

namespace GT {
template<typename T>
class Vector2 {
private:
	T x;
	T y;
public:
	Vector2();
	virtual ~Vector2();
};

} /* namespace GT */

#endif /* VECTOR2_H_ */
