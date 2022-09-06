#include <iostream>
#include <array>


void print_table(std::array<char, 9>&table)
{
	
		std::cout << table[0] << ".|." << table[ 1] <<".|." << table[2] << std::endl;
		std::cout<<"----------" << std::endl;
		std::cout << table[3] << ".|." << table[4] << ".|." << table[5] << std::endl;
		std::cout <<"---------" << std::endl;
		std::cout << table[6] << ".|." << table[7] << ".|." << table[8] << std::endl;
}

int valid_cor(std::array<char,9>polje)
{
	int cordinate;
	bool not_valid;

	do
	{
		not_valid = 0;
		std::cout << "Insert cordinate 1-9" << std::endl;
		std::cin >> cordinate;
		not_valid = ((cordinate < 1 || cordinate>9) || (cordinate + '0') != polje[cordinate - 1]);

	} while (not_valid);

	return cordinate;
}

bool victory_check (std::array<char,9> polje)
{

	if ( // reci
		polje[0] == polje[1] && polje[1] == polje[2]
		|| polje[3] == polje[4] && polje[4] == polje[5]
		|| polje[6] == polje[7] && polje[7] == polje[8]
		// stupci
		|| polje[0] == polje[3] && polje[3] == polje[6]
		|| polje[1] == polje[4] && polje[4] == polje[7]
		|| polje[2] == polje[5] && polje[5] == polje[8]
		// dijagonale
		|| polje[0] == polje[4] && polje[4] == polje[8]
		|| polje[2] == polje[4] && polje[4] == polje[6]
		)
	{
		return true;
	}
	return 0;
}

int main()
{

	std::array<char, 9>table;
	for (int i = 0; i < 9; i++)
		table[i] = i + '1';
	print_table(table);
	const char ZNAK1 = 'X';
	const char ZNAK2 = 'O';
	

	int cordinate;
		bool igra_traje;
		int potezi = 0;
		do
		{
			igra_traje = 0;
			cordinate = valid_cor(table);

			table[cordinate - 1] = ZNAK1;
			print_table(table);
			
			potezi++;
			
			bool victory_check2 = victory_check(table);
			if (victory_check2)
			{
				std::cout << " Winner is player 1." << std::endl;
				break;

			}

			int unesena_kordinata2 = valid_cor(table);
			table[unesena_kordinata2 - 1] = ZNAK2;
			print_table(table);
			potezi++;
			
			bool victory_checkk = victory_check(table);
			if (victory_checkk)
			{
				std::cout << " Winner is player 2" << std::endl;
			}

			igra_traje = potezi < 9 && !(victory_checkk || victory_check2);

		} while (igra_traje);






	



	
		


	return 0;
}