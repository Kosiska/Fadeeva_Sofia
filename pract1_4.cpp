#include <iostream>
using namespace std;


void vvod(double& h, double& s, double& p){
    cout << "¬ведите часы работы, ставку и премию работника: ";
    cin >> h >> s >> p;
}

void f(double h, double s, double p, double& salary, double& nalog, double& total){

    salary = h * s * (1 + p / 100);
    nalog = salary * 0.13;
    total = salary - nalog;

}

int main(){
    setlocale(0, "");
    double h, s, p, nalog, salary, total;
    vvod(h, s,p);
    f(h, s, p, salary, nalog, total);
    cout << "ќбща€ сумма, сумма налога и зп на руки: ";
    cout << salary << " " << nalog << " " << total;

    return 0;
}
