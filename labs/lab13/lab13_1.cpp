#include <iostream>
#include <string>
using namespace std;
 



int main()
{
    char string[] = "this is string - "; // объ€вление и инициализаци€ строки
    cout << "Enter the string: ";
    char in_string[500]; // строковый массив дл€ ввода
    fgets(in_string, 501, stdin); // функци€ gets() считывает все введЄнные символы с пробелами до тех пор, пока не будет нажата клавиша Enter
    cout << string << in_string << endl; // вывод строкового значени€

    strchr('H');
    return 0;
}