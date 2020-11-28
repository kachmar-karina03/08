// Дано літерний рядок, який містить послідовність символів
// s[0], ... , s[n], ...
// Підрахувати найбільшу кількість цифр, які розташовані поспіль.

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <set>

using namespace std;
string FindLongestSubquence(string seq)
{
    int maxLen(0);
    int maxStart(0);
    int start(0);
    int len(0);

    for (int i = 0; i < seq.size(); ++i) 
    {
        set<char> s;
        int j;
        for (j=i; j >= 0 && s.size() <=3; j--)
        {
            s.insert(seq[j]);
        }

        start = (s.size()>3) ? j+2:0;
        len = i-start+1;
        maxLen = max(maxLen, len);

        if (len == maxLen) 
        {
            maxStart = start;
        }
    }

    cout << "Length of max continuous subarray : " << maxLen << endl;
   
    return seq.substr(maxStart, maxLen);

}

void DoTest(string str)
{
    cout << "Input : " << str << endl;
    FindLongestSubquence(str);
    cout << "------------------------" << endl;
}

int UnitTest(int* a, const int size)
{
    int S = 0;
    for (int i = 0; i < size; i++)
        S += a[i];
    return S;
}

int main()
{
    string str;
    cout << "Enter string:" << endl;
    getline(cin, str);
    cout << "What you actually entered : " << FindLongestSubquence(str) << endl;
    return 0;
}