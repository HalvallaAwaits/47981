/*
  Joseph Reimbold
  11/28/2013
  Project 2: Tic Tac Toe: Now with AI!
*/

//Libraries
#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
using namespace std;

//Globals
const int LOSSES=2;//to hold score in 2d array, will be output to file

//Function Prototypes
string sttngs(int, string &);
void gameBoard(char [],string,string,int);
char plyrTrn(int &);
char gtSpc(int, string, string);
void mrkSpc(char [],char,char,int &);
int gmOvr(char [],int &,string, string,int);
void rslt(int,int,string,string,int [][LOSSES],int,int &);
void rcrdScr(int [][LOSSES],int,string,string,int,int);


//Begin Execution Here
int main(int argc, char *argv[])
{
    //Declare Variables
    const int SIZE=10,WINS=2;
    char board[SIZE]={'0','1','2','3','4','5','6','7','8','9'}; //Board spaces
    //int state=0; //Variable to track if game is over 0=no, 1=over, 2=draw;
    char space; //Board Selection space
    char choice='y'; //Play again?
    int state=0;
    int player=1; //Determines which player's turn is happening
    int numPlyr; //holds number of players
    int gmNum=1; //holds number of games played
    int draws=0; //counts number of draws
    int diff; //holds difficulty choice
    char plyrMrk='X'; //Bases the X or O off player #
    string p1Name; //holds player 1 name
    string p2Name="AI"; //holds player 2 name
    int score[WINS][LOSSES]={0,0,0,0}; //holds wins and losses for each player
    srand(static_cast<unsigned int>(time(0)));
    
    //Introduce game
    cout<<"Welcome to Tic Tac Toe!"<<endl;
    cout<<"Now with AI!"<<endl<<endl;
        
    //prompt for number of players or AI opponent selection
    cout<<"Enter 1 for Easy AI opponent"<<endl;
    cout<<"Enter 2 for Hard AI opponent"<<endl;
    cout<<"Enter 3 for 2 players!"<<endl;
    cin>>numPlyr;
    
    //read in player names from settings.txt
    p1Name=sttngs(numPlyr,p2Name);
    
    switch(numPlyr){
        case 1:
             do{
                do{
                   //change AI name
                   p2Name="Easy AI";
                   
                   //draw board
                   gameBoard(board,p1Name,p2Name,gmNum);
                   
                   //determine which player's turn
                   plyrMrk=plyrTrn(player);
                   
                   //get user's selection for space
                   space=gtSpc(player,p1Name,p2Name);
                   
                   //mark the board with selection
                   mrkSpc(board,space,plyrMrk,player);
                   
                   //check to see if game is over
                   state=gmOvr(board,player,p1Name,p2Name,gmNum);
                
                }while(state==0);
                
                //display result of game end
                rslt(state,player,p1Name,p2Name,score,WINS,draws);
    
                //Ask if user would like to play the game again
                cout<<"Would you like to play again? (Y/N)"<<endl;
                cin>>choice;
        
                //keeps track of how many games have been played
                gmNum++;
                
             //runs again if yes    
             }while (choice=='y'||choice=='Y');
             break;
        
        case 2:
             do{
                do{
                   //change AI name
                   p2Name="Hard AI";
                   
                   //draw board
                   gameBoard(board,p1Name,p2Name,gmNum);
                   
                   //determine which player's turn it is
                   plyrMrk=plyrTrn(player);
                   
                   //get user's selection for space
                   space=gtSpc(player,p1Name,p2Name);
                   
                   //mark the board with selection
                   mrkSpc(board,space,plyrMrk,player);
                   
                   //check to see if game is over
                   state=gmOvr(board,player,p1Name,p2Name,gmNum);
                
                }while(state==0);
                
                //display end result of game
                rslt(state,player,p1Name,p2Name,score,WINS,draws);
    
                //Ask if user would like to play the game again
                cout<<"Would you like to play again? (Y/N)"<<endl;
                cin>>choice;
        
                //keeps track of how many games have been played
                gmNum++;
                
             //runs again if yes    
             }while (choice=='y'||choice=='Y');
             break;
        
        case 3:
             //Outer loop to determine if you want to play again
             do{
                //Loop until victory or draw
                do{
                   //Draw Board
                   gameBoard(board,p1Name,p2Name,gmNum);
       
                   //Determine which player's turn it is
                   plyrMrk=plyrTrn(player);
       
                   //Get Board Space selection from player
                   space=gtSpc(player, p1Name, p2Name);
            
                   //Mark Game Board with selection
                   mrkSpc(board,space,plyrMrk,player);
        
                   //Check to see if the game has ended with this selection
                   state=gmOvr(board,player,p1Name,p2Name,gmNum);
       
                }while(state==0);
    
             //display game end results
             rslt(state,player,p1Name,p2Name,score,WINS,draws);
    
             //Ask if user would like to play the game again
             cout<<"Would you like to play again? (Y/N)"<<endl;
             cin>>choice;
        
             //keeps track of how many games have been played
             gmNum++;
    
             //runs again if yes    
             }while (choice=='y'||choice=='Y');
             break;     
    }
    
    //records the score by outputting to file
    rcrdScr(score,WINS,p1Name,p2Name,gmNum,draws);
        
    system("PAUSE");
    return EXIT_SUCCESS;
}//End of Main

//outputs final overall stats and stores them in a file
//designated by the user
void rcrdScr(int s[][LOSSES],int,string p1,string p2,int g,int d){
     string rsltFl;
     
     //output results to screen
     cout<<endl;
     cout<<"Please specify a filename that you would"<<endl
         <<"like to output the results to: ";
     cin>>rsltFl;
     
     //declare the outfile and open
     ofstream outputFile;
     outputFile.open(rsltFl.c_str());
     
     cout<<endl<<"You can find the file "<<rsltFl<<" within"<<endl
         <<"the program folder."<<endl<<endl;   
     cout<<"Games Played = "<<(g-1)<<" Draws = "<<d<<endl;
     cout<<p1<<"'s score: "<<endl<<s[0][0]<<"W "<<s[0][1]<<"L"<<endl;
     cout<<p2<<"'s score: "<<endl<<s[1][0]<<"W "<<s[1][1]<<"L"<<endl;
     
     //output results to file
     outputFile<<"Games Played = "<<(g-1)<<" Draws = "<<d<<endl;
     outputFile<<p1<<"'s score: "<<endl<<s[0][0]<<"W "<<s[0][1]<<"L"<<endl;
     outputFile<<p2<<"'s score: "<<endl<<s[1][0]<<"W "<<s[1][1]<<"L"<<endl;
     
     //close file
     outputFile.close();
}

//outputs winning game results
void rslt(int s,int p,string p1,string p2,int scr[][LOSSES],int w, int &d){
     //Show end results of game
             if (s==1){
                if((p)%2==1){
                    cout<<p1<<" is the winner! Good job!"<<endl;
                    scr[0][0]++;
                    scr[1][1]++;
                }
                if((p)%2==0){
                    cout<<p2<<" is the winner! Good job!"<<endl;
                    scr[1][0]++;
                    scr[0][1]++;
                }
             }
             if (s==2){
                 cout<<"The game has ended in a draw!"<<endl;
                 d++;
             }
}

//determines if the  game is over
int gmOvr(char a[],int &p,string p1, string p2,int g){
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
    
    if(s==1){
         //draws board to show final move
         gameBoard(a,p1,p2,g);
         
         //Reset values of the board
         a[1]='1';
         a[2]='2';
         a[3]='3';
         a[4]='4';
         a[5]='5';
         a[6]='6';
         a[7]='7';
         a[8]='8';
         a[9]='9';
    }
    
    //game ends in draw
    else if (a[1]!='1'&&a[2]!='2'&&a[3]!='3'&&a[4]!='4'
         &&a[5]!='5'&&a[6]!='6'&&a[7]!='7'&&a[8]!='8'&&a[9]!='9')
         s=2;
    //game continues
    else{
         s=0;
         p++;
    }
    //Increment player by 1 to give next player their turn
    //p++;
    
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
          p--;//decrement player so that it runs again for the same player
     }
     //system("CLS");
}

//get player's selection for space
char gtSpc(int p, string p1, string p2){
     string space;//holds space typed by player
     char sp;//holds actual char value of first digit in string
     do{
        if(p==1)
            cout<<p1<<", make your selection by typing the space number: ";
        else{
            cout<<p2<<", make your selection by typing the space number: ";
            }
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
void gameBoard(char a[],string p1, string p2,int g){
    system("CLS");
    cout<<"Game "<<g<<endl;
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

string sttngs(int numP, string &p2){  
    string p1;//hold player 1 name
    
    //declare inputfile and open it
    ifstream inputFile;
    inputFile.open("settings.txt");
    
    //read in player names
    inputFile>>p1;
    if(numP==3)
        inputFile>>p2;
        
    //close inputfile
    inputFile.close();
    
    return p1;
}
