#ifndef SCORE_FILE_H
#define SCORE_FILE_H

#include "scoresorter.h"

class ScoreFile : public ScoreSorter
{
public:
	ScoreFile();

	void setFileName(const char* fileName);

	bool loadEntries() override;
	bool saveFile();

	std::string outputFilename() const;

private:
	std::string _filename;
};


#endif