#include "KNNClassifier.h"

KNNClassifier::KNNClassifier(vector<Data>& classified) : m_classified(classified) { }

string KNNClassifier::classify(const Data& data, int k) const {
	// Calculating the distance from the classified data.
	vector<pair<double, string>> distances(m_classified.size());
	/*for (auto iterThis = m_data.begin(), iterData = data.m_data.begin();
	iterThis != getData().end() && iterData != data.getData().end(); ++iterThis, ++iterData) {
		dist += pow(*iterThis - *iterData, 2);
	}*/
	auto iterDist = distances.begin();
	auto iterClassified = m_classified.begin();
	for (; iterDist != distances.end() && iterClassified != m_classified.end() ; ++iterDist, ++iterClassified) {
		*iterDist = pair<double, string>(data.distance(*iterClassified), (*iterClassified).getCategory());
	}
	sort(distances.begin(), distances.end(), less<pair<double, string>>());
	map<string, unsigned int> types;
	for (int i = 0; i < k; ++i) {
		if (!types.count(distances[i].second)) {
			types[distances[i].second] = 0;
		}
		types[distances[i].second]++;
	}
	pair<string, unsigned int> classType;
	for (pair<string, unsigned int> typeAmount: types) {
		if (typeAmount.second > classType.second)
			classType = typeAmount;
	}
	return classType.first;
}

vector<string> KNNClassifier::classifyAll(vector<Data>& dataList, int k) const {
	vector<string> classes(dataList.size());
	for (Data& data: dataList) {
		string type = classify(data, k);
		classes.push_back(type);
		data.setCategory(type);
	}
	return classes;
}
