// Algorithms.cpp : Defines the entry point for the application.
//

#include <iostream>
#include "MyAlgos/Sorting.h"

using namespace std;

int main()
{
	int arr[] = {5,2,4,6,1,3};
	float fArr[] = { 5.5,1.1,2.3,4.6,6.9,3.1 };
	MA_MergeNSort(fArr, 0,5);
	for (int i = 0; i < 6; i++) {
		cout << fArr[i] << endl;
	}
	return 0; 
}
