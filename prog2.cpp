#include <iostream>
#include <string>
#include <time.h>

using namespace std;

int main()
{
    bool running = true;
    string n_s,a_s,b_s;
    int a,b,n;
    srand(time(0));
    while(running){
       cout<<"Введите размер матрицы: ";
       getline(cin, n_s);
       n = atoi(n_s.c_str());
       cout<<"Введите нижнюю границу: ";
       getline(cin, a_s);
       a = atoi(a_s.c_str());
       cout<<"Введите верхнюю границу: ";
       getline(cin, b_s);
       b = atoi(b_s.c_str());
       //correct
       if ( !(n!=0 && n_s[0]!='0') || (a!=0 && a_s[0]!='0') || (b!=0 && b_s[0]!=0) ) break;
    }
    int arr[n][n];
    cout<<"Матрица: "<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if (i+j==n-1) arr[i][j]=0;
            else arr[i][j]=random()%(a-b+1)+a;
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
}
