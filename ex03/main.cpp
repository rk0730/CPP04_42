#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"
#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

int main()
{
	IMateriaSource *src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter *me = new Character("me");
	
	AMateria *tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	ICharacter *bob = new Character("bob");

	me->use(0, *bob);
	me->use(1, *bob);

	delete bob;
	delete me;
	delete src;
	std::cout << "finish simple test" << std::endl;

	// full inventory
	ICharacter *me2 = new Character("me2");
	ICharacter *target = new Character("target");
	IMateriaSource *src2 = new MateriaSource();
	src2->learnMateria(new Ice());
	src2->learnMateria(new Cure());
	me2->equip(src2->createMateria("ice"));
	me2->equip(src2->createMateria("cure"));
	me2->equip(src2->createMateria("ice"));
	me2->equip(src2->createMateria("cure"));
	std::cout << "full inventory" << std::endl;
	me2->equip(src2->createMateria("ice"));
	me2->equip(src2->createMateria("cure"));
	me2->equip(src2->createMateria("ice"));
	me2->equip(src2->createMateria("cure"));

	me2->use(0, *target);
	me2->use(1, *target);
	me2->use(2, *target);
	me2->use(3, *target);
	std::cout << "invalid index" << std::endl;
	me2->use(4, *target);
	me2->use(-1, *target);

	me2->unequip(0);
	me2->unequip(1);
	me2->unequip(2);
	me2->unequip(3);
	me2->unequip(4);
	me2->unequip(-1);

	me2->use(0, *target);
	me2->use(1, *target);
	me2->use(2, *target);

	me2->unequip(0);
	me2->use(0, *me2);

	std::cout << "equip again" << std::endl;
	me2->equip(src2->createMateria("cure"));
	me2->equip(src2->createMateria("ice"));
	me2->equip(src2->createMateria("cure"));
	me2->equip(src2->createMateria("ice"));
	me2->use(0, *target);
	me2->use(1, *target);
	me2->use(2, *target);
	me2->use(3, *target);

	delete me2;
	delete target;
	delete src2;

	return 0;
}