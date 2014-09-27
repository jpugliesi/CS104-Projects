#include "../header/Map.h"
#include <iostream>

//constructor
template <class keyType, class valueType> Map<keyType, valueType>::Map()
{
	//create a dummy, zeroth node
	MapItem<keyType, valueType> *m = new MapItem<keyType, valueType>();
	this->head = m;
	this->tail = m;

	this->m_size = 0;
}

template <class keyType, class valueType> Map<keyType, valueType>::~Map()
{
	MapItem<keyType, valueType> *iter = this->tail;
	while(this->m_size > 0)
	{
		iter = iter->prev;
		delete iter->next;
		this->m_size--;
	}
	delete iter; //kill the dummy
}

template <class keyType, class valueType> int Map<keyType, valueType>::size() const
{
	return this->m_size;
}

template <class keyType, class valueType> void Map<keyType, valueType>::add(keyType key, valueType value)
{
	bool success = false;
	this->get(key, success);
	if (success)
		return;

	MapItem<keyType, valueType> *item = new MapItem<keyType, valueType>();
	item->key = key;
	item->value = value;

	tail->next = item;
	item->prev = tail;
	tail = item;
	
	//first item
	if(head->next == nullptr)
		head->next = tail;

	this->m_size++;
}

template <class keyType, class valueType> void Map<keyType, valueType>::remove(keyType key)
{
	bool success = false;
	this->get(key, success);
	if (!success)
		return;

	MapItem<keyType, valueType> *iter = head;
	while (iter->key != key)
	{
		iter = iter->next;
	}

	iter->prev->next = iter->next;
	if(iter == tail)
		tail = iter->prev;
	else
		iter->next->prev = iter->prev;

	delete iter;

	this->m_size--;

}

template <class keyType, class valueType> valueType Map<keyType, valueType>::get(keyType key, bool & success) const
{
	MapItem<keyType, valueType> *iter = head;
	while (iter != nullptr && iter->key != key)
	{
		iter = iter->next;
	}

	if(iter == nullptr)
	{
		success = false;
		valueType v;
		return v;
	}
	success = true;
	return iter->value;
}

template <class keyType, class valueType> void Map<keyType, valueType>::merge (const Map<keyType, valueType> & other)
{
	MapItem<keyType, valueType> *iter = other.head;
	while (iter->next != nullptr)
	{
		this->add(iter->key, iter->value);
		iter = iter->next;
	}
	this->add(iter->key, iter->value);
}

template <class keyType, class valueType> void Map<keyType, valueType>::printAll() const
{
	MapItem<keyType, valueType> *iter = this->head;
	std::cout << "Current contents:" << std::endl;
	while (iter->next != nullptr)
	{
		iter = iter->next;
		std::cout << iter->key << " : " << iter->value << std::endl;
	}
}

