#include "Person.h"
#include <sstream>


Person::Person(string last_Name, string sur_Name) {
	this->vorName = sur_Name;
	this->name = last_Name;
	
}
void Person::ausgeben(std::ostream& o) const {
	o << toString();
}

std::ostream& operator<<(std::ostream& o, const Person& person) {
	return o << person.toString();
}
std::istream& operator>>(std::istream& i, const Person& person) {
	 i >> person.name >> person.vorName;
	 return i;
}
std::string Person::toString() const {
	ostringstream o;
	o << vorName << " " << name ;
	return o.str();
}
