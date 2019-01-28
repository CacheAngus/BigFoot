#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "textfileioe.h"

using namespace std;

TextFileException::TextFileException(const string& message) : message(message) {}
string& TextFileException::what() { return message; }

TextFileIO::TextFileIO(const string& fname) : filename(fname) {
}

vector<string> TextFileIO::readFile() const {
	ifstream fileIn(filename.c_str());
	vector<string> contents;
	string line;
	if (fileIn.fail()) {
		throw TextFileException("File cannot be read.");
	}
	while (getline(fileIn, line))
		contents.push_back(line);
	fileIn.close();
	return contents;
} // end readFile

int TextFileIO::writeFile(const vector<string>& contents) const {
	unsigned int lineCount = 0;
	ofstream fileOut(filename.c_str());
	unsigned int lines = contents.size();
	if (fileOut.fail()) {
		throw TextFileException("File cannot be written.");
	}
	while (lineCount < lines) {
		fileOut << contents.at(lineCount) << endl;
		lineCount++;
	}
	fileOut.close();
	return lineCount;
} // end writeFile

