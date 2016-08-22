#include <iostream>

#include "scorefile.h"

/** Prints usage
*/
void usage()
{
	std::cerr << "Usage: \n";
	std::cerr << "	grade-scores <filename>";
}

/** Main function
*/
int main(int argc, char* argv[])
{
	//Bail if we don't have the correct number of args
	if (argc != 2)
	{
		usage();
		return -1;
	}

	//Load file
	ScoreFile scoreFile;
	scoreFile.setFileName(argv[1]);

	//Bail if we failed
	if (!scoreFile.loadEntries())
	{
		std::cerr << "Could not load entries from file\n";
		return -1;
	}

	//Sort entries
	scoreFile.sort();

	//Save file, bail if we failed
	if (!scoreFile.saveFile())
	{
		std::cerr << "Could not save results to file\n";
		return -1;
	}

	std::cout << "Finished: created " << scoreFile.outputFilename();
	return 0;
}

