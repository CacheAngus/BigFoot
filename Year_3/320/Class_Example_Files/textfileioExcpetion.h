/*
 * This is the same class as textfileio.h except that it
 * uses an exception.
 */
#pragma once

#include <string>
#include <vector>
using namespace std;

class TextFileException {
public:
	TextFileException(const string& message);
	string& what();
private:
	string message;
};

class TextFileIO {
public:
	TextFileIO(const string& filename);
	vector<string> readFile() const;
	int writeFile(const vector<string>& contents) const;
private:
	string filename;
};
