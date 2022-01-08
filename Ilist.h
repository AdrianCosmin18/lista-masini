#include "Masina.h"


class Ilist
{
	

public:

	virtual void add(Masina* m) = 0;


	virtual void remove(int index) = 0;


	virtual void remove(Masina* m) = 0;


	virtual bool contains(Masina* m) = 0;

	virtual bool isEmpty() = 0;

	virtual int indexOf(Masina* m) = 0;

	virtual int size() = 0;

	virtual Masina* get(int index) = 0;

};

