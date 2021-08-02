#include "CSVPrinter.h"

CSVPrinter::CSVPrinter(const string& path) : m_printer(path) { }

void CSVPrinter::write(const vector<Data>& list) {
	for (const Data& data: list) {
		m_printer << data;
	}
}

CSVPrinter::~CSVPrinter() {
	m_printer.close();
}
