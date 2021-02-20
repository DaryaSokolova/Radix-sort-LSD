#include <iostream>
#include <vector>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");

    //Числа сортируются по разрядам.
    //сортировка проводится от младшего разряда к старшему. Итоговый порядок: короткие
    //ключи идут раньше длинных, одинаковые ключи сортируются по алфавиту.Подходит для чисел

    //Вход: A — массив, N — размер массива, k — максимальный разряд
    int n; cin >> n;
    int k; cin >> k;

    bool flag = true;;

    int* A = new int[n];

    for (int i = 0; i < n; i++)
    {
        cin >> A[i];

        if (A[i] > pow(10, k))
        {
            flag = false;
        }
    }


    //Основание системы счисления 
    int P = 10;

    //создаем P дополнительных векторов
    vector < vector < int > > v1(P);

    if ((k <= 0)||(flag == false))
    {
        cout << "неверные входные данные" << endl;
    }
    else
    {
        for (int i = 0; i < k; i++)
        {

            //подсчет степени P^i
            int P1 = 1;
            for (int index = 0; index < i; index++)
            {
                P1 = P1 * P;
            }

            //добавление A[j] в вектор
            for (int j = 0; j < n; j++)
            {
                int q = (A[j] / P1) % P;
                v1[q].push_back(A[j]);
            }

            //перезаписываем вектора от 0-вого до P − 1-ого в массив A
            //Распределяем элементы измененного по векторам в соответствии с десятками (первым разрядом):

            int q = 0;
            for (int i = 0; i < v1.size(); i++)
            {
                for (int j = 0; j < v1[i].size(); j++)//вывод с помощью индекса
                {
                    A[q] = v1[i][j];
                    q++;
                }
            }

            //вывод вектора векторов
            //    for (int i = 0; i < v1.size(); i++)
            //    {
            //        for (vector<int>::iterator it = v1[i].begin(); it != v1[i].end(); it++)
            //        {
            //            cout << i << " " << *it << " ";
            //        }
            //        cout << endl;
            //    }

            //очищаем вектора
            for (int i = 0; i < v1.size(); i++)
            {
                v1[i].clear();
            }

        }

        cout << "Отсортированный массив: " << endl;
        for (int i = 0; i < n; i++)
        {
            cout << A[i] << " ";
        }
    }

    return 0;
}
