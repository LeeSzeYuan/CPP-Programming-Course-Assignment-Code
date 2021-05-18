//LEE SZE YUAN A19EC0068 991029-02-5069 SEC 02 30/11/2019
//LOH YEW CHONG A19EC0076 000722-02-0135 SEC 02 30/11/2019

#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

ifstream inp;
ofstream out ("output3.txt");

void readFile(double [], int &);
void computeC(double [],double [],int);
double average(double [],int);
char grade(double);
void writeFile (double [],double [],int);

int main()
{
	int num=0, R=50, numH=0, numM=0, numL=0;
	double F[R];
	double C[R];
	
	readFile(F,num);
	R=num;
	
	computeC(F, C, num);
	
	writeFile (F,C,num);
	
	cout << fixed << setprecision(2);
	
	for (int i=0; i<num; i++)
	{
		if (C[i]>=35)
        numH++;
        else if (C[i]>=20)
    	numM++;
        else
    	numL++;
	}
	
	cout << "Average of the temperature: " << average(C, num) << endl;
	cout << "Number of high temperature: " << numH << endl;
	cout << "Number of medium temperature: " << numM << endl;
	cout << "Number of low temperature: " << numL << endl;
	
	inp.close();
	out.close();
	return 0;
}

void readFile(double F[], int &num)
{
	num=0;
	double n1;
	int i=0;
	
	inp.open("input3.txt");
	
	if(!inp.is_open())
	{
		cout << "Error!!" << endl;
		exit(0);
	}
	
	while (inp >> n1)
	{
		num++;
		F[i]=n1;
		i++;
	}
}

void computeC(double F[],double C[],int num)
{
	for (int i=0; i<num; i++)
	{
		C[i]=(5.0/9.0)*(F[i]-32.0);
	}	
}

double average(double C[], int num)
{
	double sum=0;
	double avg=0;
	
	for (int i=0; i<num; i++)
	{
		sum+=C[i];
	}
	
	avg=sum/num;
	
	return avg;
}

char grade(double C)
{
	char Gra;
	
    if (C>=35)
    Gra='H';
    else if (C>=20)
    Gra='M';
    else
    Gra='L';
    	
	return Gra;
}

void writeFile (double F[],double C[],int num)
{
	out << fixed << setprecision(2);
	out << "C(Celcius)" << setw(19) << "F (Farenheit)" << setw(17) <<  "Description" << endl;
	out << "==========" << setw(15) << "=========" << setw(18) <<  "=====" << endl;
	
	for (int i=0; i<num; i++)
	{
		out << right << setw(7) << C[i] <<  setw(17) << F[i] <<  setw(17) << grade(C[i]) << endl;
	}
}



