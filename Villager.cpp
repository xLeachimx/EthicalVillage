/*FILE: Villager.hpp
*Author: Michael Huelsman
*Created On: 30 Jan 2017
*Purpose:
*  Implmentation File for the Villager class
*/

#include "Villager.hpp"

Villager::Villager(){
	alive = true;
	resources = 0;
}

Villager::Villager(int starting){
	alive = true;
	resources = starting;
}

Villager::Villager(const Villager &copy){
	alive = copy.alive;
	resources = copy.resources;
}

//villager methods
int Villager::worth(){
	return resources;
}

bool Villager::isAlive(){
	return alive;
}

void Villager::addResources(int num){
	resources += num;
}

void Villager::kill(){
	alive = false;
}

//operators
Villager &Villager::operator=(const Villager &copy){
	alive = copy.alive;
	resources = copy.resources;
	return *this;
}