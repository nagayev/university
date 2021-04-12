/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

int main()
{
    int start,end,symbols;
    vector <int> v;
    char s[25];
    start = 0;
    end = 0;
    symbols = 0;
    cout<<"Введите текст: ";
    fgets(s,sizeof(s),stdin);
    int curr = 0;
    float max = 0.0f;
    for(int i=0;i<strlen(s);i++){
        char c = s[i];
        if (c=='a' || c=='e' || c=='i' || c=='o' || c=='u' || c=='y'){
            curr++;
        }
        if(isspace(s[i])){
            symbols--;
            if (curr>=max && curr!=0){
                v.push_back(start);
                v.push_back(end);
            }
        
            curr = 0;
            start = end+1;
        }
        symbols++;
        end++;
    }
    if (v.size()==0){
        cout<<"Некорректные данные"<<endl;
    } else {
        cout<<"Слово (слова): ";
        for(int i=0;i<v.size();i++){
            for(int j=v[i];j<v[i+1];j++){
                cout<<s[j];
            }
            cout<<" ";
        }
        cout<<endl;
    }
    return 0;
}
