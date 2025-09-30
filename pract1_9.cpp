#include <iostream>
#include <Windows.h>
#include <string>
using namespace std;

int min_element( double n[] ){
    int k = 0, size = sizeof(n) / sizeof(n[0]), m = 100000000000;
    for (int i = 0; i < size ; i++ ){
        if (n[i] < m){
            m = n[i];
            k = i+1;
        }
    }
    return k;
}




int* max_element( double n[] ){
    int k = 0, size = sizeof(n) / sizeof(n[0]), m = -10000000;
    for (int i = 0; i < size ; i++ ){
        if (n[i] > m){
            m = n[i];
            k = i+1;
        }
    }
    int s[] = {k, m};
    return s;
}

int bigger( double n[] , double s){
    int k = 0, size = sizeof(n) / sizeof(n[0]);
    for (int i = 0; i < size ; i++ ){
        if (n[i] > s){
            k = i+1;
        }
    }
    return k;
}


double sum( double n[] , double s){
    double k = 0, size = sizeof(n) / sizeof(n[0]);
    for (int i = 0; i < size ; i++ ){
            k += n[i];
        }
    
    return k;
}


int main(){
    return 0;
}