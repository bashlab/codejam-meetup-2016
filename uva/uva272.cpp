// 272 - TEX Quotes
#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

int main()
{
    string sentence, output; 
    int p = 0;
    while(getline(cin, sentence))
    {
        output = "";
        for(int i=0; i<sentence.length(); ++i)
        {
            if(sentence[i] == '"')
            {
                output += p % 2 == 0 ? "``" : "''";
                ++p;
            } 
            else 
            {
                output += sentence[i];
            }
        }
        printf("%s\n", output.c_str());
    }
}
