#include <stdio.h>
#include <iostream>

int Plus(int a, int b);
int Minus(int a, int b);
int Mult(int a, int b);
int Div(int a, int b);
int (*functptr[])(int a, int b) = { Plus, Minus, Mult, Div };

void main()
{
	setlocale(LC_ALL, "Russian");

	int a;
	int b;
	int choice;
	std::cout << "------- КАЛЬКУЛЯТОР -------" << "\n";
	std::cout << "Введите первое число:\n";
	std::cin >> a;
	std::cout << "Введите второе число:\n";
	std::cin >> b;
	std::cout << "Выберите действие:\n0 - сложение,\n1 - вычитание, \n2 - умножение, \n3 - деление.\n";
	std::cin >> choice;
	std::cout << "Результат: \n";
	(*functptr[choice])(a, b);

}

int Plus(int a, int b)
{
	std::cout << a+b;
	return 0;
}

int Minus(int a, int b)
{
	std::cout << a - b;
	return 0;
}

int Mult(int a, int b)
{
	std::cout << a*b;
	return 0;
}

int Div(int a, int b)
{
	std::cout << a/b;
	return 0;
}