#include"Ilist.h"

class Nod
{
private:
	Masina *m;
	Nod* next;

public:

	Masina* get_masina() { return m; }
	Nod* get_next() { return next; }

	void set_masina(Masina* m1) { m = m1; }
	void set_next(Nod* n) { next = n; }
};

