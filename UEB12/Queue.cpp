#ifndef __Queue_H__
#define __Queue_H__

#include <assert.h>  
template <class Element>
class Queue
{
public:
	Queue(int MaxSize = 500);
	Queue(const Queue<Element> &OtherQueue);
	~Queue(void);

	void Enqueue(const Element &Item);    
	Element Dequeue(void);             
	inline int ElementNum(void);                

protected:
	Element *Data;     
	const int MAX_NUM;  
	int Beginning, 
		End;

	int       ElementCount;
};

template <class Element>
Queue<Element>::Queue(int MaxSize) :
MAX_NUM(MaxSize)   
{
	Data = new Element[MAX_NUM + 1];
	Beginning = 0;
	End = 0;
	ElementCount = 0;
}

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

template <class Element>
Queue<Element>::~Queue(void)
{
	delete[] Data;
}

template <class Element>
void Queue<Element>::Enqueue(const Element &Item)
{
	assert(ElementCount < MAX_NUM);

	Data[End++] = Item;
	++ElementCount;

	if (End > MAX_NUM)
		End -= (MAX_NUM + 1);
}

template <class Element>
Element Queue<Element>::Dequeue(void)
{
	assert(ElementCount > 0);

	Element ReturnValue = Data[Beginning++];
	--ElementCount;

	if (Beginning > MAX_NUM)
		Beginning -= (MAX_NUM + 1);

	return ReturnValue;
}

template <class Element>
inline int Queue<Element>::ElementNum(void)
{
	return ElementCount;
}

#endif 