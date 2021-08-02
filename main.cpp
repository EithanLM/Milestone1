#include "CSVtoData.h"
#include "KNNClassifier.h"
#include "CSVPrinter.h"

/**
 * The main method.
 * @args The path to the classified data, then the path to the unclassified data,
 * then the path to the output file.
 * Exactly 3 are required or default values will be used.
 * @return 0 if everything worked. If something went wrong- other numbers.
 */
int main() {
	string classifiedPath = ".\\classified.csv";
	string unclassifiedPath = ".\\Unclassified.csv";
	string outputPath = ".\\output.csv";
	if (_argc==3){
		classifiedPath = _argv[0];
		unclassifiedPath = _argv[1];
		outputPath = _argv[2];
	}
	CSVtoData readerClassified(classifiedPath), readerUnclassified(unclassifiedPath);
	vector<Data> classified = readerClassified.read(), unclassified = readerUnclassified.read();
	KNNClassifier classifier(classified);
	std::cout << "Enter the k from the KNN classification" << std::endl;
	int k;
	std::cin >> k;
	vector<string> classes = classifier.classifyAll(unclassified, k);
	CSVPrinter printer(outputPath);
	printer << unclassified;
	return 0;
}
