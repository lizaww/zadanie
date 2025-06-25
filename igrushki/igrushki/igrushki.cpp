#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm> 
#include <windows.h> 

using namespace std;

// Структура для хранения данных о каждой игрушке
struct ToyData {
    string name;     // Название игрушки
    double price;    // Стоимость в рублях
    int vot;         // Возраст от
    int vdo;         // Возраст до
};

// Функция ввода данных в файл
void inputData() {
    ofstream fout("Assort.txt");
    int count;

    cout << "Введите количество игрушек: " << endl;
    cin >> count;

    ToyData* toys = new ToyData[count];

    for (int i = 0; i < count; ++i) {
        cout << "Запись №" << i + 1 << ":" << endl;

        cout << "\nНазвание игрушки: "; 
        cin.ignore(); getline(cin, toys[i].name);
        cout << "Цена в рублях: "; 
        cin >> toys[i].price;
        cout << "Возраст 'От': "; 
        cin >> toys[i].vot;
        cout << "Возраст 'До': ";
        cin >> toys[i].vdo;

        fout << toys[i].name << " " << toys[i].price << " " << toys[i].vot << " " << toys[i].vdo << endl;
    }

    fout.close();
    delete[] toys;
}

// Функция поиска игрушек для детей до 4-х лет
ToyData findMostExpensiveForUnderFour() {
    ifstream fin("Assort.txt");
    ToyData result{ "Нет подходящих игрушек", 0, 0, 0 }; 
    ToyData current;

    while (fin >> current.name >> current.price >> current.vot >> current.vdo) {
        if (current.vdo <= 4 && current.price > result.price)
            result = current;
    }

    fin.close();
    return result;
}

// Функция вывода найденных игрушек
void displayResult(const ToyData& toy) {
    cout << "Самая дорогая игрушка для детей до 4 лет:\n"
        << "Название: " << toy.name << "\n"
        << "Цена: " << toy.price << " руб.\n\n";
}

// Сохранение итогового результата поиска в отдельный файл
void saveResult(const ToyData& result) {
    ofstream fout("most_expensive_toy_for_under_four.txt");
    fout << "Самая дорогая игрушка для детей до 4 лет:\n"
        << "Название: " << result.name << "\n"
        << "Цена: " << result.price << " руб.";
    fout.close();
}

// Главное меню программы
int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int choice;
    bool exit = false;

    while (!exit) {
        cout << "\nМеню программы:\n"
            "1. Ввести новые данные о товарах\n"
            "2. Найти самую дорогую игрушку для детей до 4 лет\n"
            "3. Вывести найденную игрушку на экран\n"
            "4. Сохранить результат поиска в файл\n"
            "5. Завершить работу\n"
            "Ваш выбор: ";
        cin >> choice;

        switch (choice) {
        case 1:
            inputData();
            break;
        case 2:
            findMostExpensiveForUnderFour();
            break;
        case 3:
            displayResult(findMostExpensiveForUnderFour());
            break;
        case 4:
            saveResult(findMostExpensiveForUnderFour());
            break;
        case 5:
            exit = true;
            break;
        default:
            cout << "Ошибка! Неверный выбор!\n";
        }
    }

    return 0;
}