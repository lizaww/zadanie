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

    // ������� ���������� �������
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

    // ����� ����� ������� ������� ��� ����� �� 4 ���
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
        cout << "����� ������� ������� ��� ����� �� 4 ���: " << most_expensive_toy
            << " (����: " << max_price << " ���.)" << endl;
        fout << "����� ������� ������� ��� ����� �� 4 ���: " << most_expensive_toy
            << " (����: " << max_price << " ���.)" << endl;
    }
    else
    {
        cout << "������� ��� ����� �� 4 ��� �� �������." << endl;
        fout << "������� ��� ����� �� 4 ��� �� �������." << endl;
    }

    fin.close();
    fout.close();
    delete[] toys;
}