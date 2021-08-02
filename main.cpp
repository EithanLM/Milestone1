#include "CSVtoData.h"
#include "KNNClassifier.h"
#include "CSVPrinter.h"

/**
 * The main method. Invokes anything needed to classify things.
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
	vector<string> classes = classifier.classifyAll(unclassified);
	CSVPrinter printer(outputPath);
	printer.write(unclassified);
	return 0;
}
