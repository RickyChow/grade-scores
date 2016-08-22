#include "scorefile.h"

#include <fstream>
#include <sstream>
#include <algorithm>

#define FINISHED_EXT "-graded"

using namespace std;

ScoreFile::ScoreFile()
{}

void ScoreFile::setFileName(const char* fileName)
{
	_filename = fileName;
}

bool ScoreFile::loadEntries()
{
	ifstream file(_filename);

	if (!file.good())
		return false;

	string line;
	while (getline(file, line))
	{
		//Remove any spaces in the current line
		line.erase(remove_if(line.begin(), line.end(), isspace), line.end());

		istringstream iss(line);
		ScoreEntry scoreEntry;

		for (int i = 0; i < 3; ++i)
		{
			string token;
			//Split string by comma
			getline(iss, token, ',');
			switch (i)
			{
			case 0:
				scoreEntry.setLastName(token);
				break;
			case 1:
				scoreEntry.setFirstName(token);
				break;
			case 2:
				scoreEntry.setScore(atoi(token.c_str()));
				break;
			default:
				break;
			}
		}
		_entries.push_back(scoreEntry);
	}
	return true;
}

bool ScoreFile::saveFile()
{
	ofstream file;
	file.open(outputFilename());

	for (int i = 0; i < (int)_entries.size(); ++i)
	{
		file << _entries[i].lastName() << ", "
			<< _entries[i].firstName() << ", "
			<< _entries[i].score() << "\n";
	}

	file.close();
	return true;
}

std::string ScoreFile::outputFilename() const
{
	string outFileName = _filename;

	//Add output extension to the end of filename
	outFileName.insert(outFileName.find_last_of('.'), FINISHED_EXT);

	return outFileName;
}
