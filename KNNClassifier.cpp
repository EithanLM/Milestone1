#include <iostream>
#include "KNNClassifier.h"

KNNClassifier::KNNClassifier(vector<Data>& classified) : m_classified(classified) { }

string KNNClassifier::classify(const Data& data, int k = 1) const {
	vector<pair<double, string>> distances(m_classified.size());
	for (int i = 0; i < m_classified.size(); ++i) {
		distances[i] = pair<double, string>(data.distance(m_classified[i]), m_classified[i].getCategory());
	}
	sort(distances.begin(), distances.end(), less<pair<double, string>>());
	map<string, unsigned int> classes;
	for (int i = 0; i < k; ++i) {
		if (!classes.count(distances[i].second)) {
			classes[distances[i].second] = 0;
		}
		classes[distances[i].second]++;
	}
	return "class"; // to do
}

vector<string> KNNClassifier::classifyAll(const vector<Data>& dataList, int k) const {
	vector<string> classes(dataList.size());
	for (const Data& data: dataList) {
		classes.push_back(classify(data, k));
	}
	return classes;
}
