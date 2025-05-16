#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain is born!" << std::endl;
	for (int i = 0; i < 100; i++)
		_ideas[i] = "default idea";
}

Brain::Brain(const std::string &idea)
{
	std::cout << "Brain is born with idea: " << idea << std::endl;
	for (int i = 0; i < 100; i++)
		_ideas[i] = idea;
}

Brain::Brain(const Brain &other)
{
	std::cout << "Brain is born! with copy constructor" << std::endl;
	for (int i = 0; i < 100; i++)
		_ideas[i] = other._ideas[i];
}

Brain &Brain::operator=(const Brain &other)
{
	std::cout << "Brain is born! with copy assignment operator" << std::endl;
	if (this != &other)
	{
		for (int i = 0; i < 100; i++)
			_ideas[i] = other._ideas[i];
	}
	return *this;
}

Brain::~Brain()
{
	std::cout << "Brain is dead!" << std::endl;
}

std::string Brain::getIdea(int index) const
{
	return _ideas[index];
}
