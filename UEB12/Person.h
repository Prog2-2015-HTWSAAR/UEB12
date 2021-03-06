#include <cstring>
#include <iostream>
using namespace std;

class Person
{
public:
	/**
	* @brief Person Konstruktor
	*/
	Person(string last_Name = "Mustermann", string sur_Name = "Max");
	/**
	* @brief ~Person Dekonstruktor
	*/
	virtual ~Person(){};
	/**
	* @brief <<Operator zur Ausgabe in einen Stream
	* @param o Streamreferenz
	* @param person const Person&
	* @returns Referenz auf Stream mit angehaengtem LinListString
	*/
	friend ostream& operator<<(std::ostream& o, const Person& person);
	/**
	* @brief >>Operator zur Eingabe aus einem Stream
	* @param i Streamreferenz
	* @param person const Person&
	* @returns Referenz auf Stream ohne LinListString
	*/
	friend istream& operator>>(std::istream& i, const Person& person);
	/**
	* @brief toString gibt den Inhalt der Person als String zurueck
	* @returns Stringrepresentation des Person-Objekts
	*/
	virtual string toString() const;
	/**
	* @brief ausgeben ausgabe FKT
	*/
	virtual void ausgeben(std::ostream&) const;

private:
	string name;
	string vorName;
};

