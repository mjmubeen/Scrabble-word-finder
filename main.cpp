#include <iostream>
#include <fstream>
using namespace std;

int length(char arr[]);
void read(char name[], int size);
int compare(char name[], char arr[]);
int * regrow(char arr[]);
void swap(char a[], int i, int j);
void shuffle(char a[], int size);

int main()
{
	char name[100]; int size, no;
	cout << "Enter a word:";
	cin >> name;
	size = length(name);
	cout << "If you want to UnScramble the word press 1 or Scramble it then press 2:";
	cin >> no;
	if (no == 1)
	{
		while (size > 0)
		{
			cout << "By UnScramble the word " << name << " of size:" << endl;
			read(name, size);
			size--;
		}
	}
	else if (no == 2)
	{
		shuffle(name, size);
	}
}

int length(char arr[])
{
	int i;
	for (i = 0; arr[i] != '\0'; i++);
	return i;
}

void read(char name[], int s)
{
	ifstream fin("dictionary.txt");
	int s1; char arr[100];
	int a, b;
	cout << s << " length" << endl;
	for (int i = 0; !fin.eof(); i++)
	{
		fin >> arr;
		s1 = length(arr);
		if (s == s1)
		{
			a = compare(name, arr);
			if (a == s1)
			{
				cout << arr << " ";
			}
		}
	}
	cout << endl << "-------------------------------------------------------------------" << endl;
}

int compare(char name[], char arr[])
{
	int x = 0;
	int *check = regrow(arr);
	for (int i = 0; name[i] != '\0'; i++)
	{
		for (int j = 0; arr[j] != '\0'; j++)
		{
			if (check[j] == 1 && name[i] == arr[j])
			{
				check[j] = 0;
				x++;
				break;
			}
		}
	}
	return x;
}

int * regrow(char arr[])
{
	int * temp = new int[length(arr)];
	for (int i = 0; arr[i] != '\0'; i++)
	{
		temp[i] = 1;
	}
	return temp;
}

void swap(char a[], int i, int j)
{
	char temp = a[i];
	a[i] = a[j];
	a[j] = temp;
}

void shuffle(char a[], int s)
{
	cout << "By Scrambling the word " << a << " we get:" << endl;
	for (int i = 0; i < s; i++)
	{
		for (int j = 0; j < s - 1; j++)
		{
			swap(a, j, j + 1);
			cout << a << " ";
		}
	}
	cout << endl;
}
