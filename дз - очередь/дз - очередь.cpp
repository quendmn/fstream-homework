#include <iostream>
#include <queue>
#include <vector>


int Queue_Sort(std::queue <int>& q);

int main()
{
    //создание очереди: std::queue <тип данных> имя;

    std::queue <int> q;
    int num;

    for (int i = 0; i < 10; i++)                         //заполнение очереди
    {
        std::cout << "Enter number: " << "\n";
        std::cin >> num;
        q.push(num);
    }

    Queue_Sort(q);

    return 0;
}

int Queue_Sort(std::queue <int> &q)
{
    int size_q = q.size();    
    int* arr = new int[size_q];      //массив для хранения
    auto b = q._Get_container();
    int current = 0;

    std::cout << "Current queue:\n";
    for (int i = 0; i < 10; i++) //вывод очереди
    {
        std::cout << b[i] << " ";
    }
    for (int i = 0; i < 10; i++) //перенос данных из очереди в массив 
    {
        arr[i] = b[i];
    }

    std::cout << "\nArray:\n";  //вывод хранящего массива
    for (int i = 0; i < 10; i++)
    {
        std::cout << arr[i] << " ";
    }

    for (int i = 0; i < 10; i++)         // сортировка массива
    {
        for (int j = 0; j < 9; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int b = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = b;
            }
        }
    }
    std::cout << "\nSorted array:\n";     // вывод отсортированного массива
    for (int i = 0; i < size_q; i++)
    {
        std::cout << arr[i] << " ";
    }

    for (int i = 0; i < size_q; i++)    // очищение очереди
    {
        q.pop();
    }

    for (int i = 0; i < size_q; i++)
    {
        current = arr[i];             // заполнение очереди элементами из массива
        q.push(current);
    }

    std::cout << "\nSorted queue:\n";
    while (!q.empty())
    {
        std::cout << q.front() << "\n";
        q.pop();
    }

    delete[] arr;
    return 0;
}


