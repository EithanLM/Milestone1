#ifndef EX1_DATA_H
#define EX1_DATA_H

#include <string>
#include <vector>
#include <sstream>
#include <cmath>

using std::vector;
using std::string;
using std::endl;
using std::stringstream;
using std::exception;

/**
 * A class representing a unit of data: its numerical data and its category.
 */
class Data {
private:
	vector<double> m_data;
	string m_category;
public:
	
	/**
	 * Constructor.
	 * @param data the numerical data of the data unit.
	 * @param category the category of the data unit.
	 */
	Data(const vector<double>& data, const string& category);
	
	/**
	 * A static method that creates a Data piece from a string in csv format.
	 * @param csvString the string.
	 * @return the Data piece.
	 */
	static Data fromCSVString(const string& csvString);
	
	/**
	 * Getter of the numerical data.
	 * @return the numerical data in a vector.
	 */
	const vector<double>& getData() const;
	
	/**
	 * Getter of the category.
	 * @return the category.
	 */
	const string& getCategory() const;
	
	/**
	 * Setter of the category.
	 * @param category the new category.
	 */
	void setCategory(const string& category);
	
	/**
	 * Calculates the Euclidean distance from the given data.
	 * @param data the given data.
	 * @return the distance.
	 */
	double distance(const Data& data) const;
};

#endif //EX1_DATA_H