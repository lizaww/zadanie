#include "module_1.h"
struct Toy
{
    string name;
    double price;
    int min_age;
    int max_age;
};

void enter()
{
    ofstream fout("Assort.txt");
    int n;
    cout << "������� ���������� �������: ";
    cin >> n;
    Toy* toys = new Toy[n];

    for (int i = 0; i < n; i++)
    {
        cout << "������� " << i + 1 << endl;
        cout << " ��������: ";
        cin >> toys[i].name;
        cout << " ���� (���): ";
        cin >> toys[i].price;
        cout << " ����������� �������: ";
        cin >> toys[i].min_age;
        cout << " ������������ �������: ";
        cin >> toys[i].max_age;

        fout << toys[i].name << " " << toys[i].price << " "
            << toys[i].min_age << " " << toys[i].max_age << endl;
    }
    fout.close();
    delete[] toys;
}