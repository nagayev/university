#include "stdafx.h"
#include <iostream>
#include <string>
#include <time.h>
#include <conio.h>
#include <Windows.h>

using namespace std;

int main()
{
	SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    string n_s,a_s,b_s;
    int a,b,n;
    srand(time(0));
	cout<<"Введите размер матрицы: ";
    getline(cin, n_s);
    n = atoi(n_s.c_str());
    cout<<"Введите нижнюю границу: ";
    getline(cin, a_s);
    a = atoi(a_s.c_str());
    cout<<"Введите верхнюю границу: ";
    getline(cin, b_s);
    b = atoi(b_s.c_str());
    while(!((n!=0 && n_s[0]!='0') || (a!=0 && a_s[0]!='0') || (b!=0 && b_s[0]!=0))){
       cout<<"Введите размер матрицы: ";
       getline(cin, n_s);
       n = atoi(n_s.c_str());
       cout<<"Введите нижнюю границу: ";
       getline(cin, a_s);
       a = atoi(a_s.c_str());
       cout<<"Введите верхнюю границу: ";
       getline(cin, b_s);
       b = atoi(b_s.c_str());
    }
    int **arr=new int*[n];
	for(int i=0;i<n;i++) arr[i]=new int[n];
    cout<<"Матрица: "<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if (i+j==n-1) arr[i][j]=0;
            else arr[i][j]=rand()%(a-b+1)+a;
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    for(int i=0;i<n;i++){
        swap(arr[i][i],arr[i][n-i-1]);
    } 
    cout<<"Исходная матрица: "<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++) cout<<arr[i][j]<<" ";
        cout<<endl;
    }
	_getch();
}
