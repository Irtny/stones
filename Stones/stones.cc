/*
 * stones.cc
 *
 *  Created on: 11 ����. 2020 �.
 *      Author: ��������
 */


#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <chrono>
#include <random>
#include <sstream>
#include <algorithm>
#include <chrono>


//���� ������ � ��������
int get_int(const char *question) {
	int result;
	std::string inp;
	re: std::cout << question;
	std::getline(std::cin, inp);
	{
		std::stringstream inps { inp };
		inps >> result;
		{
			if (inps.fail()) {
				if (std::cin.eof()) {
					std::cout << "������ �����/������" << std::endl;
					std::exit(1);
				}
				std::cout << "������������ ����" << std::endl;
				goto re;
			} else if (not inps.eof()) {
				std::cout << "������������ ����" << std::endl;
				goto re;
			}
		}
	}


	return result;
}

int read_int_in_range(const char *question, int min, int max) {
	for (;;) {
		int returnInt = get_int(question);
		if (returnInt >= min && returnInt <= max) {
			return returnInt;
		}
		std::cout << "������� ���������� �����!" << std::endl;
		continue;
	}
	return 0;
}
int main()
{
	//���������� ��������� ���������� ��������� ������
	qre1:using clk=std::chrono::system_clock;
	std::minstd_rand rnd { unsigned(clk::now().time_since_epoch().count()) };

	std::uniform_int_distribution <int> d{15,25};
	std::uniform_int_distribution <int> min_stone{1,3};
	unsigned stone_count = d(rnd);
	unsigned stone;
	int hard;



	do{



		std::cout << "� ���� " << stone_count << " ������." << std::endl;
		stone =read_int_in_range("������� ������ �����? (�� 1 �� 3) ",1,std::min(3U,stone_count));
		stone_count-=stone;
		//<algorithm>


		{
			if (stone_count==0){
						std::cout << "�� �������!" << std::endl;
						break;
					}
					else if(stone_count==1){
						std::cout << "�� ��������!" << std::endl;
						break;
					}

			qwe1:stone=min_stone(rnd);

			//˸���� ��

			if (hard==0){
				if(stone<=3 && stone<=stone_count && stone>=1){
									stone_count-=stone;
							}
				else{// std::cout <<  << std::endl;
									goto qwe1;

							}
			}

			//C������ ��
			if (hard==1){
				if(stone<=3 && stone<=stone_count && stone>=1 && stone_count>8){
						stone_count-=stone;
			}
			else if(stone_count<=8){
				switch ( stone_count ) {
				case 8:
					stone=3;
					stone_count-=stone;
					break;
				case 7:
					stone=2;
					stone_count-=stone;
					break;
				case 6:
					stone=1;
					stone_count-=stone;
					break;
				case 5:
					stone=1;
					stone_count-=stone;
					break;
				case 4:
				  stone=3;
				  stone_count-=stone;
				  break;
				case 3:
					stone=2;
					stone_count-=stone;
				  break;
				case 2:
					stone=1;
					stone_count-=stone;


				  break;
				}
			}
			}

			else{// std::cout <<  << std::endl;
					goto qwe1;

			}

			//std::cout << stone_count << std::endl;
			std::cout << "��� ���� " << stone << " ������." << std::endl;
		}

	} while(stone_count!=0);
	int h;
	std::cout <<"������ �������? (1 - ��, 2 - ���)" <<std::endl;
	std::cin >>h;
	switch(h){
	case 1:
		goto qre1;
		break;
	case 2:
		exit(0);

	}

//	}
	return 0;
}

