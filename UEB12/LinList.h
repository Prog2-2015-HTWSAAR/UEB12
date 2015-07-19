/**
* compile: g++ -c -Wall -pedantic *.cpp
* compile: g++ -o ueb08 *.o
* @file	LinList.h
* @author Andreas Schreiner & Simon Bastian
* Changelog: https://onedrive.live.com/redir?page=view&resid=A24EC16A1F3E72AA!4270&authkey=!AFE0aRW5WKEHg3Q
*
* @details Basierend auf Folz Klasse
* @date 14.06.2015
*/
#ifndef LINLIST_H_
#define LINLIST_H_
#include "ListElement.h"

class LinListException : public ElementException {
public:
    LinListException(const string& msg = "") : ElementException(msg) {}
};

template <class T> class LinList {
public:
	/**
	* @brief Konstruktor
	*/
	template<T> LinList();
	/**
	 * Kopierkonstruktor
	 * @param linlist Referenz auf zu kopierendes Objekt
	 */
	template<T> LinList(const LinList&);
	/**
	* @brief Dekonstruktor
	*/
	template<T> ~LinList();
	template<T> LinList& operator=(const T);
	/**
	* @brief push_back Haengt Element hinten an die Liste an
	* @param t Wert der in die Liste Aufgenommen werden soll
	*/
	template<T> void push_back(InhaltTyp T);
	/**
	* @brief push_front Haengt Element vorne an die Liste an
	* @param t Wert der in die Liste Aufgenommen werden soll
	*/
	template<T>	void push_front(InhaltTyp T);
	/**
	* @brief pop_back Entfernt letztes Element in der Liste
	*/
	template<T>	void pop_back();
	/**
	* @brief pop_front Entfernt erstes Element in der Liste
	*/
	template<T>	void pop_front();
	/**
	* @brief insert Fuegt Element vor pos ein
	* @param pos Position des Obj, welches der neue Nachfolger werden soll
	* @param t Wert der in die Liste Aufgenommen werden soll
	*/
	template<T>	void insert(int pos, InhaltTyp T);
	/**
	* @brief erase Entfernt Element auf pos
	* @param pos Position des zu loeschenden Obj
	*/
	template<T> void erase(int pos);
	/**
	* @brief clear Entfernt alle Elemente der Liste
	*/
	template<T>	void clear();
	/**
	* @brief isEmpty Pruefung auf leer
	* @returns true == empty false == non empty
	*/
	template<T>	bool isEmpty();
	/**
	 * @brief gibt den Inhalt der Liste als String zurueck
	 * @returns Stringrepresentation des LinList-Objekts
	 */
	template<T>	string toString() const;
	/**
	 * @brief <<Operator zur Ausgabe in einen Stream
	 * @param o Streamreferenz
	 * @param linList Listenreferenz
	 * @returns Referenz auf Stream mit angehaengtem LinListString
	 */
	template<T> friend ostream& operator<< (ostream& o, const LinList& linList);
	/**
	 * @brief >>Operator zur Eingabe durch einen Stream
	 * @param i Streamreferenz
	 * @param linList Listenreferenz
	 * @returns Referenz auf Stream mit entnommenem LinListString
	 */
	template<T> friend istream& operator>> (istream& i, LinList& linList);
	/**
	* @brief Operator[] zum Ausgeben einens Elements
	* @param pos position
	* @returns Referenz auf objekt
	*/
	template<T> ListElement& operator[](T);

//	const ListElement& operator[](int pos) const;
	/**
	* @brief Operator+= zur Append obj
	* @param linList Listenreferenz
	* @returns Referenz auf Stream mit angehaengtem obj
	*/
	template<T>	LinList& operator+=(LinList& linList);
	/**
	* @brief Operator== Vergleicht obj
	* @param linList Listenreferenz
	* @returns ergebnis bool value
	*/
	template<T>	bool operator==(LinList& linList);
	/**
	* @brief Operator!= Vergleicht obj
	* @param linList Listenreferenz
	* @returns ergebnis bool value
	*/
	template<T>	bool operator!=(LinList& linList);
	/**
	* @brief Operator+ Erzeugt neues obj mit den werten 2er objs
	* @param linList1 Listenreferenz1
	* @param linList2 Listenreferenz2
	* @returns Referenz auf objekt
	*/
	template<T>	friend LinList& operator+(LinList& linList1, LinList& linList2);
	static const char* MELDUNG_LISTE_LEER;
	static const char* MELDUNG_FALSCHE_POS;
	static const char* ADD_SPACE;
	static const char* CHAINED_LIST;
	static const char* ELEMENTS;
	static const char* NIL_PHRASE;
	static const char* EMPTY_CHAR_ARRAY;

private:
	/**
	* @brief copyElements Kopierfunktion
	* @param linList Referenz auf LinListen Obj
	*/
	void copyElements(const LinList& linList);
	size_t size;
	ListElement* first;
	ListElement* last;
};

#endif /* LINLIST_H_ */
