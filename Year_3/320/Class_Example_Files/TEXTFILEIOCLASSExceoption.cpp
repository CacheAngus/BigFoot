#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "textfileioe.h"

using namespace std;

int main() {

	string inputFile("Input.txt");
	string outputFile("Output.txt");
	string badFile("IDoNotExist.txt");

	TextFileIO input(inputFile);
	vector<string> data(input.readFile());

	for(unsigned int i = 0; i < data.size(); i++)
		cout << data[i] << endl;

	TextFileIO output(outputFile);
	cout << output.writeFile(data) << " lines written." << endl;

	TextFileIO testBad(badFile);
//	try {
      vector<string> testData(testBad.readFile());
//	} catch (TextFileException& e) {
//		cerr << e.what() << endl;
//	}

	return 0;

} // end main
