#include <stdlib.h>
#include <iostream>


using namespace std;

//void show_main_menu();
//int get_item_menu(int count);

void show_main_menu()
{
    system("cls"); // очищаем экран
    cout << "Выберите пункт меню" << endl;
    cout << "1. Показать таблицу Коллекция монет" << endl;
    cout << "2. Показать таблицу Состояние монет" << endl;
    cout << "3. Показать таблицу Страны" << endl;
    cout << "4. Показать объединенную таблицу" << endl;
    cout << "5. Показать дополнительные данные" << endl;
    cout << "6. Выход" << endl;
    cout << ">";
}

int get_item_BDmenu(int count)
    {
    int variant;
    string s; // строка для считывания введённых данных
    cin >> variant;
    //getline(cin, s); // считываем строку

    // пока ввод некорректен, сообщаем об этом и просим повторить его
    while (variant > count) 
    {
        cout << "Некорректный ввод. Повторите снова: "; // выводим сообщение об ошибке
        cin >> variant;; // считываем строку повторно
    }

    return variant;
}