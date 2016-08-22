#ifndef SCORE_SORTER_H
#define SCORE_SORTER_H

#include <vector>

#include "scoreentry.h"

class ScoreSorter
{
public:
	/** Load entries into _entries
	*	@return True if load entries was succesful
	*
	*	this function is used to populate _entries for use in sort();
	*/
	virtual bool loadEntries() = 0;

	/** Sorts entries in descending order
	*	@return True if sort was succesful
	*/
	virtual bool sort();

	/** Returns the current entry list
	*	@return Const reference to the current entry list
	*/
	const std::vector<ScoreEntry>& entries() const;

protected:
	std::vector<ScoreEntry> _entries;
};


#endif