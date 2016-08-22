#include "scoreentry.h"

ScoreEntry::ScoreEntry(std::string firstName,
	std::string lastName,
	int score)
	:_firstName(firstName),
	_lastName(lastName),
	_score(score)
{

}

ScoreEntry::ScoreEntry()
	:_score(0)
{
}

bool ScoreEntry::operator<(const ScoreEntry& other) const
{
	if (_score == other._score)
	{
		if (_lastName == other._lastName)
		{
			return _firstName > other._firstName;
		}
		return _lastName > other._lastName;
	}
	return _score < other._score;
}

bool ScoreEntry::operator==(const ScoreEntry& other) const
{
	return _score == other._score &&
		_lastName == other._lastName &&
		_firstName == other._firstName;
}

void ScoreEntry::setFirstName(const std::string& firstName)
{
	_firstName = firstName;
}
void ScoreEntry::setLastName(const std::string& lastname)
{
	_lastName = lastname;
}
void ScoreEntry::setScore(int score)
{
	_score = score;
}

std::string ScoreEntry::firstName() const
{
	return _firstName;
}
std::string ScoreEntry::lastName() const
{
	return _lastName;
}

int ScoreEntry::score() const
{
	return _score;
}