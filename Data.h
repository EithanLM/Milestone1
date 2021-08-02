#ifndef EX1_DATA_H
#define EX1_DATA_H

#include <string>
#include <vector>
#include <sstream>
#include <cmath>

using namespace std;

class Data {
private:
	vector<double> m_data;
	string m_category;
public:
	Data(const vector<double>& data, const string& category);
	Data static fromCSVString(const string& csvString);
	const vector<double>& getData() const;
	const string& getCategory() const;
	void setCategory(const string& category);
	double distance(const Data& data) const;
};

ostream& operator<<(ostream& out, Data& data);

#endif //EX1_DATA_H