/*
 * The implementation of the TextFileIO object.
 */
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "textfileio.h"

using namespace std;

TextFileIO::TextFileIO(const string& fname) : filename(fname) {
}

vector<string> TextFileIO::readFile() const {
	ifstream fileIn(filename.c_str());
	vector<string> contents;
	string line;
	if (fileIn.fail()) {
		cerr << "Unable to open file: " << filename << endl;
		return contents;
	}
	while (getline(fileIn, line))
		contents.push_back(line);
	fileIn.close();
	return contents;
} // end readFile

int TextFileIO::writeFile(const vector<string>& contents) const {
	unsigned int lineCount = 0;
	ofstream fileOut(filename.c_str());
	if (fileOut.fail()) {
		cerr << "Unable to open file: " << filename << endl;
		return lineCount;
	}
	// C++11 for each loop:
	for(string line : contents) {
		fileOut << line << endl;
		lineCount++;
	}
	fileOut.close();
	return lineCount;
} // end writeFile