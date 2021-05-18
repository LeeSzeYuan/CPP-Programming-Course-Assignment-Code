#include <iostream>
#include <cstdlib>
using namespace std;

class Rectangle
{
	private:
		int height, width;
		
	public:
		Rectangle(int a=0, int b=0){height =b; width =a;}
		int getWidth() {return width;}
		int getHeight() {return height;}
		
		friend Rectangle operator+(Rectangle, Rectangle);
		Rectangle operator-(Rectangle);
		friend ostream &operator << (ostream &, const Rectangle &);
};

Rectangle operator+(Rectangle A, Rectangle B)
{
	Rectangle C;
	C.height=A.height+B.height;
	C.width =A.width+B.width;
	return C;
}

Rectangle Rectangle::operator-(Rectangle A)
{
	Rectangle C;
	C.height=abs(height-A.height);
	C.width = abs(width-A.width);
	return C;
}

ostream &operator<<(ostream &strm, const Rectangle &obj)
{
	strm << obj.height << " CM height, " << obj.width << " CM width";
	return strm;
}


int main()
{
	int w, l;
	cout << "Please enter the height and width of rectangle A in CM: " << endl;
	cin >> l >> w;
	Rectangle A(w, l);
	
	cout << "Please enter the height and width of rectangle B in CM: " << endl;
	cin >> l >> w;
	Rectangle B(w, l);
	
	Rectangle C;
	
	cout << endl;
	
	C=A+B;
	cout << "The combined height and width of A and B is " << C << endl << endl;
	
	A=A-B;
	cout << "The difference in height and width of A and B is " << A << endl;
	
	return 0;

}
