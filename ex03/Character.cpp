#include "Character.hpp"
#include "AMateria.hpp"

Character::Character() : ICharacter(), _name(""), _trashIndex(0)
{
	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;
	for (int i = 0; i < _MAX_TRASH; i++)
		_trash[i] = NULL;
}

Character::Character(std::string name) : ICharacter(), _name(name), _trashIndex(0)
{
	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;
	for (int i = 0; i < _MAX_TRASH; i++)
		_trash[i] = NULL;
}

Character::Character(const Character &other)
{
	*this = other;
}

Character &Character::operator=(const Character &other)
{
	if (this != &other)
	{
		_name = other._name;
		for (int i = 0; i < 4; i++)
		{
			if (_inventory[i])
				delete _inventory[i];
			_inventory[i] = other._inventory[i] ? other._inventory[i]->clone() : NULL;
		}
	}
	return *this;
}

Character::~Character()
{
	for (int i = 0; i < 4; i++)
	{
		if (_inventory[i])
			delete _inventory[i];
	}
	for (int i = 0; i < _trashIndex; i++)
	{
		if (_trash[i])
			delete _trash[i];
	}
}

std::string const &Character::getName() const
{
	return _name;
}

void Character::equip(AMateria *m)
{
	for (int i = 0; i < 4; i++)
	{
		if (_inventory[i] == NULL)
		{
			_inventory[i] = m;
			return;
		}
	}
	delete m;
}

void Character::unequip(int idx)
{
	if (idx < 0 || idx >= 4)
		return;
	if (_inventory[idx])
	{
		if (_trashIndex < _MAX_TRASH)
			_trash[_trashIndex++] = _inventory[idx];
		else
		{
			delete _trash[_trashIndex % _MAX_TRASH];
			_trash[_trashIndex % _MAX_TRASH] = _inventory[idx];
			_trashIndex++;
		}
	}
	_inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter &target)
{
	if (idx < 0 || idx >= 4)
		return;
	if (_inventory[idx])
		_inventory[idx]->use(target);
}
