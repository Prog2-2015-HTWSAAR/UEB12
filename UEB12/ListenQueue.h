/*
 * ListenQueue.h
 *
 *  Created on: 20.07.2015
 *      Author: Simon
 */

#ifndef LISTENQUEUE_H_
#define LISTENQUEUE_H_
#include "LinListT.h"

template<typename T> class LinListT;
template<typename T> class ListenQueue;
template<typename T>
class ListenQueue : public LinListT<T>{
public:
	ListenQueue();
	virtual ~ListenQueue();
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
};
template <typename T>
ListenQueue<T>::ListenQueue(){}

template<typename T>
ListenQueue<T>::~ListenQueue(){}

/**
* @brief enQueue
*/
template <typename T>
void ListenQueue<T>::enQueue (const T& x) {
	this->push_front(x);
}
/**
* @brief deQueue
* @returns top
*/
template <typename T>
T ListenQueue<T>::deQueue()  {
	return this->pop_back();
}





#endif /* LISTENQUEUE_H_ */
