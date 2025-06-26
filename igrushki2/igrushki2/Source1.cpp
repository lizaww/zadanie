#include "module_2.h"
struct Toy
{
    string name;
    double price;
    int min_age;
    int max_age;
};

void find()
{
    ifstream fin("Assort.txt");
    ofstream fout("intermediate.txt");

    // ѕодсчет количества записей
    int count = 0;
    string temp;
    while (getline(fin, temp))
    {
        count++;
    }
    fin.clear();
    fin.seekg(0);

    Toy* toys = new Toy[count];
    for (int i = 0; i < count; i++)
    {
        fin >> toys[i].name >> toys[i].price >> toys[i].min_age >> toys[i].max_age;
    }

    // ѕоиск самой дорогой игрушки дл€ детей до 4 лет
    double max_price = 0;
    string most_expensive_toy;
    bool found = false;

    for (int i = 0; i < count; i++)
    {
        if (toys[i].max_age < 4 && toys[i].price > max_price)
        {
            max_price = toys[i].price;
            most_expensive_toy = toys[i].name;
            found = true;
        }
    }

    if (found)
    {
        cout << "—ама€ дорога€ игрушка дл€ детей до 4 лет: " << most_expensive_toy
            << " (цена: " << max_price << " руб.)" << endl;
        fout << "—ама€ дорога€ игрушка дл€ детей до 4 лет: " << most_expensive_toy
            << " (цена: " << max_price << " руб.)" << endl;
    }
    else
    {
        cout << "»грушек дл€ детей до 4 лет не найдено." << endl;
        fout << "»грушек дл€ детей до 4 лет не найдено." << endl;
    }

    fin.close();
    fout.close();
    delete[] toys;
}