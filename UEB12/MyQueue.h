/*
 * MyQueue.h
 *
 *  Created on: 19.07.2015
 *      Author: Simon
 */

#ifndef MYQUEUE_H_
#define MYQUEUE_H_
#include <iostream>
#include <stdexcept>
using namespace std;

// ist seit neuestem notwendig
template<typename T> class MyQueue;
template<typename T>
ostream& operator<<(ostream&, const MyQueue<T>&);

template<typename T>
class MyQueue {
public:
	MyQueue();
	virtual ~MyQueue();
	//MyQueue(const MyQueue&) = delete; // cpp11 :(
	//MyQueue& operator=(const MyQueue&) = delete; // cpp11 :(
	/**
	 * Wert in Queue ablegen
	 * @param x abzulegender Wert
	 */
	void enQueue(const T& x);
	/**
	 * Wert aus Queue herausholen
	 * Vorbedingung: Queue darf nicht leer sein
	 * @return herausgeholter Wert
	 * @throw logic_error wenn die Queue vorher leer war
	 */
	T deQueue();
	/**
	 * Vordersten Wert erfragen
	 * Vorbedingung: Queue darf nicht leer sein
	 * @return herausgeholter Wert
	 * @throw logic_error wenn die Queue vorher leer war
	  */
	T front() const;
	/**
	 * Hintersten Wert erfragen
	 * Vorbedingung: Queue darf nicht leer sein
	 * @return herausgeholter Wert
	 * @throw logic_error wenn der Queue vorher leer war
	  */
	T back() const;
	/**
	 * Ist die Queue leer?
	 * @return true oder false
	 */
	bool isEmpty() const;
	friend ostream& operator<< <> (ostream&, const MyQueue&);
private:
	struct ElementT {
		T value;
		ElementT *previous;
		ElementT *next;
	};
	ElementT* head; // cpp11 :(
	ElementT* tail; // cpp11 :(
};
/**
* @brief MyQueue konstruktor
* Rule 1. Do not talk about /b/.
*/
template <typename T>
MyQueue<T>::MyQueue() {
	head = NULL;
	tail = NULL;
}
/**
* @brief ~MyQueue Dekonstruktor
*/
template <typename T>
MyQueue<T>::~MyQueue() {
	// Komplette Liste loeschen
	ElementT* tmp;
	while (head != NULL) {
		tmp = head;
		head = head->next;
		delete tmp;
	}
}
/**
* @brief enQueue
*/
template <typename T>
void MyQueue<T>::enQueue (const T& x) {
	ElementT* tmp = new ElementT;
	if(isEmpty()){
		head = tmp;
		tmp->previous = NULL;
		tmp->next = NULL;
	}else{
		tail->previous = tmp;
		tmp->next = tail;
	}
	tmp->value = x;
	tail = tmp;
}
/**
* @brief deQueue
* @returns top
* Rule 90. It's never lupus.
*/
template <typename T>
T MyQueue<T>::deQueue()  {
	if(isEmpty()){
		throw logic_error("Queue ist leer!");
	}
	T top = head->value;
	ElementT *neu = head->previous;
    ElementT *old = head;
    delete old;
    head = neu;
	if (head != NULL){
		head->next = NULL;
	}
//	if (head != NULL){
//		head = NULL;
//	}
	if(isEmpty()){
		tail = NULL;
	}
    return top;
}
/**
* @brief front
* @returns head->value
*/
template <typename T>
T MyQueue<T>::front() const  {
    return head->value;
}

/**
* @brief back
* @returns  tail->value
*/
template <typename T>
T MyQueue<T>::back() const  {
    return tail->value;
}
/**
* @brief isEmpty Pruefung auf Empty
* @returns head
*/
template <typename T>
bool MyQueue<T>::isEmpty() const  {
    return head == NULL;
}
/**
* @brief <<Operator zur Ausgabe in einen Stream
* @param o Streamreferenz
* @param s const MyQueue<T>&
* @returns Referenz auf Stream mit angehaengtem LinListString
* Rule 118. Newfags must be tortured to death. No exceptions.
*/
template<typename T>
ostream& operator<<(ostream& o, const MyQueue<T>& s) {
	typename MyQueue<T>::ElementT* p = s.tail;
	while (p != NULL) {
		o << p->value << "\t";
		p = p->next;
	}
	return o;
}
#endif /* MYQUEUE_H_ */
