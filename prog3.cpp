#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    vector<string> v;
    string s, tmp;
    getline(cin, s);
    int words = 0;
    float max = 0.0f;
    int symbols, all_symbols;
    symbols = 0;
    all_symbols = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (isspace(s[i]))
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
        if (symbols / all_symbols > max)
            max = symbols / all_symbols;
    }
    //find words max
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
        if (symbols / all_symbols == max)
            cout << v[i];
    }
    cout << endl;
    return 0;
}
