// CollectCoinsCPlusPlus.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <conio.h>
#include <iomanip>
#include <cstring>
#include <fstream>
#include <stdio.h>
#include <windows.h>
#include "StructCoins.cpp"
//#include "Menu.cpp"

using namespace std;

int count_Coins = 0;
int count_Country = 0;
int count_Condition = 0;

boolean load_Count(string name_file, int* counter);
int get_item_BDmenu(int count);
void show_main_menu();

boolean load_Coins(CollectCoins* collectCoins, Header_CollectionCoins* header_CollectionCoin);
void print_Coins(CollectCoins* collectCoins, Header_CollectionCoins* header_CollectionCoin);

boolean load_Country(Country* country, Header_Country* header_Country);
void print_Country(Country* country, Header_Country* header_Country);

boolean load_Condition(Condition* condition, Header_Condition* header_Condition);
void print_Condition(Condition* condition, Header_Condition* header_Condition);

void print_Joint_Tabl(CollectCoins* collectCoins, Header_CollectionCoins* header_CollectionCoin, 
						Country* country, Header_Country* header_Country, 
						Condition* condition, Header_Condition* header_Condition);



int main()
{
	setlocale(LC_ALL, "Russian_Russia.1251");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, ".1251");
	setlocale(LC_ALL, "Russian");
	system("mode con cols=200 lines=50");

	

	cout << "Самостоятельное задание. Ляхнович И.З. 19.06.2022 года. С++" << endl;
	cout << "Обработка данных о коллекции монет" << endl;
	cout << endl;

	cout << "________________________________________________________________________________________________";
	cout << endl << endl << endl;

	if (!load_Count("Коллекция монет.txt", &count_Coins))
	{
		cout << "файл Коллекция монет.txt неверен. Программа завершает свою работу.";
		return 0;
	}
	
	if (!load_Count("Страны.txt", &count_Country))
	{
		cout << "файл Страны.txt неверен. Программа завершает свою работу.";
		return 0;
	}	
	
	if (!load_Count("Состояние.txt", &count_Condition))
	{
		cout << "файл Состояние.txt неверен. Программа завершает свою работу.";
		return 0;
	}
		cout << "файл Коллекция монет.txt." << endl;
		CollectCoins* collectCoins = new CollectCoins[count_Coins];
		Header_CollectionCoins* header_CollectionCoin = new Header_CollectionCoins;

		load_Coins(collectCoins, header_CollectionCoin);
		print_Coins(collectCoins, header_CollectionCoin);
	
		cout << "файл Страны.txt ." << endl;
		Country* country = new Country[count_Country];
		Header_Country* header_Country = new Header_Country;

		load_Country(country, header_Country);
		print_Country(country, header_Country);

		cout << "файл Состояние.txt ." << endl;
		Condition* condition = new Condition[count_Condition];
		Header_Condition* header_Condition = new Header_Condition;

		load_Condition(condition, header_Condition);
		print_Condition(condition, header_Condition);

		cout << "Объединенная таблица - слияние трех таблиц - Коллекции моонет + Страны + Состояние ." << endl;
		print_Joint_Tabl(collectCoins, header_CollectionCoin,
			country, header_Country,
			condition, header_Condition);

		int item_menu;

		do {
			show_main_menu();

			item_menu = get_item_BDmenu(6); // получаем номер выбранного пункта меню

			switch (item_menu) {
			case 1:
				print_Coins(collectCoins, header_CollectionCoin);
				break;

			case 2:
				print_Condition(condition, header_Condition);
				break;

			case 3:
				print_Country(country, header_Country);
				break;

			case 4:
				print_Joint_Tabl(collectCoins, header_CollectionCoin,
					country, header_Country,
					condition, header_Condition);
				break;
			case 5:
				cout << "В разработке." << endl;
				break;
			}

			if (item_menu != 6)
				system("pause"); // задерживаем выполнение, чтобы пользователь мог увидеть результат выполнения выбранного пункта
		} while (item_menu != 6);

	system("pause");
	return 0;
}



boolean load_Count(string name_file, int* counter)
{
	ifstream flow;                                       // Поток ввода
	flow.open(name_file);                 // Открытие файла и связывание его с потоком flow.
	int number_line = 0;		// Количество строк в файле
	boolean isRead = true;

	if (!flow.is_open())                                 // Проверка открытия файла
	{
		cout << "The data file cannot be opened!" << endl;         // Если файл не может быть прочитан

		number_line = 0;
		isRead = false;

	}
	else
	{
		char buffer[1000];                                          // буфер для чтения одной строки файла
		while (flow.eof() == false)                      // цикл работает пока не конец файла и считаем количество строк в файле
		{
			flow.getline(buffer, 1000, '\n');             // прочитать текущую строку из файла в буфер
			number_line++;                                         //  увеличиваем счетчик количества строк
		}

		flow.close();

		isRead = true;
	}

	*counter = (number_line - 1);

	cout << "Количество элементов в: " << name_file << ": " << *counter << endl;

	return isRead;
}

boolean load_Coins(CollectCoins* collectCoins, Header_CollectionCoins* header_CollectionCoin)
{
	ifstream flow_Coins;                                       // Поток ввода
	flow_Coins.open("Коллекция монет.txt");                 // Открытие файла и связывание его с потоком flow_Coins.
	boolean isRead = true;
	
	if (!flow_Coins.is_open())                                 // Проверка открытия файла
	{
		cout << "The data file cannot be opened!" << endl;         // Если файл не может быть прочитан
		
		isRead = false;

	}
	else 
	{	                                       
		setlocale(LC_ALL, "Russian_Russia.1251");
		SetConsoleCP(1251);
		SetConsoleOutputCP(1251);
		setlocale(LC_ALL, ".1251");
		setlocale(LC_ALL, "Russian");

		flow_Coins.seekg(0, ios::beg);                         // Устанавливаем указатель на начало файла
		int i = 0;                                   // Начальное значение индекса элементов массива collectionCoins

		flow_Coins >> (*header_CollectionCoin).id_Coin;
		flow_Coins >> (*header_CollectionCoin).Name_Coin;
		flow_Coins >> (*header_CollectionCoin).id_Country;
		flow_Coins >> (*header_CollectionCoin).id_Condition;
		flow_Coins >> (*header_CollectionCoin).Year_Coin;
		flow_Coins >> (*header_CollectionCoin).Circulation_Coin;
		flow_Coins >> (*header_CollectionCoin).Material_Coin;
		flow_Coins >> (*header_CollectionCoin).Weight_Coin;
		flow_Coins >> (*header_CollectionCoin).Est_Price_Coin;
		
		//i++;

		while (flow_Coins.eof() == false)				// Читаем данные пока не конец файла
		{                    
			flow_Coins >> collectCoins[i].id_Coin;
			flow_Coins >> collectCoins[i].Name_Coin;
			flow_Coins >> collectCoins[i].id_Country;
			flow_Coins >> collectCoins[i].id_Condition;
			flow_Coins >> collectCoins[i].Year_Coin;
			flow_Coins >> collectCoins[i].Circulation_Coin;
			flow_Coins >> collectCoins[i].Material_Coin;
			flow_Coins >> collectCoins[i].Weight_Coin;
			flow_Coins >> collectCoins[i].Est_Price_Coin;

			i++;
		}
				
		flow_Coins.close();

		isRead = true;
	}

	return isRead;
}

boolean load_Country(Country* country, Header_Country* header_Country)
{
	ifstream flow_Country;                                       // Поток ввода
	flow_Country.open("Страны.txt");                 // Открытие файла и связывание его с потоком flow_Coins.
	boolean isRead = true;

	if (!flow_Country.is_open())                                 // Проверка открытия файла
	{
		cout << "The data file cannot be opened!" << endl;         // Если файл не может быть прочитан

		isRead = false;

	}
	else
	{
		setlocale(LC_ALL, "Russian_Russia.1251");
		SetConsoleCP(1251);
		SetConsoleOutputCP(1251);
		setlocale(LC_ALL, ".1251");
		setlocale(LC_ALL, "Russian");

		flow_Country.seekg(0, ios::beg);                         // Устанавливаем указатель на начало файла
		int i = 0;                                   // Начальное значение индекса элементов массива country

		flow_Country >> (*header_Country).id_Country;
		flow_Country >> (*header_Country).Name_Country;
		flow_Country >> (*header_Country).Code_Country;
		
		//i++;

		while (flow_Country.eof() == false)				// Читаем данные пока не конец файла
		{
			flow_Country >> country[i].id_Country;
			flow_Country >> country[i].Name_Country;
			flow_Country >> country[i].Code_Country;
			
			i++;
		}

		flow_Country.close();

		isRead = true;
	}

	return isRead;
}

boolean load_Condition(Condition* condition, Header_Condition* header_Condition)
{
	ifstream flow_Condition;                                       // Поток ввода
	flow_Condition.open("Состояние.txt");                 // Открытие файла и связывание его с потоком flow_Coins.
	boolean isRead = true;

	if (!flow_Condition.is_open())                                 // Проверка открытия файла
	{
		cout << "The data file cannot be opened!" << endl;         // Если файл не может быть прочитан

		isRead = false;

	}
	else
	{
		setlocale(LC_ALL, "Russian_Russia.1251");
		SetConsoleCP(1251);
		SetConsoleOutputCP(1251);
		setlocale(LC_ALL, ".1251");
		setlocale(LC_ALL, "Russian");

		flow_Condition.seekg(0, ios::beg);                         // Устанавливаем указатель на начало файла
		int i = 0;                                   // Начальное значение индекса элементов массива country

		flow_Condition >> (*header_Condition).id_Condition;
		flow_Condition >> (*header_Condition).Name_Condition;
		flow_Condition >> (*header_Condition).Desc_Condition;

		//i++;

		while (flow_Condition.eof() == false)				// Читаем данные пока не конец файла
		{
			flow_Condition >> condition[i].id_Condition;
			flow_Condition >> condition[i].Name_Condition;
			flow_Condition >> condition[i].Desc_Condition;

			i++;
		}

		flow_Condition.close();

		isRead = true;
	}

	return isRead;
}

void print_Coins(CollectCoins* collectCoins, Header_CollectionCoins* header_CollectionCoin)
{
	cout << left << setw(20) << (*header_CollectionCoin).id_Coin;											// Вывод заголовка
	cout << left << setw(20) << (*header_CollectionCoin).Name_Coin;
	cout << left << setw(20) << (*header_CollectionCoin).id_Country;
	cout << left << setw(20) << (*header_CollectionCoin).id_Condition;
	cout << left << setw(20) << (*header_CollectionCoin).Year_Coin;
	cout << left << setw(20) << (*header_CollectionCoin).Circulation_Coin;
	cout << left << setw(20) << (*header_CollectionCoin).Material_Coin;
	cout << left << setw(20) << (*header_CollectionCoin).Weight_Coin;
	cout << left << setw(20) << (*header_CollectionCoin).Est_Price_Coin;

	cout << endl << endl;

	for (int i = 0; i < count_Coins; i++) {                                                                   // Вывод массива CollectCoins
		cout << setw(20) << collectCoins[i].id_Coin << setw(20)
			<< collectCoins[i].Name_Coin << setw(20)
			<< collectCoins[i].id_Country << setw(20)
			<< collectCoins[i].id_Condition << setw(20)
			<< collectCoins[i].Year_Coin << setw(20)
			<< collectCoins[i].Circulation_Coin << setw(20)
			<< collectCoins[i].Material_Coin << setw(20)
			<< collectCoins[i].Weight_Coin << setw(20)
			<< collectCoins[i].Est_Price_Coin << endl;
	}

	cout << endl << endl;
}

void print_Country(Country* country, Header_Country* header_Country)
{
	cout << left << setw(20) << (*header_Country).id_Country;											//вывод заголовка
	cout << left << setw(20) << (*header_Country).Name_Country;
	cout << left << setw(20) << (*header_Country).Code_Country;
	
	cout << endl << endl;

	for (int i = 0; i < count_Country; i++) {                                                                   // Вывод массива country
		cout << setw(20) << country[i].id_Country << setw(20)
			 << country[i].Name_Country << setw(20)
			 << country[i].Code_Country << setw(20) << endl;

	}

	cout << endl << endl;
}

void print_Condition(Condition* condition, Header_Condition* header_Condition)
{
	cout << left << setw(20) << (*header_Condition).id_Condition;											//вывод заголовка
	cout << left << setw(20) << (*header_Condition).Name_Condition;
	cout << left << setw(20) << (*header_Condition).Desc_Condition;

	cout << endl << endl;

	for (int i = 0; i < count_Condition; i++) {                                                                   // Вывод массива country
		cout << setw(20) << condition[i].id_Condition << setw(20)
			<< condition[i].Name_Condition << setw(20)
			<< condition[i].Desc_Condition << setw(20) << endl;

	}

	cout << endl << endl;
}

void print_Joint_Tabl(CollectCoins* collectCoins, Header_CollectionCoins* header_CollectionCoin,
	Country* country, Header_Country* header_Country,
	Condition* condition, Header_Condition* header_Condition)
{
	cout << left << setw(20) << (*header_CollectionCoin).id_Coin;											// Вывод заголовка
	cout << left << setw(20) << (*header_CollectionCoin).Name_Coin;
	cout << left << setw(20) << (*header_Country).Name_Country;
	cout << left << setw(20) << (*header_Condition).Name_Condition;
	cout << left << setw(20) << (*header_CollectionCoin).Year_Coin;
	cout << left << setw(20) << (*header_CollectionCoin).Circulation_Coin;
	cout << left << setw(20) << (*header_CollectionCoin).Material_Coin;
	cout << left << setw(20) << (*header_CollectionCoin).Weight_Coin;
	cout << left << setw(20) << (*header_CollectionCoin).Est_Price_Coin;

	cout << endl << endl;

	for (int i = 0; i < count_Coins; i++) {                                                                   // Вывод массива CollectCoins
		cout << setw(20) << collectCoins[i].id_Coin << setw(20)
			<< collectCoins[i].Name_Coin << setw(20)
			<< country[collectCoins[i].id_Country-1].Name_Country << setw(20)
			<< condition[collectCoins[i].id_Condition-1].Name_Condition << setw(20)
			<< collectCoins[i].Year_Coin << setw(20)
			<< collectCoins[i].Circulation_Coin << setw(20)
			<< collectCoins[i].Material_Coin << setw(20)
			<< collectCoins[i].Weight_Coin << setw(20)
			<< collectCoins[i].Est_Price_Coin << endl;
	}

	cout << endl << endl;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
