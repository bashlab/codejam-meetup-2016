// 483 - Word Scramble
#include <stdio.h>
#include <vector>
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

string reverse(string);
/*
int main()
{
    string line_str, word;
    while(getline(cin, line_str)) 
    {
        stringstream ss(line_str);
        while(getline(ss, word, ' '))
        {
            cout << reverse(word) << ' ';
        }        
        cout << endl;
    }
}


// The above solution gets a PE
*/

int main()
{
    string word = "", res = "", sentence;

    while(getline(cin, sentence))
    {
        for(int i=0; i<sentence.length(); ++i)
        {
            if(sentence[i] == ' ')
            {
                cout << reverse(word) + ' ';
                word = ""; // reset the word
            }
            else 
            {
                word += sentence[i];
                if(i==sentence.length()-1)
                {
                    cout << reverse(word);
                    word = "";
                }
            }
        }        
        cout << endl;
    }
}

string reverse(string w)
{
    string res = "";
    for(int i=w.length()-1; i>=0; --i)
    {
        res += w[i];
    }
    return res;
}
