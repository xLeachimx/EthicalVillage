/*FILE: Village.hpp
*Author: Michael Huelsman
*Created On: 30 Jan 2017
*Purpose:
*  Header File for the Village class
*/

#ifndef VILLAGE_HPP
#define VILLAGE_HPP

#include "Villager.hpp"
#include "Culture.hpp"

//Union descriptor is a compact way to split the genetic
//Bitstring into multiple populations
union Descriptor{
	char units[4];
	int number;
};

class Village{
public:
	Village();
	Village(Descriptor population, Culture *cultural);
	Village(const Village &copy);
	~Village();

	//Simulation Functions
	void simulateDay(); //Runs a one day simulation of the village
	void simulatePeriod(int days); //Runs the simulation for the specfied length

	//Status Report Functions
	int getEconomy(); //Returns the amount of money in the economy
	int getAlive(); //Returns the amount of villagers still alive

	//Operators
	Village &operator=(const Village &copy);
	//Boolean operators for genetic comparison
	//This evaluates utility of a village by the culture of the village asked
	bool operator>(const Village &other);
	bool operator<(const Village &other);
	bool operator==(const Village &other);
	bool operator>=(const Village &other);
	bool operator<=(const Village &other);
protected:
private:
	Villager *citizens;
	Culture *culture;
	int day;
	int pop;
};

#endif