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
const int CLS=7;//for prob6

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
     //Function Prototypes
     int retrand(short [],int [],int,int);
     
     //Declare Variables
     const int n=5,ntimes=10000;
     int freq[n]={0};
     int rnd;
     short int rndseq[]={9,51,78,181,251};
     
     cout<<"Random number sequence rolled 10k times: 9,51,78,181,251"<<endl;
     
     //get sequence and increment
     for(int i=0;i<ntimes;i++){
         //get sequence
         rnd=retrand(rndseq,freq,n,ntimes);
         
         //increment count for each occurrance
         if(rnd==rndseq[0])freq[0]++;
         if(rnd==rndseq[1])freq[1]++;
         if(rnd==rndseq[2])freq[2]++;
         if(rnd==rndseq[3])freq[3]++;
         if(rnd==rndseq[4])freq[4]++;
     }
     
     //output results
     for(int i=0;i<n;i++)
          cout<<rndseq[i]<<" occured "<<freq[i]<<" times"<<endl;
     cout<<endl<<endl;
     
     
}//End main for Problem 4

int retrand(short s[],int f[],int n,int nt){
     int r;
     
     r=rand()%5+1;
     if(r==1)return s[0];
     if(r==2)return s[1];
     if(r==3)return s[2];
     if(r==4)return s[3];
     if(r==5)return s[4];
     
}

//Begin Problem 5
void prob5(){
     //Function Prototypes
     void prntArry(string [],int);
     void srtArry(string [],int);
     
     //Declare Variables
     const int SIZE=10;
     string array[SIZE];
     
     //open and read in characters for 2d array
     ifstream inputFile;
     inputFile.open("input.dat");
     
     for(int i=0;i<SIZE;i++){
          inputFile>>array[i];
     }
     
     //print the array
     prntArry(array,SIZE);
     
     //sort the array
     srtArry(array,SIZE);
     
     //print sorted array
     prntArry(array,SIZE);
     
     //close file
     inputFile.close();
     
}//End main for Problem 5

void prntArry(string a[],int n){
     for(int i=0;i<n;i++){
          cout<<a[i]<<endl;
     }
     cout<<endl<<endl;
}
void srtArry(string a[],int n){
     
     //Push the array into a vector
     vector<string>c;
     for(int i=0;i<n;i++){
         c.push_back(a[i]);
     }
     //Sort it and reverse
     sort(c.begin(),c.end());
     reverse(c.begin(),c.end());
     
     //Push info back into an array
     for(int i=0;i<n;i++){
         a[i]=c[i];
     }
     
     /*
     char temp[COLS];
     
     for(int i=0;i<(n-1);i++){
          if(a[i][0]<a[i+1][0]){
               for(int j=0;j<COLS;j++){
                    temp[j]=a[i][j];
                    a[i][j]=a[i+1][j];
                    a[i+1][j]=temp[j];
               }
          }
          if(a[i][0]==a[i+1][0]){
               for(int j=0;j<COLS;j++){
                    temp[j]=a[i][j];
                    a[i][j]=a[i+1][j];
                    a[i+1][j]=temp[j];
               }
          }
     }
     */
}

//Begin Problem 6
void prob6(){
     //Function Prototypes
     void prntTble(int [][CLS],int,int &);
     void sumTble(int [][CLS],int);
     
     //Declare Variables
     const int ROWS=6;
     int table[ROWS][CLS]={0};
     int cnt=0;
     
     //read in table from file
     ifstream inputFile;
     inputFile.open("table.dat");
     
     for(int i=0;i<ROWS-1;i++){
          for(int j=0;j<CLS-1;j++){
               inputFile>>table[i][j];
          }
     }
     
     //print original
     prntTble(table,ROWS,cnt);
     
     //sum it all up
     sumTble(table,ROWS);
     
     //print augmented
     prntTble(table,ROWS,cnt);
     
     //output augmented table to file
     ofstream outputFile;
     outputFile.open("augtable.dat");
     
     for(int i=0;i<ROWS;i++){
          for(int j=0;j<CLS;j++){
               outputFile<<table[i][j]<<"   ";
               if(j%(CLS)==(CLS-1))outputFile<<endl;
          }
     }
     
     //close files
     inputFile.close();
     outputFile.close();
     
}//End main for Problem 6

void prntTble(int a[][CLS],int n,int &cnt){
     if(cnt==0){
         for(int i=0;i<n-1;i++){
              for(int j=0;j<CLS-1;j++){
                   cout<<setw(6)<<a[i][j];
                   if(j%(CLS-1)==(CLS-2))cout<<endl;
              }
         }
     cout<<endl;
     cnt++;
     return;
     }
     
     if(cnt==1){
          for(int k=0;k<n;k++){
              for(int l=0;l<CLS;l++){
                   cout<<setw(6)<<a[k][l];
                   if(l%(CLS)==(CLS-1))cout<<endl;
              }
         }
     cout<<endl;
     }
}

void sumTble(int a[][CLS],int n){
     //get column totals
     for(int i=0;i<n;i++){
          for(int j=0;j<CLS-2;j++){
               a[n-1][i]+=a[j][i];
          }
     }
     
     //get row totals
     for(int k=0;k<CLS-1;k++){
          for(int l=0;l<CLS-1;l++){
               a[k][CLS-1]+=a[k][l];
          }
     }     
}

void dflt(short val){
        cout<<"You typed "<<val<<" to exit the program"<<endl;
}
