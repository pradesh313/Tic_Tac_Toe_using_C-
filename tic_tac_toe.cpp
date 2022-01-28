#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<process.h>
#include<dos.h>
#include<string.h>

char square[10] = {'0','1','2','3','4','5','6','7','8','9'};
char play_n[3][100],play_city[3][100];
char load[42]={'-',' ','-',' ','-',' ','-',' ','-',' ','-',' ','-',' ','-',' ','-',' ','-',' ','-',' ','-',' ','-',' ','-',' ','-',
' ','-',' ','-',' ','-',' ','-',' ','-',' '};
int play_age[3];


void start_screen();
void rules_screen();
void player_1();
void player_2();
void loading();
int game_screen();
int checkwin();
void board();

// main function
int main()
 {
   start_screen();
   rules_screen();
   player_1();
   player_2();
   loading();
   game_screen();
   return 0;
 }


//Funtion to show the Starting Screen
void start_screen()
 {
   clrscr();
   cout<<"\n\n\t\t\t  Welcome to TIC TAC TOE ";
   cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t  Press any key to continue";
   getch();
 }





//Function to display the rules
void rules_screen()
 {
   clrscr();
   cout<<"\n\n\t\t\t   Rules and regulations";
   cout<<"\n\n\n 1) The game is played on a grid that's 3 squares by 3 squares.";
   cout<<"\n\n 2) Player 1 is X, Player 2 is O.";
   cout<<"\n\n 3) Players take turns putting their marks in numbered squares.";
   cout<<"\n\n 4) The first player to get 3 of her marks in a row is the winner.";
   cout<<"\n\n 5) When all 9 squares are full, the game ends in a tie.";
   cout<<"\n\n\n\n\n\n\n\t\t\t  Press any key to continue";
   getch();
 }


//Function to get the details of player 1
void player_1()
 {
   clrscr();
   cout<<"\n\n\t\t\t   Enter the details of Player 1";
   cout<<"\n\n\n";

   cout<<" Enter your name (max 100 characters): ";
   gets(play_n[1]);

   cout<<"\n\n Enter your age: ";
   cin>>play_age[1];

   if(play_age[1]>100||play_age[1]<1)
     {
       cout<<"\n\n\n\n\n\n\n\t\t           Your age is not a valid age";
       cout<<"\n\n\t\t\t      Press any key to exit";
       getch();
       exit(0);
     }

   cout<<"\n\n Enter your city (max 50 characters): ";
   gets(play_city[1]);

   cout<<"\n\n\n\n\n\n\n\t\t\t  Press any key to continue";
   getch();
 }


//Function to get the details of player 2
void player_2()
 {
   clrscr();
   cout<<"\n\n\t\t\t   Enter the details of Player 2";
   cout<<"\n\n\n";

   cout<<" Enter your name (max 100 characters): ";
   gets(play_n[2]);

   cout<<"\n\n Enter your age: ";
   cin>>play_age[2];

   if(play_age[2]>100||play_age[2]<1)
     {
       cout<<"n\n\n\n\n\n\n\t\t           Your age is not a valid age";
       cout<<"\n\n\t\t\t      Press any key to exit";
       getch();
       exit(0);
     }

   cout<<"\n\n Enter your city (max 50 characters): ";
   gets(play_city[2]);

   cout<<"\n\n\n\n\n\n\n\t\t\t  Press any key to continue";
   getch();
 }


//Function to show the loading screen
void loading()
 {
   clrscr();

   for(int k=0;k<=4;k++)
      {
	for(int i=0;i<41;i++)
	   {
		 clrscr();
		 cout<<"\n\n\n\n\n\n\n\n\n\t\t\t\t    LOADING\n\n";
		 cout<<"\t\t     ";
		 for(int j=0;j<=i;j++)
		    {
			 cout<<load[j];
		    }
		 delay(20);
	   }
      }

   cout<<"\n\n\n\n\n\n\t\t\t       Your game is ready";
   cout<<"\n\n\t\t\t    Press any key to continue";
   getch();
 }


//Function to show the game screen
int game_screen()
 {
   clrscr();
   int player = 1,i,choice;
   char mark;

   do
     {
	 clrscr();
	 board();
	 player=(player%2)?1:2;

	 cout << play_n[player]<<  ", please enter a number:  ";
	 cin >> choice;

	 mark=(player == 1) ? 'X' : '0';

	 if (choice == 1 && square[1] == '1')
		square[1] = mark;
	 else if (choice == 2 && square[2] == '2')
		square[2] = mark;
	 else if (choice == 3 && square[3] == '3')
		square[3] = mark;
	 else if (choice == 4 && square[4] == '4')
		square[4] = mark;
	 else if (choice == 5 && square[5] == '5')
		square[5] = mark;
	 else if (choice == 6 && square[6] == '6')
		square[6] = mark;
	 else if (choice == 7 && square[7] == '7')
		square[7] = mark;
	 else if (choice == 8 && square[8] == '8')
		square[8] = mark;
	 else if (choice == 9 && square[9] == '9')
		square[9] = mark;
	 else
	      {
		cout<<"You have given an invalid move ";
		player--;
		cin.ignore();
		cin.get();
	      }
	i=checkwin();
	player++;
	}
	while(i==-1);
   clrscr();
   board();

   if(i==1)
     {
	 cout<<"==> Congrats "<<play_n[--player]<<" , you win the game ";
	 cout<<"\n==> Your prize will be given to "<<play_city[player]<<" city centre";
	 cout<<"\n==> Say your real age "<<play_age[player]<<" and collect it!!";
     }
   else
	 cout<<"\n  ==> Oops , the Game drawn";
   cout<<"\n\n\n\t\t\t      Press any key to exit";
   getch();
   return 0;
 }
//Function to check whether the game is won by the player
int checkwin()
 {
	if (square[1] == square[2] && square[2] == square[3])
		return 1;
	else if (square[4] == square[5] && square[5] == square[6])
		return 1;
	else if (square[7] == square[8] && square[8] == square[9])
		return 1;
	else if (square[1] == square[4] && square[4] == square[7])
		return 1;
	else if (square[2] == square[5] && square[5] == square[8])
		return 1;
	else if (square[3] == square[6] && square[6] == square[9])
		return 1;
	else if (square[1] == square[5] && square[5] == square[9])
		return 1;
	else if (square[3] == square[5] && square[5] == square[7])
		return 1;
	else if (square[1] != '1' && square[2] != '2' && square[3] != '3' && square[4] != '4' && square[5] != '5' && square[6] != '6' && square[7] != '7' && square[8] != '8' && square[9] != '9')
		return 0;
	else
		return -1;
 }


//Function to show the Tic-Tac-Toe board
void board()
 {
   cout << "\n\n\t\t\t\t  Tic Tac Toe\n\n";
   cout << endl;
   cout << "\t\t\t            |     |     " << endl;
   cout << "\t\t\t         " << square[1] << "  |  " << square[2] << "  |  " << square[3] << endl;
   cout << "\t\t\t       _____|_____|_____" << endl;
   cout << "\t\t\t            |     |     " << endl;
   cout << "\t\t\t         " << square[4] << "  |  " << square[5] << "  |  " << square[6] << endl;
   cout << "\t\t\t       _____|_____|_____" << endl;
   cout << "\t\t\t            |     |     " << endl;
   cout << "\t\t\t         " << square[7] << "  |  " << square[8] << "  |  " << square[9] << endl;
   cout << "\t\t\t            |     |     " << endl << endl;
   cout << play_n[1] <<" -(X) \n"<< play_n[2] <<" -(0)" << endl << endl;
 }
