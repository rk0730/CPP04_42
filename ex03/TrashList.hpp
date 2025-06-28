#ifndef TRASHLIST_HPP
#define TRASHLIST_HPP

class AMateria;

struct TrashNode
{
	AMateria *materia;
	TrashNode *next;
	TrashNode(AMateria *m, TrashNode *n) : materia(m), next(n) {}
};

class TrashList
{
public:
	TrashList();
	TrashList(const TrashList &other);
	TrashList &operator=(const TrashList &other);
	~TrashList();
	void add(AMateria *m);
private:
	TrashNode *_head;
};

#endif
