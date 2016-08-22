#include "scoresorter.h"

#include <algorithm>

bool ScoreSorter::sort()
{
	//Use algorithm sort to sort entries
	std::sort(_entries.rbegin(), _entries.rend());
	return true;
}

const std::vector<ScoreEntry>& ScoreSorter::entries() const
{
	return _entries;
}