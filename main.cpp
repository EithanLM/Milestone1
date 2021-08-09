#include <iostream>
#include "CSVtoData.h"
#include "KNNClassifier.h"
#include "CSVPrinter.h"

/**
 * The main method. Receives the paths to the files as arguments and the k in runtime- k must be positive and less
 * than the amount of classified data.
 * @parameters The path to the classified data, then the path to the unclassified data,
 * then the path to the output file. Exactly 3 are required or default values will be used.
 * @throw Runtime exception if k is invalid.
 * @return 0 if everything worked. If something went wrong- other numbers.
 */
int main(int argc, char** argv) {
	string classifiedPath = "classified.csv";
	string unclassifiedPath = "Unclassified.csv";
	string outputPath = "output.csv";
	if (argc == 4) {
		classifiedPath = argv[1];
		unclassifiedPath = argv[2];
		outputPath = argv[3];
	}
	std::cout << "Enter the k from the KNN classification" << std::endl;
	int k;
	std::cin >> k;
	CSVtoData readerClassified(classifiedPath), readerUnclassified(unclassifiedPath);
	vector<Data> classified = readerClassified.read(), unclassified = readerUnclassified.read();
	if (k <= 0)
		throw std::runtime_error("Illegal k inserted - k must be positive.");
	KNNClassifier classifier(classified);
	vector<string> categories = classifier.classifyAll(unclassified, k);
	CSVPrinter printer(outputPath);
	printer << categories;
	return 0;
}