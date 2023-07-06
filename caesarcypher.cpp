#include<iostream>
#include<string.h>
using namespace std;
void main()
{	string encdec, msg, encdecmsg;
	int shiftno;
	cout << "Type encode to encrypt and decode to decrypt:";
	cin >> encdec;
	cout << "Type the message:";
	cin >> msg;
	cout << "Enter the number of shifts:";
	cin >> shiftno;
	if(encdec == "encode")
		for (char& i:msg)
			if (i == 'z')
			{
				i = 'a';
				i = i + shiftno - 1;
			}
			else
				i+=shiftno;
	else
		for (char& i : msg)
			if (i == 'a')
			{
				i = 'z';
				i = i - shiftno + 1;
			}
			else
				i-=shiftno;
	cout << "The " << encdec << "d message is " << msg;
}
