#include "Dog.hpp"

Dog::Dog() : Animal()
{
	_type = "Dog";
	_brain = new Brain();
	std::cout << "Dog " << _type << " is born! with default constructor" << std::endl;
}

Dog::Dog(const std::string &idea) : Animal()
{
	_type = "Dog";
	_brain = new Brain(idea);
	std::cout << "Dog " << _type << " is born! with default constructor and idea: " << idea
			  << std::endl;
}

Dog::Dog(const Dog &other) : Animal(other), _brain(new Brain(*other._brain))
{
	std::cout << "Dog " << _type << " is born! with copy constructor" << std::endl;
}

Dog &Dog::operator=(const Dog &other)
{
	if (this != &other)
	{
		_type = other._type;
		_brain = new Brain(*other._brain);
	}
	std::cout << "Dog " << _type << " is born! with copy assignment operator" << std::endl;
	return *this;
}

Dog::~Dog()
{
	std::cout << "Dog " << _type << " is dead!" << std::endl;
	delete _brain;
}

void Dog::makeSound() const
{
	std::cout << "Dog " << _type << " barks!" << std::endl;
}

std::string Dog::getIdea(int index) const
{
	return _brain->getIdea(index);
}
