#include <iostream>

#include "scorefile.h"

void usage()
{
	std::cerr << "Usage: \n";
	std::cerr << "	grade-scores <filename>";
}

int main(int argc, char* argv[])
{
	if (argc != 2)
	{
		usage();
		return -1;
	}

	ScoreFile scoreFile;

	scoreFile.setFileName(argv[1]);
	if (!scoreFile.loadEntries())
	{
		std::cerr << "Could not load entries from file\n";
		return -1;
	}

	scoreFile.sort();

	if (!scoreFile.saveFile())
	{
		std::cerr << "Could not save results to file\n";
		return -1;
	}

	std::cout << "Finished: created " << scoreFile.outputFilename();
	return 0;
}

