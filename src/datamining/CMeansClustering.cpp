/*
 * CMeansClustering.cpp
 *
 *  Created on: Mar 22, 2014
 *      Author: visio
 */

#include "CMeansClustering.h"

namespace GT{

CMeansClustering::CMeansClustering(int centers, int vector_attributes, int vector_count)
//: distanceMatrix(vector_count, vector_count),
// prevAssigments(vector_count),
// currentAssigments(vector_count)
{
	numberOfCenters = centers;
	vectorSize = vector_attributes;
	//vector_count;

	prevAssigments = NULL;
	currentAssigments = NULL;
	vectorSize = 0;
	numberOfCenters = 0; // ?
}

CMeansClustering::~CMeansClustering(){

}

void CMeansClustering::addVector(const Vector<float>* vec){

	if(vec->getSize() != vectorSize)
		throw;

	//vectorList.push_back(vec);
}

void CMeansClustering::calculateCenters(){

//	Matrix<float> distance(vectorSize, vectorList.size());


}



};


