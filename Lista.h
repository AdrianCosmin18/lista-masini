#include"Nod.h"

class Lista: public Ilist
{

private:

	Nod* head=NULL;

public:


	void addStart(Masina* data) {

		if (head == NULL) {
			 
			head = new Nod();
			head->set_masina(data);
			head->set_next(NULL);
				
		}
		else {

			Nod* nou = new Nod();

			nou->set_next(head);
			nou->set_masina(data);

			head = nou;
		}
		
	}

	void traverse() {

		Nod* p = head;
		while (p != NULL) {

			cout << *(p->get_masina()) << endl;

			p = p->get_next();
		}
	}


	Nod* get_last_nod() {

		Nod* p = head;
		Nod* aux = new Nod();
		aux = p;
		while (p != NULL) {

			aux = p;
			p = p->get_next();
		}

		return aux;
	}

	void add(Masina* m) override {

		if (head == NULL) {

			Nod* p = new Nod();
			p->set_masina(m);
			p->set_next(NULL);

			head = p;
		}
		else {

			Nod* p = new Nod();
			p->set_masina(m);
			
			Nod* privious = new Nod();
			privious = get_last_nod();
			privious->set_next(p);

		}
	}


	int indexOf(Masina* m)override {

		Nod* nod = head;
		int poz = -1;

		while (nod != NULL) {

			poz++;
			if (nod->get_masina() == m) { return poz; }

			nod = nod->get_next();
		}

		return -1;
	}

	int indexOf(string marca, string model) {

		Nod* nod = head;
		int poz = -1;

		while (nod != NULL) {

			poz++;
			if (nod->get_masina()->get_marca() == marca && nod->get_masina()->get_model() == model) { return poz; }

			nod = nod->get_next();
		}

		return -1;
	}

	Nod* poz_nod(int p) {

		Nod* nod = head;
		int poz = -1;
		while (nod != NULL) {

			poz++;
			if (poz == p) { return nod; }
			nod = nod->get_next();
		}
		return NULL;
	}

	void remove_first() {


		Nod* aux = head;
		this->head = this->head->get_next();

		delete aux;
		
	}

	void remove_last(int index) {}
	
	void remove(int index)override {


		Nod* aux = poz_nod(index);
		Nod* pred = poz_nod(index - 1);

		pred->set_next(aux->get_next());

	}

	void remove(Masina* m) override {
	
		int pozitie = indexOf(m);

		if (pozitie != -1) {

			Nod* aux = poz_nod(pozitie);
			Nod* predecesor = poz_nod(pozitie - 1);

			predecesor->set_next(aux->get_next());
		}
	}

	bool contains(Masina* m)override {

		Nod* nod = head;

		while (nod != NULL) {

			if (nod->get_masina() == m) { return true; }
			nod = nod->get_next();
		}
		return false;
	}

	bool isEmpty()override {

		if (head == NULL) {
			return true;
		}

		return false;

	}

	int size()override {

		
		if (isEmpty() == true) { return 0; }
		else {

			int size = 0;
			Nod* nod = head;

			while (nod != NULL) {

				size++;
				nod = nod->get_next();
			}
			return size;
		}
	}

	Masina* get(int index)override {

		Nod* nod = poz_nod(index);

		if (nod != NULL) { return nod->get_masina(); }

		return NULL;
	}

	void replace(Masina* m, int index) {


		int poz = -1;
		Nod* nod = head;

		while (nod != NULL) {

			poz++;
			if (poz == index) {

				nod->set_masina(m);
			}

			nod = nod->get_next();
		}
	}

	void swap(Nod* n1, Nod* n2) {


		int pozitie1 = indexOf(n1->get_masina());
		int pozitie2 = indexOf(n2->get_masina());

		replace(n1->get_masina(), pozitie2);
		replace(n2->get_masina(), pozitie1);
	}
	//soraterea dupa an
	void sort() {

		int flag = 0;
		do {
			flag = 0;

			for (int i = 0; i < size()-1; i++) {

				if (get(i+1)->operator< (*get(i))) 
				{
				
					Masina* aux = get(i);

					replace(get(i + 1),i);
					
					replace(aux, i + 1);

					flag = 1;

				}
				
				
			}


		}while(flag == 1);

	}

	Nod* iterator() {

		return this->head;
	}

};

