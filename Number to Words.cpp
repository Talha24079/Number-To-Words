#include <iostream>
using namespace std;

string numberToWord(int num)
{
	if (num == 0)
		return "Zero";
	const string belowTwenty[] = { "Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine",
								  "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen","Eighteen", "Nineteen" };

	const string tens[] = { "", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety" };
	int count_And = 0;
	string result;
	if (num >= 1000)
	{
		result += belowTwenty[num / 1000] + " Thousand ";
		num %= 1000;
	}
	if (num >= 100)
	{
		result += belowTwenty[num / 100] + " Hundred ";
		num %= 100;
	}
	if (num >= 20)
	{
		if (num > 0)
		{
			result += "and ";
			count_And++;
		}
		result += tens[num / 10] + " ";
		num %= 10;
	}
	if (num > 0)
	{
		if (count_And == 0)
			result += "and ";
		result += belowTwenty[num] + " ";
	}
	return result;
}

int main() {
	int num;
	cout << "Enter a num: ";cin >> num;
	string numToWord = numberToWord(num);
	cout << "The number " << num << " in words is \"" << numToWord << "\b\"";
	return 0;
}