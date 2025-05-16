#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal
{
public:
	Dog();
	Dog(const std::string &idea);
	Dog(const Dog &other);
	Dog &operator=(const Dog &other);
	~Dog();
	void makeSound() const;
	std::string getIdea(int index) const;

private:
	Brain *_brain;
};

#endif // !DOG_HPP
