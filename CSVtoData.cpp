#include "CSVtoData.h"

CSVtoData::CSVtoData(const string& filePath) : m_csvIn(filePath) { }

/**
 * Reads the csv file and creates the Data.
 * @return the formatted Data.
 */
vector<Data> CSVtoData::read(){
	string line;
	vector<Data> dataList;
	while (!m_csvIn.eof()) {
		getline(m_csvIn, line);
		if (!line.empty()) {
			dataList.push_back(Data::fromCSVString(line));
		}
	}
	return dataList;
}

CSVtoData::~CSVtoData() {
	m_csvIn.close();
}
