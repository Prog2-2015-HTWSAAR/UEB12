/**
* compile: g++ -c -Wall -pedantic *.cpp
* compile: g++ -o ueb08 *.o
* @file	LinList.cpp
* @author Andreas Schreiner & Simon Bastian
* Changelog: https://onedrive.live.com/redir?page=view&resid=A24EC16A1F3E72AA!4270&authkey=!AFE0aRW5WKEHg3Q
*
* @details Basierend auf Folz Klasse
* @date 14.06.2015
*/

#include "LinList.h"
#include <sstream>
#include <iostream>
const char* LinList::MELDUNG_LISTE_LEER = "List EMPTY!";
const char* LinList::MELDUNG_FALSCHE_POS  = " Invalid Position!";
const char* LinList::ADD_SPACE = " ";
const char* LinList::CHAINED_LIST = "Linked List: ";
const char* LinList::ELEMENTS = " Element(s)\n";
const char* LinList::NIL_PHRASE = "NIL";
const char* LinList::EMPTY_CHAR_ARRAY = "";

/**
* @brief Konstruktor
*/

template <class T> LinList::LinList() {
	this->first = 0;
	this->last = 0;
	this->size = 0;
}
/**
* @brief Kopierkonstruktor
* @param linlist Referenz auf zu kopierendes Objekt
*/
template <class T> LinList::LinList(const T){
	this->size = 0;
	copyElements(T);
}
/**
* @brief Dekonstruktor
*/
template <class T> LinList::~LinList() {
	clear();
}

template <class T> LinList& LinList::operator=(const T){
	//Zuweisung auf mich selbst?
	if(this == T){
		return *this;
	}
	// bisherige ListElement-Objekte destruieren
	clear();

	//Listenelemente kopieren
	copyElements(linlist);
	return *this;
}
/**
* @brief push_back Haengt Element hinten an die Liste an
* @param t Wert der in die Liste Aufgenommen werden soll
*/
template <class T> void LinList::push_back(InhaltTyp t) {
	ListElement* tmp = new ListElement(t);
	if(isEmpty()){
		first = tmp;
	}else{
		last->next = tmp;
		tmp->previous = last;
	}
	last = tmp;
	size++;
}
/**
* @brief push_front Haengt Element vorne an die Liste an
* @param t Wert der in die Liste Aufgenommen werden soll
*/
template <class T> void LinList::push_front(InhaltTyp t) {
	ListElement* tmp = new ListElement(t);
	if(isEmpty()){
		last = tmp;
	}else{
		first->previous = tmp;
		tmp->next = first;
	}
	first = tmp;
	size++;
}
/**
* @brief pop_back Entfernt letztes Element in der Liste
*/
template <class T> void LinList::pop_back() {
	if(isEmpty()){
		throw LinListException(MELDUNG_LISTE_LEER);
	}
	ListElement* tmp = last->previous;
	delete last;
	size--;
	last = tmp;
	if (last != NULL){
		last->next = NULL;
	}
	if(isEmpty()){
		first = NULL;
	}
}
/**
* @brief pop_front Entfernt erstes Element in der Liste
*/
template <class T> void LinList::pop_front() {
	if(isEmpty()){
		throw LinListException(MELDUNG_LISTE_LEER);
	}
	ListElement* tmp = first->next;
	delete first;
	size--;
	first = tmp;
	if(first){
		first->previous = NULL;
	}
	if(isEmpty()){
		last = NULL;
	}
}
/**
* @brief insert F�gt Element vor pos ein
* @param pos Position des Obj, welches der neue Nachfolger werden soll
* @param t Wert der in die Liste Aufgenommen werden soll
*/
template <class T> void LinList::insert(int pos, InhaltTyp t){
	int suchIndex = 2; //Start bei zwei wegen Vorgaengersuche
	ListElement* tmp1 = first;
	ListElement* tmp2 = NULL;
	ListElement* tmp3 = NULL;
	//TODO Trotzdem Anfang/Ende anhaengen?
	if ((size_t)pos < 1 || (size_t)pos > size){
		throw LinListException(MELDUNG_FALSCHE_POS);
	}

	//Anfang
	if(pos == 1){
		push_front(t);
	}else{
		//Mitte
		//Finde Vorgaenger falls noetig
		while(suchIndex < pos){
			suchIndex++;
			tmp1 = tmp1->next;
		}
		tmp2 = tmp1->next; //Nachfolger merken
		tmp3 = new ListElement(t); // neues Element
		// links zu neuem Element
		tmp1->next = tmp3;
		tmp2->previous = tmp3;
		// links ausgehend von neuem Element
		tmp3->previous = tmp1;
		tmp3->next = tmp2;
		size++;

	}

}
/**
* @brief erase Entfernt Element auf pos
* @param pos Position des zu loeschenden Obj
*/
template <class T> void LinList::erase(int pos){
	int suchIndex = 1;
	ListElement* tmp = first;
	if ((size_t)pos < 1 || (size_t)pos > size){
		throw LinListException(MELDUNG_FALSCHE_POS);
	}
	//Anfang
	if(pos == 1){
		pop_front();
	}else{
		//Ende
		if((size_t)pos >= size){
			pop_back();
		}else{
			//Mitte
			//Finde Element
			while(suchIndex < pos){
				suchIndex++;
				tmp = tmp->next;
			}
			//Vorgaenger und Nachfolger verbinden
			tmp->previous->next = tmp->next;
			tmp->next->previous = tmp->previous;
			//Element loeschen
			delete tmp;
			size--;
		}
	}

}
/**
* @brief clear Entfernt alle Elemente der Liste
*/
template <class T> void LinList::clear(){
	while(!isEmpty()){
		pop_back();
	}
}
/**
* @brief isEmpty Pruefung auf leer
* @returns true == empty false == non empty
*/
template <class T> bool LinList::isEmpty(){
	return (size == 0);
}
/**
 * @brief gibt den Inhalt der Liste als String zurueck
 * @returns Stringrepresentation des LinList-Objekts
 */
template <class T> string LinList::toString() const {
	ostringstream o;
	o << CHAINED_LIST << size << ELEMENTS;
	ListElement* tmp = first;

	while (tmp){
		o << *tmp << ADD_SPACE;
		tmp = tmp->next;
	}
	o << endl;
	return o.str();
}
/**
 * @brief <<Operator zur Ausgabe in einen Stream
 * @param o Streamreferenz
 * @param linList Listenreferenz
 * @returns Referenz auf Stream mit angehaengtem LinListString
 */
template <class T> ostream& operator<<(ostream& o, const LinList& linList){
	return o << linList.toString();
}
/**
 * @brief >>Operator zur Eingabe durch einen Stream
 * @param i Streamreferenz
 * @param linList Listenreferenz
 * @returns Referenz auf Stream mit entnommenem LinListString
 */
template <class T> istream& operator>> (istream& i, LinList& linList){
	linList.clear();
	InhaltTyp t = LinList::EMPTY_CHAR_ARRAY;
	while (i >> t && t != LinList::NIL_PHRASE){
		linList.push_back(t);
	}
	return i;
}
/**
* @brief Operator[] zum Ausgeben einens Elements
* @param pos position
* @returns Referenz auf objekt
*/
template <class T> ListElement& LinList::operator[] (int pos){
	int suchIndex = 1;
	ListElement* tmp = first;
	if ((size_t)pos < 1 || (size_t)pos > size){
		throw LinListException(MELDUNG_FALSCHE_POS);
	}
	while (suchIndex < pos){
		tmp = tmp->next;
		suchIndex++;
	}
	return *tmp;
}

//const ListElement& LinList::operator[](int pos) const{
//	int suchIndex = 1;
//	const ListElement* tmp = first;
//	if ((size_t)pos < 1 || (size_t)pos > size){
//		throw LinListException(MELDUNG_FALSCHE_POS);
//	}
//	while (suchIndex < pos){
//		tmp = tmp->next;
//		suchIndex++;
//	}
//	return *tmp;
//}
/**
* @brief Operator+= zur Append obj
* @param linList Listenreferenz
* @returns Referenz auf Stream mit angehaengtem obj
*/
template <class T> LinList& LinList::operator+= (LinList& linList){
	copyElements(linList);
	return *this;
}
/**
* @brief Operator== Vergleicht obj
* @param linList Listenreferenz
* @returns ergebnis bool value
*/
template <class T> bool LinList::operator== (LinList& linList){
	bool ergebnis = true;
	ListElement* tmp1 = first;
	ListElement* tmp2 = linList.first;

	if(size != linList.size){
		ergebnis = false;
	}
	while(tmp1 &&  tmp2 && ergebnis){
		if(*tmp1!=*tmp2){
			ergebnis = false;
		}
		tmp1 = tmp1->next;
		tmp2 = tmp2->next;
	}
	return ergebnis;
}
/**
* @brief Operator!= Vergleicht obj
* @param linList Listenreferenz
* @returns ergebnis bool value
*/
template <class T> bool LinList::operator!= (LinList& linList){
	return !(*this == linList);
}
/**
* @brief Operator+ Erzeugt neues obj mit den werten 2er objs
* @param linList1 Listenreferenz1
* @param linList2 Listenreferenz2
* @returns Referenz auf objekt
*/
template <class T> LinList& operator+(LinList& linList1, LinList& linList2){
	LinList* tmp = new LinList(linList1);
	*tmp += linList2;
	return *tmp;
}
/**
* @brief copyElements Kopierfunktion
* @param linList Referenz auf LinListen Obj
*/
template <class T> void LinList::copyElements(const LinList& linList){
	ListElement* tmp = linList.first;

	while(tmp != NULL){
		push_back(tmp->inhalt);
		tmp = tmp->next;
	}
}
