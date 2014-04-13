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
	std::list<const Vector<float>* > vectorList;
	//Matrix<float> distanceMatrix; // TODO je matica sposobila na taketo pouzitie?
	Vector<int>* prevAssigments;
	Vector<int>* currentAssigments;
	//Vector<Vector<float> > centers; // ako sa bude vector inicializovat?
	int numberOfCenters;
	int vectorSize; // Will be min from all vector sizes, in case they differ.

public:
	CMeansClustering(int centers, int vector_attributes, int vector_count);
	virtual ~CMeansClustering();
	void addVector(const Vector<float>* vec);
	void calculateCenters();
};

} /* namespace GT */

#endif /* CMEANSCLUSTERING_H_ */
