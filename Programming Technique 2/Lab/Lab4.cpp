// Name : Lee Sze Yuan                                             //
// Matrics No : A19EC0068  
#include <iostream>

using namespace std;

#define PI 3.1415

// TASK 1
class Object3D
{
	public:
		Object3D() {}
		virtual double getVolume() const {return 0;}
		virtual void print() const {}
};

//TASK 2
class Sphere: public Object3D
{
	private:
		double r;
		
	public:
		Sphere(double _r=0) {setRadius(_r);}
		
		void setRadius(double _r) {r = _r;}
		double getRadius() const {return r;}
		
		double getVolume() const {return (4*PI*r*r*r)/3;}
		void print() const{cout << "Sphere: r=" << r << endl;}
};

//TASK 3
class Cylinder: public Object3D
{
	private:
		double r;
		double h;
	
	public:
		Cylinder(double _r=0, double _h=0){
			setRadius(_r);
			setHeight(_h);
		};
		
		void setRadius(double _r) {r = _r;}
		void setHeight(double _h) {h = _h;}
		double getRadius() const {return r;}
		double getHeight() const {return h;}
		
		void print() const{
			cout << "Cylinder: r=" << r << ", h=" << h << endl;
		};
		double getVolume() const{
			return PI*(r*r)*h;
		}
};

//TASK 4
class Cuboid: public Object3D
{
	private:
		double w;
		double h;
		double l;
	
	public:
		Cuboid(double _w=0, double _l=0, double _h=0){
			setWidth(_w);
			setLength(_l);
			setHeight(_h);			
		}
		
		void setWidth(double _w) {w = _w;}
		void setLength(double _l) {l = _l;}
		void setHeight(double _h) {h = _h;}
		double getWidth() const {return w;}
		double getLength() const {return l;}
		double getHeight() const {return h;}
		
		double getVolume() const {
			return w*l*h;
		}
		void print() const{
			cout << "Cuboid: dimension " << w << " x " << l << " x " << h << endl;
		}
};

int main()
{
	//TASK 5
	Object3D *object[5];
	
	Cuboid C1(10, 20, 30);
	Cylinder Cy1(20, 20);
	Sphere S1(10);
	Cylinder Cy2(2, 5);
	Sphere S2(3);
	
	//TASK 6
	object[0] = &C1;
	object[1] = &Cy1;
	object[2] = &S1;
	object[3] = &Cy2;
	object[4] = &S2;
	
	//TASK 7
	for (int i=0; i<5; i++)
	{
		cout << "Object #" << (i+1) << endl;
		object[i]->print();
		
		cout << "Volume= " << object[i]->getVolume() << endl;
		cout << endl;
	}
	
	
	double totalVolume = 0;
	
	//TASK 8
	for (int i=0; i<5; i++)
		totalVolume+=object[i]->getVolume();		
		
	cout << "Total volume = " << totalVolume << endl;
	return 0;
}
