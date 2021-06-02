// Nagayev6.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <conio.h>
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

/*
Разработать программу, которая читает текстовой файл и некоторую букву и 
выводит слова файла, начинающиеся с этой буквы,
а также их количество. 
Имя читаемого файла и название буквы запрашиваются с клавиатуры.
*/
int _tmain()
{
	vector<string> words;
	int counter = 0;
	string filename;
	system("chcp 1251");
	system("cls");
	//..\\Debug\\a.txt
	ifstream f;
	while(!f.is_open()){
		cout<<"Введите название файла ";
		getline(cin,filename);
		f.open(filename);
		if(!f.is_open()){
		  cout<<"Неправильное имя файла"<<endl;
		  cout<<"Попробуйте еще раз"<<endl;
		}
	}
	char c;
	while(!isalpha(c)){
	    cout<<"Введите букву:";
	    cin>>c;
	    if (!isalpha(c)) cout<<"Введена не буква!"<<endl;
	}
    	string word;
	while (f >> word){
	    if (word[0]==c){
	        counter++;
	    } 
	    words.push_back(word);
	}
	f.close();
	if(counter==0){
		cout<<"Слов нет";
	} else {
		cout<<endl<<"Количество: "<<counter<<endl;
		cout<<"Слова: ";
	}
	for(int i=0;i<words.size();i++){
		if(words[i][0]==c){
			cout<<words[i];
			cout<<' ';
		}
	}
	_getch();
	return 0;
}

