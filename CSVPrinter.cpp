#include "CSVPrinter.h"

CSVPrinter::CSVPrinter(const string& path) : m_printer(path) { }

CSVPrinter::~CSVPrinter() { m_printer.close(); }

void CSVPrinter::operator<<(const Data& data) {
	for (double x : data.getData())
		m_printer << x << ",";
	m_printer << data.getCategory();
}

void CSVPrinter::operator<<(const vector<Data>& list) {
	for (const Data& data: list) {
		(*this) << data;
		m_printer << endl;
	}
}

void CSVPrinter::operator<<(const vector<string>& list) {
	for (const string& line: list) {
		m_printer << line;
		if (&line != &list.back())
			m_printer << endl;
	}
}
