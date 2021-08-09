#ifndef EX1_KNN_CLASSIFIER_H
#define EX1_KNN_CLASSIFIER_H

#include <algorithm>
#include <map>
#include "Data.h"

using std::pair;
using std::map;
using std::less;

/**
 * A class that is responsible for classifying data.
 */
class KNNClassifier {
private:
	vector<Data> m_classified;
public:
	
	/**
	 * Constructor.
	 * @param classified the classified data in a vector.
	 */
	KNNClassifier(vector<Data>& classified);
	
	/**
	 * Classifies a unit of data.
	 * @param data the unit of data.
	 * @param k the k of KNN.
	 * @return the category of the unit according to the algorithm.
	 */
	string classify(const Data& data, int k) const;
	
	/**
	 * Classifies a vector of Data units.
	 * @param dataList the vector.
	 * @param k the k of KNN.
	 * @return a vector of the categories of the units.
	 */
	vector<string> classifyAll(const vector<Data>& dataList, int k) const;
};

#endif //EX1_KNN_CLASSIFIER_H