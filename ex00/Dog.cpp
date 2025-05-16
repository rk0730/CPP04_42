#include "Dog.hpp"

Dog::Dog() : Animal()
{
	_type = "Dog";
	std::cout << "Dog " << _type << " is born! with default constructor" << std::endl;
}

Dog::Dog(const Dog &other) : Animal(other)
{
	std::cout << "Dog " << _type << " is born! with copy constructor" << std::endl;
}

Dog &Dog::operator=(const Dog &other)
{
	if (this != &other)
		_type = other._type;
	std::cout << "Dog " << _type << " is born! with copy assignment operator" << std::endl;
	return *this;
}

Dog::~Dog()
{
	std::cout << "Dog " << _type << " is dead!" << std::endl;
}

void Dog::makeSound() const
{
	std::cout << "Dog " << _type << " barks!" << std::endl;
}
