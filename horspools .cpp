#include <iostream>
#include <cstring>
using namespace std;

int shiftTable[256];

// Create shift table
void shiftTableFunction(char pattern[])
{
    int m = strlen(pattern);

    for(int i = 0; i < 256; i++)
        shiftTable[i] = m;

    for(int j = 0; j < m - 1; j++)
        shiftTable[pattern[j]] = m - 1 - j;
}

// Horspool search
int horspool(char text[], char pattern[])
{
    int n = strlen(text);
    int m = strlen(pattern);

    shiftTableFunction(pattern);

    int i = m - 1;

    while(i < n)
    {
        int k = 0;

        while(k < m && pattern[m-1-k] == text[i-k])
            k++;

        if(k == m)
            return i - m + 1;

        else
            i += shiftTable[text[i]];
    }

    return -1;
}

int main()
{
    char text[100], pattern[100];

    cout<<"Enter Text: ";
    cin>>text;

    cout<<"Enter Pattern: ";
    cin>>pattern;

    int result = horspool(text, pattern);

    if(result >= 0)
        cout<<"Pattern found at position "<<result+1;
    else
        cout<<"Pattern not found";

    return 0;
}