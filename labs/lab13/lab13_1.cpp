#include <iostream>
#include <string>
#include <Windows.h>

using namespace std;
 
void full_name (string fn,string ln,string pt){
    cout << fn << " " << ln << " " << pt << " " << endl;
}

void fn_ln_pt (string fn,string ln,string pt){
    cout << fn[0] << ". " << ln[0] << ". " << pt[0] <<". " << endl;
}

void fname_ln_pt (string fn,string ln,string pt){
    cout << fn << " " << ln[0] << ". " << pt[0] << ". "<< endl;
}


int main()
{
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    
    string fname, lname, patronymic;

    cout << "¬ведите им€, фамилию и отчество через пробел: ";
    cin >> fname >> lname >> patronymic;
    cin.ignore();

    full_name(fname, lname, patronymic);
    fn_ln_pt(fname, lname, patronymic);
    fname_ln_pt(fname, lname, patronymic);


    return 0;
}