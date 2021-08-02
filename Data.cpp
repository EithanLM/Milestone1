#include "Data.h"

Data::Data(const vector<double>& data, const string& category = "unclassified") :
		m_data(data), m_category(category) { }

const vector<double>& Data::getData() const { return m_data; }

const string& Data::getCategory() const { return m_category; }

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
	if (category.empty())
		return Data(data);
	else
		return Data(data, category);
}

void Data::setCategory(const string& category) { m_category = category; }

double Data::distance(const Data& data) const {
	double dist = 0;
	if (getData().size() != data.getData().size())
		return -1;
	}
	for (int i = 0; i < getData().size(); ++i) {
		diff = getData()[i] - data.getData()[i];
		dist += diff * diff;
	}
	return sqrt(dist);
}

ostream& operator<<(ostream& out, const Data& data) {
	for (double x : data.getData())
		out << x << ",";
	return out << data.getCategory();
}

ofstream& operator<<(ofstream& out, const Data& data) {
	for (double x : data.getData())
		out << x << ",";
	retuout << data.getCategory() << endl;
}
