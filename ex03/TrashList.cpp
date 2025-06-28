#include "TrashList.hpp"
#include "AMateria.hpp"
#include <cstdlib>

TrashList::TrashList() : _head(NULL)
{
}

TrashList::TrashList(const TrashList &other)
{
	_head = new TrashNode(other._head->materia->clone(), NULL);
	TrashNode *current = _head;
	TrashNode *otherCurrent = other._head->next;
	while (otherCurrent)
	{
		current->next = new TrashNode(otherCurrent->materia->clone(), NULL);
		current = current->next;
		otherCurrent = otherCurrent->next;
	}
}

TrashList &TrashList::operator=(const TrashList &other)
{
	if (this != &other)
	{
		while (_head)
		{
			TrashNode *temp = _head;
			_head = _head->next;
			delete temp->materia;
			delete temp;
		}
		_head = new TrashNode(other._head->materia->clone(), NULL);
		TrashNode *current = _head;
		TrashNode *otherCurrent = other._head->next;
		while (otherCurrent)
		{
			current->next = new TrashNode(otherCurrent->materia->clone(), NULL);
			current = current->next;
			otherCurrent = otherCurrent->next;
		}
	}
	return *this;
}

TrashList::~TrashList()
{
	while (_head)
	{
		TrashNode *temp = _head;
		_head = _head->next;
		delete temp->materia;
		delete temp;
	}
}

void TrashList::add(AMateria *m)
{
	if (!m)
		return;
	TrashNode *newNode = new TrashNode(m, _head);
	_head = newNode;
}
