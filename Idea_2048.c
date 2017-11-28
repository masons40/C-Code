#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

/*
Game based upon teh popular app game 2048,this is the chemistry version.
it works by adding the elements of the of same type to create the next highest element ,e.g H+H = He.
each element is represent by a number which is divisable by 2, when adding the element the numbers are added,ie.H=2 , He =4.
to win you must get to element Ne which equivalent to 2048.

Controls: 8 = up, 4 = left, 6 = right, 2 = down.
Press enter when selecting a move.

*/


void intialize(int array[6][6]);//initialize's the array and sets a border
void print(int array[6][6]);//prints out the array 
int random(int i);//return a number,either 2 or 4
void movement(int array[6][6]);
void after_move(int array[6][6]);
int check_bound(int array[6][6]);
int check_win(int array[6][6]);

int main()
{
	srand(time(NULL));
	int array[6][6];
	intialize(array);
	int n=1;
	while(n)
	{
		system("cls");
		print(array);
		movement(array);
		after_move(array);//puts a new element in a position after every move
		n = check_bound(array);
		n = check_win(array);
	}
}

void intialize(int array[6][6])
{
	int n,m;
	for(int i=0;i<6;i++)//initialize 6x6 to 0,this allows for a border to be made
	{
		for(int j=0;j<6;j++)
		{
			array[i][j] = 1;
		}
	}
	for(int i=1;i<5;i++)//code for center 4x4
	{
		for(int j=1;j<5;j++)
		{
			array[i][j] = 0;
		}
	}
	int cont =1;
	int counter=0;
	while(cont)//then 
	{
		n =random(1);
		m =random(1);
		if(array[n][m] == 0)
		{
			array[n][m] = random(0);
			counter++;
			if(counter == 2)
			{
				cont =0;
			}
		}
	}
}
void after_move(int array[6][6])
{
	int cont =1;
	int counter=0;
	int n,m;
	while(cont)
	{
		n =random(1);
		m =random(1);
		if(array[n][m] == 0)
		{
			array[m][n] = random(0);
			counter++;
			if(counter == 1)
			{
				cont =0;
			}
		}
	}
}

void print(int array[6][6])//prints the game
{
	for(int o=1;o<5;o++)//code for center 4x4
	{
		for(int p=1;p<5;p++)//scans through the array to number in each position and replace it with the corrisponding Element
		{
			if(array[o][p] == 2)
			{
				printf("H   ");
			}else if(array[o][p] == 0)
			{
				printf("-   ");
			}
			else if(array[o][p] == 4)
			{
				printf("He  ");
			}
			else if(array[o][p] == 8)
			{
				printf("Li  ");
			}else if(array[o][p] == 16)
			{
				printf("Be  ");
			}else if(array[o][p] == 32)
			{
				printf("B   ");
			}else if(array[o][p] == 64)
			{
				printf("C   ");
			}else if(array[o][p] == 128)
			{
				printf("N   ");
			}else if(array[o][p] == 256)
			{
				printf("O   ");
			}else if(array[o][p] == 512)
			{
				printf("F   ");
			}else if(array[o][p] == 1024)
			{
				printf("Ne  ");
			}else if(array[o][p] == 2048)
			{
				printf("Ne  ");
			}
		}
		printf("\n\n");
	}
}
int check_bound(int array[6][6])
{
	int up,down,left,right; //checks boundaries 
	int counter =0;
	for(int o=1;o<5;o++)//code for center 4x4
	{
		for(int p=1;p<5;p++)
		{
			up=o;
			down=o;
			left=p;
			right=p;
			up+=1;
			down-=1;
			right+=1;
			left-=1;
			if(array[up][p] == array[o][p] || array[down][p] == array[o][p] || array[right][p] == array[o][p] || array[left][p] == array[o][p])
			{
				return 1;
			}else
			{
				counter++;
			}
		}
	}
	if(counter == 16)
	{
		return 0;
	}
}

int check_win(int array[6][6])
{
	for(int o=1;o<5;o++)
	{
		for(int p=1;p<5;p++)
		{
			if(array[o][p] == 2048)//scans the array for 2038 , if found you win
			{
				printf("Winner!!!!");
				return 0;
			}else
			{
				return 1;
			}
		}
	}
}

int random(int i) //random number 2 or 4 
{
	int arr[10] = {2,2,2,2,4,2,2,2,2,2};//allows for a 10% chance of getting a random 4 on the grid
	int x;
	switch(i)
	{
		case 0:
			x = rand()%10;
			return arr[x];
			break;
		case 1:
			x = (rand()%4) + 1;
			return x;
			break;
	}
}

void movement(int array[6][6])
{
	int checkarray[4] = {2,4,6,8};
	int n,i=0;
	int cont=1;
	int check=0;
	while(cont)
	{
		printf("\nMove:");
		scanf("%d",&n);
		while(i<4)
		{
			if(n == checkarray[i])
			{
				check++;
			}
			i++;
		}
		if(check == 1)
		{
			cont =0;
		}else
		{
			cont =1;
		}
		i=0;
	}

	int q,r;
	int tmp;
	
	//notice left and right are inverted for this part of the code
	
	//left
	if(n == 6)
	{
		for(int o=4;o>=1;o--)//code for center 4x4
		{
			for(int p=4;p>=1;p--)
			{
				if(array[o][p] != 0)
				{
					q=p;
					q++;
					r=p;
					if(array[o][q] == array[o][p])//adds together teh two squares if equal
					{
						array[o][q] += array[o][p];
						array[o][p] = 0;
					}else
					{
						while(array[o][q] == 0)//else if the next square is empty if changes current element to the empty space, continues to do this until it reaches the border
						{
							tmp = array[o][r];
							array[o][r] = array[o][q];
							array[o][q] = tmp;
							q++;
							r++;
						}
					}
				}
			}
		}
	}
	//right
	if(n == 4)
	{
		for(int o=1;o<5;o++)//code for center 4x4
		{
			for(int p=1;p<5;p++)
			{
				if(array[o][p] != 0)
				{
					q=p;
					q--;
					r=p;
					if(array[o][q] == array[o][p])
					{
						array[o][q] += array[o][p];
						array[o][p] = 0;
					}else
					{
						while(array[o][q] == 0)
						{
							tmp = array[o][r];
							array[o][r] = array[o][q];
							array[o][q] = tmp;
							q--;
							r--;
						}
					}
				}
			}
		}
	}
	//up
	if(n == 8)
	{
		for(int o=1;o<5;o++)//code for center 4x4
		{
			for(int p=1;p<5;p++)
			{
				if(array[o][p] != 0)
				{
					q=o;
					q--;
					r=o;
					if(array[q][p] == array[o][p])
					{
						array[q][p] += array[o][p];
						array[o][p] =0;
					}
					while(array[q][p] == 0)
					{
						tmp = array[r][p];
						array[r][p] = array[q][p];
						array[q][p] = tmp;
						q--;
						r--;
					}
				}
			}
		}
	}
	//down
	if(n == 2)
	{
		for(int o=4;o>=1;o--)//code for center 4x4
		{
			for(int p=4;p>=1;p--)
			{
				if(array[o][p] != 0)
				{
					q=o;
					q++;
					r=o;
					if(array[q][p] == array[o][p])
					{
						array[q][p] += array[o][p];
						array[o][p] = 0;
					}
					while(array[q][p] == 0)
					{
						tmp = array[r][p];
						array[r][p] = array[q][p];
						array[q][p] = tmp;
						q++;
						r++;
					}
				}
			}
		}
	}
}