#include <iostream>
#include <array>
#include <vector>

 const int rand_num = 6;


std::array<int,rand_num> validation(const int &down,const int &up)
{
	std::array<int, rand_num>num;
	
	bool same_as_previous = 0;
	bool range = 0;
	for(int i=0; i<rand_num; i++)
	do
	{
		same_as_previous = 0;
		
		do
		{
			range = false;//reset 
			std::cout << "Insert "<<i+1. <<" number" << std::endl;
			std::cin >> num[i];
			range = num[i]<down || num[i]> up;
			if (range)
				std::cout << "Number out of range, try again!" << std::endl;

		} while (range);

		for (int j = 0; j < i; j++)
			if (num[i] == num[j])
				same_as_previous = 1;
		if (same_as_previous)
			std::cout << "You have already entered that number ";
		
	} while (same_as_previous);

	return num;

}

std::array<int, rand_num> validation2(const int& down, const int& up)
{
	std::array<int, rand_num>num;
	srand(time(NULL)); rand(); rand();
	bool same_as_previous = 0;
	bool range = 0;
	for (int i = 0; i < rand_num; i++)
		do
		{
			same_as_previous = 0;

			do
			{
				range = false;//reset 
				num[i] = rand() % up + 1;
				range = num[i]<down || num[i]> up;
				

			} while (range);

			for (int j = 0; j < i; j++)
				if (num[i] == num[j])
					same_as_previous = 1;
		

		} while (same_as_previous);

		return num;

}




void print(std::array<int, rand_num>nums)
{
	std::cout << "Your numbers" << std::endl;
	std::cout << "--------------" << std::endl;
	for (auto el : nums)
		std::cout << el << ",";

	std::cout << std::endl;
}

void print2(std::array<int, rand_num>nums)
{
	std::cout << "Random numbers" << std::endl;
	std::cout << "--------------" << std::endl;
	for (auto el : nums)
		std::cout << el << ",";
	std::cout << std::endl;
}

std::vector<int>compare(const std::array<int, rand_num>& player, const std::array<int, rand_num>& rand_)
{
	std::vector<int>bingo;
	int number_of_bingo = 0;
	for (int i = 0; i < rand_num; i++)
	{
		for (int j = 0; j < i; j++)
			if (player[i] == rand_[j])
			{
				bingo.push_back({ player[i] });
				number_of_bingo++;

			}
			
	}
	std::cout << "Number of bingo->" << number_of_bingo << std::endl;
	return bingo;

}




int main2()
{
	const int up_limit = 25;
	const int down_limit = 10;
	

	
	std::array<int,rand_num>valid_player_nums;
	std::array<int, rand_num>random_get_num;
	
	//Players numbers

	valid_player_nums = validation(down_limit, up_limit);
	print(valid_player_nums);

	random_get_num = validation2(down_limit, up_limit);


	print2(random_get_num);


	auto bingo = compare(valid_player_nums, random_get_num);

	std::cout << "These are bingo numbers" << std::endl;
	std::cout << "-----------------------" << std::endl;
	for (auto el : bingo)
		std::cout << el << ",";
	


return 0;
}

