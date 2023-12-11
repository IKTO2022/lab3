#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Data {
    string name;
    int age;
    double balance;
;

void readData(Data*    B, int    size) {
    ifstream file("data.txt");
    file >> size;
    B = new Data[size];
    for (int i = 0; i < size; i++) {
        file >> B[i].name >> B[i].age >> B[i].balance;
    }
    file.close();


void showData(Data* B, int size) {
    for (int i = 0; i < size; i++) {
        cout << "Name: " << B[i].name << endl;
        cout << "Age: " << B[i].age << endl;
        cout << "Balance: " << B[i].balance << endl;
        cout << endl;
    }


void correctData(Data* B, int size, int index) {
    if (index >= 0        index < size) {
        cout << "Enter new name: ";
        cin >> B[index].name;
        cout << "Enter new age: ";
        cin >> B[index].age;
        cout << "Enter new balance: ";
        cin >> B[index].balance;
        cout << "Data corrected." << endl;
     else {
        cout << "Invalid index." << endl;
    }


void calculate(Data* B, int size) {
    double totalBalance = 0;
    for (int i = 0; i < size; i++) {
        totalBalance += B[i].balance;
    }
    double averageBalance = totalBalance / size;
    cout << "Total balance: " << totalBalance << endl;
    cout << "Average balance: " << averageBalance << endl;


void saveData(Data* B, int size) {
    string filename;
    cout << "Enter filename to save data: ";
    cin >> filename;
    ofstream newFile(filename);
    newFile << size << endl;
    for (int i = 0; i < size; i++) {
        newFile << B[i].name << " " << B[i].age << " " << B[i].balance << endl;
    }
    newFile.close();
    cout << "Data saved to file." << endl;


int main() {
    Data* B = nullptr;
    int size = 0;
    readData(B, size);

    int choice;
    do {
        cout << "1. Show data" << endl;
        cout << "2. Correct data" << endl;
        cout << "3. Calculate" << endl;
        cout << "4. Save data" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                showData(B, size);
                break;
            case 2:
                int index;
                cout << "Enter index of data to correct: ";
                cin >> index;
                correctData(B, size, index);
                break;
            case 3:
                calculate(B, size);
                break;
            case 4:
                saveData(B, size);
                break;
            case 5:
                cout << "Exiting program..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
     while (choice != 5);

    delete[] B;
    return 0;
