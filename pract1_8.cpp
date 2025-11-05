#include <iostream>
#include <Windows.h>
#include <string>
using namespace std;

double summa(double h,double s,double p){ //общая сумма с учетом премии
    double n;
    n = h * s * (1 + p / 100);
    return n;
}


int main(){
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    
    int size;
    
    cout << "Введите кол-во работников: ";
    cin >> size ;

    double* salary = new double[size]; //массив с зп
    double* nalogi = new double[size]; //массив с налогами
    double hours, rate, prem, nmin, maxs = 0, nmax, k = 0, sum = 0, min = 1000000000;
    string numb = "";

    for (int i = 0; i < size; i++){
        cout << "для " << i+1 << " работника:" << endl;
        cout << "кол-во часов: ";
        cin >> hours;
        cout << "ставка: ";
        cin >> rate;
        cout << "% премии: ";
        cin >> prem;

        nalogi[i] = summa(hours,rate,prem) * 0.13;
        salary[i] = summa(hours,rate,prem) * 0.87;
    }
    

    for (int i = 0; i < size; i++){
        if (salary[i] < min){ // номер работника с мин зп
            nmin = i;
            min = salary[i];
        }

        if (salary[i] > maxs){// номер и сумма зп работника с макс зп
            nmax = i+1;
            maxs = salary[i];
        } 

        if (salary[i] > 50000){// кол-во и номера с зп>50000
        k ++;
        string n = to_string(i+1) + " ";
        numb += n;
        }
        
        sum += nalogi[i];
        delete[] salary;
        delete[] nalogi;
    }

    cout << "номер работника, получившего меньше всех: " << nmin + 1 << endl;
    cout << "максимальная из зарплат и номер получившего ее работника: " << maxs << " " << nmax << endl;
    cout << "количество работников, получивших на руки более 50000 руб: "<< k << " и их номера: " << numb << endl;
    cout << "общая сумма налога, уплаченного всей бригадой: "<< sum;


    return 0;
}