// Lab_8_1.cpp
// < Качмар Каріни >
// Лабораторна робота 8.1
//Дано літерний рядок, який містить послідовність символів s0, ..., sn, ... .
//1. Вияснити, чи є серед цих символів пара сусідніх букв “no” або “on”.
//2. Замінити кожну пару сусідніх букв “no” трійкою зірочок “ ***”.


//Ітераційний спосіб


#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int Count(char* str)
{
    if (strlen(str)<3)
        return 0;

    int k = 0;
    for (int i=0; str[i+1] != 0; i++)
        if ((str[i] == 'n' && str[i+1] == 'o') || (str[i] == 'o' && str[i+1] == 'n'))
            k++;
    return k;
}

char* Change(char* str)
{
    if (strlen(str) < 3)
        return str;

    char* tmp = new char[strlen(str) * 4 / 3 + 1];
    char* t = tmp;

    tmp[0] = '\0';
    int i = 0;
    while (str[i+1] != 0)
    {
        if (str[i] == 'n' && str[i+1] == 'o')
        {
            strcat(t, "***");
            t += 3;
            i += 2;
        }
        else
        {
            *t++ = str[i++];
            *t = '\0';

        }
    }
    *t++ = str[i++];
    *t++ = str[i++];
    *t = '\0';

    strcpy(str, tmp);

    return tmp;

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
    char str[101];
    cout << "Enter string:" << endl;
    cin.getline(str, 100);

    cout << "String contained " << Count(str) << " groups of 'no on' " << endl;
     
    char* dest = new char[151];
    dest = Change(str);

    cout << "Modified string (param) : " << str << endl;
    cout << "Modified string (result): " << dest << endl;

    return 0;

}



/*
// Lab_8_1.cpp
// < Качмар Каріни >
// Лабораторна робота 8.1
//Дано літерний рядок, який містить послідовність символів s0, ..., sn, ... .
//1. Вияснити, чи є серед цих символів пара сусідніх букв “no” або “on”.
//2. Замінити кожну пару сусідніх букв “no” трійкою зірочок “ ***”.


//Рекурсивний спосіб

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
int Count(char* str, int i) 
{
    if (strlen(str)<3)
        return 0;
    if (str[i + 1] != 0)
        if ((str[i] == 'n' && str[i + 1] == 'o') || (str[i] == 'o' && str[i + 1] == 'n'))
            return 1 + Count(str, i + 1);
        else
            return     Count(str, i + 1);
    else
        return 0;
}

char* Change(char* dest, const char* str, char* t, int i)
{
    if (str[i+1] != 0)
    {
        if (str[i] == 'n' && str[i+1] == 'o') 
        {
            strcat(t, "***");

            return Change(dest, str, t+3, i+2);
        }
        else
        {
            *t++ = str[i++];
            *t = '\0';
            return Change(dest, str, t, i);
        }
    }
    else
    {
        *t++ = str[i++];
        *t++ = str[i++]; *t = '\0';
        return dest;
    }
}
int main()
{
    char str[101];
    cout << "Enter string:" << endl;
    cin.getline(str, 100);

    cout << "String contained " << Count(str, 0) << " groups of 'no on'" << endl;


    char* dest1 = new char[151]; dest1[0] = '\0';
    char* dest2;
    dest2 = Change(dest1, str, dest1, 0);
    cout << "Modified string (param) : " << dest1 << endl; cout << "Modified string (result): " << dest2 << endl;
    return 0;
}
*/



