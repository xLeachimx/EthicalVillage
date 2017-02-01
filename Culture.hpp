/*FILE: Culture.hpp
*Author: Michael Huelsman
*Created On: 30 Jan 2017
*Purpose:
*  Header File for the Culture class
*/

#ifndef CULTURE_HPP
#define CULTURE_HPP

class Village;
class Villager;

class Culture{
public:
	//defining characteristics
	virtual void generatePopulation(Villager *citizens, int size) = 0;
	virtual void dailyDuties(int actor, Villager *population, int size) = 0;
	virtual void utility(const Village &ville) = 0;
protected:
private:
};

#endif