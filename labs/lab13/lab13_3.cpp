#include <iostream>
#include <string>
#include <Windows.h>
#include <algorithm>
using namespace std;

string replace_min(string& str){ //a
    int n = str.length();
    while (str.find("min") < n){
        int f = str.find("min");
        str.replace(str.begin()+ f, str.begin() + f + 3,"MAX");
    }

    return str;
}

string ku_ku(string& str_kuku){ //b
    int n = str_kuku.length();
    int k = 0;

    for (int i = 0; i < n; i++){
        if (str_kuku[i] != ' ') k+=1;
        else if (str_kuku[i] == ' '){
            if (k == 5) {
                str_kuku.replace((str_kuku.begin() + i - 5), (str_kuku.begin() + i), "ku-ku");
                k = 0;
            }
            k = 0;
        }
    
    }
    if (k == 5) str_kuku.replace(str_kuku.end() - 5, str_kuku.end(), "ku-ku");
    return str_kuku;

}

string kukareku(string& str_kukareku){ //c
    if (str_kukareku.find("ku-ku") > str_kukareku.length()){
        int n = str_kukareku.length();
        str_kukareku.replace(n/2, 11,"ku-ka-re-ku");
    }
    else{
        while (str_kukareku.find("ku-ku") < str_kukareku.length()){
            int f = str_kukareku.find("ku-ku");
            str_kukareku.replace(str_kukareku.begin()+ f, str_kukareku.begin() + f + 3,"ku-ka-re-ku");
        }
    }
    return str_kukareku;
}

string without_kuku(string& no_kuku){ //d
    while(no_kuku.find("ku-ku") < no_kuku.length()){
        no_kuku.erase(no_kuku.find("ku-ku"));
    }
    return no_kuku;
}

int words(string& str) { //e
    int wordCount = 0;
    bool inWord = false;

    for (char ch : str) {
        if (isalnum(ch)) {  // буква или цифра
            if (!inWord) {
                inWord = true;
                wordCount++;
            }
        } else {
            inWord = false;  // разделитель (пробел, пунктуация и т.п.)
        }
    }

    return wordCount;
}

bool balance(const string& str) { //g
    int balance = 0;

    for (char ch : str) {
        if (ch == '(') {
            balance++;
        } else if (ch == ')') {
            balance--;
            if (balance < 0) {
                return false;  // закрывающая скобка без открывающей
            }
        }
    }

    return balance == 0;  // все открывающие скобки закрыты
}

string without_brackets(const string& str) { //h
    string result;
    int depth = 0;  

    for (char ch : str) {
        if (ch == '(') {
            depth++;
        } else if (ch == ')') {
            if (depth > 0) {
                depth--;  
            }
            
        } else {
            if (depth == 0) {  
                result += ch;
            }
            
        }
    }

    return result;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    
    string str  = "minmax 55555 minmax 55555"; //65-90 - A-Z, 122- z, цифры - 48-57
    string str_kuku = str;
    int n = str.length();
 
    cout << replace_min(str);
    cout << ku_ku(str_kuku);

    string str_kukareku = str_kuku;
    string no_kuku = str_kuku;
    cout <<kukareku(str_kukareku);
    cout <<without_kuku(no_kuku);
    cout <<words(str);
    cout <<balance(str);
    cout <<without_brackets(str);


    return 0;
}

