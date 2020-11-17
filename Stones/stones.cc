

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <chrono>
#include <random>
#include <sstream>
#include <algorithm>
#include <chrono>


int WAI=0;
int WU=0;

//Input and check
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
					std::cout << "Input/Output error" << std::endl;
					std::exit(1);
				}
				std::cout << "Incorrect input" << std::endl;
				goto re;
			} else if (not inps.eof()) {
				std::cout << "Incorrect input" << std::endl;
				goto re;
			}
		}
	}


	return result;
}

int getAndCheckInRange(const char *question, int min, int max) {
	for (;;) {
		int returnInt = get_int(question);
		if (returnInt >= min && returnInt <= max) {
			return returnInt;
		}
		std::cout << "Введите подходящее число!" << std::endl;
		continue;
	}
	return 0;
}

int read_int_in_range(const char *question, int min, int max) {
	for (;;) {
		int returnInt = get_int(question);
		if (returnInt >= min && returnInt <= max) {
			return returnInt;
		}
		std::cout << "Input correct number!" << std::endl;
		continue;
	}
	return 0;
}


int main()
{

	qre1:using clk=std::chrono::system_clock;
	std::minstd_rand rnd { unsigned(clk::now().time_since_epoch().count()) };

	std::uniform_int_distribution <int> d{15,25};
	std::uniform_int_distribution <int> min_stone{1,3};
	unsigned stone_count = d(rnd);
	unsigned stone;
	int hard=1;

	for (;;) {

				std::cout << "МЕНЮ \n"
						"1 | Play \n"
						"2 | Difficulty \n"
						"3 | Statistic \n"
						"4 | Help \n"
						"5 | Exit" << std::endl;
				int intForSwitch = getAndCheckInRange("Select menu item", 1, 5);
				switch (intForSwitch) {
				case 1:
					goto qre2;
					break;
				case 2:
					std::cout << "Difficulty \n"
						"1 | Easy \n"
						"2 | Hard \n"
						 << std::endl;
					hard = getAndCheckInRange("Select difficulty", 1, 2);
					break;
				case 3:
					std::cout << "Statistic of wins \n"
								"USER | " << WU <<" \n"
								"AI | " << WAI <<" \n"
									<< std::endl;
					break;
				case 4:
					std::cout << "It is easy(no) game \n"
											"take 1-3 stones \n"
											"AI turn \n"
											"Repeat \n"
											"if you take last stone - AI WIN \n"
											"else - YOU" << std::endl;
					break;
				case 5:
					exit(0);
					break;
				}
			}
			return 0;


	do{

		qre2:if (stone_count==0){
				std::cout << "USER WIN!" << std::endl;
				::WU++;
				break;
				}
		if(stone_count==1){
					std::cout << "AI WIN!" << std::endl;
					::WAI++;
					break;
				}

		std::cout << "In heap " << stone_count << " stones." << std::endl;
		stone =read_int_in_range("How much take? (1-3) ",1,std::min(3U,stone_count));
		stone_count-=stone;
		//<algorithm

		if(stone_count==stone){
			std::cout << "AI WIN!" << std::endl;
			::WAI++;
			goto qre1;

		}

			qwe2:
			stone=min_stone(rnd);

			//Easy AI

			if (hard==1){
				if(stone<=3 && stone<=stone_count){
									stone_count-=stone;
							}
				else{
					goto qwe2;
						}
				std::cout << "Bot take " << stone << " stones." << std::endl;
				goto qre2;
			}

			//Hard AI
			if (hard==2){
				if(stone_count==3){
					stone=2;
					stone_count-=stone;
			}
				if(stone_count==2){
					stone=1;
					stone_count-=stone;
			}

			else if(stone_count>=4){
				switch ( stone_count%4 ) {
				case 0:
					stone=3;
					stone_count-=stone;
					break;
				case 1:
					stone=2;
					stone_count-=stone;
					break;
				case 2:
					stone=1;
					stone_count-=stone;
					break;
				case 3:
					stone=2;
					stone_count-=stone;
					break;



				  break;
				}

			}
			else if(stone_count==1){
				stone_count--;
				}
				std::cout << "Bot take " << stone << " stones." << std::endl;
				goto qre2;


	}
	} while(stone_count!=0);


		goto qre1;

	}

