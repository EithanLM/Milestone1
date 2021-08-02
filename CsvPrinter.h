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
	void write(const vector<Data>& list);
	~CSVPrinter();
};


#endif //EX1_CSV_PRINTER_H
