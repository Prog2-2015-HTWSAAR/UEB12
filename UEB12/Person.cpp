#include "Person.h"
#include <sstream>


Person::Person(string last_Name, string sur_Name) {
	this->vorName = sur_Name;
	this->name = last_Name;
	
}
void Person::ausgeben(std::ostream& o) const {
	o << toString();
}

std::ostream& operator<<(std::ostream& o, const Person& artikel) {
	return o << artikel.toString();
}
std::string Person::toString() const {
	ostringstream o;
	o << name << vorName << "\t";
	return o.str();
}