// Nagayev5.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <conio.h>
#include <string>
#include <iostream>
#include <time.h>
#include <vector>
#include <iomanip>
#include <CoreWindow.h>
using namespace std;
/*
Разработать программу, которая удаляет в целочисленной матрице столбец с номером k.
Размеры матрицы и значение k вводятся пользователем с клавиатуры. 
Значения элементов матрицы формируются случайным образом в диапазоне [-99, 99], 
матрица хранится в памяти в виде динамического массива.
*/

int _tmain(int argc, _TCHAR* argv[])
{
	SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
	string x_s,y_s,k_s;
	int x,y,k,r;
	srand(time(NULL));
	bool running = true;
	while(running){
		cout<<"Введите размеры матрицы "<<endl;
		cout<<"Введите количество строк:";
		cin>>x_s;
		cout<<"Введите количество столбцов:";
		cin>>y_s;
		cout<<"Введите k, номер столбца, который нужно удалить: ";
		cin>>k_s;
		x = atoi(x_s.c_str());
		y = atoi(y_s.c_str());
		k = atoi(k_s.c_str());
		if( (x==0 && x_s[0]!='0') || (y==0 && y_s[0]!='0') || (k==0 && k_s[0]!='0') ){
			cout<<"Некорректные данные"<<endl;
		}
		else running = false;
	}
	int** a;
	cout<<"Исходная матрица:"<<endl;
	a = new int *[x];
	for(int i=0;i<x;i++){
		a[i]=new int[y];
		for(int j=0;j<y;j++){
			r=rand()%100;
			r=rand()%2?r:-r;
			a[i][j]=r;
			cout<<setw(3)<<a[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
	cout<<"Итоговая матрица:"<<endl;
	for(int i=0;i<x;i++){
		for(int j=0;j<y-1;j++){
			if (j>=k-1)
				a[i][j]=a[i][j+1];
			cout<<setw(3)<<a[i][j]<<" ";
		}
		cout<<endl;
	}
	_getch();
	return 0;
}

