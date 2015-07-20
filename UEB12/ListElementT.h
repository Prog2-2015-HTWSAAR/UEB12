/**
* compile: g++ -c -Wall -pedantic *.cpp
* compile: g++ -o ueb08 *.o
* @file	ListElementT.h
* @author Andreas Schreiner & Simon Bastian
* Changelog: https://onedrive.live.com/redir?page=view&resid=A24EC16A1F3E72AA!4270&authkey=!AFE0aRW5WKEHg3Q
*
* @details Basierend auf Folz Klasse
* @date 14.06.2015
*/
#ifndef LISTELEMENT_H_
#define LISTELEMENT_H_
#include "LinListT.h"
#include <string>
#include <stdexcept>
using namespace std;

template<typename T> class ListElementT;
template<typename T>
ostream& operator<<(ostream&, const ListElementT<T>&);
template <typename T>
class ListElementT {
public:
	/**
	* @brief Konstruktor
	* @param inhalt Der Inhalt des Listenelements
	* @param previous Das Vorangegangene Element
	* @param next Das Nachfolgende Element
	*/
	ListElementT(T, ListElementT* =0, ListElementT* =0);
	~ListElementT();
	friend class LinListT<T>;
	/**
	* @brief <<Operator zur ausgabe in einen stream
	* @param o Streamreferenz
	* @param listElement Listenreferenz
	* @returns referenz auf stream mit angehaengtem ListenString
	*/
	friend ostream& operator<< (ostream& o, const ListElementT& listElement);
	/**
	* @brief <<Operator zum auswerten eines isteams
	* @param i Streamreferenz
	* @param listElement Listenreferenz
	* @returns referenz auf stream mit angehaengtem istream Element
	*/
	friend istream& operator>> (istream& i, ListElementT& listElement);
	bool operator==(ListElementT<T>& listElementT);
	bool operator!=(ListElementT<T>& listElementT);

private:

	T value;
	ListElementT* previous;
	ListElementT* next;
};
/**
* @brief Konstruktor
* @param inhalt Der Inhalt des Listenelements
* @param previous Das Vorangegangene Element
* @param next Das Nachfolgende Element
*/
template <typename T>
ListElementT<T>::ListElementT(T inhalt, ListElementT* previous,
		                                   ListElementT* next) {
	this->value = inhalt;
	this->previous = previous;
	this->next = next;
}
/**
* @brief Dekonstruktor
*/
template <typename T>
ListElementT<T>::~ListElementT() {
	// Nothins to do here!
}
/**
* @brief <<Operator zur ausgabe in einen stream
* @param o Streamreferenz
* @param listElement Listenreferenz
* @returns referenz auf stream mit angehaengtem ListenString
*/
template <typename T>
ostream& operator<<(ostream& o, const ListElementT<T>& listElementT){
	o << listElementT.inhalt;
	return o;
}
/**
* @brief <<Operator zum auswerten eines isteams
* @param i Streamreferenz
* @param listElement Listenreferenz
* @returns referenz auf stream mit angehaengtem istream Element
*/
template <typename T>
istream& operator>> (istream& i, ListElementT<T>& listElementT){
	i >> listElementT.inhalt;
	return i;
}
template <typename T>
bool ListElementT<T>::operator==(ListElementT<T>& listElementT){
	bool ergebnis = false;
	if(value == (listElementT.value)){
		ergebnis = true;
	}
	return ergebnis;
}
template <typename T>
bool ListElementT<T>::operator!=(ListElementT<T>& listElementT){
	bool ergebnis = false;
	if(value != (listElementT.value)){
		ergebnis = true;
	}
	return ergebnis;
}


#endif /* LISTELEMENT_H_ */ 
