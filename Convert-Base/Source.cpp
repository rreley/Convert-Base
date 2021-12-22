#include <iostream>

int charToVal(char curChar)
{
	char convArray[] =
	{ '0','1', '2', '3', '4', '5', '6', '7', '8', '9','A', 'B', 'C', 'D', 'E', 'F' };
	for (int i = 0; i < 16; ++i)
	{
		if (curChar == convArray[i])
		{
			return i;
		}
	}
	return -1;
}

char valToChar(int val)
{
	char convArray[] =
	{ '0','1', '2', '3', '4', '5', '6', '7', '8', '9','A', 'B', 'C', 'D', 'E', 'F' };

	if (val < 16 && val >= 0)
	{
		return convArray[val];
	}
	return ' ';
}

bool convertToDecimal(char * gdstr, int length, int inConvertor, int & decimal)
{
	int factor = 1;
	decimal = 0;
	//std::cout << length;
	for (int i = length - 1; i >= 0; --i)
	{
		int curVal(charToVal(gdstr[i]));
		decimal += factor * curVal;
		factor *= inConvertor;
	}
	//std::cout << decimal << std::endl;
	return true;
}
bool convertFromDecimal(int  decimal, int outConvertor, char * outString, int & length)
{
	int fact = 1;
	length = 0;
	while (decimal > 0)
	{
		fact = decimal % outConvertor;
		char curChar(valToChar(fact));
		outString[length] = curChar;
		decimal /= outConvertor;
		length++;
	}
	return true;
}

int main()
{
	char out[50];
	int outLeng = 0;
	int decVal;
	int inLeng;
	std::cout << "Length of Value: ";
	std::cin >> inLeng;
	char *any;
	any = (char *)malloc(sizeof(char) * inLeng);
	for (int i = 0; i < inLeng; i++)
	{
		std::cout << "Enter the value in base: "; //each value is entered one by one as to store in array
		std::cin >> any[i];
	}
	int inType;
	std::cout << "Enter the base number system: ";
	std::cin >> inType;
	int outtype;
	std::cout << "Enter the target number system: ";
	std::cin >> outtype;
	convertToDecimal(any, inLeng, inType, decVal);
	convertFromDecimal(decVal, outtype, out, outLeng);
	std::cout << std::endl << "Your number in base " << inType << " is equal to ";
	for (int i = outLeng - 1; i >= 0; --i)
	{
		std::cout << out[i];
	}
	std::cout << " in base " << outtype << std::endl;
	free(any);
}
