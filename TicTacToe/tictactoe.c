#include <stdio.h>

void startGame();
void printGrid();
int checkWin();

int board[3][3] = {
    {-1, -1, -1},
    {-1, -1, -1},
    {-1, -1, -1}};

int main(int argc, char *argv[])
{
    printf("\t\tTicTacToe\t\t\n");
    printf("Player 1 (X)\t\t\t Player 2 (O)");
    startGame();
    printf("\n\t\tGame Over");
}

void startGame()
{
    printf("\n\nMemorize the location of each block shown\n");

    printf("\t1\t|\t2\t|\t3\n");
    printf("____________________________________________________\n");

    printf("\n\t4\t|\t5\t|\t6\n");
    printf("____________________________________________________\n");

    printf("\n\t7\t|\t8\t|\t9\n");

    int winStatus = 0;
    int cntBlock = 1;

    _Bool flag = 1;

    while (winStatus == 0 && cntBlock <= 9)
    {
        int blockNum;
        char move = flag == 1 ? 'X' : 'O';
        printf("\n%c's Move\n", move);
        printf("Enter Block Number = ");
        scanf("%d", &blockNum);

        switch (blockNum)
        {
        case 1:
            if (board[0][0] == -1)
            {
                board[0][0] = flag;
                cntBlock++;
            }
            else
            {
                printf("Block already filled! Try again.\n");
                continue;
            }
            break;

        case 2:
            if (board[0][1] == -1)
            {
                board[0][1] = flag;
                cntBlock++;
            }
            else
            {
                printf("Block already filled! Try again.\n");
                continue;
            }
            break;
        case 3:
            if (board[0][2] == -1)
            {
                board[0][2] = flag;
                cntBlock++;
            }
            else
            {
                printf("Block already filled! Try again.\n");
                continue;
            }
            break;
        case 4:
            if (board[1][0] == -1)
            {
                board[1][0] = flag;
                cntBlock++;
            }
            else
            {
                printf("Block already filled! Try again.\n");
                continue;
            }
            break;
        case 5:
            if (board[1][1] == -1)
            {
                board[1][1] = flag;
                cntBlock++;
            }
            else
            {
                printf("Block already filled! Try again.\n");
                continue;
            }
            break;
        case 6:
            if (board[1][2] == -1)
            {
                board[1][2] = flag;
                cntBlock++;
            }
            else
            {
                printf("Block already filled! Try again.\n");
                continue;
            }
            break;
        case 7:
            if (board[2][0] == -1)
            {
                board[2][0] = flag;
                cntBlock++;
            }
            else
            {
                printf("Block already filled! Try again.\n");
                continue;
            }
            break;
        case 8:
            if (board[2][1] == -1)
            {
                board[2][1] = flag;
                cntBlock++;
            }
            else
            {
                printf("Block already filled! Try again.\n");
                continue;
            }
            break;
        case 9:
            if (board[2][2] == -1)
            {
                board[2][2] = flag;
                cntBlock++;
            }
            else
            {
                printf("Block already filled! Try again.\n");
                continue;
            }
            break;

        default:
            printf("\nEnter a Valid Number\n");
            continue;
        }

        flag = flag == 1 ? 0 : 1;

        printGrid();
        winStatus = checkWin();
    }
}

void printGrid()
{

    printf("_________________________________________________\n\n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            char ch;
            if (board[i][j] == 0)
            {
                ch = 'O';
            }

            else if (board[i][j] == 1)
            {
                ch = 'X';
            }

            else
                ch = ' ';

            printf("|\t%c\t|", ch);
        }
        printf("\n_________________________________________________\n\n");
    }
}

int checkWin()
{
    for (int i = 0; i < 3; i++)
    {
        if (board[i][0] != -1 && board[i][0] == board[i][1] && board[i][1] == board[i][2])
        {
            if (board[i][0] == 1)
                printf("Player 1 Wins");
            else
                printf("Player 2 Wins");
            return 1;
        }

        if (board[0][i] != -1 && board[0][i] == board[1][i] && board[1][i] == board[2][i])
        {
            if (board[0][i] == 1)
                printf("Player 1 Wins");
            else
                printf("Player 2 Wins");
            return 1;
        }
    }

    if (board[0][0] != -1 && board[0][0] == board[1][1] && board[1][1] == board[2][2])
    {
        if (board[0][0] == 1)
            printf("Player 1 Wins");
        else
            printf("Player 2 Wins");
        return 1;
    }

    if (board[0][2] != -1 && board[0][2] == board[1][1] && board[1][1] == board[2][0])
    {
        if (board[0][2] == 1)
            printf("Player 1 Wins");
        else
            printf("Player 2 Wins");
        return 1;
    }

    return 0;
}
