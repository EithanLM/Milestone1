#include <iostream>
#include "CSVtoData.h"
#include "KNNClassifier.h"
#include "CSVPrinter.h"

/**
 * The main method. Receives the paths to the files as arguments and the k in runtime.
 * @args The path to the classified data, then the path to the unclassified data,
 * then the path to the output file. Exactly 3 are required or default values will be used.
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
	KNNClassifier classifier(classified);
	vector<string> categories = classifier.classifyAll(unclassified, k);
	CSVPrinter printer(outputPath);
	printer << categories;
	return 0;
}