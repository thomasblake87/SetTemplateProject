#ifndef H_UnorderedSet
#define H_UnorderedSet

#include "unorderedArrayListType.h"

template <class elemType>

class unorderedSet: public unorderedArrayListType<elemType>
{
public:
	unorderedSet(int size = 100);
	// Constructor

	//Over Ride member functions;
	void insertAt(int location, const elemType& insertItem) override;
	void replaceAt(int location, const elemType& repItem) override;
	void insertEnd(const elemType& insertItem) override;

	//Overload these operators:
	unorderedSet<elemType> operator+(const unorderedSet<elemType>& setObj) const;
	unorderedSet<elemType> operator-(const unorderedSet<elemType>& setObj) const;

	const elemType& operator[](int index) const;
};

template <class elemType>
unorderedSet<elemType>::unorderedSet(int size) : unorderedArrayListType<elemType>(size)
{
}

template <class elemType>
void unorderedSet<elemType>::insertAt(int location, const elemType& insertItem)
{
	int found = this->seqSearch(insertItem);
	if (found == -1)
		unorderedArrayListType<elemType>::insertAt(location, insertItem);
}

template <class elemType>
void unorderedSet<elemType>::insertEnd(const elemType& insertItem)
{
	int found = this->seqSearch(insertItem);
	if (found == -1)
		unorderedArrayListType<elemType>::insertEnd(insertItem);
}

template <class elemType>
void unorderedSet<elemType>::replaceAt(int location, const elemType& repItem)
{
	int found = this->seqSearch(repItem);
	if (found == -1)
		unorderedArrayListType<elemType>::replaceAt(location, repItem);
}

template <class elemType>
unorderedSet<elemType> unorderedSet<elemType>::operator+(const unorderedSet<elemType>& setObj) const
{
	unorderedSet<elemType> obj1(*this);

	// Add elements from setObj to result set
	for (int i = 0; i < setObj.listSize(); ++i)
	{
		if (obj1.seqSearch(setObj[i]) == -1)
		{
			obj1.insertEnd(setObj[i]);
		}
	}

	return obj1;
}

template <class elemType>
unorderedSet<elemType> unorderedSet<elemType>::operator-(const unorderedSet<elemType>& setObj) const
{
	unorderedSet<elemType> obj1;

	// Add common elements to result set
	for (int i = 0; i < this->listSize(); ++i)
	{
		if (setObj.seqSearch(this->list[i]) != -1)
		{
			obj1.insertEnd(this->list[i]);
		}
	}

	return obj1;
}

template <class elemType>
const elemType& unorderedSet<elemType>::operator[](int index) const
{
	if (index < 0 || index >= this->listSize())
		cout << "Out of range" << endl;
	return this->list[index];
}

#endif