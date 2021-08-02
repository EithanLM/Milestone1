#ifndef EX1_CSV_PRINTER_H
#define EX1_CSV_PRINTER_H

#include <fstream>
#include "Data.h"

using std::string;
using std::ofstream;
using std::endl;

class CSVPrinter {
private:
	ofstream m_printer;
public:
	CSVPrinter(const string& path);
	~CSVPrinter();
	int operator<<(const vector<Data>& list);
};


#endif //EX1_CSV_PRINTER_H
