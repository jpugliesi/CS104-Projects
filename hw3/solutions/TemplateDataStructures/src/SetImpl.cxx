#include "../header/Set.h"

template <class T> Set<T>::Set()
{
	//internal storage is allocated on the stack automatically
}

template <class T> Set<T>::~Set()
{
	//internal storage will be deconstructed automatically when it goes out of scope
}

template <class T> int Set<T>::size() const
{
	return this->internalStorage.size();
}

template <class T> void Set<T>::add (T item)
{
	this->internalStorage.add(item, 0);
}
      
template <class T> void Set<T>::remove (T item)
{
	this->internalStorage.remove(item);
}

template <class T> bool Set<T>::contains (T item) const
{
	bool ans = false;
	this->internalStorage.get(item, ans);
	return ans;
}

template <class T> void Set<T>::merge (const Set<T> & other)
{
	this->internalStorage.merge(other.internalStorage);
}

template <class T> void Set<T>::printAll () const
{
	this->internalStorage.printAll();
}



