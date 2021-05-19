#include <iostream>
#include <cmath>
using namespace std;

int getProblem();
void getRateDropFactor(double &, double &);
int figDropsMin(double , double );
void getKgRateConc(double &, double &, double &);
int byWeight(double, double, double);


int main()
{
	int number;
	double rate,dropFactor,weight,concentration;
	cout << "INTRAVENOUS RATE ASSISTANT" << endl << endl;

    do
    {
        number = getProblem();
    	switch (number)
	{
		case 1: getRateDropFactor(rate,dropFactor);
		        cout << "The drop rate per minute is " << figDropsMin(rate,dropFactor) << endl;
	            break;
	    case 2: getKgRateConc(rate,weight,concentration);
	            cout << "The rate in milliltresper hour is "<<byWeight(rate,weight,concentration)<<endl;
	            break;
       	case 3: cout <<"You have chosen to quit the program.\nThank you for using our system." <<endl;
	            break;
	    default : cout <<"Please run the system again and choose a problem number between 1 and 3."<< endl;
	              break;
    }
        cout << endl;
	}while (number == 1 || number == 2);
    return 0;
}

int getProblem()
{
	int problem;

	cout <<"Enter the number of the problem you wish to solve.\n";
	cout <<"     GUVEN A MEDICAL ORDER IN            CALCULATE RATE IN" <<endl;
	cout <<"(1) ml/hr & tubing drop factor             drops/min"<< endl;
	cout <<"(2) mg/kg/hr & concentration in mg/ml      ml/hr"<< endl;
	cout <<"(3) QUIT\n"<< endl;
	
	cout <<"Problem => ";
	cin >> problem;
	
	return problem;
}

void getRateDropFactor(double &m, double &d)
{
	cout << "Enter rate in ml/hr => ";
	cin >> m;
	cout << "Enter tubing's drop factor(drops/ml) => ";
	cin >> d;
}

int figDropsMin(double m, double d)
{
	return (ceil((m/60)*d));
}

void getKgRateConc(double &m, double &k, double &l)
{
	cout << "Enter rate in mg/hr => ";
	cin >> m;
	cout << "Enter patient weight in kg => "; 
	cin >> k;
	cout << "Enter concentration in mg/ml => ";
	cin >> l;
}

int byWeight(double m,double k,double l)
{
	return (ceil(m*k*l));
	
}
