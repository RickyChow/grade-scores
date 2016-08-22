#ifndef SCORE_ENTRY_H
#define SCORE_ENTRY_H

#include <string>

class ScoreEntry
{
public:
	ScoreEntry(std::string firstName,
		std::string lastName,
		int score);

	ScoreEntry();

	/** operator< for score entry
	*	@return True if LHS is smaller than RHS
	*	precedence is score, lastname, firstname
	*/
	bool operator<(const ScoreEntry& other) const;
	
	/** operator== for score entry
	*	@return True if LHS == RHS
	*/
	bool operator==(const ScoreEntry& other) const;

	void setFirstName(const std::string& firstName);
	void setLastName(const std::string& lastName);
	void setScore(int score);

	std::string firstName() const;
	std::string lastName() const;
	int score() const;

private:
	std::string _firstName;
	std::string _lastName;
	int _score;
};

#endif