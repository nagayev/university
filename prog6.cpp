// Nagayev6.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <conio.h>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <cstdio>
using namespace std;

/*
Разработать программу, которая читает текстовой файл и некоторую букву и 
выводит слова файла, начинающиеся с этой буквы,
а также их количество. 
Имя читаемого файла и название буквы запрашиваются с клавиатуры.
*/
int _tmain(int argc, _TCHAR* argv[])
{
	vector<char> tmp;
	vector<vector<char>> words;
	FILE *f;
	int counter = 0;
	char filename[255];
	system("chcp 1251");
	system("cls");
	//..\\Debug\\a.txt
	while(1){
		cout<<"Введите название файла ";
		gets_s(filename,255);
		int err = fopen_s(&f,filename, "r");
		if(err!=0){
		  cout<<"Неправильное имя файла"<<endl;
		  cout<<"Попробуйте еще раз"<<endl;
		} else {
			break;
		}
	}
	cout<<"Введите букву:";
	char c;
	c=getchar();
	fseek(f, 0, SEEK_END);
	long fsize = ftell(f);
	fseek(f, 0, SEEK_SET);  /* same as rewind(f); */

	char *content = (char*) malloc(fsize + 1);
	fread(content, sizeof(char), fsize, f);
	fclose(f);
	content[fsize] = 0;
	int i,j;
	for(i=0;i<fsize;i++){
		char current = content[i];
		if(current==' '){
			words.push_back(tmp);
			tmp.clear();
		}
		else tmp.push_back(current);
	}
	cout<<"Слова: "<<endl;
	if(tmp.size()!=0) words.push_back(tmp);
	for(int i=0;i<words.size();i++){
		if(words[i][0]==c){
			for(int j=0;j<words[i].size();j++){
				cout<<words[i][j];
			}
			counter++;
			cout<<' ';
		}
	}
	if(counter==0){
		cout<<"Слов нет";
	} else {
		cout<<endl<<"Количество: "<<counter;
	}
	_getch();
	return 0;
}

