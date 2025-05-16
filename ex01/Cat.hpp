#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal
{
public:
	Cat();
	Cat(const std::string &idea);
	Cat(const Cat &other);
	Cat &operator=(const Cat &other);
	~Cat();
	void makeSound() const;
	std::string getIdea(int index) const;

private:
	Brain *_brain;
};

#endif // !CAT_HPP
