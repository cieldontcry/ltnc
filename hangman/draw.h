#ifndef _DRAW__H
#define _DRAW__H

#include<iostream>

using namespace std;

void draw(int a){

    cout <<"-------------"<<'\n';
    cout <<"|           |"<<'\n';
    if (a>=2) cout << "|           o"<<'\n';
    else cout << "|" <<'\n';
    if (a==3) cout << "|           |"<<'\n';
    else if (a==4) cout << "|          /|"<<'\n';
    else if (a>=5) cout << "|          /|\\"<<'\n';
    else cout <<"|            "<<'\n';
    if (a>=6) cout << "|          / ";
    else cout << "|"<<'\n';
    if (a==7) cout << "\\"<<'\n';

}

#endif // _DRAW__H
