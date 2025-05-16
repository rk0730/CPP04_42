#include "Cat.hpp"
#include "Dog.hpp"

int main(void)
{
	const Animal *j = new Dog();
	const Animal *i = new Cat();
	std::cout << "j's idea: " << j->getIdea(0) << std::endl;
	std::cout << "i's idea: " << i->getIdea(0) << std::endl;
	delete j;
	delete i;

	// animals array
	Animal *animals[4];
	for (int i = 0; i < 2; i++)
		animals[i] = new Dog();
	for (int i = 2; i < 4; i++)
		animals[i] = new Cat();
	for (int i = 0; i < 4; i++)
	{
		animals[i]->makeSound();
		std::cout << "idea: " << animals[i]->getIdea(0) << std::endl;
	}
	for (int i = 0; i < 4; i++)
		delete animals[i];

	// deep copy
	const Animal *dog = new Dog("dog's special idea");
	Animal *copy_dog = new Dog(*(Dog *)dog);
	delete dog;
	std::cout << "copy_dog's idea: " << copy_dog->getIdea(0) << std::endl;
	delete copy_dog;

	return 0;
}
