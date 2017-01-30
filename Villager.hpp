/*FILE: Villager.hpp
*Author: Michael Huelsman
*Created On: 30 Jan 2017
*Purpose:
*  Header File for the Villager class
*/

#ifndef VILLAGER_HPP
#define VILLAGER_HPP

class Villager{
	Villager();
	Villager(const Villager &copy);

	//villager methods
	int worth();
	bool isAlive();

	//operators
	Villager &operator=(const Villager &copy);
public:
protected:
private:
	bool alive;
	int resources;
};

#endif