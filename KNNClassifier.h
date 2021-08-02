#ifndef EX1_KNN_CLASSIFIER_H
#define EX1_KNN_CLASSIFIER_H

#include "Data.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

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
	KNNClassifier(vector<Data>& classified);
	string classify(const Data& data, int k = 1) const;
	vector<string> classifyAll(vector<Data>& dataList, int k = 1) const;
};

#endif //EX1_KNN_CLASSIFIER_H