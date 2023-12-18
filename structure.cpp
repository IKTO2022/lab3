#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <windows.h>
#include <io.h>
#include <fcntl.h>
#include <clocale>


using namespace std;


struct Trasport {
	int id = 0;
	string brand;
	string BodyType;
	int HP = 0;
	int price = 0;
};

void input_struct(struct Trasport* P, int n);
void output_struct(struct Trasport* P, int n);
void correct(struct Trasport* P, int n);
void min_account(struct Trasport* P, int n);
void newFile(struct Trasport* P, int n);

int main() {
	setlocale(LC_ALL, "Rus");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
	Trasport* P;
	P = new Trasport[3];
	int breaker = 0;

	input_struct(P, 3);
	cout << "Транспорт" << endl;
	cout << "Действия: " << endl;
	while (true) {
		cout << "Узнать цену - нажмите 1" << endl;
		cout << "Исправить данные- нажмите 2" << endl;
		cout << "Найти самый дешевый автомобиль - нажмите 3" << endl;
		cout << "Сохранить и выйти - нажмите 4" << endl;
		cin >> breaker;
		switch (breaker) {
			case 1:
				output_struct(P, 3);
				cout << endl;
				break;
			case 2:
				correct(P, 3);
				cout << endl;
				break;
			case 3:
				min_account(P, 3);
				cout << endl;
				break;
			case 4:
				newFile(P, 3);
				cout << endl;
				break;
			default:
				cout << "НЕТ ТАКОЙ ЦИФРЫ - " << breaker << endl;
				cout << "Попрубуйте еще раз";
		}
		if (breaker == 4) {
			break;
		}
	}

	cout << "Очистка данных" << endl;
	delete[] P;
	return 0;
}



void input_struct(struct Trasport* P, int n) {
	ifstream fin;
	fin.open("fileTransport.txt", ios::in);
	for (int i = 0; i < n; i++) {
		fin >> P[i].id;
		fin >> P[i].brand;
		fin >> P[i].BodyType;
		fin >> P[i].HP;
		fin >> P[i].price;
	}
	fin.close();
}

void output_struct(struct Trasport* P, int n) { 

	cout << "id\t" << "brand\t" << "BodyType\t" << "HP\t" << "price" << endl;
	cout << "====================================" << endl;
	for (int i = 0; i < n; i++) {
		cout << P[i].id;
		cout << "\t" << P[i].brand;
		cout << "\t" << P[i].BodyType;
		cout << "\t" << P[i].HP;
		cout << "\t" << P[i].price << endl;
	}
	cout << "====================================" << endl;

}

void correct(struct Trasport* P, int n) {
	int key0 = 0;
	int key = 0;
	cout << "1 если нужно исправить, 0 если скип" << endl;
	cin >> key0;
	while (key0 != 0) {

		if (key0 == 1) {
			cout << "номер линии" << endl;
			cin >> key;
			if ((key != 1) && (key != 2) && (key != 3) && (key != 4)) {
				cout << "Нет такого" << endl;
			}
			if ((key == 1) || (key == 2) || (key == 3) || (key == 4)) {
				cout << "Внести изменения в " << key << " линию:" << endl;
				cout << "id: ";
				cin >> P[key - 1].id;
				cout << "brand: ";
				cin >> P[key - 1].brand;
				cout << "BodyType: ";
				cin >> P[key - 1].BodyType;
				cout << "HP: ";
				cin >> P[key - 1].HP;
				cout << "price: ";
				cin >> P[key - 1].price;
			}
		}
		cout << endl << "нажмите 0 чтобы выйти,для продолжения 1" << endl;
		cin >> key0;
	}
}

void min_account(struct Trasport* P, int n) { 
	int min = P[0].price;
	int k = 0;
	for (int i = 1; i < n; i++) {
		if (P[i].price < min) {
			min = P[i].price;
			k = i;
		}
	}
	cout << "Самая дешевая машина: " << P[k].id << " " << P[k].brand << " " << P[k].BodyType << " " << P[k].HP << " " << min << "\n";
}

void newFile(struct Trasport* P, int n) {
	char brand[20];
	cout << endl << "Введите название файла: ";
	cin >> brand;
	strcat_s(brand, ".txt");
	ofstream save;
	save.open(brand);
	for (int i = 0; i < n; i++) {
		save << P[i].id;
		save << " " << P[i].brand;
		save << " " << P[i].BodyType;
		save << " " << P[i].HP;
		save << " " << P[i].price << endl;
	}
	save.close();
}