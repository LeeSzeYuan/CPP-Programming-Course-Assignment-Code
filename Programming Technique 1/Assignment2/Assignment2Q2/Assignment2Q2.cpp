//LEE SZE YUAN A19EC0068 991029-02-5069 SEC 02 30/11/2019
//LOH YEW CHONG A19EC0076 000722-02-0135 SEC 02 30/11/2019

#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

void displayLine();
void findIndWinner(int [][7]);
void findTeamWinner(int [][1]);

int main()
{
	int sum,m=0,n1,n2,j=0,Final=0;
	int marks[12][7];
	int TotalMarks[3][1];
	
	ifstream inp ("input2.txt");
	
	if(!inp.is_open())
	{
		cout << "Sorry, input file does not exist!\nPress any key to continue . . ." << endl;
        exit(0);
	}
	
	displayLine();
	
	cout << left;
	cout << setw(8) << "Id " << setw(8) << "E1 " << setw(8) << "E2 " << setw(8) << "E3 " << setw(8) << "E4 " << setw(8) << "E5 "  << setw(8) << "TOTAl " << endl;
	
	displayLine();
	
	cout << "TEAM 1" << endl;
	
	for (int i=0; i<12; i++)
	{
		j=1;
		
		inp >> n1;
		inp >> marks[i][0];
		
		cout << setw(8) << marks[i][0];
		
		sum=0;
		
		while (j>0&&j<6)
		{
			inp >> marks[i][j];
			
			sum +=marks[i][j];
			
			cout << setw(8) << marks[i][j];
			
			j++;
			
			marks[i][6]=sum;			
	    }
	    cout << marks[i][6] << endl;
		Final+=marks[i][6];
		
		if (i==3||i==7||i==11)
	    {
	    	TotalMarks[m][1]=Final;
	    	
	    	cout << setw(48) << "TOTAL" << Final << endl;
	        displayLine();
				
	        if (i==3)
	        cout << "TEAM 2"<< endl;
	        if (i==7)
	        cout << "TEAM 3" << endl;
	        
	        Final=0;
	        m++;
		}
		
	}
	
    findIndWinner(marks);
    findTeamWinner(TotalMarks);
    
	inp.close();
	return 0;
}

void displayLine()
{
	cout << "-----------------------------------------------------" << endl;
}

void findIndWinner(int marks[][7])
{
	int highest=-999999,highestInd,n;
	
	for (int i=0;i<12;i++)
	{
		if (highest<marks[i][6])
		{
			highest =marks [i][6];
			highestInd=i;
		}	
	}
	
	if (highestInd >=0 && highestInd <=3)
	n=1;
	else if (highestInd >=4 && highestInd <=7)
	n=2;
	else if (highestInd >=8 && highestInd <=11)
	n=3;
	
	cout << "\nWinner for Individual Category: "<< marks[highestInd][0] << " (Team " << n <<")" << endl;
}

void findTeamWinner(int TotalMarks[][1])
{
	int score=-999999,scoreId,n;
	
	for (int n=0;n<3;n++)
	{
		if (score<TotalMarks[n][1])
		{
			score =TotalMarks [n][1];
			scoreId=n+1;
		}	
	}
	cout << "Winner for Group Category: Team " << scoreId << " (Score = " << score << ")" << endl;
}





