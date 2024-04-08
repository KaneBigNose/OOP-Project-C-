#include <iostream>
#include <cstdlib>
using namespace std;

class BoundCheck2DIntArray
{
private:
	int* arr2D;
	int width, height;
public:
	BoundCheck2DIntArray(int height, int width)
	{
		this->width = width;
		this->height = height;
	}
	int* operator[](const int num)
	{
		if (num < 0)
		{
			cout << "error1" << endl;
		}
		int temp_arr2D[num];
		return temp_arr2D;  
	}
	int* operator[](const int* num)
	{
		if (*num < 0)
		{
			cout << "error2" << endl;
		}
		arr2D = new int[*num];
		return arr2D;
	}
	friend ostream& operator<<(ostream os, int* arr);
};
ostream& operator<<(ostream os, int* arr)
{
	cout << "[" << *arr << "]";
	return os;
}
int main(void)
{
	BoundCheck2DIntArray arr2D(3, 4);
	for (int n = 0; n < 3; n++)
	{
		for (int m = 0; m < 4; m++)
		{
			arr2D[n][m] = n + m;
		}
	}
	for (int n = 0; n < 3; n++)
	{
		for (int m = 0; m < 4; m++)
		{
			cout << arr2D[n][m] << " ";
		}
		cout << endl;
	}
}