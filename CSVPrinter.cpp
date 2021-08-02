#include "CSVPrinter.h"

CSVPrinter::CSVPrinter(const string& path) : m_printer(path) { }

CSVPrinter::~CSVPrinter() {
	m_printer.close();
}

/**
 * Writes a list of Data to the csv file.
 * @param list the Data list
 * @return 0 if succeeded.
 */
int CSVPrinter::operator<<(const vector<Data>& list) {
	for (const Data& data: list) {
		m_printer << data;
	}
	return 0;
}
