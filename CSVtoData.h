#ifndef EX1_CSV_TO_DATA_H
#define EX1_CSV_TO_DATA_H

#include <fstream>
#include "Data.h"

using std::ifstream;

/**
 * A class responsible for taking data in csv format and creating data pieces from the data.
 */
class CSVtoData {
private:
	ifstream m_csvIn;
public:
	
	/**
	 * Constructor.
	 * @param filePath the path to the file to read from.
	 */
	CSVtoData(const string& filePath);
	
	/**
	 * Reads the csv file and creates the data.
	 * @return the formatted data.
	 */
	vector<Data> read();
	
	/**
	 * Destructor.
	 */
	~CSVtoData();
};

#endif //EX1_CSV_TO_DATA_H
