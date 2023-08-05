#include<bits/stdc++.h>
using namespace std;

string let()
{
    string alph = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    return string(1, alph[rand() % alph.length()]);
}

string numm()
{
    string numm = "0123456789";
    return string(1, numm[rand() % numm.length()]);
}

string symb()
{
    string symb = "!@#$%^&*()_+-=[]{}|;':,.<>?\"";
    return string(1, symb[rand() % symb.length()]);
}

string generate(int letno, int numno, int symno)
{
    string passgen;
    while (letno--)
        passgen += let();
    while (numno--)
        passgen += numm();
    while (symno--)
        passgen += symb();
    for (int i = 0; i < passgen.length(); ++i) {
        int j = rand() % passgen.length();
        swap(passgen[i], passgen[j]);
    }
    return passgen;
}

int main()
{
    while(1)
    {
      int letno, numno, symno;
      cout << "Welcome to the password generator\n";
      cout << "How many letters do you want in your password? ";
      cin >> letno;
      cout << "How many numbers do you want in your password? ";
      cin >> numno;
      cout << "How many symbols do you want in your password? ";
      cin >> symno;
      string password = generate(letno, numno, symno);
      cout << "This is your password as per your requirements:\n" << password << endl;
      }
    return 0;
}
