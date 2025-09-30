#include <iostream>
#include <Windows.h>
#include <string>
using namespace std;

double summa(double h,double s,double p){ //обща€ сумма с учетом премии
    double n;
    n = h * s * (1 + p / 100);
    return n;
}

double nalog(double sum){ // сумма налогов
    double s = sum * 0.13;
    return s;
}

double totl(double sum, double nal){ // зп на руки работнику
    double t = sum - nal;
    return t;
}

int main(){
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    
    int size;
    
    cout << "¬ведите кол-во работников: ";
    cin >> size ;

    double* salary = new double[size]; //массив с зп
    double* nalogi = new double[size]; //массив с налогами
    double hours, rate, prem, nmin, maxs = 0, nmax, k = 0, sum = 0, min = 1000000000;
    string numb = "";

    for (int i = 0; i < size; i++){
        cout << "дл€ " << i+1 << " работника:" << endl;
        cout << "кол-во часов: ";
        cin >> hours;
        cout << "ставка: ";
        cin >> rate;
        cout << "% премии: ";
        cin >> prem;

        double s = summa(hours,rate,prem);
        nalogi[i] = nalog(s);
        salary[i] = totl(s, nalog(s));
    }
    

    for (int i = 0; i < size; i++){

        if (salary[i] < min){ // номер работника с мин зп
            nmin = i+1;
            min = salary[i];}

        if (salary[i] > maxs){// номер и сумма зп работника с макс зп
            nmax = i+1;
            maxs = salary[i];} 

        if (salary[i] > 50000){// кол-во и номера с зп>50000
        k ++;
        string n = to_string(i+1) + " ";
        numb += n;}
        sum += nalogi[i];
    }

    cout << "номер работника, получившего меньше всех: " <<nmin << endl;
    cout << "максимальна€ из зарплат и номер получившего ее работника: " << maxs << " " << nmax << endl;
    cout << "количество работников, получивших на руки более 50000 руб: "<< k << " и их номера: " << numb << endl;
    cout << "обща€ сумма налога, уплаченного всей бригадой: "<< sum;


    return 0;
}