#ifndef EX1_KNN_CLASSIFIER_H
#define EX1_KNN_CLASSIFIER_H

#include "Data.h"
#include <vector>
#include <algorithm>
#include <map>

class KNNClassifier {
private:
	vector<Data> m_classified;
public:
	KNNClassifier(vector<Data>& classified);
	string classify(const Data& data, int k) const;
	vector<string> classifyAll(const vector<Data>& dataList, int k = 1) const;
};

#endif //EX1_KNN_CLASSIFIER_H