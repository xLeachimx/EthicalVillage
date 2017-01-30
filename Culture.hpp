/*FILE: Culture.hpp
*Author: Michael Huelsman
*Created On: 30 Jan 2017
*Purpose:
*  Header File for the Culture class
*/

#ifndef CULTURE_HPP
#define CULTURE_HPP

class Village;

class Culture{
public:
	//defining characteristics
	virtual int starting() = 0;
	virtual void dailyDuties(int actor, Villager *population, int size) = 0;
	virtual void utility(Village *ville) const = 0;
protected:
private:
};

#endif