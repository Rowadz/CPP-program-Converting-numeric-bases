#include <iostream>
#include "stdafx.h"
#include <windows.h> 
#include <math.h>
#include <string>
using namespace std;
class BinaryToOther {
public:
	BinaryToOther();

	double convert_to_decimal(double binary_number) {
		double fractional;
		double integer;
		fractional = modf(binary_number, &integer);
		int counter = 0;
		int integer2 = (int)integer;
		int int_array[100];
		while (integer2)
		{
			int_array[counter] = integer2 % 10;
			integer2 /= 10;
			counter++;
		}
		//tracing
		/*
		for (int j = 0; j < counter; j++)
		{
			cout << int_array[j] << endl;
		}
		*/
		//cout << " ( ";
		int result1 = 0;
		for (int i = counter - 1; i >= 0; i--)
		{
			result1 += int_array[i] * pow(2, i);
		}
		//cout << "The Answer is "<<result1;
		/*if (fractional == 0)
		{
			cout << ") 10";
		}*/
		if (fractional > 0)
		{
			
			string x = to_string(fractional);
			
			int size = x.size();
			char digits[100];
			int found_it;
			int counter = 0;
			for (int i = 1; i < size; i++)
			{
				if (x[i] == '.')
				{
					found_it = i;
				}
				else
				{
					digits[i] = x[i];
					counter++;
					//cout << "digits[i]" << digits[i] << "\n";
				}
				
			}
			double result2 = 0;
			int k = -1;
			for (int j = 2; j < counter; j++)
			{
				result2 += ((double)digits[j] - 48) * pow(2, k);
				//cout << "reutle2 = " << result2 << endl;
				//cout << "(double)digits["<<j<<"]"<<" - 48 = " << (double)digits[j] - 48<<endl;
				//cout << "K =" << k << endl;
				k--;
			}
			//string result2x = "."+to_string(result2);
			//cout << result2x<<"\nssss";
			return result1 + result2;
			//counter = 0;
			//double do_array[100];
			///*This Will take digits after the dicmal point and put them into an array (one by one)
			//example 0.11
			//do_array[0] = 0.1;
			//do_array[1] = 0.11;  and so on
			//This will not give the correct Answer it won't br accurate!
			//*/
			//for (int i = 0; i < 4; i++)
			//{
			//	do_array[i] = floor(fractional * pow(10, i + 1)) / pow(10, i + 1);
			//	counter++;
			//}
			//double result2 = 0;
			//int power = -1;
			//for (int i = 0; i < counter; i++)
			//{
			//	result2 += ((do_array[i] * pow(2, power)) * 10);
			////	cout  << "RESULT 2 = " << result2 << endl;
			//	power--;
			//}
			//double helper;
			//result2 = modf(result2, &helper);
			////cout << result1 + result2;
			//return result1 + result2;
			////cout << " ) 10" << endl;
		
		}
		return result1;
	}
};