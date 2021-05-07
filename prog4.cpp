// Nagayev4.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <conio.h>
#include <string>
using namespace std;

float minl(float a[],int k,int size){
	if (k==size-1) return a[k];
	float c = a[k];
	float d = minl(a,k+1,size);
	if(c<d) return c;
	return d;
}
float min(float* a,int size){
	return minl(a,0,size);
}
int _tmain(int argc, _TCHAR* argv[])
{
	int n;
	system("chcp 1251");
	system("cls");
	cout<<"Введите количество элементов массива: ";
	cin>>n;
	cout<<"Введите сами элементы"<<endl;
	//int arr[] = {1,2,6,-1,0,5};
	int a = 1;
	int b = 5;
	float *x = new float[n];
	string s;
	float tmp;
	for(int i=0;i<n;i++){
		while(true){
			cin>>s;
      tmp=atoi(s.c_str());
			if(!(tmp==0 && s!="0")){
				x[i]=tmp;
				break;
			} else {
				cout<<"Некорректный ввод"<<endl;
				cout<<"Попробуйте еще раз"<<endl;
			}
		}
	} 
	cout<<endl;
	cout<<"Минимальный элемент: "<<min(x,n)<<endl;
	_getch();
	return 0;
}
