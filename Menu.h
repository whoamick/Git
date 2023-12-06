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
        cout << "�������� ���������: "
            << endl << "[1] �������� � ������ ������; "
            << endl << "[2] �������� � ����� ������; "
            << endl << "[3] ����������� ������; "
            << endl << "[4] �������� �������� �� �������;"
            << endl << "[5] �������� ����; "
            << endl << "[6] ����� ������� �� �������; "
            << endl << "[7] �������� ��������;"
            << endl << "[8] �������� �������"
            << endl << "[9] ������ � ����"
            << endl << "[10] ������� �� �����"
            << endl << "[11] ����� �� ���������"
            << endl << "[12] ���������� �� ����������"
            << endl << "[13] ������ ����������� ��������"
            << endl << "[0] �����."
            << endl;

       
        cin >> x;
      
        rewind(stdin);
        switch (x) {
        case 1: {
            system("cls");
            T ex;
            cout << "������� ������:" << endl;
            cin >> ex;
            rewind(stdin);
            list.prepend(ex);
            
        }
              break;
              //���������� � ������ ������+
        case 2: {
            system("cls");
            T ex;
            cout << "������� ������:";
            cin >> ex;
            rewind(stdin);
            list.append(ex);
        }
              break;
              ///���������� � ����� ������+
        case 3: {
            system("cls");
            T ex;
            ex.shapka();
           /* list.display();
            system("pause");*/
          
        }
              break;
              //����� �� �����+
        case 4: {
            system("cls");
            cout << "������� ������ �������� ��� ��������: ";
            int index;
            cin >> index;
            list.deleteElement(index - 1);
            system("pause");

        }
              break;
              //�������� �� �������+
        case 5: {
            system("cls");
            list.clearlist();
            cout << "���� ������!" << endl;
            system("pause");
        }
              break;
              //������� �����+
        case 6: {
            system("cls");
            cout << "������� ������: ";
            int index;
            cin >> index;
            T data = list.getElementByIndex(index - 1);
            data.shapka();
            cout << data;
            system("pause");

        }
              break;
              //����� �� �������+
        case 7: {
            system("cls");
            int id;
            T ex;
            ex.shapka();
            list.display();
            cout << "������� ������ ��������:";
            cin >> id;
            ex = list.getElementByIndex(id - 1);
            ex.change();
            list.setElementByIndex(id - 1, ex);
            system("pause");

        }
              break;
              //������� ���������+-
        case 8: {
            system("cls");
            int c1, c2;
            cout << "������� ������ ������� ��������: ";
            cin >> c1;
            cout << "������� ������ ������� ��������: ";
            cin >> c2;
            list.swapElements(c1, c2);
            system("pause");
        }
              break;
              //�������� �������+-
        case 9: {
            list.wrtFile("list.txt");

        }
              break;
              //�������� � ����-
        case 10: {
                
        }
               break;
               //������� �� �����-
        case 11: {

        }
               break;
               //�������� ����-
        case 12: {

        }
               break;
               //����� �� ���������-
        case 13: {
            int param;
            cin >> param;
            /*Algorithm<T> alg;*/
          /*  alg.Sort(list);*/
        }
               break;
               //���������� �� ���������-

        case 14: {

        }
               break;
               //������ ���������� ��������-
        case 0: return;
     
        }
    } while (1);
}

int menu::start()
{
    while (1) {
        system("CLS");
        cout << "\t\t\t" << "����� ���������� � ��������� ������������!"
            << endl << endl << "�������� ����: "
            << endl << endl << "[1] ��������;"
            << endl << "[2] ���������;"
            << endl << "[3] �������;"
            << endl << "[4] �����; "
            << endl << "[0] ��������� ���������."
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
            cout << "������� �����(0-4)!" << endl;
            system("pause");
        }
               break;
        }
       
    }
 
}
