#include <stdlib.h>
#include <iostream>


using namespace std;

//void show_main_menu();
//int get_item_menu(int count);

void show_main_menu()
{
    system("cls"); // ������� �����
    cout << "�������� ����� ����" << endl;
    cout << "1. �������� ������� ��������� �����" << endl;
    cout << "2. �������� ������� ��������� �����" << endl;
    cout << "3. �������� ������� ������" << endl;
    cout << "4. �������� ������������ �������" << endl;
    cout << "5. �������� �������������� ������" << endl;
    cout << "6. �����" << endl;
    cout << ">";
}

int get_item_BDmenu(int count)
    {
    int variant;
    string s; // ������ ��� ���������� �������� ������
    cin >> variant;
    //getline(cin, s); // ��������� ������

    // ���� ���� �����������, �������� �� ���� � ������ ��������� ���
    while (variant > count) 
    {
        cout << "������������ ����. ��������� �����: "; // ������� ��������� �� ������
        cin >> variant;; // ��������� ������ ��������
    }

    return variant;
}