#include <iostream>
#include <string>
#include <Windows.h>
#include <algorithm>

using namespace std;
int main()
{
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    
    string str ; //65-90 - A-Z, 122- z, цифры - 48-57
    cin >> str;
    cin.ignore();
    string str1 = str;
    
    char f = 'l';
    int count_s = 0, count_S = 0, count_numb = 0, count_big= 0;
    const int n = str.length();

  

    replace(str1.begin(), str1.end(), '1', '5');
    for (int i = 0; i < n; i++){
            if (str[i] == 's') count_s +=1; //s
            if (str[i] == 'S') count_S +=1; //S
            if (int(str[i]) >= 65 && int(str[i]) <= 90 ) count_big +=1; //A-Z
            if (int(str[i]) >= 48 && int(str[i]) <= 57 ) count_numb +=1; //0-9
                else str1[i] = toupper(str1[i]); // from a to A
    }
    
    const char* cstr = str1.c_str();
    printf("исходная строка:%s\nкол-во s: %d\nкол-во S:%d\nкол-во заглавных букв:%d\nкол-во цифр:%d\nновая строка = %s", str.c_str(), count_s, count_S, count_big, count_numb, cstr);

    return 0;
}

