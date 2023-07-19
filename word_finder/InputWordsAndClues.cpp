#include <iostream>
#include <random>
#include <fstream>
#include <string>
#include <sstream>
#include "InputWordsAndClues.hpp"

void InputWordsAndClues(std::string *arr) { // массив для того чтоб записать вместе с словом и подсказки
	const std::string fileName = "Words.txt";
	std::ifstream wordsRand(fileName);
	
	if (!wordsRand.is_open())
	{
		//надо будет сделать вывод ошибки
	}
	else {
		int line = rand() % 3;//ввести конечное кол-во строчек
		std::string currentLine;
		int counter=0;

		for (int i = 0; i < arr->size(); i++)//очищаем массив потому-что push_back() лиш добавляет элемент, но не заменяет
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
				for (char splitString : currentLine)//так как string это массив char-ов мы проходимся по нему
				{
					if (splitString == *(",")) {	//если splitString равна запятой мы меняем индекс для заполнения другой ячейки другими подсказками
						i++;
						continue; //contune для того чтоб в слова/посказки не записывалась запятая
					}
					arr[i].push_back(splitString);//записываем по смвольно так как проходимся char-ом а не целой строкой
				}

			}
		}
	}

	wordsRand.close();
}