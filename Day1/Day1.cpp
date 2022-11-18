// Day1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stdint.h>

#define UP '('
#define DOWN ')'

int8_t part1()
{
	std::ifstream inputfile;
	std::string line;
	std::vector<char> ch;
	uint32_t floor = 0;

	inputfile.open("day1.txt");
	if (inputfile.is_open())
	{
		while (std::getline(inputfile, line, '\n'))
		{
			std::copy(line.begin(), line.end(), std::back_inserter(ch));
		}
	}
	else 
	{
		std::cout << "File not found. Exiting\n";
		return -1;
	}

	for (size_t i = 0; i < ch.size(); i++)
	{
		switch (ch[i])
		{
			case UP:
				floor++;
				break;
			case DOWN:
				floor--;
				break;
			default:
				break;
		}
	}

	std::cout << "Ending on floor: " << floor << "\n";

	inputfile.close();

	return 0;
}

int8_t part2() 
{
	std::ifstream inputfile;
	std::string line;
	std::vector<char> ch;
	int32_t floor = 0;
	uint32_t floor_count = 0;

	inputfile.open("day1.txt");
	if (inputfile.is_open())
	{
		while (std::getline(inputfile, line, '\n'))
		{
			std::copy(line.begin(), line.end(), std::back_inserter(ch));
		}
	}
	else 
	{
		std::cout << "File not found. Exiting\n";
		return -1;
	}

	for (size_t i = 0; i < ch.size(); i++)
	{
		switch (ch[i])
		{
			case UP:
				floor++;
				break;
			case DOWN:
				floor--;
				break;
			default:
				break;
		}
		floor_count++;

		if (floor < 0) break;
	}

	std::cout << "Elevator enters the basement on turn: " << floor_count << "\n";

	inputfile.close();

	return 0;
}

int main()
{
	const uint8_t day = 2;
	errno_t retcode = 0;

	switch (day)
	{
		case 1:
			retcode = part1();
			break;
		case 2:
			retcode = part2();
			break;
		default:
			break;
	}

	if (retcode != 0)
		return -1;

	return 0;
}