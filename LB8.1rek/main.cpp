#include <iostream>
#include <cstring>

using namespace std;

bool findStr(char* str, int i)
{
    if (str[i] == 'a' && str[i + 1] == 'a' ||
        str[i] == 'b' && str[i + 1] == 'b' ||
        str[i] == 'c' && str[i + 1] == 'c')
        return true;
    else if (i < strlen(str) - 2)
        return findStr(str, ++i);
    else
        return false;
}

char* Change(char* dest, const char* str, int i, int destIndex)
{
    if (str[i] != 0)
    {
        if (str[i] == 'a' && str[i + 1] == 'a' ||
            str[i] == 'b' && str[i + 1] == 'b' ||
            str[i] == 'c' && str[i + 1] == 'c')
        {

            strcat_s(dest, 150 - destIndex, "***");
            return Change(dest, str, i + 2, destIndex + 3);

        }
        else
        {
            dest[destIndex] = str[i];
            dest[destIndex + 1] = '\0';
            return Change(dest, str, i + 1, destIndex + 1);
        }
    }
    else
    {
        return dest;
    }
}

int main()
{
    char str[101];
    cout << "Enter string:" << endl;
    cin.getline(str, 100);

    char* dest1 = new char[151];
    dest1[0] = '\0';

    char* dest2 = Change(dest1, str, 0, 0);

    findStr(str, 0) ? cout << "'aa or bb or cc' found and will be changed" << endl : cout << "'aa and bb and cc' not found" << endl;

    cout << "Modified string (param) : " << str << endl;
    cout << "Modified string (result): " << dest2 << endl;

    delete[] dest1;
    return 0;
}
