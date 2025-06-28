#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal()
{
	_type = "WrongCat";
	std::cout << "WrongCat " << _type << " is born! with default constructor" << std::endl;
}

WrongCat::WrongCat(const WrongCat &other) : WrongAnimal(other)
{
	std::cout << "WrongCat " << _type << " is born! with copy constructor" << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &other)
{
	if (this != &other)
		_type = other._type;
	std::cout << "WrongCat " << _type << " is born! with copy assignment operator" << std::endl;
	return *this;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat " << _type << " is dead!" << std::endl;
}

void WrongCat::makeSound() const
{
	std::cout << "WrongCat " << _type << " meows!" << std::endl;
}
