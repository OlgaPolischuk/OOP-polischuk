#include <iostream>
#include <fstream>
using namespace std;
ofstream f("output.txt");//открытие файла на запись

double determMatrix(double **pM, int n, int deep = 0)
{  
    if(n == 2)
	{
        return pM[0][0 + deep] * pM[1][1 + deep] - pM[0][1 + deep] * pM[1][0 + deep];
	}
     
    double znak = 1;//переменная определяющая знак алгебраического дополнения Aij
				
    double sum_det = 0;
     
    for(int i = 0; i < n; i++)
    {  
        double **pI = new double *[n - 1];//создание нового масива указатей
									//указывающих только на столбцы минора(верхние ненужные строки(ка)
									//отсекаются за cщет переменной deep(глубина рекурсии))
									//создание очередного минора
        int p = 0;   
        for(int ii = 0; ii < n; ii++)
        {
            if(ii == i)
			{
				continue;
			}
             
            pI[p] = pM[ii];
            p++;
        }
         
        sum_det += znak * pM[i][deep] * determMatrix(pI, (n - 1), (deep + 1));
        //указывает первую строку с которой начинаетcя данный минор
         
        delete [] pI;
        znak *= -1;
         
    }
    return sum_det;
}

double search_a( int n, double **A, int i)
{
	for(int j = 0; j < n; j++)
	{
	
		int search;
		if ( A[j][i] != 0 )
		{
			search = j;

			for(int k = 0; k < n; k++)
			{
				swap(A[i][k], A[search][k]);
			}
					
			break;
		}
	}
			
	return A[i][i];		
}

void print(int n, double **A)
{
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			cout << A[i][j] << "   " ;
		}
		cout << endl;
	}
}

void multiplication(int n, double **A_obr, double *B)
{
	double *c = new double[n];
	for (int i = 0; i < n; i++)
	{double sum = 0;
		
			for (int j = 0; j < n; j++)
			{
				sum += B[j] *A_obr[i][j] ;
			}
			c[i] = sum;
		
	}

	cout << "Решение СЛУ : " << endl;
	f << "Решение СЛУ : " << endl;
	for (int i = 0; i < n; i++)
	{
		cout << "X[" << i + 1 << "]= " << c[i] << "\t" << "\n";
		f << "X[" << i + 1 << "]= " << c[i] << "\t" << "\n";
	}
}

int gaus(int n, double **A, double **A_obr, double *B)
{
	int i, j, k;

	if (determMatrix(A, n) == 0)
	{
		cout << "Решение СЛУ не может быть получено, матрица коэффициентов не совместна." << endl;
		return 0;
	}

	//создание единичной матрицы
	for(i = 0; i < n; i++)
	{
		A_obr[i] = new double [n];

		for(j = 0; j < n; j++)
		{
			A_obr[i][j] = 0;
		}

		A_obr[i][i] = 1;
	}

	//прямой ход методом Гаусса
	double a, b;
	for(i = 0; i < n; i++)
	{
		a = A[i][i];
		if (a == 0)
		{
			a = search_a(n, A, i);
		}
		
		for(j = i + 1; j < n; j++)
		{
			b = A[j][i];

			for(k = 0; k < n; k++)
			{
				A[j][k] = A[i][k] * b - A[j][k] * a;
				A_obr[j][k] = A_obr[i][k] * b - A_obr[j][k] * a;
			}
		}
		
	}	
			
	//обратный ход вычисления элементов обратной матрицы
	double sum;
	for(i = 0; i < n; i++)
	{
		for(j = n - 1; j >= 0; j--)
		{
			sum = 0;
			for(k = n - 1; k > j; k--)
			{
				sum += A[j][k] * A_obr[k][i];
			}

			A_obr[j][i] = (A_obr[j][i] - sum) / A[j][j];
		}
	}

	//решение системы!!!
	cout << endl;
	cout << "обратная матрица к данной: " << endl;
	print(n, A_obr);
	multiplication(n, A_obr, B);	
	cout << endl;

	delete []A_obr;
} 

int main()
{
    setlocale(LC_ALL,"Russian");
    int n;

    ifstream file("input.txt");
    file >> n;

    double **A = new double*[n];
	double **A_obr = new double*[n];
	

	for (int i = 0; i < n; i++)
	{
        A[i] = new double [n]; 
		A_obr[i] = new double [n]; 
	}

	int ind1 = 0;
	while (!file.eof())
	{
		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < n; j++)
			{
				file >> A[i][j];
			}
		}
	}

    double *B = new double[n];

	int ind = 0;
	while (!file.eof())
	{		
		for(int i = 0; i < n; i++)
		{
			file >> B[i];
			ind++;
		}
	}
	
	if ((ind != n - 1) || (ind1 != 2 * (n - 1)))
	{
		cout << "Проверьте считываемые данные!" << endl;
		return 0;
	}

	cout << "Система имеет вид: " << endl;          
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
			cout << A[i][j] << "   " ;
        }
        cout<< " |    " << B[i] << endl;
    }

	gaus(n, A, A_obr, B);

	delete []A;
	f.close();
	file.close();
	cin >> n;
	return 0;
}
