/**
* compile: g++ -c -Wall -pedantic *.cpp
* compile: g++ -o ueb12 *.o
* @file	LinListT.h
* @author Andreas Schreiner & Simon Bastian
* Changelog: https://onedrive.live.com/redir?page=view&resid=A24EC16A1F3E72AA!4270&authkey=!AFE0aRW5WKEHg3Q
*
* @details Basierend auf Folz Klasse
* @date 14.06.2015
*/
#ifndef LINLIST_H_
#define LINLIST_H_
#include <stdexcept>
#include <iostream>
#include <sstream>
using namespace std;
template<typename T> class LinListT;
template<typename T>
ostream& operator<<(ostream&, const LinListT<T>&);
template<typename T>
istream& operator>>(istream&, LinListT<T>&);
template<typename T>
LinListT<T>& operator+(LinListT<T>& linListT1, LinListT<T>& linListT2);

/**
 * Doppelt-verkettete Lineare Liste
 *
 * @author	folz
 * @version
 * @date	20.05.2012
 */
template<typename T>
class LinListT {
public:
	/**
	* @brief Konstruktor
	*/
	LinListT();
	/**
	 * Kopierkonstruktor
	 * @param linlist Referenz auf zu kopierendes Objekt
	 */
	LinListT(const LinListT&);
	/**
	* @brief Dekonstruktor
	*/
	~LinListT();
	LinListT& operator=(const LinListT& linList);
	/**
	* @brief push_back Haengt Element hinten an die Liste an
	* @param t Wert der in die Liste Aufgenommen werden soll
	*/
	void push_back (T t);
	/**
	* @brief push_front Haengt Element vorne an die Liste an
	* @param t Wert der in die Liste Aufgenommen werden soll
	*/
	void push_front(T t);
	/**
	* @brief pop_back Entfernt letztes Element in der Liste
	*/
	T& pop_back();
	/**
	* @brief pop_front Entfernt erstes Element in der Liste
	*/
	T& pop_front();
	/**
	* @brief insert Fuegt Element vor pos ein
	* @param pos Position des Obj, welches der neue Nachfolger werden soll
	* @param t Wert der in die Liste Aufgenommen werden soll
	*/
	void insert(int pos, T t);
	/**
	* @brief erase Entfernt Element auf pos
	* @param pos Position des zu loeschenden Obj
	*/
	void erase(int pos);
	/**
	* @brief clear Entfernt alle Elemente der Liste
	*/
	void clear();
	/**
	* @brief isEmpty Pruefung auf leer
	* @returns true == empty false == non empty
	*/
	bool isEmpty();
	/**
	 * @brief gibt den Inhalt der Liste als String zurueck
	 * @returns Stringrepresentation des LinListT-Objekts
	 */
	string toString() const;
	/**
	 * @brief <<Operator zur Ausgabe in einen Stream
	 * @param o Streamreferenz
	 * @param linList Listenreferenz
	 * @returns Referenz auf Stream mit angehaengtem LinListTString
	 */
	friend ostream& operator<< <>(ostream& o, const LinListT<T>& linListT);
	/**
	 * @brief >>Operator zur Eingabe durch einen Stream
	 * @param i Streamreferenz
	 * @param linList Listenreferenz
	 * @returns Referenz auf Stream mit entnommenem LinListTString
	 */
	friend istream& operator>> <>(istream& i, LinListT<T>& linList);
	/**
	* @brief Operator[] zum Ausgeben einens Elements
	* @param pos position
	* @returns Referenz auf objekt
	*/
	T& operator[] (int pos);

//	const ListElementT& operator[](int pos) const;
	/**
	* @brief Operator+= zur Append obj
	* @param linList Listenreferenz
	* @returns Referenz auf Stream mit angehaengtem obj
	*/
	LinListT& operator+=(LinListT& linListT);
	/**
	* @brief Operator== Vergleicht obj
	* @param linList Listenreferenz
	* @returns ergebnis bool value
	*/
	bool operator==(LinListT& linListT);
	/**
	* @brief Operator!= Vergleicht obj
	* @param linList Listenreferenz
	* @returns ergebnis bool value
	*/
	bool operator!=(LinListT& linListT);
	/**
	* @brief Operator+ Erzeugt neues obj mit den werten 2er objs
	* @param linList1 Listenreferenz1
	* @param linList2 Listenreferenz2
	* @returns Referenz auf objekt
	*/
	friend LinListT<T>& operator+ <>(LinListT<T>& linListT1, LinListT<T>& linListT2);

private:
	struct ElementT {
		T value;
		ElementT *previous;
		ElementT *next;
	};
	ElementT* first; // cpp11 :(
	ElementT* last; // cpp11 :(
	/**
	* @brief copyElements Kopierfunktion
	* @param linList Referenz auf LinListTen Obj
	*/
	void copyElements(const LinListT& linList);
	size_t size;
};
/**
* @brief Konstruktor
*/
template <typename T>
LinListT<T>::LinListT() {
	this->first = 0;
	this->last = 0;
	this->size = 0;
}
/**
* @brief Kopierkonstruktor
* @param linlist Referenz auf zu kopierendes Objekt
*/
template<typename T>
LinListT<T>::LinListT(const LinListT& linlist){
	this->size = 0;
	copyElements(linlist);
}
/**
* @brief Dekonstruktor
*/
template<typename T>
LinListT<T>::~LinListT() {
	clear();
}
template<typename T>
LinListT<T>& LinListT<T>::operator=(const LinListT<T>& linlist){
	//Zuweisung auf mich selbst?
	if(this == &linlist){
		return *this;
	}
	// bisherige ListElementT-Objekte destruieren
	clear();

	//Listenelemente kopieren
	copyElements(linlist);
	return *this;
}
/**
* @brief push_back Haengt Element hinten an die Liste an
* @param t Wert der in die Liste Aufgenommen werden soll
*/
template<typename T>
void LinListT<T>::push_back(T t) {
	ElementT* tmp = new ElementT();
	tmp->value = t;
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
template<typename T>
void LinListT<T>::push_front(T t) {
	ElementT* tmp = new ElementT();
	tmp->value = t;
	if(isEmpty()){
		last = tmp;
	}else{
		first->previous = tmp;
		tmp->next = first;
	}
	first = tmp;
	tmp->previous = NULL;
	size++;
}
/**
* @brief pop_back Entfernt letztes Element in der Liste
*/
template<typename T>
T& LinListT<T>::pop_back() {
	if(isEmpty()){
		throw logic_error("List EMPTY!");
	}
	ElementT* erg = last;
	ElementT* tmp = last->previous;
	size--;
	last = tmp;
	if (last != NULL){
		last->next = NULL;
	}
	if(isEmpty()){
		first = NULL;
	}
	return erg->value;
}
/**
* @brief pop_front Entfernt erstes Element in der Liste
*/
template<typename T>
T& LinListT<T>::pop_front() {
	if(isEmpty()){
		throw logic_error("List EMPTY!");
	}
	ElementT* erg = first;
	ElementT* tmp = first->next;
	size--;
	first = tmp;
	if(first){
		first->previous = NULL;
	}
	if(isEmpty()){
		last = NULL;
	}
	return erg->value;
}
/**
* @brief insert F�gt Element vor pos ein
* @param pos Position des Obj, welches der neue Nachfolger werden soll
* @param t Wert der in die Liste Aufgenommen werden soll
*/
template<typename T>
void LinListT<T>::insert(int pos, T t){
	int suchIndex = 2; //Start bei zwei wegen Vorgaengersuche
	ElementT* tmp1 = first;
	ElementT* tmp2 = NULL;
	ElementT* tmp3 = NULL;
	if ((size_t)pos < 1 || (size_t)pos > size){
		throw logic_error(" Invalid Position!");
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
		tmp3 = new ElementT(); // neues Element
		tmp3->value = t;
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
template<typename T>
void LinListT<T>::erase(int pos){
	int suchIndex = 1;
	ElementT* tmp = first;
	if ((size_t)pos < 1 || (size_t)pos > size){
		throw logic_error(" Invalid Position!");
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
template<typename T>
void LinListT<T>::clear(){
	while(!isEmpty()){
		pop_back();
	}
}
/**
* @brief isEmpty Pruefung auf leer
* @returns true == empty false == non empty
*/
template<typename T>
bool LinListT<T>::isEmpty(){
	return (size == 0);
}
/**
 * @brief gibt den Inhalt der Liste als String zurueck
 * @returns Stringrepresentation des LinListT-Objekts
 */
template<typename T>
string LinListT<T>::toString() const {
	ostringstream o;
	o << "Linked List: " << size << " Element(s)\n";
	ElementT* tmp = first;

	while (tmp){
		o << (tmp->value) << " ";
		tmp = tmp->next;
	}
	o << endl;
	return o.str();
}
/**
 * @brief <<Operator zur Ausgabe in einen Stream
 * @param o Streamreferenz
 * @param linList Listenreferenz
 * @returns Referenz auf Stream mit angehaengtem LinListTString
 */
template<typename T>
ostream& operator<<(ostream& o, const LinListT<T>& linListT){
	return o << linListT.toString();
}
/**
 * @brief >>Operator zur Eingabe durch einen Stream
 * @param i Streamreferenz
 * @param linList Listenreferenz
 * @returns Referenz auf Stream mit entnommenem LinListTString
 */
template<typename T>
istream& operator>> (istream& i, LinListT<T>& linList){
	linList.clear();
	T t ;
	while (i >> t){
		linList.push_back(t);
	}
	return i;
}
/**
* @brief Operator[] zum Ausgeben einens Elements
* @param pos position
* @returns Referenz auf objekt
*/
template<typename T>
T& LinListT<T>::operator[] (int pos){
	int suchIndex = 1;
	ElementT* tmp = first;
	if ((size_t)pos < 1 || (size_t)pos > size){
		throw logic_error(" Invalid Position!");
	}
	while (suchIndex < pos){
		tmp = tmp->next;
		suchIndex++;
	}
	return *tmp;
}

//const ListElementT& LinListT<T>::operator[](int pos) const{
//	int suchIndex = 1;
//	const ListElementT* tmp = first;
//	if ((size_t)pos < 1 || (size_t)pos > size){
//		throw logic_error(" Invalid Position!");
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
template<typename T>
LinListT<T>& LinListT<T>::operator+= (LinListT& linList){
	copyElements(linList);
	return *this;
}
/**
* @brief Operator== Vergleicht obj
* @param linList Listenreferenz
* @returns ergebnis bool value
*/
template<typename T>
bool LinListT<T>::operator== (LinListT& linList){
	bool ergebnis = true;
	ElementT* tmp1 = first;
	ElementT* tmp2 = linList.first;

	if(size != linList.size){
		ergebnis = false;
	}
	while(tmp1 &&  tmp2 && ergebnis){
		if((tmp1->value) != (tmp2->value)){
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
template<typename T>
bool LinListT<T>::operator!= (LinListT& linList){
	return !(*this == linList);
}
/**
* @brief Operator+ Erzeugt neues obj mit den werten 2er objs
* @param linList1 Listenreferenz1
* @param linList2 Listenreferenz2
* @returns Referenz auf objekt
*/
template<typename T>
LinListT<T>& operator+(LinListT<T>& linListT1, LinListT<T>& linListT2){
	LinListT<T>* tmp = new LinListT<T>(linListT1);
	*tmp += linListT2;
	return *tmp;
}
/**
* @brief copyElements Kopierfunktion
* @param linList Referenz auf LinListTen Obj
*/
template<typename T>
void LinListT<T>::copyElements(const LinListT<T>& linListT){
	ElementT* tmp = linListT.first;

	while(tmp != NULL){
		push_back(tmp->value);
		tmp = tmp->next;
	}
}

#endif /* LINLIST_H_ */
