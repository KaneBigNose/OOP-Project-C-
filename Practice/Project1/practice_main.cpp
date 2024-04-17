#include <iostream>
using namespace std;

template <class T>

T SumArray(T arr[], int len)
{
	T sum = 0;
	for (int i = 0; i < len; i++)
	{
		sum += arr[i];
	}
	return sum;
}

int main(void)
{
	int arr1[5] = { 1,2,3,4,5 };
	double arr2[5] = { 0.1,0.2,0.3,0.4,0.5 };
	cout << SumArray(arr1, 5) << endl;
	cout << SumArray(arr2, 5);
}