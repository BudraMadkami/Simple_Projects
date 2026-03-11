#include <iostream>
using namespace std;

// 1. Show address of each character
void showAddress(char str[])
{
    int i = 0;
    while(str[i] != '\0')
    {
        cout << str[i] << " -> " << (void*)&str[i] << endl;
        i++;
    }
}

// 2. Concatenate two strings
void concatenate(char s1[], char s2[])
{
    int i = 0, j = 0;

    while(s1[i] != '\0')
        i++;

    while(s2[j] != '\0')
    {
        s1[i] = s2[j];
        i++;
        j++;
    }

    s1[i] = '\0';

    cout << "Concatenated String: " << s1 << endl;
}

// 3. Compare two strings
void compare(char s1[], char s2[])
{
    int i = 0;

    while(s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
        i++;

    if(s1[i] == s2[i])
        cout << "Strings are Equal\n";
    else if(s1[i] > s2[i])
        cout << "First String is Greater\n";
    else
        cout << "Second String is Greater\n";
}

// 4. Length using pointer
int length(char *str)
{
    int count = 0;

    while(*str != '\0')
    {
        count++;
        str++;
    }

    return count;
}

// 5. Convert lowercase to uppercase
void toUpper(char str[])
{
    int i = 0;

    while(str[i] != '\0')
    {
        if(str[i] >= 'a' && str[i] <= 'z')
            str[i] = str[i] - 32;

        i++;
    }

    cout << "Uppercase String: " << str << endl;
}

// 6. Reverse string
void reverseString(char str[])
{
    int i = 0;
    char temp;

    while(str[i] != '\0')
        i++;

    int j = i - 1;
    i = 0;

    while(i < j)
    {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        i++;
        j--;
    }

    cout << "Reversed String: " << str << endl;
}

// 7. Insert string at position
void insertString(char mainStr[], char subStr[], int pos)
{
    char result[200];
    int i = 0, j = 0, k = 0;

    while(mainStr[i] != '\0')
    {
        if(i == pos)
        {
            while(subStr[j] != '\0')
                result[k++] = subStr[j++];
        }

        result[k++] = mainStr[i++];
    }

    result[k] = '\0';

    cout << "String after insertion: " << result << endl;
}

int main()
{
    char str1[100], str2[100];
    int choice, pos;

    cout << "Enter first string: ";
    cin >> str1;

    cout << "Enter second string: ";
    cin >> str2;

    do
    {
        cout << "\n------ MENU ------\n";
        cout << "1. Show address of each character\n";
        cout << "2. Concatenate two strings\n";
        cout << "3. Compare two strings\n";
        cout << "4. Calculate length of string\n";
        cout << "5. Convert lowercase to uppercase\n";
        cout << "6. Reverse the string\n";
        cout << "7. Insert string at position\n";
        cout << "8. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                showAddress(str1);
                break;

            case 2:
                concatenate(str1, str2);
                break;

            case 3:
                compare(str1, str2);
                break;

            case 4:
                cout << "Length of string: " << length(str1) << endl;
                break;

            case 5:
                toUpper(str1);
                break;

            case 6:
                reverseString(str1);
                break;

            case 7:
                cout << "Enter position: ";
                cin >> pos;
                insertString(str1, str2, pos);
                break;

            case 8:
                cout << "Program Exiting...\n";
                break;

            default:
                cout << "Invalid Choice\n";
        }

    } while(choice != 8);

    return 0;
}
