
#include <iostream>
#include <cmath>
#include <iomanip>
#include <cctype>
using namespace std;

double getBMI (double, double);
void dispStatus(double);

int main()
{
	int number,i;
	double weight,totalWeight=0, OverallWeight, height,totalHeight=0, OverallHeight, BMI, OverallBMI;
	char name[30], Name[30];
	
	cout << fixed << setprecision(2);

	cout << "Number of people for BMI test: ";
	cin >> number;

	for (i=0;i<number;i++)
	{
		cout <<endl<< "Enter the name of the person => ";
		cin.ignore();
      	cin.clear();
	    cin.getline(name, 30);
	    
		cout << "Enter weight (kg) and height (m) => ";
	    cin >> weight >> height;
	    
	    totalWeight += weight;
	    totalHeight += height;
	    BMI=getBMI (weight, height);
	    
	    cout << endl;
	    cout << "Name   : " << name << endl;
	    cout << "Weight : " << weight <<" kilograms" << endl;
	    cout << "Height : " << height <<" meters" << endl;
	    cout << "BMI    : " << BMI << endl;
	    cout << "Status : ";
		dispStatus(BMI);	
	}
	
	OverallWeight=totalWeight/number;
	OverallHeight=totalHeight/number;
	
	OverallBMI=getBMI (OverallWeight, OverallHeight);
	
	cout << "\n\nOverall BMI : " << OverallBMI << endl;
	cout << "Overall Status : ";
	dispStatus(OverallBMI);
	
	return 0;
}

double getBMI (double w, double h)
{
	return (w/(pow(h,2)));
}

void dispStatus(double B)
{
	if ((B>0)&&(B<18.5))
	cout << "Underweight"<<endl;
	else if (B <=25)
	cout << "Normal";
	else if (B <=30)
	cout << "Overweight"<<endl;
	else if (B>30)
	cout << "Obese"<<endl;
	else 
	cout << "You have input invalid data. Please run our system again" << endl;
}
