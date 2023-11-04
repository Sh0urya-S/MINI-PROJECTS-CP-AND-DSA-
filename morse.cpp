#include <iostream>
#include <unordered_map>
#include <string>
#include <string.h>
#include<cstdlib>
#include<vector>
#include<Windows.h>
#include<conio.h>
using namespace std;

unordered_map<char, string> m;
unordered_map<string, char> n;

void initmorse()
{
    m['a'] = ".-";
    m['b'] = "-...";
    m['c'] = "-.-.";
    m['d'] = "-..";
    m['e'] = ".";
    m['f'] = "..-.";
    m['g'] = "--.";
    m['h'] = "....";
    m['i'] = "..";
    m['j'] = ".---";
    m['k'] = "-.-";
    m['l'] = ".-..";
    m['m'] = "--";
    m['n'] = "-.";
    m['o'] = "---";
    m['p'] = ".--.";
    m['q'] = "--.-";
    m['r'] = ".-.";
    m['s'] = "...";
    m['t'] = "-";
    m['u'] = "..-";
    m['v'] = "...-";
    m['w'] = ".--";
    m['x'] = "-..-";
    m['y'] = "-.--";
    m['z'] = "--..";

    n[".a"] = 'a';
    n["-..."] = 'b';
    n["-.-."] = 'c';
    n["-.."] = 'd';
    n["."] = 'e';
    n["..-."] = 'f';
    n["--."] = 'g';
    n["...."] = 'h';
    n[".."] = 'i';
    n[".---"] = 'j';
    n["-.-"] = 'k';
    n[".-.."] = 'l';
    n["--"] = 'm';
    n["-."] = 'n';
    n["---"] = 'o';
    n[".--."] = 'p';
    n["--.-"] = 'q';
    n[".-."] = 'r';
    n["..."] = 's';
    n["-"] = 't';
    n["..-"] = 'u';
    n["...-"] = 'v';
    n[".--"] = 'w';
    n["-..-"] = 'x';
    n["-.--"] = 'y';
    n["--.."] = 'z';
}
void loadingscreen()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j <=2; j++)
        {
            cout << "Loading";
            for (int k = 0; k<=j ; k++)
                cout << ".";
            Sleep(250);
            system("cls");
        }
    }
}
void texttomorse(const string& a)
{
    string t;
    for (char letter : a)
    {
        t = m[tolower(letter)];
        for (char symb : t)
        {
            cout << symb;
            if (symb == '.')
                cout << "\a";
            else
                cout << "\a\a\a";
            Sleep(1000);
        }
        cout << " ";
    }
    cout << endl;
}
void morsetotext(const string& p)
{
    string word;
    string result;
    for (char c : p) {
        if (c == ' ' && word == "") {
            result += " ";
        }
        else if (c == ' ' && word != "") {
            result += n[word];
            word = "";
        }
        else {
            word += c;
        }
    }
    if (!word.empty()) {
        result += n[word];
    }
    cout << result;
}
int main()
{
    loadingscreen();
    initmorse();
    int choice;
    while (1)
    {
        cout << " _      ____  ____  ____  _____   ____  ____  ____  _____" << endl
            << "/ \\__/|/  _ \\/  __\\/ ___\\/  __/  /   _\\/  _ \\/  _ \\/  __/" << endl
            << "| |\\/||| / \\||  \\/||    \\|  \\    |  /  | / \\|| | \\||  \\  " << endl
            << "| |  ||| \\_/||    /\\___ ||  /_   |  \\_ | \\_/|| |_/||  /_ " << endl
            << "\\_/  \\|\\____/\\_/\\_\\\\____/\\____\\  \\____/\\____/\\____/\\____\\ \n\n";
        cout << "MENU\n\n";
        cout << "Type 1 to convert Text to Morse Code\n\n";
        cout << "Type 2 to convert Morse Code to Text\n\n";
        cout << "Type 3 to exit\n\n\n";
        cout << "Enter your choice:";
        cin >> choice;
        string answer, temp;
        switch (choice)
        {
        case 1: cout << "\n\nEnter the text you want to convert:";
            cin >> answer;
            cout << "\n";
            texttomorse(answer);
            _getch();
            system("cls");
            break;
        case 2: cout << "\n\nEnter the morse code with space for letter:";
            cin >> answer;
            cout << "\n";
            morsetotext(answer);
            _getch();
            system("cls");
            break;
        case 3: exit(0);
        }
    }
    return 0;
}
