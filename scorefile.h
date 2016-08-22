#ifndef SCORE_FILE_H
#define SCORE_FILE_H

#include "scoresorter.h"

class ScoreFile : public ScoreSorter
{
public:
	ScoreFile();

	/**	Sets the file name of the file we wish to load
	*	@param fileName Filename of file we wish to load
	*/
	void setFileName(const char* fileName);

	/** Populates the score entries
	*	@return True if operation was successful
	*/
	bool loadEntries() override;

	/**	Saves file to <filename>-graded.<ext>
	*	@return True if save was successful
	*/
	bool saveFile();

	/** Returns the output filename
	*	@return Output filename, <filename>-graded.<ext>
	*/
	std::string outputFilename() const;

private:
	std::string _filename;
};


#endif