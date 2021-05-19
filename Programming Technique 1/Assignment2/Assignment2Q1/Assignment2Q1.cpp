#include <iostream>
#include <fstream>
#include <cstdlib>
#include <iomanip>
#define R 20
using namespace std;

void getInput(int [],int [],int [], string []);
int calTotal(int []);
int getLowest(int [], string [], string &);
int getHighest(int [], string [], string &);

ofstream out ("output.txt");

int main()
{
    int num1[R], num2[R], num3[R];
    
	int lowest1, lowest2, lowest3, highest1, highest2, highest3;
	
    int range1, range2, range3;
    int sum1, sum2, sum3;
    
	string name[R], lowestU1, lowestU2, lowestU3, highestU1, highestU2, highestU3;
	
	out << "\t\tNUMBER OF STUDENTS' INTAKE, ENROLMENT AND OUTPUT\n\t\t\t    IN PUBLIC UNIVERSITIES (2015)" << endl << endl;
	out << "---------------------------------------------------------------" << endl;
	out << "  UNIVERSITY" << setw(18) << "INTAKE" << setw(17) << "ENROLMENT"<< setw(13) << "OUTPUT" << endl;
	out << "---------------------------------------------------------------" << endl;
	getInput(num1,num2, num3, name);
	
	out << "---------------------------------------------------------------" << endl;
	
	sum1=calTotal(num1);
	sum2=calTotal(num2);
	sum3=calTotal(num3);
	out << "\t "<< left << setw(19) << "TOTAL" << right << setw(5)<<sum1 << setw(15) << sum2 << setw(15) << sum3 << endl;
	
	out << fixed <<setprecision(2);
	out << "\t "<< left << setw(15) <<"AVERAGE\t" << right <<  static_cast<double>(sum1)/20;
	out << setw(15) << static_cast<double>(sum2)/20 << setw(15) << static_cast<double>(sum3)/20 << endl;

	out << "---------------------------------------------------------------\n" << endl;
	
	lowest1=getLowest(num1,name,lowestU1);
	lowest2=getLowest(num2,name,lowestU2);
	lowest3=getLowest(num3,name,lowestU3);
	out << "THE LOWEST NUMBER OF STUDENTS' INTAKE    = " << lowest1 << " (" << lowestU1 << ")" << endl;
	out << "THE LOWEST NUMBER OF STUDENTS' ENROLMENT = " << lowest2 << " (" << lowestU2 << ")" << endl;
	out << "THE LOWEST NUMBER OF STUDENTS' OUTPUT    = " << lowest3 << " (" << lowestU3 << ")" << endl;
	
	out << endl;
	
	highest1=getHighest(num1, name, highestU1);
	highest2=getHighest(num2, name, highestU2);
	highest3=getHighest(num3, name, highestU3);	
	out << "THE HIGHEST NUMBER OF STUDENTS' INTAKE    = " << highest1 << " (" << highestU1 << ")" << endl;
	out << "THE HIGHEST NUMBER OF STUDENTS' ENROLMENT = " << highest2 << " (" << highestU2 << ")" << endl;
	out << "THE HIGHEST NUMBER OF STUDENTS' OUTPUT    = " << highest3 << " (" << highestU3 << ")" << endl;
	
	out << endl;

	range1=highest1-lowest1;
	range2=highest2-lowest2;
	range3=highest3-lowest3;
	out << "THE RANGE OF NUMBER OF STUDENTS' INTAKE    = " << range1 << endl;
	out << "THE RANGE OF NUMBER OF STUDENTS' ENROLMENT = " << range2 << endl;
	out << "THE RANGE OF NUMBER OF STUDENTS' OUTPUT    = " << range3 << endl;
	
	out << "\n---------------------------------------------------------------" << endl;
	
    out.close();
	return 0;
} 

void getInput(int num1[],int num2[],int num3[],string name[])//can make into 3 arrays
{
	char n1[10];
	int n2, n3, n4, i=0;

	ifstream inp;
	inp.open("input1.txt");
	
	if(!inp.is_open())
	{
		cout << "Error!!" << endl;
		exit(0);
	}
	
	while (inp>>n1)
	{
		
	    inp >> num1[i];
	    inp >> num2[i];
	    inp >> num3[i];
	    
		out << "\t " << left << setw(20) << n1;
		out << right << setw(5) << num1[i] << setw(15) << num2[i] << setw(15) << num3[i] << endl;
		
		name[i]=n1;

	    i++;
	}
	
	inp.close();	
}

int calTotal(int num[])
{
    int sum=0;

	for(int i=0;i<R;i++)
		sum+=num[i];
		
	return sum;
}

int getLowest(int num[], string name[], string &lowestU)//use refrence and return 1
{
	int lowest=99999;
	
	for(int i=0;i<R;i++)
	{
		if (lowest>num[i])
		{
			lowest=num[i];
			lowestU=name[i];
		}
	}
	
	return lowest;
}

int getHighest(int num[], string name[], string &highestU)
{
	int highest=-99999;

	for(int i=0;i<R;i++)
	{
		if (highest<num[i])
		{
			highest=num[i];
			highestU=name[i];
		}
	}
	
	return highest;
}










