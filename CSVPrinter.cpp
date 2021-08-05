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

int CSVPrinter::operator<<(const vector<string>& list) {
	for (const string& line: list) {
		m_printer << line;
		if (&line != &list.back())
			m_printer << endl;
	}
	return 0;
}
