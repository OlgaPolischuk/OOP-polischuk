#include "stdafx.h"
#include <iostream>
#include <windows.h>
#include <assert.h>
#include <stdio.h>
#include <algorithm>

#include <string>
#include <cctype>
#include <fstream>
#include <math.h>
using namespace std;

void _tmain(int argc, _TCHAR* argv[])
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int n = 0;
	char ch;		
	ifstream fin("input.txt");
	int alf[33];
	
	for (int i = 0; i < 33; i++)
	{
		alf[i] = 0;
	}

	char alf1[33] = {'а','б','в','г','д','е','Є','ж','з','и','й','к','л','м','н','о','п','р','с','т','у','ф','х','ц','ч','ш','щ','ъ','ы','ь','э','ю','€'};
	if (!fin.is_open()) 
	{
        cout << "‘айл не может быть открыт!\n"; 
	}
    else
	{
		//65504 - a
		//65535 - €
		while (!fin.eof())
		{
			fin >> ch;

			if ((wchar_t)ch >= 65472 && (wchar_t)ch <= 65477) 
			{
				alf[(wchar_t)ch - 65472]++;
				n++;
			
			}
			if ((wchar_t)ch >= 65478 && (wchar_t)ch <= 65503) 
			{
				alf[(wchar_t)ch - 65471]++;
				n++;
			}

			if ((wchar_t)ch == 65448 || (wchar_t)ch == 65464) 
			{
				alf[6]++;
				n++;
			}

			if ((wchar_t)ch >= 65504 && (wchar_t)ch <= 65509) 
			{
				alf[(wchar_t)ch - 65504]++;
				n++;
			}

			if ((wchar_t)ch >= 65510 && (wchar_t)ch <= 65535) 
			{
				alf[(wchar_t)ch - 65503]++;
				n++;
			}	
		}
	}
	
	for (int i = 0; i < 33; i++)
	{
		cout << alf1[i] << " = " ;
		cout << ((double)(alf[i]) / n) * 100 << "%" << endl;		
	}

	fin.close();
	system("pause");
}


