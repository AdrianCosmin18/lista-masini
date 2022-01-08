#include"ControlMasina.h"

class VIEW {

private:
	ControlMasina* cm;

public:

	VIEW() {

		cm = new ControlMasina();
	}

	void meniu() {

		cout << "\nMeniu : ";

		cout << "\n\n1 : Vedeti toate masinile";
		cout << "\n2 : Adaugati o masina";
		cout << "\n3 : Stergeti o masina";
		cout << "\n4 : Modificati o masina";
		cout << "\n5 : Iesire";
	}

	//add masina


	void play() {

		bool flag = 1;
		meniu();

		string al;
		int choise;

		while (flag == true) {


			cout << "\n\nAlegere : ";
			getline(cin, al);

			choise = stoi(al);

			switch (choise) {

			case 1: cm->traverse();
				break;

			case 2: add_car();
				break;

			case 3: delete_car();
				break;

			case 4: modify_car();
				break;

			case 5: flag = 0;
				break;
			}
		}
	}

	void add_car() {

		cout << "\n\nIntroduceti Marca masinii : ";
		string marca;
		getline(cin, marca);

		cout << "\nIntroduceti Modelul masinii : ";
		string model;
		getline(cin, model);

		cout << "\nIntroduceti anul masinii : ";
		string a;
		getline(cin, a);
		int an = stoi(a);

		Masina* m = new Masina(marca, model, an);

		cm->add_car(m);
	}

	void delete_car() {

		cout << "\n\nIntroduceti Marca masinii : ";
		string marca;
		getline(cin, marca);

		cout << "\nIntroduceti Modelul masinii : ";
		string model;
		getline(cin, model);

		cm->remove(marca, model);
	}

	void modify_car() {

		cout << "\n\nIntroduceti Marca masinii pe care doriti sa o modificati : ";
		string marca;
		getline(cin, marca);

		cout << "\nIntroduceti Modelul masinii pe care doriti sa o modificati : ";
		string model;
		getline(cin, model);

		cout << "\nIntroduceti anul modificat al masinii : ";
		string a;
		getline(cin, a);
		int an = stoi(a);

		cm->modify(marca, model, an);
	}
};
