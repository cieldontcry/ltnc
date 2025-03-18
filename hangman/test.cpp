#include<iostream>
#include<iomanip>

using namespace std;

int main(){

    int a[10];
    a[0]=1;
    a[1]=2;
    a[2]=3;
    cout << *(&a+1);

    return 0;

}

