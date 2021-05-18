#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;

ifstream inp("answer.txt");

class Student{
	private:
		char studentName[20];
		char matrixNumber[20];
		char answer[26];
		char grade;
		float marks;
	
	public:
		float getData();
		void gradeTest();
		void printDetail();
};


float Student::getData(){
	char name[20], number[20], ans[26];
	inp >> name >> number >> answer;
	strcpy(studentName, name);
	strcpy(matrixNumber, number);
	strcpy(answer, ans);
}

void Student::gradeTest(){
	char correct[26] = "ABCAABCAABCAABCAABCAABCAA";
	int count = 0;

	for (int i=0; i<26; i++){
		if (correct[i] == answer[i]){
			count  += 1;
		}
	}
	marks = count * 4;
	marks -= (25 - count);
	
	
	if (marks >= 75)
		grade = 'A';
	else if (marks >= 65)
		grade = 'B';
	else if (marks >= 55)
		grade = 'C';
	else if (marks >= 45)
		grade = 'D';
	else
		grade = 'E';
}

void Student::printDetail(){
	cout << "Name: " << studentName << "\tMarks: " << marks << "%\t" << grade << endl;
}

int main(){
	Student list[20];
	
	if (!inp)
	{
		cerr<<"Error!!Cannot open the file!";
		return 0;
	}
	
	for (int i = 0 ; i < 20;i++){
		list[i].getData();
		list[i].gradeTest();
		list[i].printDetail();
	}
	
	inp.close();
	return 0;
}

