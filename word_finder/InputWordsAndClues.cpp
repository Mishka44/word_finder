#include <iostream>
#include <random>
#include <fstream>
#include <string>
#include <sstream>
#include "InputWordsAndClues.hpp"

void InputWordsAndClues(std::string *arr) { // ������ ��� ���� ���� �������� ������ � ������ � ���������
	const std::string fileName = "Words.txt";
	std::ifstream wordsRand(fileName);
	
	if (!wordsRand.is_open())
	{
		//���� ����� ������� ����� ������
	}
	else {
		int line = rand() % 3;//������ �������� ���-�� �������
		std::string currentLine;
		int counter=0;

		for (int i = 0; i < arr->size(); i++)//������� ������ ������-��� push_back() ��� ��������� �������, �� �� ��������
		{
			if (arr[i] != "")
			{
				arr[i] = "";
			}
		}

		while (std::getline(wordsRand, currentLine) && ++counter <= line) {
			if (counter==line)
			{
				int i = 0;
				for (char splitString : currentLine)//��� ��� string ��� ������ char-�� �� ���������� �� ����
				{
					if (splitString == *(",")) {	//���� splitString ����� ������� �� ������ ������ ��� ���������� ������ ������ ������� �����������
						i++;
						continue; //contune ��� ���� ���� � �����/�������� �� ������������ �������
					}
					arr[i].push_back(splitString);//���������� �� �������� ��� ��� ���������� char-�� � �� ����� �������
				}

			}
		}
	}

	wordsRand.close();
}