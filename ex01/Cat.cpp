#include "Cat.hpp"

Cat::Cat() : Animal()
{
	_type = "Cat";
	_brain = new Brain();
	std::cout << "Cat " << _type << " is born! with default constructor" << std::endl;
}

Cat::Cat(const std::string &idea) : Animal()
{
	_type = "Cat";
	_brain = new Brain(idea);
	std::cout << "Cat " << _type << " is born! with default constructor and idea: " << idea
			  << std::endl;
}

Cat::Cat(const Cat &other) : Animal(other), _brain(new Brain(*other._brain))
{
	std::cout << "Cat " << _type << " is born! with copy constructor" << std::endl;
}

Cat &Cat::operator=(const Cat &other)
{
	if (this != &other)
	{
		_type = other._type;
		_brain = new Brain(*other._brain);
	}
	std::cout << "Cat " << _type << " is born! with copy assignment operator" << std::endl;
	return *this;
}

Cat::~Cat()
{
	std::cout << "Cat " << _type << " is dead!" << std::endl;
	delete _brain;
}

void Cat::makeSound() const
{
	std::cout << "Cat " << _type << " meows!" << std::endl;
}

std::string Cat::getIdea(int index) const
{
	return _brain->getIdea(index);
}
