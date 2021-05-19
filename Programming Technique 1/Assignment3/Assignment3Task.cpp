#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

ofstream out("output1.txt");
const int NUM_STATE = 14;
const int NUM_YEAR = 10;

struct dataAcc
{
	int numAcc[10];
	string state;
	float avg;
};

void displayLine();
float cal_Avg(int []);
void find_HighLow(dataAcc []);

//-----------------------------------------------------------------//
int main()
{
	ifstream inp("input1.txt");
	dataAcc data[NUM_STATE];
	
	if(!inp.is_open())
	{
		cout << "Error!!" << endl;
		exit(0);
	}
	
	for (int i = 0; i<NUM_STATE; i++)
	{
		for (int j =0; j<NUM_YEAR; j++)
		{
			inp>>data[i].numAcc[j];
		}
		data[i].avg = cal_Avg(data[i].numAcc);
		getline(inp, data[i].state, '\n');
	}
	
	displayLine();
	out << setw(10) << "STATE";
	out << right << setw(10) << " ";
	
	out << left;
	
	for (int y=0; y<NUM_YEAR; y++)
	{
		out << setw(7) << (2006+y);
	}
	
	out << "AVERAGE" << endl << endl;;
	displayLine();
	
	out << fixed << setprecision(1);
	
	for (int i = 0; i<NUM_STATE; i++)
	{
		out << left << setw(17) << data[i].state;
		
		for (int j =0; j<NUM_YEAR; j++)
		{
			out << right;
			out << setw(7) << data[i].numAcc[j];
		}
		
		out << setw(10) << data[i].avg << endl << endl;
	}
	
	displayLine();
	find_HighLow(data);
	displayLine();
	
	out.close();
	inp.close();
	return 0;
}

void displayLine()
{
	for (int j = 0; j<98; j++)
		out << "-";
		
	out << endl << endl;
}

float cal_Avg(int arr[])
{
	int sum=0;
	float avg;
	
	for (int j =0; j < NUM_YEAR; j++)
		sum += arr[j];

	avg = static_cast<float>(sum)/NUM_YEAR;
	
	return avg;
}

void find_HighLow(dataAcc data[])
{
	int highest=-999999, stat, year;
	
	for (int i = 0; i < NUM_STATE; i ++)
	{
		for (int j =0; j < NUM_YEAR; j++)
		{
			if (highest < data[i].numAcc[j])
			{
				highest = data[i].numAcc[j];
				stat = i;
				year = j;
			}
		}
	}
	out <<  "The highest number of road accidents = "<< highest << " at" 
		<< data[stat].state << " on " << (2006+year) << endl << endl;
		
}
