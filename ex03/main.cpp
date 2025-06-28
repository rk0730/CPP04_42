#include "AMateria.hpp"
#include "Character.hpp"
#include "Cure.hpp"
#include "ICharacter.hpp"
#include "IMateriaSource.hpp"
#include "Ice.hpp"
#include "MateriaSource.hpp"

int main()
{
	{
		// simple test
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
	}
	// full inventory
	{
		IMateriaSource *src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
		ICharacter *me = new Character("me");
		ICharacter *target = new Character("target");
		me->equip(src->createMateria("ice"));
		me->equip(src->createMateria("cure"));
		me->equip(src->createMateria("ice"));
		me->equip(src->createMateria("cure"));
		std::cout << "full inventory" << std::endl;
		me->equip(src->createMateria("ice"));
		me->equip(src->createMateria("cure"));
		me->equip(src->createMateria("ice"));
		me->equip(src->createMateria("cure"));
		delete me;
		delete target;
		delete src;
	}
	// copy character
	{
		IMateriaSource *src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
		Character me = Character("me");
		Character me2 = Character("target");
		me.equip(src->createMateria("ice"));
		me.equip(src->createMateria("cure"));
		me2.equip(src->createMateria("ice"));
		me2.equip(src->createMateria("cure"));
		me2 = me; // copy assignment
		delete src;
	}
	return 0;
}
