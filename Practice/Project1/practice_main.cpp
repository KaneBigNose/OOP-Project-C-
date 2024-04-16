#include <iostream>
using namespace std;

template <class T>

class Point
{
private:
	T xpos, ypos;
public:
	Point(T xpos, T ypos) : xpos(xpos), ypos(ypos) {}
	void ShowPosition() const
	{
		cout << "[" << xpos << ", " << ypos << "]" << endl;
	}
};

int main(void)
{
	int a = 1;
	int b = 2;
	double c = 0.8;
	double d = 5.5;
	const char* e = "5";
	const char* f = "15";

	Point<int> p1(a, b);
	Point<double> p2(c, d);
	Point<const char*> p3(e, f);

	p1.ShowPosition();
	p2.ShowPosition();
	p3.ShowPosition();
}