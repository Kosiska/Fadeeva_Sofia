#include <iostream>
#include <Windows.h>
#include <string>
using namespace std;

int min_element( double n[], double size ){ //номер минимального элемента
    int k = 0, min = n[0];
    for (int i = 0; i < size ; i++ ){
        if (n[i] < min){
            min = n[i];
            k = i+1;
        }
    }
    return k;
}


string max_element_num( double n[], double size ){ //макс элемент и его номер
    int k = 0, m = -100000;
    string s;
    for (int i = 0; i < size ; i++ ){
        if (n[i] > m){
            m = n[i];
            k = i+1;
        }
    }
    s = to_string(m) + " " + to_string(k);
    return s;
}


string bigger_el_num( double n[] , double s, double size){ //кол-во элементов и номера, которые больше заданного числа (s)
    int k = 0;
    string res, nums = "";
    for (int i = 0; i < size ; i++ ){
        if (n[i] > s){
            k ++;
            nums= nums + " " + to_string(i+1);
        }
    }
    res = to_string(k) + "; " + nums;
    return res;
}


double sum( double n[] ,double size){ // сумма всех элементов массива
    double k = 0;
    for (int i = 0; i < size ; i++ ){
            k += n[i];
        }
    
    return k;
}



double summa(double h,double s,double p){ //зп работника без вычета налогов
    double n;
    n = h * s * (1 + p / 100);
    return n;
}


int main(){
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    
    int size; // размер будущих массивов
    double hours, rate, prem;
    
    cout << "Введите кол-во работников: ";
    cin >> size ;

    double* salary = new double[size]; //массив с зп
    double* nalogi = new double[size]; //массив с налогами


    for (int i = 0; i < size; i++){
        cout << "для " << i+1 << " работника:" << endl;
        cout << "кол-во часов, ставка, премия: ";
        cin >> hours >> rate >> prem;

        double su = summa(hours,rate,prem);
        nalogi[i] = su * 0.13;
        salary[i] = su * 0.87;
    }


    cout << "номер работника, получившего меньше всех: " << min_element(salary, size) << endl;
    cout << "максимальная из зарплат и номер получившего ее работника: " << max_element_num(salary, size) << endl;
    cout << "количество работников, получивших на руки более 50000 руб и их номера: "<< bigger_el_num(salary, 50000, size) << endl;
    cout << "общая сумма налога, уплаченного всей бригадой: "<< sum(nalogi, size);
    delete[] salary;
    delete[] nalogi;

    return 0;
}