#include <iostream>
#include <fstream>
#define R 20
#define C 3
using namespace std;

void getInput(int [][C]);
int calTotal(int [][C], int &, int &, int &);
int getLowest(int [][C]);
int getHighest(int [][C]);
int calAverage (int &, int &, int &); //Note: Use proper output formatting.

int main()
{
	int num[R][C];
	int sum1=0, sum2=0, sum3=0;
	ofstream out ("output.txt");
	
	out << "--------------------------------" << endl;
	out << "UNIVERSITY" << "\t" << "INTAKE" << "\t" << "ENROLMENT"<< "\t" << "OUTPUT" << endl;
	out << "--------------------------------" << endl;
	getInput(num);
	out << "--------------------------------" << endl;
	
	calTotal(num, sum1, sum2, sum3);
	out << "TOTAL\t" << sum1 << "\t" << sum2 << "\t" << sum3 << endl;
	
	int avg1, avg2, avg3;
	avg1=sum1/20;
	avg2=sum2/20;
	avg3=sum3/20;
	out << "AVERAGE\t" << sum1 << "\t" << sum2 << "\t" << sum3 << endl;

	out << "--------------------------------" << endl;
	

	out.close();
	return 0;
} 

void getInput(int num[R][C])
{
	int n1, n2, n3, n4, i=0, j=0;
	ifstream inp;

	ofstream out ("output.txt");
	
	inp.open("Input.txt");
	
	if(!inp.is_open())
	{
		cout << "Error!!" << endl;
		exit(0);
	}
	
	while (inp>>n1)//(!inp.eof())
	{
		i++;
	    inp >> n2;
	    inp >> n3;
	    inp >> n4;
	    
	    num[i][0]=n2;
	    num[i][1]=n3;
	    num[i][2]=n4;
		out << n1 << "\t" << n2 << "\t" << n3 << "/t" << n4 << endl;
	}
	inp.close();
	out.close();
}

int calTotal(int num[R][C], int &sum1, int &sum2, int &sum3)
{
    sum1=0, sum2=0, sum3=0;
	for(int i=0;i<R;i++)
	{
		sum1+=num[i][0];
		sum2+=num[i][1];
		sum3+=num[i][2];
	}
}








