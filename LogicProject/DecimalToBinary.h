#include <iostream>
#include "stdafx.h"
#include <windows.h> 
#include <math.h>
#include <string>
using namespace std;
#ifndef DecimalToBinary_H
#define DecimalToBinary_H
class DecimalToBinary {
	HANDLE  hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
public:
	DecimalToBinary();

	int integers_array[100];
	int fractional_array[100];
	int counter = 0;
	// The Method that convert to Binary
	void convert_To_Binary(double decimal_num) {
		double fractional;// To store the fractional part from the number
		double integers;// To store the integer part from the number
		fractional = modf(decimal_num, &integers);//getting the fractional part and the integer part
		int real_intergers = (int)integers; // casting the integers to real_integers to perform mod(%) later!
		//cout << "fractional =" << fractional << " integers = " << integers << " real_intergers = " << real_intergers << endl;  //tracing
		// converting the integer part!
		while (real_intergers != 0)
		{
			if (real_intergers % 2 == 0)
			{
				integers_array[counter] = 0;
				counter++;
			}
			else
			{
				integers_array[counter] = 1;
				counter++;
			}
			real_intergers = real_intergers / 2;
		}// end of integer convert!
		int hold_counter = counter;
		counter = 0;
		SetConsoleTextAttribute(hConsole, 6);//darkyellow
		// start typing the integer part in binary
		cout << "( ";
		for (int i = hold_counter; i >= 0; i--)
		{
			cout << integers_array[i - 1];
			counter++;
			if (counter == hold_counter)break;

		}//end of typing!
		if (fractional == 0)// style!
		{
			cout << " )2\n";
		}
		if (fractional > 0)// if the number we want to convert has fractional!
		{
			double x;
			int counter2 = 0;
			while (counter2 < 5)// start converting the fractional part  (only five fractional digits)!
			{
				if (fractional * 2 > 1)
				{
					fractional_array[counter2] = 1;
					//cout  << counter2 << " " <<fractional; // tracing

				}
				else
				{
					fractional_array[counter2] = 0;
				}
				fractional *= 2;
				fractional = modf(fractional, &x);// seperate the fracional part from the integer
				counter2++;


			}// end converting the fractional part
			counter2 = 0;
			cout << ".";
			for (int i = 5; i > counter2; i--)// typing the fractional part
			{
				cout << fractional_array[i - 1];

			}
			cout << " )2\n";
			
		}
	}


	void convet_to_octal(double decimal_number) {
		int result;
		int hold[100];
		int hold2[100];
		double num_before_point;//intergers
		double numb_after_point;//fractionals
		//saperate the fractional part from the ineger part
		numb_after_point = modf(decimal_number, &num_before_point);
		//cout << "frac" << numb_after_point << "int" << num_before_point<<endl;//tracing
		int real_intergers = (int)num_before_point;
		int i = 0;
		while (real_intergers != 0)
		{
			result = real_intergers % 8;
			hold[i] = result;
			i++;
			real_intergers = real_intergers / 8;
		}
		SetConsoleTextAttribute(hConsole, 3);
		cout << "( ";
		for (int j = i; j > 0; j--)
		{
			cout << hold[j - 1];
		}
		if (numb_after_point == 0)//style!
		{
			cout << " )8 \n";
		}
		i = 0;
		if (numb_after_point > 0)
		{
			int counter = 0;
			double result2;
			double result3;
			cout << ".";
			while (counter < 5)
			{
				result2 = modf(numb_after_point * 8, &result3);
				//cout << "result2 " << result2 << endl; //tracing
				//cout << "result3 " << result3 << endl; //tracing
				hold2[i] = result3;

				numb_after_point = result2;
				counter++;
				i++;
				cout << result3;
			}

			cout << " )8\n";
		}
	}
	void convert_to_Hexadecimal(double decimal_number) {
		double integers, fractionals;
		fractionals = modf(decimal_number, &integers);
		int real_integers = (int)integers;
		int i = 0, result;
		int reverse[100];
		while (real_integers != 0)
		{
			result = real_integers % 16;
			real_integers /= 16;
			reverse[i] = result;
			i++;
		}
		SetConsoleTextAttribute(hConsole, 2);
		cout << "( ";
		for (int k = i; k > 0; k--)
		{
			switch (reverse[k - 1])
			{
			case 10:
				cout << "A";
				break;
			case 11:
				cout << "B";
				break;
			case 12:
				cout << "C";
				break;
			case 13:
				cout << "D";
				break;
			case 14:
				cout << "E";
				break;
			case 15:
				cout << "F";
				break;
			default:
				cout << reverse[k - 1];
				break;
			}
		}
			if (fractionals == 0)
			{
				cout << " )16 \n";
			}
			
			double result2;
			double result3;
			int counter = 0;
			int holder[100];
			if (fractionals > 0)
			{
				cout << ".";
				i = 0;
				while (counter < 5) {
					result2 = modf(fractionals * 16, &result3);
					//cout << "result2 " << result2 << endl; //tracing
					//cout << "result3 " << result3 << endl; //tracing
					holder[i] = result3;
					counter++;
					i++;
					fractionals = result2;
				}
				for (int s = 0; s < i; s++)
				{
					switch (holder[s])
					{
					case 10:
						cout << "A";
						break;
					case 11:
						cout << "B";
						break;
					case 12:
						cout << "C";
						break;
					case 13:
						cout << "D";
						break;
					case 14:
						cout << "E";
						break;
					case 15:
						cout << "F";
						break;
					default:
						cout << holder[s];
						break;
					}
				}
				cout << " )16 \n";
			}
			
		}

};
#endif // !DecimalToBinary_h
