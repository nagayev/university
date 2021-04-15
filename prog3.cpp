#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <conio.h>
#include <Windows.h>
using namespace std;

int main()
{
	SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    vector<string> v;
    string s, tmp;
    float max = 0.0f;
    int symbols, all_symbols;
    symbols = 0;
    all_symbols = 0;
	cout<<"Введите текст: ";
	getline(cin, s);
    for (int i = 0; i < s.size(); i++)
    {
        if (isspace(s[i]) || s[i]=='.')
        {
            v.push_back(tmp);
            tmp = "";
        }
        else
        {
            tmp.push_back(s[i]);
        }
    }
    if (tmp != "")
    {
        v.push_back(tmp);
    }

    //Now we have vector with words
    //find max
    for (int i = 0; i < v.size(); i++)
    {
        all_symbols = v[i].size();
        symbols = 0;
        for (int j = 0; j < all_symbols; j++)
        {
            char c = tolower(v[i][j]);
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y')
            {
                symbols++;
            }
        }
        if (symbols*1.0 / all_symbols > max)
            max = 1.0*symbols / all_symbols;
    }
    //find words max
	cout<<"Искомое слово (слова): ";
    for (int i = 0; i < v.size(); i++)
    {
        all_symbols = v[i].size();
        symbols = 0;
        for (int j = 0; j < v[i].size(); j++)
        {
            char c = tolower(v[i][j]);
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y')
            {
                symbols++;
            }
        }
        if (symbols*1.0 / all_symbols == max && max!=0)
            cout << v[i]<<" ";
    }
	if(max==0) cout<<"Некорректные данные";
	cout << endl;
	_getch();
    return 0;
}
