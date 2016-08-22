#ifndef SCORE_SORTER_H
#define SCORE_SORTER_H

#include <vector>

#include "scoreentry.h"

class ScoreSorter
{
public:
	virtual bool loadEntries() = 0;

	virtual bool sort();
	const std::vector<ScoreEntry>& entries() const;

protected:
	std::vector<ScoreEntry> _entries;
};


#endif