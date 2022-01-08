#include "Lista.h"
#include<fstream>


class ControlMasina
{
private:
	Lista* list;


public:
	//CRUDE


	

	ControlMasina() {
	
		list = new Lista();
		load();
	
	}

	void load() {

		ifstream f("masini.txt");

		while (!f.eof()) {
			string m;
			getline(f, m);

			if(m != ""){ list->add(new Masina(m)); }
		}
	}

	void add_car(Masina* m1) {

		list->add(m1);
	}	

	void traverse() {


		Nod* itr = list->iterator();

		while (itr != NULL) {

			cout << *(itr->get_masina());


			itr = itr->get_next();
		}
	}

	void remove(string marca, string model) {

		int poz = list->indexOf(marca, model);
		cout << poz<<"pozitie de stergere";


		if(poz != -1 && poz == 0){ list->remove_first(); }
		else if (poz != -1){ list->remove(poz); }
		else{ cout << "\nNu exista aceasta masina"; }
	}

	void modify(string marca, string model, int an) {

		int index = list->indexOf(marca, model);

		if(index != -1){
		
			Masina* masina_noua = new Masina(marca, model, an);
			list->replace(masina_noua, index);
		}
		else { cout << "nu exista aceasta masina"; }
		
	}

	Masina* GetMasinaByMarcaAndModel(string marca, string model) {

		int index = list->indexOf(marca, model);
		if (index != -1) {

			Masina* m = list->get(index);
			return m;
		}
		else { cout << "Nu ex aceasta masina"; }
	}
};

