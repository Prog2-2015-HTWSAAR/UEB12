/*
 * MyQueue.h
 *
 *  Created on: 19.07.2015
 *      Author: Simon
 */

#ifndef MYQUEUE_H_
#define MYQUEUE_H_
#include <iostream>
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
	 * @throw logic_error wenn der Queue vorher leer war
	 */
	T deQueue();
	/**
	 * Vordersten Wert erfragen
	 * Vorbedingung: Queue darf nicht leer sein
	 * @return herausgeholter Wert
	 * @throw logic_error wenn der Queue vorher leer war
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
template <typename T>
MyQueue<T>::MyQueue() {
	head = 0;
	tail = 0;
}

template <typename T>
MyQueue<T>::~MyQueue() {
	// Komplette Liste loeschen
	ElementT* tmp;
	while (head != 0) {
		tmp = head;
		head = head->next;
		delete tmp;
	}
}

template <typename T>
void MyQueue<T>::enQueue (const T& x) {
	ElementT* tmp = new ElementT;
	if(isEmpty()){
		head = tmp;
		tmp->next = NULL;
	}else{
		tail->previous = tmp;
		tmp->next = tail;
	}
	tmp->value = x;
	tail = tmp;

}

template <typename T>
T MyQueue<T>::deQueue  ()  {
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
	if(isEmpty()){
		tail = NULL;
	}
    return top;
}

template <typename T>
T MyQueue<T>::front() const  {
    return head->value;
}

template <typename T>
T MyQueue<T>::back() const  {
    return tail->value;
}

template <typename T>
bool MyQueue<T>::isEmpty() const  {
    return head == 0;
}

template<typename T>
ostream& operator<<(ostream& o, const MyQueue<T>& s) {
	typename MyQueue<T>::ElementT* p = s.tail;
	while (p != 0) {
		o << p->value << "\t";
		p = p->next;
	}
	return o;
}
#endif /* MYQUEUE_H_ */
