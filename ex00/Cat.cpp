#include "Cat.hpp"

Cat::Cat() : Animal()
{
	_type = "Cat";
	std::cout << "Cat " << _type << " is born! with default constructor" << std::endl;
}

Cat::Cat(const Cat &other) : Animal(other)
{
	std::cout << "Cat " << _type << " is born! with copy constructor" << std::endl;
}

Cat &Cat::operator=(const Cat &other)
{
	if (this != &other)
		_type = other._type;
	std::cout << "Cat " << _type << " is born! with copy assignment operator" << std::endl;
	return *this;
}

Cat::~Cat()
{
	std::cout << "Cat " << _type << " is dead!" << std::endl;
}

void Cat::makeSound() const
{
	std::cout << "Cat " << _type << " meows!" << std::endl;
}
