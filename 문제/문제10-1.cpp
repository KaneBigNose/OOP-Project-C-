#include <iostream>
using namespace std;

class Point
{
private:
	int xpos, ypos;
public:
	Point(int x = 0, int y = 0) : xpos(x), ypos(y)
	{  }
	void ShowPosition() const
	{
		cout << '[' << xpos << ", " << ypos << ']' << endl;
	}
	friend Point operator+(const Point& pos1, const Point& pos2);
	friend Point operator-(const Point& pos1, const Point& pos2);
	Point& operator+=(const Point& copy)
	{
		xpos += copy.xpos;
		ypos += copy.ypos;
		return *this;
	}
	Point& operator-=(const Point& copy)
	{
		xpos -= copy.xpos;
		ypos -= copy.ypos;
		return *this;
	}
	friend bool operator==(const Point& copy1, const Point& copy2);
	friend bool operator!=(const Point& copy1, const Point& copy2);
};

Point operator+(const Point& pos1, const Point& pos2)
{
	Point pos(pos1.xpos + pos2.xpos, pos1.ypos + pos2.ypos);
	return pos;
}
Point operator-(const Point& pos1, const Point& pos2)
{
	Point pos(pos1.xpos - pos2.xpos, pos1.ypos - pos2.ypos);
	return pos;
}
bool operator==(const Point& copy1, const Point& copy2)
{
	if (copy1.xpos == copy2.xpos && copy1.ypos == copy2.ypos) { return true; }
	else { return false; }
}
bool operator!=(const Point& copy1, const Point& copy2)
{
	return !(copy1 == copy2);
}

int main(void)
{
	Point pos1(20, 30);
	Point pos2(5, 7);
	Point pos3(5, 7);

	(pos1 - pos2).ShowPosition();
	(pos2 += pos3).ShowPosition();
	pos1.ShowPosition();
	pos2.ShowPosition();

	if (pos1 == pos2) { cout << "같음" << endl; }
	else { cout << "다름" << endl; }
	cout << "check" << endl;
	if (pos2 != pos3) { cout << "다름" << endl; }
	else { cout << "같음" << endl; }

	return 0;
}
