#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <ios>
#include <iomanip>

int main()
{
	setlocale(LC_ALL, "ru");
	std::fstream file_name;                                        // создание файла с названиями 
	file_name.open("name.txt", std::ofstream::out);

	std::fstream file_amount;                                       // создание файла с кол-вом          } режим записи
	file_amount.open("amount.txt",std::ofstream::out);

	std::fstream file_price;                                        // создание файла с ценой
	file_price.open("price.txt", std::ofstream::out);

	if (!file_name.is_open() || !file_amount.is_open() || !file_price.is_open())  //проверка
	{
		std::cerr << "Error!\n";
	}
	else
	{
		std::string name;
		int price;
		int amount;
		int choice;
		int replays = 3;

		std::cout << "\n" << "-------------------------------";
		std::cout << "Приложение для работы с файлами";
		std::cout << "-------------------------------" << "\n";
		std::cout << "\n" << "Доступные для записи файлы: " <<                                         // меню
			"\n1) name.txt " <<                                                      
			"\n2) amount.txt " <<
			"\n3) price.txt";
		for (int i = 0; i < replays; i++)
		{
			std::cout << "\nВ какой файл записать данные? Введите цифру: \n";
			std::cin >> choice;
			std::cout << "-------------------------------";

			if (choice == 1)
			{
				std::cout << "\nВыбран файл name.txt \n" << "Введите данные для трех элементов:\n";
				for (int i = 0; i < replays + 1; i++)
				{                                                                                           // заполнение name.txt
					std::getline(std::cin, name, '\n');
					file_name << name << std::endl;
				}
			
			}
			if (choice == 2)
			{
				std::cout << "\nВыбран файл amount.txt \n" << "Введите данные для трех элементов:\n";
				for (int i = 0; i < replays; i++)
				{                                                                                          // заполнение amount.txt
					std::cin >> amount;
					file_amount << amount << "\n";
				}
			}
			if (choice == 3)
			{
				std::cout << "\nВыбран файл price.txt \n" << "Введите данные для трех элементов:\n";
				for (int i = 0; i < replays; i++)
				{
					std::cin >> price;                                                                   // заполнение price.txt
					file_price << price << "\n";
				}
		    }

		}
		
		

		file_name.close();
		file_amount.close();
		file_price.close();

		file_amount.open("amount.txt", std::ios::in); 
		file_price.open("price.txt", std::ios::in);      // открытие в режиме чтения
		file_name.open("name.txt", std::ios::in);


		std::string* name_arr = new std::string[replays];
		int* amount_arr = new int[replays];                         //массивы для хранения инфы
		int* price_arr = new int[replays];

		for (int i = 0; i < replays + 1; i++)
		{   
			file_name >> name_arr[i];                             // запись названий в массив
		}
		
		for (int i = 0; i < replays + 1; i++)
		{
			file_amount >> amount_arr[i];                        // запись кол-ва в массив
		}
		
		for (int i = 0; i < replays + 1; i++)
		{
			file_price >> price_arr[i];                         // запись цен в массив
		}
		
		std::cout << "ID\t" << "Название\t" << "Количество\t" << "Цена\t" << std::endl;
		for (int i = 0; i < replays; i++)
		{
			std::cout << i + 1 << "\t" << name_arr[i] << "\t\t" << amount_arr[i] << "\t\t" << price_arr[i] << std::endl;

		}
		
		delete[] name_arr;
		delete[] amount_arr;
		delete[] price_arr;

	}

	file_name.close();
	file_amount.close();
	file_price.close();

	
	return 0;

}
