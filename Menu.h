#pragma once
#include<iostream>
#include<iomanip>
#include <vector>
#include "detectiv.h"
#include "drama.h"
#include "romantic.h"
#include "fantasy.h"
#include "list.cpp"
#include "err.h"
#include "algorithm.h"

using namespace std;


class menu
{
    int choise;
    char chooseGenre;
public:
    int start();
    template<typename T>
    void InList(List<T>& list, int index);


};
template<typename T>
void menu::InList(List<T>& list, int index) {
    int x;
    do {
        system("CLS");
        cout << "Выберите категорию: "
            << endl << "[1] Добавить в начало списка; "
            << endl << "[2] Добавить в конец списка; "
            << endl << "[3] Просмотреть список; "
            << endl << "[4] Удаление элемента по индексу;"
            << endl << "[5] Очистить лист; "
            << endl << "[6] Найти элемент по индексу; "
            << endl << "[7] Изменить параметр;"
            << endl << "[8] Поменять местами"
            << endl << "[9] Запись в файл"
            << endl << "[10] Считать из файла"
            << endl << "[11] Поиск по параметру"
            << endl << "[12] Сортировка по параметрам"
            << endl << "[13] Отмена предыдущего действия"
            << endl << "[0] Назад."
            << endl;

       
        cin >> x;
      
        rewind(stdin);
        switch (x) {
        case 1: {
            system("cls");
            T ex;
            cout << "Введите данные:" << endl;
            cin >> ex;
            rewind(stdin);
            list.prepend(ex);
            
        }
              break;
              //добавление в начало списка+
        case 2: {
            system("cls");
            T ex;
            cout << "Введите данные:";
            cin >> ex;
            rewind(stdin);
            list.append(ex);
        }
              break;
              ///добавление в конец списка+
        case 3: {
            system("cls");
            T ex;
            ex.shapka();
           /* list.display();
            system("pause");*/
          
        }
              break;
              //Вывод на экран+
        case 4: {
            system("cls");
            cout << "Введите индекс элемента для удаления: ";
            int index;
            cin >> index;
            list.deleteElement(index - 1);
            system("pause");

        }
              break;
              //Удаление по индексу+
        case 5: {
            system("cls");
            list.clearlist();
            cout << "Лист очищен!" << endl;
            system("pause");
        }
              break;
              //Очистка листа+
        case 6: {
            system("cls");
            cout << "Введите индекс: ";
            int index;
            cin >> index;
            T data = list.getElementByIndex(index - 1);
            data.shapka();
            cout << data;
            system("pause");

        }
              break;
              //Поиск по индексу+
        case 7: {
            system("cls");
            int id;
            T ex;
            ex.shapka();
            list.display();
            cout << "Введите индекс элемента:";
            cin >> id;
            ex = list.getElementByIndex(id - 1);
            ex.change();
            list.setElementByIndex(id - 1, ex);
            system("pause");

        }
              break;
              //Измение параметра+-
        case 8: {
            system("cls");
            int c1, c2;
            cout << "Введите индекс первого элемента: ";
            cin >> c1;
            cout << "Введите индекс второго элемента: ";
            cin >> c2;
            list.swapElements(c1, c2);
            system("pause");
        }
              break;
              //Поменять местами+-
        case 9: {
            list.wrtFile("list.txt");

        }
              break;
              //Записать в файл-
        case 10: {
                
        }
               break;
               //Считать из файла-
        case 11: {

        }
               break;
               //Очистить файл-
        case 12: {

        }
               break;
               //Поиск по параметру-
        case 13: {
            int param;
            cin >> param;
            /*Algorithm<T> alg;*/
          /*  alg.Sort(list);*/
        }
               break;
               //Сортировка по парметрам-

        case 14: {

        }
               break;
               //Отмена последнего действия-
        case 0: return;
     
        }
    } while (1);
}

int menu::start()
{
    while (1) {
        system("CLS");
        cout << "\t\t\t" << "Добро пожаловать в картотеку видеофильмов!"
            << endl << endl << "Выберите жанр: "
            << endl << endl << "[1] Детектив;"
            << endl << "[2] Романтика;"
            << endl << "[3] Фэнтези;"
            << endl << "[4] Драма; "
            << endl << "[0] Завершить программу."
            << endl;
        rewind(stdin);
        switch (_getch()) {
        case '1': {
            List<detectiv> l;
            detectiv detf;
            InList(l, 1);
        }
                break;
        case '2': {
            List<romantic> l;
            romantic romf;
            InList(l, 2);
        }
                break;
        case '3': {
            List<fantasy> l;
            fantasy fanf;
            InList(l, 3);
        }
                break;
        case '4': {
            List<drama> l;
            drama draf;
            InList(l, 4);
        }
        break;
        case '0': return 0;
         
        
        default: {
            cout << "Введите число(0-4)!" << endl;
            system("pause");
        }
               break;
        }
       
    }
 
}
