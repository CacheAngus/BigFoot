/*
 * The declaration file for the TextFileIO class.
 */
#pragma once

#include <string>
#include <vector>
using namespace std;

class TextFileIO {
public:
	TextFileIO(const string& filename);			// The constructor accepts a string filename
	vector<string> readFile() const;			// Reads the file and returns the strings in a vector
	int writeFile(const vector<string>& contents) const;	// Writes the supplied vector to the file, returning
															// the number of lines written.
private:
	string filename;
};