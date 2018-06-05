#include <iostream>
#include "stdafx.h"
#include <windows.h> 
#include <math.h>
#include <string>
using namespace std;
class HexadecimalToAll {
public:
	HexadecimalToAll();

	double convert_to_decimal(string Hexadecimal_string) {
		int hexadecimal_string_size = Hexadecimal_string.size();
		int found_it;
		int result1 = 0;
		int counter1 = 0;
		char tokenaizer[100];
		for (int i = 0; i < hexadecimal_string_size; i++)
		{
			tokenaizer[i] = Hexadecimal_string[i];
			counter1++;
		}
		int real_Hexadecimal_number[100];
		for (int i = 0; i < counter1; i++)
		{
			if (tokenaizer[i] == '.')
			{
				found_it = i;
				break;
			}
			switch (tokenaizer[i])
			{
			case 'A':
				real_Hexadecimal_number[i] = 10;
				break;
			case 'B':
				real_Hexadecimal_number[i] = 11;
				break;
			case 'C':
				real_Hexadecimal_number[i] = 12;
				break;
			case 'D':
				real_Hexadecimal_number[i] = 13;
				break;
			case 'E':
				real_Hexadecimal_number[i] = 14;
				break;
			case 'F':
				real_Hexadecimal_number[i] = 15;
				break;
			default:
				/*
				Numbers in ASCII Code starts from 48
				SO ....number 9 in ascii code is -> 9+48 = 57
				number 2 -> 2+48 = 50
				*/
				real_Hexadecimal_number[i] = (int)tokenaizer[i] - 48;
				break;
			}
		}
		if (found_it > 0) //EVERY THING CHANGE FROM HRERE!
		{
			double frac[100];
			int countereeer = found_it + 1;
			int counter99 = 0;
			for (int i = countereeer; i < hexadecimal_string_size; i++)
			{
				switch (tokenaizer[i])
				{
				case 'A':
					frac[i] = 10;
					break;
				case 'B':
					frac[i] = 11;
					break;
				case 'C':
					frac[i] = 12;
					break;
				case 'D':
					frac[i] = 13;
					break;
				case 'E':
					frac[i] = 14;
					break;
				case 'F':
					frac[i] = 15;
					break;
				default:
					frac[i] = (double)tokenaizer[i] - 48;
					break;
				}
				/*frac[i] = (double)FileMeasure[i] - 48 ;
				cout << "frac[" << i << "]" << frac[i] <<endl;
				//found_it++;
				counter99++;*/
			}
			int power = -1;
			double result2 = 0;

			for (int j = countereeer; j < hexadecimal_string_size; j++)
			{
				result2 += (pow(16, power) * frac[j]);

				//cout << "POW(16," << power << ") * frac[" << j << "] = ";
				//cout << (pow(16, power) * frac[j]) << endl;
				power--;

			}
			//cout << result2 << endl;
			
			int counter = found_it - 1;
			for (int i = 0; i < found_it; i++)
			{
				result1 += real_Hexadecimal_number[i] * pow(16, counter);
				counter--;
			}
			return result1 + result2;
		}
		else
		{
			int counter = hexadecimal_string_size-1;
			for (int i = 0; i < hexadecimal_string_size; i++)
			{
				result1 += real_Hexadecimal_number[i] * pow(16, counter);
				counter--;
			}
			
			return result1;
		}
		//cout << result1 + result2 << endl;
	}

};


