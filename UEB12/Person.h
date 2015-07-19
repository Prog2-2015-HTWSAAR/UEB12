#include <cstring>
#include <iostream>
using namespace std;

class Person
{
public:
	Person(string last_Name = "Mustermann", string sur_Name = "Max");
	virtual ~Person(){};
	friend ostream& operator<<(std::ostream& o, const Person& artikel);
	virtual string toString() const;
	virtual void ausgeben(std::ostream&) const;

private:
	string name;
	string vorName;
};

