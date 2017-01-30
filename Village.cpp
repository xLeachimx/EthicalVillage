/*FILE: Village.cpp
*Author: Michael Huelsman
*Created On: 30 Jan 2017
*Purpose:
*  Implementation File for the Village class
*/

#include "Village.hpp"

Village::Village(){
	pop = 0;
	citizens = 0;
	culture = 0;
	day = 0;
}

Village::Village(Descriptor population, Culture *cultural){
	pop = population.number;
	citizens = new Villager[pop];
	culture = cultural;
	day = 0;

	//initialize citizens with resources according to culture
	for(int i = 0;i < pop;i++){
		citizen = culture.starting();
	}
}

Village::Village(const Village &copy){
	pop = copy.pop;
	citizens = new Villager[pop];
	for(int i = 0;i < pop;i++){
		citizens[i] = copy.citizens[i];
	}
	culture = copy.culture;
	day = copy.day;
}

Village::~Village(){
	delete[] citizens;
}

//Simulation Functions
//Runs a one day simulation of the village
void Village::simulateDay(){
	for(int i = 0;i < pop;i++){
		culture.dailyDuties(i,citizens,pop);
	}
}

//Runs the simulation for the specfied length
void Village::simulatePeriod(int days){ 
	for(int i = 0; i < days;i++){
		simulateDay();
	}
}

//Status Report Functions
//Returns the amount of money in the economy
int Village::getEconomy(){
	int count = 0;
	for(int i = 0;i < pop;i++){
		count += citizens[i].worth();
	}
	return count;
}

//Returns the amount of villagers still alive
int Village::getAlive(){
	int count = 0;
	for(int i = 0;i < pop;i++){
		count += citizens[i].isAlive()?1:0;
	}
	return count;
}

//Operators
Village &Village::operator=(const Village &copy){
	if(citizens != 0)delete[] citizens;
	pop = copy.pop;
	citizens = new Villager[pop];
	culture = copy.culture;
	for(int i = 0;i < pop;i++){
		citizens[i] = copy.citizens[i];
	}
	return *this;
}

//Boolean operators for genetic comparison
//This evaluates utility of a village by the culture of the village asked
bool Village::operator>(const Village &other){
	return (culture.utility(this) > culture.utility(&other))
}

bool Village::operator<(const Village &other){
	return (culture.utility(this) < culture.utility(&other))
}

bool Village::operator==(const Village &other){
	return (culture.utility(this) == culture.utility(&other))
}

bool Village::operator>=(const Village &other){
	return (culture.utility(this) >= culture.utility(&other))
}

bool Village::operator<=(const Village &other){
	return (culture.utility(this) <= culture.utility(&other))
}