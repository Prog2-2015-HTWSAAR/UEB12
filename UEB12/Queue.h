#ifndef __QUEUE_H__
#define __QUEUE_H__

#include <assert.h>  
using namespace std;

// ist seit neuestem notwendig
//template<typename T> class Queue;
//template<typename T>
//ostream& operator<<(ostream&, const Queue<T>&);

template <class Element>
class Queue
{
public:
	Queue(int MaxSize = 500);
	Queue(const Queue<Element> &OtherQueue);
	~Queue(void);

	void enqueue(const Element &Item);
	Element dequeue(void);
	inline int ElementNum(void);
	friend ostream& operator<< <>(ostream& o, const Queue<Element>& q);
protected:
	Element *Data;
	const int MAX_NUM;
	int Beginning,
		End;

	int       ElementCount;
};
/**
* @brief Queue konstruktor Bei weilchen die groesse definiert wird
* @param MaxSize int
*/

template <class Element>
Queue<Element>::Queue(int MaxSize) :
MAX_NUM(MaxSize)
{
	Data = new Element[MAX_NUM + 1];
	Beginning = 0;
	End = 0;
	ElementCount = 0;
}
/**
* @brief Queue konstruktor
* @param OtherQueue const Queue &
*/
template <class Element>
Queue<Element>::Queue(const Queue &OtherQueue) :
MAX_NUM(OtherQueue.MAX_NUM)
{
	Beginning = OtherQueue.Beginning;
	End = OtherQueue.End;
	ElementCount = OtherQueue.ElementCount;

	Data = new Element[MAX_NUM + 1];
	for (int i = 0; i < MAX_NUM; i++)
		Data[i] = OtherQueue.Data[i];
}
/**
* @brief ~Queue Dekonstruktor
*/
template <class Element>
Queue<Element>::~Queue(void)
{
	delete[] Data;
}
/**
* @brief enqueue
* @param Item const Element &
* Rule 299. This is madness. No exceptions.
*/
template <class Element>
void Queue<Element>::enqueue(const Element &Item)
{
	assert(ElementCount < MAX_NUM);

	Data[End++] = Item;
	++ElementCount;

	if (End > MAX_NUM)
		End -= (MAX_NUM + 1);
}
/**
* @brief dequeue
* @returns ReturnValue
*/
template <class Element>
Element Queue<Element>::dequeue(void)
{
	assert(ElementCount > 0);

	Element ReturnValue = Data[Beginning++];
	--ElementCount;

	if (Beginning > MAX_NUM)
		Beginning -= (MAX_NUM + 1);

	return ReturnValue;
}
/**
* @brief ElementNum
* @returns ElementCount
*/
template <class Element>
inline int Queue<Element>::ElementNum(void)
{
	return ElementCount;
}
/**
* @brief <<Operator zur Ausgabe in einen Stream
* @param o Streamreferenz
* @param q const Queue<Element>&
* @returns Referenz auf Stream mit angehaengtem LinListString
*/
template <class Element>
ostream& operator<<(ostream& o, const Queue<Element>& q){
	for (int i = 0; i < q.MAX_NUM; ++i) {
		o << q.Data[i] << "  ";
	}
	return o;
	// Rule 221. RETARDED NEWFAGS, should always be shot without warning NO EXCEPTIONS!
}
#endif 
