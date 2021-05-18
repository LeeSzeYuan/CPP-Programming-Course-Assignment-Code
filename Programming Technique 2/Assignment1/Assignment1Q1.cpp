#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

class Student
{
	private:
		string name;
		string course;
	
	public:
		Student(string, string);
		
		void set(string, string);

		string getname()const{return name;}
		string getcourse()const{return course;}
		
		~Student(){};
};

Student::Student(string a="", string b="")
{
	name = a;
	course = b;
}

void Student::set(string a, string b)
{
	name = a;
	course = b;
}

//---------------------------------------------------------------------

class Detail
{
	private:
		string advisor;
		string supervisor;
		string project;
	
	public:
		Detail(string, string, string);
		
		void set(string, string, string);

		string getadvisor()const{return advisor;}
		string getsupervisor()const{return supervisor;}
		string getproject()const{return project;}
		
		~Detail(){};
};

Detail::Detail(string a = "", string b = "", string c = "")
{
	advisor = a;
	supervisor = b;
	project = c;
}

void Detail::set(string a, string b, string c)
{
	advisor = a;
	supervisor = b;
	project = c;
}

//----------------------------------------------------------------------------------------------------------------------------

class Record
{
	public:
		Student stu;
		Detail det;
		
		Record(string a = "", string b = "", string c = "", string d = "", string e = ""):stu(a, b), det(c, d, e){};
		void set(string a, string b, string c, string d, string e);
		
		friend ifstream& operator>>(ifstream&, Record&);
		friend ofstream& operator<<(ofstream& , const Record&);
		
		~Record(){};
};

void Record::set(string a, string b, string c, string d, string e)
{
	stu.set(a, b);
	det.set(c, d, e);
}

ifstream &operator>>(ifstream &inp, Record &obj)
{
	string a, b, c, d, e, white;
	
	getline(inp, a);
	getline(inp, b);
	getline(inp, c);
	getline(inp, d);
	getline(inp, e);
	getline(inp, white);
	
	obj.set(a, b, c, d, e);
	
	return inp;
}

ofstream &operator<<(ofstream &out, const Record &obj)
{
	out << left << "  " << setw(42) << obj.stu.getname() << setw(41)  << obj.det.getsupervisor() << obj.det.getproject() << endl;
	return out;
}

//---------------------------------------------------------------------------------------------------------------------------------------

int main()
{
	ifstream inp("pgstudents.txt");
	int size;
	string white;
	Record *list;

	
	if (inp.fail())
	{
		cout << "File open error!" << endl;
		return 0;
	}
	else
	{
		inp >> size;
		getline(inp, white);
		getline(inp, white);
	}
	
	list = new Record[size];
	
	for (int i = 0; i < size; i++)
		inp >> list[i];
		
	ofstream out("output.txt");
	
	out << "THE LIST OF POSTGRADUATE STUDENTS" << endl;
	out << left << setw(3) << "NO" << setw(43) << "Name" << setw(42)
		<< "Supervisor" << "Project" << endl;
	
	for (int i = 0; i < size; i++)
	{
		out << right << setw(2) << i+1;
		out << list[i];		
	}
	
	delete [] list;
	
	return 0;
}
