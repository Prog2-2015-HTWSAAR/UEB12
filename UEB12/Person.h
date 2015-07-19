#include <cstring>
#include <iostream>
using namespace std;

class Person
{
public:
	Person(string last_Name, string sur_Name);
	virtual ~Person(){};
	friend ostream& operator<<(std::ostream& o, const Person& artikel);
	virtual string toString() const;
	virtual void ausgeben(std::ostream&) const;

private:
	string name;
	string vorName;
};

