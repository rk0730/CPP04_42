#include "Animal.hpp"

Animal::Animal() : _type("default")
{
	std::cout << "Animal " << _type << " is born! with default constructor" << std::endl;
}

Animal::Animal(const Animal &other) : _type(other._type)
{
	std::cout << "Animal " << _type << " is born! with copy constructor" << std::endl;
}

Animal &Animal::operator=(const Animal &other)
{
	if (this != &other)
		_type = other._type;
	std::cout << "Animal " << _type << " is born! with copy assignment operator" << std::endl;
	return *this;
}

Animal::~Animal()
{
	std::cout << "Animal " << _type << " is dead!" << std::endl;
}

std::string Animal::getType() const
{
	return _type;
}

void Animal::makeSound() const
{
	std::cout << "Animal " << _type << " makes sound!" << std::endl;
}
