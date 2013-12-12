/*  Joseph Reimbold
    December 11, 2013
    Final
 */

//Libraries
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
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
     
    
}//End main for Problem 2

//Begin Problem 3
void prob3(){
     
            
}//End main for Problem 3

//Begin Problem 4
void prob4(){
     
     
}//End main for Problem 4


//Begin Problem 5
void prob5(){
     
     
}//End main for Problem 5
   

//Begin Problem 6
void prob6(){
     
     
}//End main for Problem 6

void dflt(short val){
        cout<<"You typed "<<val<<" to exit the program"<<endl;
}
