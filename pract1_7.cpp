#include <iostream>
#include <Windows.h>
using namespace std;


double f(double h,double s){
    double salary;
    salary = h * s;
    return salary;
}


int main(){
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    double h1,s1,h2,s2,h3,s3,h4,s4,h5,s5;

    cout << "Введите кол-во отработанных часов и почасовую ставку 1 работника (через пробел): ";
    cin >> h1 >> s1;
    cout << "Введите кол-во отработанных часов и почасовую ставку 2 работника: ";
    cin >> h2 >> s2;
    cout << "Введите кол-во отработанных часов и почасовую ставку 3 работника: ";
    cin >> h3 >> s3;
    cout << "Введите кол-во отработанных часов и почасовую ставку 4 работника: ";
    cin >> h4 >> s4;
    cout << "Введите кол-во отработанных часов и почасовую ставку 5 работника: ";
    cin >> h5 >> s5;

    cout << "1 работник заработал: " << f(h1,s1) << endl;
    cout << "2 работник заработал: " << f(h2,s2) << endl;
    cout << "3 работник заработал: " << f(h3,s3) << endl;
    cout << "4 работник заработал: " << f(h4,s4) << endl;
    cout << "5 работник заработал: " << f(h5,s5) << endl;

    cout << "зредняя зп в бригаде: " << (f(h1,s1)+f(h2,s2)+f(h3,s3)+f(h4,s4)+f(h5,s5))/5;

    return 0;
}
