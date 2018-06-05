//Mohammed Al-Rowad „Õ„‹œ Œ‹·Ì‹· «·—Ê«œ
//Number 4  logic circuit design project
//201420697
#include "stdafx.h"
#include <iostream>
#include <windows.h> 
#include <sstream>
#include "DecimalToBinary.h"
#include "BinaryToOther.h"
#include "OctalToAll.h"
#include "HexadecimalToAll.h"
#include <conio.h>

using namespace std;

int main()
{
	double x = 0;// used to convert
	string hexadecimal_string;// used to convert
	HANDLE  hConsole = GetStdHandle(STD_OUTPUT_HANDLE);//to change the color of the console
	SetConsoleTextAttribute(hConsole, 3);
	cout << "This is a programm to convert Numeral Systems" << endl;
	cout << "Enter a number from 1 to 4 to convert from" << endl;
	cout << "1-Decimal\n2-Binary\n3-Octal\n4-Hexadecimal\n";
	// choose the numeral system to convert from
	int choice;//the system the user want to convert from
	cin >> choice;
	// if the input it not an int or out of range
	while ((choice <= 0) || (choice > 4) || cin.fail())
	{
		SetConsoleTextAttribute(hConsole, 4);//red
		cout << "Please Enter a number from 1 to 4" << endl;
		cin.clear();
		cin.ignore(256, '\n');
		cin >> choice;
	}
	SetConsoleTextAttribute(hConsole, 3);// Light Aqua
	//the objects that are used to convert
	DecimalToBinary decimal_to_ALL;
	BinaryToOther   binary_to_ALL;
	OctalToAll      octal_to_ALL;
	HexadecimalToAll hexadecimal_to_ALL;
	//cout << "1-Decimal\n2-Binary\n3-Octal\n4-Hexadecimal\n";
	SetConsoleTextAttribute(hConsole, 7);// white
	//cout << choice << endl;
	int i = 0;
	while (i != 5)
	{
		DecimalToBinary decimal_to_ALL;
		BinaryToOther   binary_to_ALL;
		OctalToAll      octal_to_ALL;
		HexadecimalToAll hexadecimal_to_ALL;
		bool binary_police2 = true;
		bool octal_police2 = true;
		bool hexadecimal_police2 = true;
		switch (choice)//Convert from
		{
		case 1://From Decimal

			cout << "Enter a Decimal number\n";
			double decimal_num;
			if (cin >> decimal_num)
			{
				//system("color 0a");
				cout << "\n\nFROM (" << decimal_num << ") Decimal TO\n\n";
				cout << "##############################################################" << endl;
				cout << endl;
				cout << "---BINARY----------" << endl << endl;
				cout << "\t";
				decimal_to_ALL.convert_To_Binary(decimal_num);
				SetConsoleTextAttribute(hConsole, 7);//white
				cout << endl << "---OCTAL-----------" << endl << endl;
				cout << "\t";
				decimal_to_ALL.convet_to_octal(decimal_num);
				SetConsoleTextAttribute(hConsole, 7);//white
				cout << endl << "---HEX-------------" << endl << endl;
				cout << "\t";
				decimal_to_ALL.convert_to_Hexadecimal(decimal_num);
				SetConsoleTextAttribute(hConsole, 7);//white
				cout << "\n##############################################################\n\n" << endl;
			}
			else
			{
				cin.clear();
				cin.ignore(INT_MAX, '\n');
				SetConsoleTextAttribute(hConsole, 4);//red
				cout << "Ops! This is not a Decimal number ! Try Again \n\n";
				SetConsoleTextAttribute(hConsole, 7);
			}
			break;
		case 2://FROM Binary

			cout << "Enter a Binary number \n\n";
			double binary_number, binary_holder;
			int binary_police;
			int binary_police_counter;
			if (cin >> binary_number)
			{
				binary_holder = binary_number;
				while (binary_holder != 0)
				{
					binary_police = fmod(binary_holder, 10);
					if (binary_police > 1)
					{
						binary_police2 = false;
						binary_police_counter++;
						break;
					}
					else if (binary_police_counter == 0)
					{
						binary_police2 = true;
					}
					binary_holder /= 10;
				}
				if (binary_police2 == true)
				{
					cout << "\n\nFROM (" << binary_number << ") Binary TO \n\n";
					cout << "##############################################################\n" << endl;
					SetConsoleTextAttribute(hConsole, 7);//white
					cout << "\n---------Decimal----------" << endl << endl;
					SetConsoleTextAttribute(hConsole, 5);
					cout << "\t(" << binary_to_ALL.convert_to_decimal(binary_number) << ")10\n";
					x = binary_to_ALL.convert_to_decimal(binary_number);
					SetConsoleTextAttribute(hConsole, 7);//white
					cout << "\n----------Octal-----------" << endl << endl;
					cout << "\t";
					decimal_to_ALL.convet_to_octal(x);
					SetConsoleTextAttribute(hConsole, 7);//white
					cout << "\n----------HEX-------------" << endl << endl;
					cout << "\t";
					decimal_to_ALL.convert_to_Hexadecimal(x);
					SetConsoleTextAttribute(hConsole, 7);//white
					cout << "\n##############################################################\n\n" << endl;
				}
				else
				{
					cin.clear();
					cin.ignore(INT_MAX, '\n');
					SetConsoleTextAttribute(hConsole, 4);//red
					cout << "Ops..! this is not binry Try Again \n\n";
					SetConsoleTextAttribute(hConsole, 7);
				}

			}
			else
			{
				cin.clear();
				cin.ignore(INT_MAX, '\n');
				SetConsoleTextAttribute(hConsole, 4);//red
				cout << "Ops..! this is not binry Try Again \n\n";
				SetConsoleTextAttribute(hConsole, 7);
			}


			break;
		case 3://FROM Octal
			cout << "Enter an Octal number\n";
			double octal_number,octal_holder;
			int octal_police, octal_police_counter;
			if (cin >> octal_number)
			{
				octal_holder = octal_number;
				
				for (int i = 0; i < sizeof(octal_holder); i++)
				{
					octal_police = (int)fmod(octal_holder, 10);
					octal_holder /= 10;
					if (octal_police == 9 || octal_police == 8)
					{
						octal_police2 = false;
						octal_police_counter++;
						break;
					}
					else if(octal_police_counter == 0)
					{
						octal_police2 = true;
					}
				}
				if (octal_police2 == true)
				{
					cout << "\n\nFORM (" << octal_number << ") Octal TO \n\n";
					cout << "\n##############################################################" << endl;
					SetConsoleTextAttribute(hConsole, 7);//white
					cout << "\n------------Decimal--------------\n\n";
					SetConsoleTextAttribute(hConsole, 1);//Blue
					cout << "( " << octal_to_ALL.convert_to_decimal(octal_number) << " )10" << endl;
					x = octal_to_ALL.convert_to_decimal(octal_number);
					SetConsoleTextAttribute(hConsole, 7);//white
					cout << "\n------------Binary---------------\n\n";
					decimal_to_ALL.convert_To_Binary(x);
					SetConsoleTextAttribute(hConsole, 7);//white
					cout << "\n--------------Hex----------------\n\n";
					decimal_to_ALL.convert_to_Hexadecimal(x);
					SetConsoleTextAttribute(hConsole, 7);//white
					cout << "\n##############################################################\n\n" << endl;
				}
				else
				{
					octal_police_counter = 0;
					cin.clear();
					cin.ignore(INT_MAX, '\n');
					SetConsoleTextAttribute(hConsole, 4);//red
					cout << "Ops..! this is not An Octal Try Again \n\n";
					SetConsoleTextAttribute(hConsole, 7);
				}
				
			}
			else
			{
				cin.clear();
				cin.ignore(INT_MAX, '\n');
				SetConsoleTextAttribute(hConsole, 4);//red
				cout << "Ops..! this is not An Octal Try Again \n\n";
				SetConsoleTextAttribute(hConsole, 7);
			}
			break;

		case 4://FROM Hexadecimal
			cout << "Enter a Hexadecimal number \n";
			cin >> hexadecimal_string;
			int hexadecimal_police;
			for (int i = 0; i < hexadecimal_string.size(); i++)
			{

				if (hexadecimal_string[i] == 'A' ||
					hexadecimal_string[i] == 'B' ||
					hexadecimal_string[i] == 'C' ||
					hexadecimal_string[i] == 'D' ||
					hexadecimal_string[i] == 'E' ||
					hexadecimal_string[i] == 'F' ||
					hexadecimal_string[i] == '0' ||
					hexadecimal_string[i] == '1' ||
					hexadecimal_string[i] == '2' ||
					hexadecimal_string[i] == '3' ||
					hexadecimal_string[i] == '4' ||
					hexadecimal_string[i] == '5' ||
					hexadecimal_string[i] == '6' ||
					hexadecimal_string[i] == '7' ||
					hexadecimal_string[i] == '8' ||
					hexadecimal_string[i] == '9' ||
					hexadecimal_string[i] == '.'
					) {
					if (hexadecimal_string == ".")
					{
						hexadecimal_police2 = false;
						break;
					}
					hexadecimal_police2 = true;
				//	break;
				}
				else 
				{
					hexadecimal_police2 = false;
					break;
				}
			}
			if (hexadecimal_police2 == true)
			{
				cout << "\n\nFROM (" << hexadecimal_string << ") Hexadecimal TO\n\n";
				cout << "##############################################################\n" << endl;
				cout << "\n------------Decimal--------------\n\n";
				SetConsoleTextAttribute(hConsole, 5);
				cout << "( " << hexadecimal_to_ALL.convert_to_decimal(hexadecimal_string) << " )10\n";
				SetConsoleTextAttribute(hConsole, 7);//white
				cout << "\n-----------Binary----------------\n\n";
				x = hexadecimal_to_ALL.convert_to_decimal(hexadecimal_string);
				decimal_to_ALL.convert_To_Binary(x);
				SetConsoleTextAttribute(hConsole, 7);//white
				cout << "\n-------------Octal---------------\n\n";
				decimal_to_ALL.convet_to_octal(x);
				SetConsoleTextAttribute(hConsole, 7);//white
				cout << "\n##############################################################\n\n" << endl;
				
			}
			else
			{
				hexadecimal_police = 0;
				cin.clear();
				cin.ignore(INT_MAX, '\n');
				SetConsoleTextAttribute(hConsole, 4);//red
				cout << "Ops..! this is not Hexadecimal Try Again \n\n";
				SetConsoleTextAttribute(hConsole, 7);
			}
			break;
		default:
			// this will never be called
			SetConsoleTextAttribute(hConsole, 4);//red
			cout << "NOT A Valid Option\n";
			SetConsoleTextAttribute(hConsole, 7);//white
			break;
		}

	}

	system("pause");
}