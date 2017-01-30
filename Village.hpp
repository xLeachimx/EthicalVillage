/*FILE: Village.hpp
*Author: Michael Huelsman
*Created On: 30 Jan 2017
*Purpose:
*  Header File for the Village class
*/

#include "Villager.hpp"

//Union descriptor is a compact way to split the genetic
//Bitstring into multiple populations
union Descriptor{
	char units[4];
	int number;
};

class Village{
public:
	Village(Descriptor population);
	Village(const Village &copy);

	//Simulation Functions
	void simulateDay(); //Runs a one day simulation of the village
	void simulatePeriod(int days); //Runs the simulation for the specfied length

	//Status Report Functions
	int getEconomy(); //Returns the amount of money in the economy
	int getAlive(); //Returns the amount of villagers still alive

	//Operators
	Village &operator=(const Village &copy);
	//Boolean operators for genetic comparison
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
};