#include <iostream>
#include <Windows.h>
#include <format>
using namespace std;


double f(double h,double s){
    double salary;
    salary = h * s*0.87;
    return salary;
}


int main(){
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    double sum = 0;
    for (int i=0; i < 5;i++){
        double h,s;
        cout << "Введите кол-во отработанных часов и почасовую ставку работника номер " << i+1;
        cin >> h >> s;
        sum += f(h, s);
        cout << "Рабочий номер " << i+1 << " заработал " << f(h,s);
    }
    
    cout << "зредняя зп в бригаде: " << sum/5;

    return 0;
}
