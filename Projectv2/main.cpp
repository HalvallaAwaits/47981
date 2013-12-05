/*
  Joseph Reimbold
  11/28/2013
  Project 2: Tic Tac Toe: Now with AI!
*/

//Libraries
#include <iostream>
#include <string>
using namespace std;

//No Globals

//Function Prototypes
void gameBoard(char [],string,string);//Draws the game board
char plyrTrn(int &);
char gtSpc(int, string, string);
void mrkSpc(char [],char,char,int &);
int gmOvr(char [],int &);
//int kpScr();

//Begin Execution Here
int main(int argc, char *argv[])
{
    //Declare Variables
    const int SIZE=10;
    char board[SIZE]={'0','1','2','3','4','5','6','7','8','9'}; //Board spaces
    //int state=0; //Variable to track if game is over 0=no, 1=over, 2=draw;
    char space; //Board Selection space
    char choice='y'; //Play again?
    int state=0;
    int player=1; //Determines which player's turn is happening
    int numPlyr; //holds number of players
    int gmNum=1; //holds number of games played
    char plyrMrk='X'; //Bases the X or O off player #
    string p1Name; //holds player 1 name
    string p2Name="Computer"; //holds player 2 name
    
    //Introduce game
    cout<<"Welcome to Tic Tac Toe!"<<endl;
    cout<<"Now with AI!"<<endl<<endl;
    
    //prompt for number of players or AI opponent selection
    cout<<"Enter 1 for Easy AI opponent"<<endl;
    cout<<"Enter 2 for Hard AI opponent"<<endl;
    cout<<"Enter 3 for 2 player mode"<<endl;
    
    do{
       cin>>numPlyr;
    }while(numPlyr<1||numPlyr>3);
    if(numPlyr==1||numPlyr==2){
        cout<<"Enter Player 1's name: ";
        cin>>p1Name;
    }
    else{
        cout<<"Enter Player 1's name: ";
        cin>>p1Name;
        cout<<"Enter Player 2's name: ";
        cin>>p2Name;
    }
    
    //Outer loop to determine if you want to play again
    do{
        //Loop until victory or draw
        do{
            system("CLS");
            cout<<"Game "<<gmNum<<endl;
            //Draw Board
            gameBoard(board,p1Name,p2Name);
       
            //Determine which player's turn it is
            plyrMrk=plyrTrn(player);
       
            //Get Board Space selection from player
            space=gtSpc(player, p1Name, p2Name);
       
            //Mark Game Board with selection
            mrkSpc(board,space,plyrMrk,player);
        
            //Check to see if the game has ended with this selection
            state=gmOvr(board,player);
       
        }while(state==0);
        
        //Show Board one last time for end status
        gameBoard(board,p1Name,p2Name);
    
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
        
        //keeps track of how many subsequent games have been played
        gmNum++;
    
    //runs again if yes    
    }while (choice=='y'||choice=='Y');
        
    system("PAUSE");
    return EXIT_SUCCESS;
}//End of Main

//determines if the  game is over
int gmOvr(char a[],int &p){
    int s=0;
    
    //game ends in a win
    if (a[1]==a[2]&&a[2]==a[3])
         s=1;
    else if (a[4]==a[5]&&a[5]==a[6])
         s=1;
    else if (a[7]==a[8]&&a[8]==a[9])
         s=1;
    else if (a[1]==a[4]&&a[4]==a[7])
         s=1;
    else if (a[2]==a[5]&&a[5]==a[8])
         s=1;
    else if (a[3]==a[6]&&a[6]==a[9])
         s=1;
    else if (a[1]==a[5]&&a[5]==a[9])
         s=1;
    else if (a[3]==a[5]&&a[5]==a[7])
         s=1;
    //game ends in draw
    else if (a[1]!='1'&&a[2]!='2'&&a[3]!='3'&&a[4]!='4'
         &&a[5]!='5'&&a[6]!='6'&&a[7]!='7'&&a[8]!='8'&&a[9]!='9')
         s=2;
    //game continues
    else
         s=0;
    //Increment player by 1 to give next player their turn
    p++;
    
    return s;
}

//marks the space the player selects
void mrkSpc(char a[],char sp,char mrk,int &p){
     if (sp=='1'&&a[1]=='1')
          a[1]=mrk;
     else if (sp=='2'&&a[2]=='2')
          a[2]=mrk;
     else if (sp=='3'&&a[3]=='3')
          a[3]=mrk;
     else if (sp=='4'&&a[4]=='4')
          a[4]=mrk;
     else if (sp=='5'&&a[5]=='5')
          a[5]=mrk;
     else if (sp=='6'&&a[6]=='6')
          a[6]=mrk;
     else if (sp=='7'&&a[7]=='7')
          a[7]=mrk;
     else if (sp=='8'&&a[8]=='8')
          a[8]=mrk;
     else if (sp=='9'&&a[9]=='9')
          a[9]=mrk;
     else{
          cout<<"Space already taken! Select a space without an X or O!"<<endl;
          p--;//decrement player so that it runs again for the same player
     }
     system("CLS");
}

//get player's selection for space
char gtSpc(int p, string p1, string p2){
     string space;//holds space typed by player
     char sp;//holds actual char value of first digit in string
     do{
        if(p==1)
            cout<<p1<<", make your selection by typing the space number: ";
        else
            cout<<p2<<", make your selection by typing the space number: ";
        //reads in a string
        cin>>space;
        //truncates the string and takes only the first character in the string
        sp=space[0];
        if(sp!='1'&&sp!='2'&&sp!='3'&&sp!='4'&&
           sp!='5'&&sp!='6'&&sp!='7'&&sp!='8'&&sp!='9')
            cout<<"Invalid selection!"<<endl;
     }while(sp!='1'&&sp!='2'&&sp!='3'&&sp!='4'&&
           sp!='5'&&sp!='6'&&sp!='7'&&sp!='8'&&sp!='9');
     return sp;
}

//determine which player's turn it is
char plyrTrn(int &p){
     if (p%2==1){
         p=1;
         return 'X';
     }
     else if (p%2==0){
         p=2;
         return 'O';
     }
}

//draws the game board
void gameBoard(char a[],string p1, string p2){
    cout<<"\n"<<p1<<" is X's and "<<p2<<" is O's."<<endl<<endl;
    cout<<"     ___ ___ ___ "<<endl;
    cout<<"    |   |   |   |"<<endl;
    cout<<"    | "<<a[7]<<" | "<<a[8]<<" | "<<a[9]<<" |"<<endl;
    cout<<"    |___|___|___|"<<endl;
    cout<<"    |   |   |   |"<<endl;
    cout<<"    | "<<a[4]<<" | "<<a[5]<<" | "<<a[6]<<" |"<<endl;
    cout<<"    |___|___|___|"<<endl;
    cout<<"    |   |   |   |"<<endl;
    cout<<"    | "<<a[1]<<" | "<<a[2]<<" | "<<a[3]<<" |"<<endl;
    cout<<"    |___|___|___|"<<endl<<endl;
}
