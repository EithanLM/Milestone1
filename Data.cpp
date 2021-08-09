#include "Data.h"

Data::Data(const vector<double>& data, const string& category = "unclassified") :
		m_data(data), m_category(category) { }

Data Data::fromCSVString(const string& csvString) {
	string substr, category;
	stringstream ss(csvString);
	vector<double> data;
	while (ss.good()) {
		getline(ss, substr, ',');
		try {
			double dataPiece = stod(substr);
			data.push_back(dataPiece);
		} catch (exception& e) {
			category = substr;
		}
	}
	return (category.empty()) ? Data(data) : Data(data, category);
}

const vector<double>& Data::getData() const { return m_data; }

const string& Data::getCategory() const { return m_category; }

double Data::distance(const Data& data) const {
	double dist = 0;
	if (getData().size() != data.getData().size())
		return -1;
	for (vector<double>::const_iterator iterThis = m_data.begin(), iterData = data.m_data.begin();
		 iterThis != getData().end() && iterData != data.getData().end(); ++iterThis, ++iterData) {
		dist += pow(*iterThis - *iterData, 2);
	}
	return sqrt(dist);
}
