#include "CSVtoData.h"
#include "KNNClassifier.h"

int main() {
	string classifiedPath = "..\\classified.csv", unclassifiedPath = "..\\Unclassified.csv",
			outputPath = "..\\output.csv";
	if (_argc==3){
		classifiedPath = _argv[0];
		unclassifiedPath = _argv[1];
		outputPath = _argv[2];
	}
	CSVtoData readerClassified(classifiedPath), readerUnclassified(unclassifiedPath);
	vector<Data> classified = readerClassified.read(), unclassified = readerUnclassified.read();
	KNNClassifier classifier(classified);
	vector<string> classes = classifier.classifyAll(unclassified);
}
