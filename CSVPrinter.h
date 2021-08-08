#ifndef EX1_CSV_PRINTER_H
#define EX1_CSV_PRINTER_H

#include <fstream>
#include "Data.h"

using std::ofstream;

/**
 * A class responsible for printing data in a csv format to a csv file.
 */
class CSVPrinter {
private:
	ofstream m_printer;
public:

	/**
	 * Constructor.
	 * @param path the path to the file to write to.
	 */
	CSVPrinter(const string& path);
	
	/**
	 * Destructor.
	 */
	~CSVPrinter();
	
	/**
	 * Writes a unit of data to the csv file.
	 * @param data the data unit.
	 */
	void operator<<(const Data& data);
	
	/**
	 * Writes a list of data to the csv file.
	 * @param list the Data list.
	 */
	void operator<<(const vector<Data>& list);
	
	/**
	 * Writes a list of strings to the csv file, each in a new line.
	 * @param list the string list.
	 * @return 0 if succeeded.
	 */
	void operator<<(const vector<string>& list);
};

#endif //EX1_CSV_PRINTER_H