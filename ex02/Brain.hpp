#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

class Brain
{
public:
	Brain();
	Brain(const std::string &idea);
	Brain(const Brain &other);
	Brain &operator=(const Brain &other);
	~Brain();
	std::string getIdea(int index) const;

private:
	std::string _ideas[100];
};
#endif
