#ifndef EX1_CSV_TO_DATA_H
#define EX1_CSV_TO_DATA_H

#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include "Data.h"

using std::ifstream;

/**
 * A class responsible for taking data in csv format and creating Data pieces from the data.
 */
class CSVtoData {
private:
	ifstream m_csvIn;
public:
	CSVtoData(const string& filePath);
	vector<Data> read();
	~CSVtoData();
};


#endif //EX1_CSV_TO_DATA_H
