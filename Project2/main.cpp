/*
  Joseph Reimbold
  11/28/2013
  Project 2: Tic Tac Toe: Now with AI!
*/

//Libraries
#include <iostream>
using namespace std;

//No Globals

//Function Prototypes
void gameBoard(char,char,char,char,char,char,char,char,char,char);//Draws the game board

//Begin Execution Here
int main(int argc, char *argv[])
{
    //Declare Variables
    char board[10]={'0','1','2','3','4','5','6','7','8','9'}; //Board spaces
    short state=0; //Variable to track if game is over 0=no, 1=over, 2=draw;
    char space; //Board Selection space
    char choice='y'; //Play again?
    short player=1; //Determines which player's turn is happening
    char plyrMrk='X'; //Bases the X or O off player #
    
    //Introduce game
    cout<<"Play Tic Tac Toe!"<<endl;
    cout<<"This game is meant for two players."<<endl;
    
    do{//Loop if you want to play again
        do{//Play until victory or draw
            //Draw Board
            gameBoard(board[0],board[1],board[2],board[3],board[4],board[5],board[6],board[7],board[8],board[9]);
       
            //Determine which player's turn it is
            if (player%2==1){
                player=1;
                plyrMrk='X';
                }
            else if (player%2==0){
                player=2;
                plyrMrk='O';
                }
       
            //Get Board Space selection from player
            cout<<"Player "<<player<<" make your selection by typing the space number: ";
            cin>>space;
       
            //Mark Game Board with selection
            if (space=='1'&&board[1]=='1')
                board[1]=plyrMrk;
            else if (space=='2'&&board[2]=='2')
                board[2]=plyrMrk;
            else if (space=='3'&&board[3]=='3')
                board[3]=plyrMrk;
            else if (space=='4'&&board[4]=='4')
                board[4]=plyrMrk;
            else if (space=='5'&&board[5]=='5')
                board[5]=plyrMrk;
            else if (space=='6'&&board[6]=='6')
                board[6]=plyrMrk;
            else if (space=='7'&&board[7]=='7')
                board[7]=plyrMrk;
            else if (space=='8'&&board[8]=='8')
                board[8]=plyrMrk;
            else if (space=='9'&&board[9]=='9')
                board[9]=plyrMrk;
            else{
                cout<<"Space already taken! Select a space without an X or O"<<endl;
                player--;//decrement player so that it runs again for the same player
            }
        
            //Check to see if the game has ended with this selection
            if (board[1]==board[2]&&board[2]==board[3])
                state=1;//victory achieved
            else if (board[4]==board[5]&&board[5]==board[6])
                state=1;//victory achieved
            else if (board[7]==board[8]&&board[8]==board[9])
                state=1;//victory achieved
            else if (board[1]==board[4]&&board[4]==board[7])
                state=1;//victory achieved
            else if (board[2]==board[5]&&board[5]==board[8])
                state=1;//victory achieved
            else if (board[3]==board[6]&&board[6]==board[9])
                state=1;//victory achieved
            else if (board[1]==board[5]&&board[5]==board[9])
                state=1;//victory achieved
            else if (board[3]==board[5]&&board[5]==board[7])
                state=1;//victory achieved
            else if (board[1]!='1'&&board[2]!='2'&&board[3]!='3'&&board[4]!='4'
                &&board[5]!='5'&&board[6]!='6'&&board[7]!='7'&&board[8]!='8'&&board[9]!='9')
                state=2;//game ends in draw
            else
                state=0;//board not yet filled, continue playing
            //Increment player by 1 to give next player their turn
            player++;
       
        }while(state==0);
        //Show Board one last time for end status
        gameBoard(board[0],board[1],board[2],board[3],board[4],board[5],board[6],board[7],board[8],board[9]);
    
        //Show end results of game, decrement to show last player was winner
        if (state==1)
            cout<<"Player "<<--player<<" is the winner! Good job!"<<endl;
        if (state==2)
            cout<<"The game has ended in a draw!"<<endl;
    
        //Ask if user would like to play the game again
        cout<<"Would you like to play again? (Y/N)"<<endl;
        cin>>choice;
        
        //Reset values of the board
        board[1]='1';
        board[2]='2';
        board[3]='3';
        board[4]='4';
        board[5]='5';
        board[6]='6';
        board[7]='7';
        board[8]='8';
        board[9]='9';
        
    }while (choice=='y'||choice=='Y');//run again if yes
    
    system("PAUSE");
    return EXIT_SUCCESS;
}

//This function draws the game board
void gameBoard(char n0, char n1,char n2, char n3, char n4, char n5, char n6, char n7, char n8, char n9){
    cout<<"\nPlayer 1 is X's and Player 2 is O's."<<endl<<endl;
    cout<<"     ___ ___ ___ "<<endl;
    cout<<"    |   |   |   |"<<endl;
    cout<<"    | "<<n7<<" | "<<n8<<" | "<<n9<<" |"<<endl;
    cout<<"    |___|___|___|"<<endl;
    cout<<"    |   |   |   |"<<endl;
    cout<<"    | "<<n4<<" | "<<n5<<" | "<<n6<<" |"<<endl;
    cout<<"    |___|___|___|"<<endl;
    cout<<"    |   |   |   |"<<endl;
    cout<<"    | "<<n1<<" | "<<n2<<" | "<<n3<<" |"<<endl;
    cout<<"    |___|___|___|"<<endl<<endl;
}
