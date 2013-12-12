/*  
    Joseph Reimbold
    December 11, 2013
    Final
 */

//Libraries
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <ctime>
#include <vector>
using namespace std;

//Global Constants

//Function Prototypes
void Menu();
short getChoice();
void dflt(short);
void prob1();
void prob2();
void prob3();
void prob4();
void prob5();
void prob6();

//Begin Execution Here!!!
int main(){
    srand(static_cast<unsigned int>(time(0)));
    short choice;
    do{
        Menu();
        choice=getChoice();
        cout<<endl;
        switch(choice){
        case 1:    prob1();break;
        case 2:    prob2();break;
        case 3:    prob3();break;
        case 4:    prob4();break;
        case 5:    prob5();break;
        case 6:    prob6();break;
        default:   dflt(choice);}
    }while(choice>=1&&choice<=6);
    return 0;
}

void Menu(){
    cout<<"Menu for Final"<<endl;
    cout<<"Type 1 for problem 1"<<endl;
    cout<<"Type 2 for problem 2"<<endl;
    cout<<"Type 3 for problem 3"<<endl;
    cout<<"Type 4 for problem 4"<<endl;
    cout<<"Type 5 for problem 5"<<endl;
    cout<<"Type 6 for problem 6"<<endl;
    cout<<"Type anything else to exit \n"<<endl;
}

short getChoice(){
        int n;
        cin>>n;
        return n;
}

//Begin Problem 1
void prob1(){ 
     //Function Prototypes
     short rvNm(unsigned short);
     
     //Declare Variables
     int n=0;
     unsigned short num=0,rev=0;
     
     //Get num from user
     do{
         cout<<"Enter an unsigned short (ex: 1-65,535)"<<endl;
         cin>>n;
     }while(n>65535||n<1);
     num=n;
     
     //get reverse
     rev=rvNm(num);
     
     if(rev==0)
         cout<<"No reverse possible!"<<endl<<endl;
     else
         cout<<endl<<"Number in reverse:"<<endl<<rev<<endl<<endl;
          
     

}//End main for Problem 1

short rvNm(unsigned short n){
     unsigned short num=0,rev=0,ttho=0,tho=0,hun=0,ten=0,one=0;
     int r=0;
     
     num=n;
     
     //get digit values and store them
     ttho=num/10000;
     num-=(ttho*10000);
     tho=num/1000;
     num-=(tho*1000);
     hun=num/100;
     num-=(hun*100);
     ten=num/10;
     num-=(ten*10);
     one=num;
     
     //get reverse number and output
     if(n>9999)
          r=(one*10000)+(ten*1000)+(hun*100)+(tho*10)+ttho;
     else if(n>999)
          r=(one*1000)+(ten*100)+(hun*10)+tho;
     else if(n>99)
          r=(one*100)+(ten*10)+hun;
     else if(n>9)
          r=(one*10)+ten;
     else
          r=one;
     
     if(r>65535)return 0;
     rev=r;
          
     return rev;
}

//Begin Problem 2
void prob2(){     
     //Declare Variables
     int num,gNum,guess=0;
     char again;
     
     do{
          if(guess==0){
               //set num to random num between 1-500
               num=rand()%500+1;
             
               //Game Intro
               cout<<"I have a number between 1 and 500."<<endl;
               cout<<"Can you guess my number?  You will be"<<endl;
               cout<<"given a maximum of 9 guesses."<<endl;
               cout<<"Please type your first guess."<<endl;
          }
     
         //player enters guess
         cin>>gNum;
         guess++;
         
         if(gNum==num){
              cout<<"Congratulations, you guessed the number!"<<endl;
              cout<<"Would you like to play again (y or n)?"<<endl;
              cin>>again;
              cout<<endl;
              guess=0;
              num=rand()%500+1;
         }
         else if(gNum<num)
              cout<<"Too low. Try again."<<endl;
         else if (gNum>num)
              cout<<"Too high. Try again."<<endl;
         else if(guess==9)
              cout<<"Too many tries."<<endl;
     }while(guess<=9);
    
}//End main for Problem 2

//Begin Problem 3
void prob3(){
     /*
     Problem 3
     Create a function that fills one vector with even
     random 2 digit numbers and another vector with
     odd random numbers.  Prompt the user for the size
     of these vectors.  Both will be the same size.
     Output the results where you ask the user how
     many columns to display.  These should be done
     with 2 functions, fillVec and prntVec.
     */
     
     //Function Prototypes
     void fillVec(vector<int> &,vector<int> &,int);
     void prntVec(vector<int> &,vector<int> &,int,int);
     
     //Declare Variables
     int size,col;
     
     //get size from user
     cout<<"How many numbers would you like in each vector?"<<endl;
     cin>>size;
     
     //declare arrays
     vector <int> even(size);
     vector <int> odd(size);
     
     //fill vectors
     fillVec(even,odd,size);
          
     //get number of columns from user
     cout<<"How many columns would you like to display?"<<endl;
     cin>>col;
     
     //print vectors
     prntVec(even,odd,size,col);
     
     cout<<endl<<endl;
            
}//End main for Problem 3

void fillVec(vector<int> &e,vector<int> &o,int n){
     int r;
     for(int i=0;i<n;i++){
             do{
                r=rand()%90+10;
             }while(r%2!=0);
             e[i]=r;
             //cout<<e[i]<<endl;
             do{
                r=rand()%90+10;
             }while(r%2!=1);
             o[i]=r;
             //cout<<o[i]<<endl;
     }
}

void prntVec(vector<int> &e,vector<int> &o,int n,int c){
     for(int i=0;i<n;i++){
             cout<<e[i]<<" ";
             if(i%c==(c-1))cout<<endl;
     }
     cout<<endl<<endl;
     for(int i=0;i<n;i++){
             cout<<o[i]<<" ";
             if(i%c==(c-1))cout<<endl;
     }
}

//Begin Problem 4
void prob4(){
/*
Problem #4  (Random Sequence)
        Create a function/method/procedure that
returns a random number from the following set,
{9,51,78,181,251}.  Loop 10000 times with this 
procedure and print the frequency of each of 
the 5 numbers obtained.  Hint: Use an array for 
the sequence and frequency.  


The following is a brief hint on items that might 
be helpful in obtaining the results.  This is not 
direct code but more pseudo code related.  Don't 
try and run the following directly and more code 
will be needed.


Setup
        const int n=5,ntimes=10000;
        int freq[n]={0};
        short int rndseq[]={9,51,78,181,251};


Call to the routine to return a random sequence
        retrand(rndseq,freq,n,ntimes);


Results
        cout<<rndseq[i]<<" occured "<<
                freq[i]<<" times"<<endl;


Sample Output
        9 occured 2055 times
        51 occured 1986 times
        78 occured 1962 times
        161 occured 2079 times
        151 occured 1919 times


Note:  Your results are not expected to be exactly
the same!  After all these are pseudo-random 
number sequences with different seeds.  
*/     
     
     //Function Prototypes
     
     
     //Declare Variables
     
     
}//End main for Problem 4


//Begin Problem 5
void prob5(){
/*
Problem #5  (All Kinds of Sorting)
Sort a 10x15 array of characters.  Largest located
at index [0][0-14] and smallest at index [9][0-14].  
Create a procedure that passes the array to a print routine, 
then a procedure that sorts the array and returns the sorted array 
to the original procedure, and finish by using the same print routine.  
Fill the array with


Lcekoeddhoffbmb
Lkcmggjcdhhglif
Cgldjhcekjigcdd
Cgldjhcekjigcdn
Bffmdbkcenlafjk
Fggdijijegfblln
Jjlncnimjldfedj
Amliglfohajcdmm
Balgfcaelhfkgeb
Kmlhmhcddfoeild


Note:  This is a character array but the sorting is 
done as if there are 10 strings with each string having 15 characters.  
The output would be


Lkcmggjcdhhglif
Lcekoeddhoffbmb
Kmlhmhcddfoeild
Jjlncnimjldfedj
Fggdijijegfblln
Cgldjhcekjigcdn
Cgldjhcekjigcdd
Bffmdbkcenlafjk
Balgfcaelhfkgeb
Amliglfohajcdmm

Full credit will be given if a file is used to read in the array.
Name the file input.dat

*/     
     
     //Function Prototypes
     
     
     //Declare Variables
     
     
}//End main for Problem 5
   

//Begin Problem 6
void prob6(){
/*
Problem #6  (Spreadsheet Stuff)
        Create the following input tables.  Output
the sum of the rows, columns and grand total.  You
will need to create procedures that print the table,
then sum rows, columns and grand total, then pass
that information to the same print routine.  Note:
the 2 procedures printTable,SumTable and finally a
call to printTable again are all invoked from subroutine 
main.  I want to see each number formated to 6 spaces.  
Print the table out exactly as below.


Example Input Table
   100   101   102   103   104   105
   106   107   108   109   110   111
   112   113   114   115   116   117
   118   119   120   121   122   123
   124   125   126   127   128   130
Example Output Augmented Table with rows summed,
columns summed and the grand total printed.
   100   101   102   103   104   105   615
   106   107   108   109   110   111   651
   112   113   114   115   116   117   687
   118   119   120   121   122   123   723
   124   125   126   127   128   130   760
   560   565   570   575   580   586  3436


More credit will be given if you read the input and write 
the results to a file.  However, if you can't do this in 
a procedure then embed in the program.  But full credit 
will not be given for the problem if files
are not utilized. Name the files table.dat and augtable.dat


Extra Credit
New ordering, Instead of using 0123456789 to order
numbers use the following 9874560321 to order.  I want to
type in two 4 digit numbers and determine which is larger
and smaller based upon the new ordering system.
*/
    
     //Function Prototypes
     
     
     //Declare Variables
     
     
     
}//End main for Problem 6

void dflt(short val){
        cout<<"You typed "<<val<<" to exit the program"<<endl;
}
