/*
 * This program tests the TextFileIO object included in the textfileio header
 * file.
 */
#include <iostream>
#include <string>
#include <vector>

#include "textfileio.h"

using namespace std;

int main() {

	string inputFile("Lumberjack.txt");
	string outputFile("Output.txt");

	TextFileIO input(inputFile);
	vector<string> data(input.readFile());

	// C++11 for each loop:
	for(auto line : data)
		cout << line << endl;

	TextFileIO output(outputFile);
	cout << output.writeFile(data) << " lines written." << endl;

	return 0;

} // end main