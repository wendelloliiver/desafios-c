#include <cs50.h>
#include <stdio.h>
#include <string.h>

void board(void);
void gameplay(void);	

int main(void)
{
	gameplay();
}

void board(void)
{
	int count = 1;

	for(int i = 0; i < 3; i++)
	{
		printf("|");
		for(int j = 0; j < 3; j++)
		{
			printf("%i", count);		
			printf("|");

			count++;
		}
		printf("\n");
	}
}

void title(void)
{
	printf("---------------------------\n");
	printf("------ Jogo Da Velha ------\n");
	printf("---------------------------\n");

}

void gameplay(void)
{
	string drawBoard[8];

	bool playerOne = true;
	bool playerTwo = false;

	drawBoard[0] = "1";
	drawBoard[1] = "2";
	drawBoard[2] = "3";
	drawBoard[3] = "4";
	drawBoard[4] = "5";
	drawBoard[5] = "6";
	drawBoard[6] = "7";
	drawBoard[7] = "8";
	drawBoard[8] = "9";

	bool hasWinner = false;

	title();
	board();

	while(true)
	{
		int value;

		if(playerOne)
			printf("Vez do jogador (X)!\n");
		else
			printf("Vez do jogador (O)!\n");

		printf("Escolha um valor: ");
		scanf("%i", &value);

		if(drawBoard[value - 1] != "X" || drawBoard[value -1] != "O")
		{
			if(drawBoard[value - 1] == "X" || drawBoard[value - 1] == "O")
			{
				printf("Escolha um local vazio!\n");
			}
			else
			{
				if(playerOne)
				{
					playerOne = false;
					playerTwo = true;
					drawBoard[value-1] = "X";
				}
				else
				{
					playerOne = true;
					playerTwo = false;
					drawBoard[value-1] = "O";
				}
			}
		}


		for(int i = 0; i < 9; i++)
		{
			printf("|");
			printf("%s", drawBoard[i]);
			if(i == 2 || i == 5 || i == 8)
			{
				printf("|\n");
			}
		}

		// checar condição de vitoria horizontal! (X)
		if(drawBoard[0] == "X" && drawBoard[1] == "X" && drawBoard[2] == "X")
		{
			printf("O jogador X é o vencedor!\n");
			break;
		}
		else if(drawBoard[3] == "X" && drawBoard[4] == "X" && drawBoard[5] == "X")
		{
			printf("O jogador X é o vencedor!\n");
			break;
		}
		else if(drawBoard[6] == "X" && drawBoard[7] == "X" && drawBoard[8] == "X")
		{
			printf("O jogador X é o vencedor!\n");
			break;
		}

		// checar condição de vitoria horizontal! (O)
		if(drawBoard[0] == "O" && drawBoard[1] == "O" && drawBoard[2] == "O")
		{
			printf("O jogador O é o vencedor!\n");
			break;
		}
		else if(drawBoard[3] == "O" && drawBoard[4] == "O" && drawBoard[5] == "O")
		{
			printf("O jogador O é o vencedor!\n");
			break;
		}
		else if(drawBoard[6] == "O" && drawBoard[7] == "O" && drawBoard[8] == "O")
		{
			printf("O jogador O é o vencedor!\n");
			break;
		}

		// checar condicao de vitoria vertical! (X)
		if(drawBoard[0] == "X" && drawBoard[3] == "X" && drawBoard[6] == "X")
		{
			printf("O jogador X é o vencedor!\n");
			break;
		}
		else if(drawBoard[1] == "X" && drawBoard[4] == "X" && drawBoard[7] == "X")
		{
			printf("O jogador X é o vencedor!\n");
			break;
		}
		else if(drawBoard[2] == "X" && drawBoard[5] == "X" && drawBoard[8] == "X")
		{
			printf("O jogador X é o vencedor!\n");
			break;
		}

		// checar condicao de vitoria vertical! (O)
		if(drawBoard[0] == "O" && drawBoard[3] == "O" && drawBoard[6] == "O")
		{
			printf("O jogador O é o vencedor!\n");
			break;
		}
		else if(drawBoard[1] == "O" && drawBoard[4] == "O" && drawBoard[7] == "O")
		{
			printf("O jogador O é o vencedor!\n");
			break;
		}
		else if(drawBoard[2] == "O" && drawBoard[5] == "O" && drawBoard[8] == "O")
		{
			printf("O jogador O é o vencedor!\n");
			break;
		}

		// checar condição de vitoria diagonal! (X)
		if(drawBoard[0] == "X" && drawBoard[4] == "X" && drawBoard[8] == "X")
		{
			printf("O jogador X é o vencedor!\n");
			break;
		}
		else if(drawBoard[2] == "X" && drawBoard[4] == "X" && drawBoard[6] == "X")
		{
			printf("O jogador X é o vencedor!\n");
			break;
		}

		// checar condição de vitoria diagonal! (O)
		if(drawBoard[0] == "O" && drawBoard[4] == "O" && drawBoard[8] == "O")
		{
			printf("O jogador O é o vencedor!\n");
			break;
		}
		else if(drawBoard[2] == "O" && drawBoard[4] == "O" && drawBoard[6] == "O")
		{
			printf("O jogador O é o vencedor!\n");
			break;
		}

		if(value <= 0)
		{
			break;
		}
	}
}
