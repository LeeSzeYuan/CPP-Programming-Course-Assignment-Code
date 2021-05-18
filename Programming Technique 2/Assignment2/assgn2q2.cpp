#include <iostream>
#include <string>
using namespace std;

class Contact
{
	private:
		string phone, email;
	
	public:
		Contact(string, string);
		
		void setPhone(string _phone) {phone = _phone;}
		void setEmail(string _email) {phone = _email;}
						
		string getPhone() const {return phone;}
		string getEmail() const {return email;}
};

Contact::Contact(string a="", string b="")
{
	phone = a;
	email = b;
}

class Person
{
	protected:
		string name;
		string id;
	
	public:		
		Contact con;
		
		Person(string, string, string);
		
		void setName(string _name) {name = _name;}
		void setId(string _id) {id = _id;}
		
		string getName() const {return name;}
		string getPhone() const {return con.getPhone();}
		string getEmail() const {return con.getEmail();}
};

Person::Person(string a="", string b="", string c=""):con(b, c)
{
	name = a;
}

class Staff:public Person
{
	protected:
		string position;
	
	public:
		Staff(string, string, string, string);
		
		void setPosition(string post) {position = post;}
		
		string getPosition() const {return position;}
};

Staff::Staff(string a="", string b="", string c="", string d=""):Person(a, b, c)
{
	position = d;
}

class Project
{
	protected:
		string title, area;
	
	public:
		Project(string);
		
		void setTitle(string _title) {title=_title;} 
		void setArea(string _area) {area=_area;} 
		
		string getTitle() const {return title;}
		string getArea() const {return area;}
};

Project::Project(string a)
{
	title = a;
}

class Student: public Person
{
	protected:
		string program;
		Project project;
		Staff *advisor;
	
	public:
		Student(string, string, string, string, string);
		
		void setProgram(string prog) {program = prog;}
		void setProject(Project proj) {project = proj;}
		void setAdvisor(Staff *adv) {advisor = adv;}
		
		string getProjectTitle() const {return project.getTitle();}
		string getProgram() const {return program;}
		string getProjectArea() const {return project.getArea();}
		string getAdvisorName() const {return advisor->getName();}
		string getAdvisorPosition() const {return advisor->getPosition();}
};

Student::Student(string a="", string b="", string c="", string d="", string e=""):Person(a, b, c), project(e)
{
	program = d;
}

int main()
{
	Staff *advisors = new Staff[3];
	
	advisors[0] = Staff("Prof. Dr. Muhammad Roslan Abdullah", "0199875678", "mroslana29@gmail.com", "Lecturer");
	advisors[1]	= Staff("Mr. Qamarool Zaman", "01156781234", "qam23@gmail.com", "Senior Technician");
	advisors[2] = Staff("Dr. Siti Zubaidah Rosli", "0101117456", "ctzr983@gmail.com", "Research Officer");
	
	Student *students = new Student[3];
	
	students[0] = Student("Lim Sew Ying", "010897634045", "lsying12@live.utm.my", "Electrical Engineering", "Smart Dustbin");
	students[1] = Student("Abu Bakar Razali", "0111210000", "abraz78@live.utm.my", "Computer Science", "Money Recognition of Blind People");
	students[2] = Student("Nur Amalina", "0129000123", "nam978@live.utm.my", "Biomedical Engineering", "Dengue Testing Kit");
	
	for (int i=0; i<3; i++)
		students[i].setAdvisor(&advisors[i]);
	
	cout << "===============================================================================" << endl;	
	cout << "Before Changing......" << endl << endl;
	cout << "DETAILS" << endl;
	for (int i=0; i<3; i++)
	{
		cout << "Name:\t\t" << students[i].getName() << endl
			 << "Phone Number:\t" << students[i].getPhone() << endl
			 << "Email Address:\t" << students[i].getEmail() << endl
			 << "Program Name:\t" << students[i].getProgram() << endl
			 << "Project Name:\t" << students[i].getProjectTitle() << endl
			 << "Advisor Name:\t" << students[i].getAdvisorName() << endl
			 << "Advisor Position:\t" << students[i].getAdvisorPosition() << endl
			 << endl << endl;
	}
	
	students[0].setAdvisor(&advisors[1]);
	students[1].setAdvisor(&advisors[0]);
	
	Staff NONE("N/A", "N/A", "N/A", "N/A");
	students[2].setAdvisor(&NONE);
	
	cout << "===============================================================================" << endl;
	cout << "After Changing......" << endl << endl;
	cout << "DETAILS" << endl;
	for (int i=0; i<3; i++)
	{
		cout << "Name:\t\t" << students[i].getName() << endl
			 << "Phone Number:\t" << students[i].getPhone() << endl
			 << "Email Address:\t" << students[i].getEmail() << endl
			 << "Program Name:\t" << students[i].getProgram() << endl
			 << "Project Name:\t" << students[i].getProjectTitle() << endl
			 << "Advisor Name:\t" << students[i].getAdvisorName() << endl
			 << "Advisor Position:\t" << students[i].getAdvisorPosition() << endl
			 << endl << endl;
	}		
	
	return 0;
}
