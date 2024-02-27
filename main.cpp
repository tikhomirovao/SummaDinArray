#include <iostream>
#include <stdlib.h>
#include <time.h>


using namespace std;
//прототип шаблонной функции для поиска среднего арифметического значений динамического массива
template <typename T> T SummaElementMiddle(T* DynArray, int Size);

int main()
{
    system("chcp 1251");
    system("cls");
    srand(time(NULL));
    // для массива элементов типа данных int
    int Size = 0; //размер массива
    int* DynArray = nullptr; //указатель адреса динамически выделенной памяти
    cout << "Введите размер массива: "; cin >> Size;
    DynArray = new int[Size] {}; //объявление динамического массива с унифицированной инициализацией
    // если память не была выделена
    if (!DynArray)cout << "Ошибка выделения памяти!" << endl;
    else // при успешном выделении памяти
    {
        //заполняем массив значениями и выводим его на экран
        for (int i = 0; i < Size; i++)
        {
            DynArray[i] = rand() % (100 - (-99)) - 99;
            cout << DynArray[i] << "\t";
        }
        cout << endl;
        cout << endl;
    }
    //вызов функции для поиска среднего арифметического значений динамического массива
    cout << SummaElementMiddle(DynArray, Size) << endl;

    //проверяем не удалена ли память и удаляем 
    if (DynArray) { delete[] DynArray; DynArray = nullptr; }
    else cout << "Память уже была освобождена!" << endl;

    // для массива элементов типа данных double
    double* DynArray1 = nullptr; //указатель адреса динамически выделенной памяти
    cout << "Введите размер массива: "; cin >> Size;
    DynArray1 = new double[Size] {}; //объявление динамического массива с унифицированной инициализацией
    // если память не была выделена
    if (!DynArray1)cout << "Ошибка выделения памяти!" << endl;
    else // при успешном выделении памяти
    {
        //заполняем массив значениями и выводим его на экран
        for (int i = 0; i < Size; i++)
        {
            DynArray1[i] = rand() % (100 - (-99)) - 99 * 1.1;
            cout << DynArray1[i] << "\t";
        }
        cout << endl;
        cout << endl;
    }
    //вызов функции для поиска среднего арифметического значений динамического массива
    cout << SummaElementMiddle(DynArray1, Size) << endl;

    //проверяем не удалена ли память и удаляем 
    if (DynArray1) { delete[] DynArray1; DynArray1 = nullptr; }
    else cout << "Память уже была освобождена!" << endl;
}
//реализация шаблонной функции для поиска среднего арифметического значений динамического массива
template<typename T>
T SummaElementMiddle(T* DynArray, int Size)
{
    T MiddleSumma = 0;//переменная для хранения суммы элементов
    //в цикле складываем все элементы
    for (int i = 0; i < Size; i++)
    {
        MiddleSumma += DynArray[i];
    }
    return MiddleSumma / Size;//возвращаем сумма всех элементов поделеная на количество элементов
}