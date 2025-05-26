#include "MateriaSource.hpp"

MateriaSource::MateriaSource() : IMateriaSource(), _materiaIndex(0)
{
	for (int i = 0; i < 4; i++)
		_materias[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource &other)
{
	*this = other;
}

MateriaSource &MateriaSource::operator=(const MateriaSource &other)
{
	if (this != &other)
	{
		for (int i = 0; i < 4; i++)
		{
			if (_materias[i])
				delete _materias[i];
			_materias[i] = other._materias[i] ? other._materias[i]->clone() : NULL;
		}
	}
	return *this;
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; i++)
		if (_materias[i])
			delete _materias[i];
}

void MateriaSource::learnMateria(AMateria *m)
{
	if (_materiaIndex < 4)
		_materias[_materiaIndex++] = m;
}

AMateria *MateriaSource::createMateria(std::string const &type)
{
	for (int i = 0; i < _materiaIndex; i++)
		if (_materias[i]->getType() == type)
			return _materias[i]->clone();
	return NULL;
}