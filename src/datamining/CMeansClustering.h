/*
 * CMeansClustering.h
 *
 *  Created on: Mar 22, 2014
 *      Author: visio
 */

#ifndef CMEANSCLUSTERING_H_
#define CMEANSCLUSTERING_H_


#include <list>
#include "../math/Vector.h"
#include "../math/Matrix.h"

namespace GT {

class CMeansClustering {
private:
	std::list<Vector<float> > vectorList;

	Matrix<float>* distanceMatrix; // TODO je matica sposobila na taketo pouzitie?

	Vector<int>* prevAssigments;
	Vector<int>* currentAssigments;


	int numberOfCenters;
	int vectorSize; // Will be min from all vector sizes, in case they differ.
	void getCenterAssigments();

public:
	CMeansClustering(int centers);
	virtual ~CMeansClustering();

	void addVector(const Vector<float> &vec);
	void calculateCenters();

};

} /* namespace GT */

#endif /* CMEANSCLUSTERING_H_ */
