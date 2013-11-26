/*  Joseph Reimbold
    November 15, 2013
    Assignment 6
 */

//Libraries
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <vector>
using namespace std;

//Global Constants
const int DYSPWK=7;//used for Gaddis Chap7 Prob4 for 2d array
const int DYSPM=30;//used for Gaddis Chap7 Prob5 for 2d array
const int QRTRS=4;//used for Gaddis Chap7 Prob7 for 2d array

//Function Prototypes
void Menu();
short getChoice();
void dflt(short);
void prob0();
void prob1();
void prob2();
void prob3();
void prob4();
void prob5();
void prob6();
void prob7();
void prob8();
void prob9();



//Begin Execution Here!!!
int main(){
    short choice;
    do{
        Menu();
        choice=getChoice();
        cout<<endl;
        switch(choice){
        case 0:    prob0();break;
        case 1:    prob1();break;
        case 2:    prob2();break;
        case 3:    prob3();break;
        case 4:    prob4();break;
        case 5:    prob5();break;
        case 6:    prob6();break;
        case 7:    prob7();break;
        case 8:    prob8();break;
        case 9:    prob9();break;
        default:   dflt(choice);}
    }while(choice>=0&&choice<=9);
    return 0;
}

void Menu(){
    cout<<"Menu for Assignment 5"<<endl;
    cout<<"Type 0 for Gaddis 7th Edition Chapter 7 problem 1"<<endl;
    cout<<"Type 1 for Gaddis 7th Edition Chapter 7 problem 2"<<endl;
    cout<<"Type 2 for Gaddis 7th Edition Chapter 7 problem 3"<<endl;
    cout<<"Type 3 for Gaddis 7th Edition Chapter 7 problem 4"<<endl;
    cout<<"Type 4 for Gaddis 7th Edition Chapter 7 problem 5"<<endl;
    cout<<"Type 5 for Gaddis 7th Edition Chapter 7 problem 6"<<endl;
    cout<<"Type 6 for Gaddis 7th Edition Chapter 7 problem 7"<<endl;
    cout<<"Type 7 for Gaddis 7th Edition Chapter 7 problem 8"<<endl;
    cout<<"Type 8 for Gaddis 7th Edition Chapter 7 problem 9"<<endl;
    cout<<"Type 9 for Gaddis 7th Edition Chapter 7 problem 10"<<endl;
    cout<<"Type anything else to exit \n"<<endl;
}

short getChoice(){
        int n;
        cin>>n;
        return n;
}

//Begin Gaddis 7th Edition Chapter 7 Problem 1
void prob0(){
     //Declare Variables
     const int SIZE=10;
     int array[SIZE];
     int value;
     
     //Prompt for array values from user
     cout<<"Please enter 10 integer values for the array."<<endl;
     for (int i=0;i<SIZE;i++){
         cout<<"Enter Value "<<i+1<<": ";
         cin>>array[i];
     }
     cout<<endl;
     
     //Check for largest value
     value=array[0];
     for (int l=0;l<SIZE;l++)
         if (array[l]>value)value=array[l];
     cout<<"The largest value you entered in the array is: "<<value<<endl;
     
     //Check for smallest value
     value=array[0];
     for (int s=0;s<SIZE;s++)
         if (array[s]<value)value=array[s];
     cout<<"The smallest value you entered in the array is: "<<value<<endl<<endl<<endl;

}//End Gaddis Chap7 Prob1


//Begin Gaddis Chap7 Prob2
void prob1(){ 
     //Function Prototypes
     void getRain(float[],int);
     float ttlRain(float[],int);
     float avgRain(float[],int);
     void highLow(float[],int);
     
     //Declare Variables
     const int SIZE=12;
     float rain[SIZE];
     float ttl, avg, high=0, low=0;
     
     //Get rainfall amounts from user
     getRain(rain,SIZE);
     cout<<endl;
     
     //Calculate total rainfall
     ttl=ttlRain(rain,SIZE);
     cout<<"The total rainfall is "<<ttl<<"."<<endl;
     
     //Calculate the average monthly rainfall
     avg=avgRain(rain,SIZE);
     cout<<"The average monthly rainfall is "<<avg<<"."<<endl;
          
     //Find highest and lowest month
     highLow(rain,SIZE);
     cout<<endl<<endl;

}//End Main of Gaddis Chap7 Prob2

void getRain(float a[],int n){
     //Prompt user for rain amounts for each month
     for (int i=0;i<n;i++){
         do{
            cout<<"Enter the amount of rain for month "<<i+1<<": ";
            cin>>a[i];
         }while (a[i]<0);
     }
}

float ttlRain(float a[], int n){
      float t=0;
      for (int i=0;i<n;i++)
          t+=a[i];
      return t;
}

float avgRain(float a[], int n){
      float avg=0;
      for (int i=0;i<n;i++)
          avg+=a[i];
          avg/=12.0f;
      return avg;
}

void highLow(float a[], int n){
     string months[12]={"January","February","March","April",
                         "May","June","July","August","September",
                         "October","November","December"};
     float high=a[0];
     float low=a[0];
     char hMnth=0;
     char lMnth=0;
     for (int i=0;i<n;i++){
         if (a[i]>high)high=a[i];
         if (a[i]<low)low=a[i];
     }
     
     for (int c=0;c<n;c++){
         if (a[c]==high)hMnth=c;
         if (a[c]==low)lMnth=c;
     }
     cout<<"The month of "<<months[hMnth]<<
           " had the highest rainfall with "<<high<<"."<<endl;
     cout<<"The month of "<<months[lMnth]<<
           " had the lowest rainfall with "<<low<<"."<<endl;
}
//End Gaddis Chap7 Prob2


//Begin Gaddis Chap7 Prob3
void prob2(){
     //Function Prototypes
     void getSales(int[],string[],int);
     int sold(int[],int);
     int hSalsa(int[],int,int &);
     int lSalsa(int[],int,int &);
     
     //Declare Variables
     const int SIZE=5;
     int salsa[SIZE];
     int ttl,high,low,hType=0,lType=0;
     string names[SIZE]={"Mild","Medium","Sweet","Hot","Zesty"};
     
     //Get amount of sales for each type of salsa
     getSales(salsa,names,SIZE);
     cout<<endl;
     
     //Calculate total jars sold
     ttl=sold(salsa,SIZE);
     cout<<"The total number of jars sold combined is: "<<ttl<<endl;
     
     //Calculate highest selling salsa
     high=hSalsa(salsa,SIZE,hType);
     cout<<names[hType]<<" sold the most with "<<high<<" jars sold!"<<endl;
     
     //Calculate lowest selling salsa
     low=lSalsa(salsa,SIZE,lType);
     cout<<names[lType]<<" sold the least with "<<low<<" jars sold!"<<endl;
     
     
     cout<<endl<<endl;
    
}//End main for Prob3

void getSales(int a[],string s[],int n){
     cout<<"Number of jars sold of each salsa type:"<<endl;
     for (int i=0;i<n;i++){
         do{
            cout<<"How many "<<s[i]<<" jars were sold?: ";
            cin>>a[i];
         }while(a[i]<0);
     }
}

int sold(int a[],int n){
    int t=0;
    for (int i=0;i<n;i++){
        t+=a[i];
    }
    return t;
}

int hSalsa(int a[],int n,int &ht){
    int high=a[0];
    ht=0;
    
    for (int i=0;i<n;i++){
        if (a[i]>high){
           high=a[i];
           ht=i;
        }
    }
    return high;
}

int lSalsa(int a[],int n,int &lt){
    int low=a[0];
    lt=0;
    
    for (int i=0;i<n;i++){
        if (a[i]<low){
           low=a[i];
           lt=i;
        }
    }
    return low;
}
//End Gaddis Chap7 Prob3


//Begin Gaddis Chap7 Prob4
void prob3(){
     //Function Prototypes
     void getFood(float[][DYSPWK],int);
     float avgFood(float[][DYSPWK],int);
     float fLeast(float[][DYSPWK],int,int &);
     float fMost(float[][DYSPWK],int,int &);
     
     //Declare Variables
     const int MNKYS=3;
     float food[MNKYS][DYSPWK];
     int lMonk=0, mMonk=0;//stores the monkey in which the most or least food was eaten
     
     //Prompt user for food values
     getFood(food,MNKYS);
     
     //Calculate the average food eaten daily
     cout<<"The average amount of food eaten daily is "
         <<avgFood(food,MNKYS)<<endl<<endl;
         
     //Find least food eaten
     cout<<"The least amount of food eaten was "
         <<fLeast(food,MNKYS,lMonk)<<" by Monkey "<<(lMonk+1)<<"."<<endl<<endl;
     
     //Find most food eaten
     cout<<"The largest amount of food eaten was "
         <<fMost(food,MNKYS, mMonk)<<" by Monkey "<<(mMonk+1)<<"."<<endl<<endl;
         
}//End Main for Gaddis Chap7 Prob4

void getFood(float a[][DYSPWK],int n){
     cout<<"Calculating the food consumption of monkeys in the zoo!"<<endl;
     for (int i=0;i<n;i++){
         for (int j=0;j<DYSPWK;j++){
             do{     
                  cout<<"Enter the amount of food consumed by Monkey "<<i+1<<
                   " on day "<<j+1<<": ";
                  cin>>a[i][j];
             }while(a[i][j]<0);
         }
     }
     cout<<endl;
}

float avgFood(float a[][DYSPWK],int n){
      float avg,t;
      int cnt=0;
      for (int i=0;i<n;i++){
         for (int j=0;j<DYSPWK;j++){
             t=t+a[i][j];
             cnt++;
         }
      }
      avg=t/cnt;
      return avg;
}

float fLeast(float a[][DYSPWK],int n,int &lm){
      float low=a[0][0];
      for (int i=0;i<n;i++){
         for (int j=0;j<DYSPWK;j++){
             if (a[i][j]<low){
                low=a[i][j];
                lm=i;
             }
         }
      }
      return low;
}

float fMost(float a[][DYSPWK],int n,int &mm){
      float high=a[0][0];
      for (int i=0;i<n;i++){
         for (int j=0;j<DYSPWK;j++){
             if (a[i][j]>high){
                high=a[i][j];
                mm=i;
             }
         }
      }
      return high;
}//End Gaddis Chap7 Prob4


//Begin Gaddis Chap7 Prob5
void prob4(){
    //Function Prototypes
    void gtrain(char [][DYSPM],int);
    void june(char [][DYSPM],int,int &,int &, int &);
    void july(char [][DYSPM],int,int &,int &, int &);
    void august(char [][DYSPM],int,int &,int &, int &);
    void rainAll(char [][DYSPM],int, int &,int &, int &);
    string mstRain(int,int,int);
    
    //Declare Variables
    const int MNTHS=3;
    char wthr[MNTHS][DYSPM];
    int rJun=0,cJun=0,sJun=0;
    int rJul=0,cJul=0,sJul=0;
    int rAug=0,cAug=0,sAug=0;
    int rAll=0,cAll=0,sAll=0;
    string mnthMst;
    
    //gather input from file
    gtrain(wthr,MNTHS);
    
    //count rainy, cloudy and sunny days for each month and output
    june(wthr,MNTHS,rJun,cJun,sJun);
    cout<<"Stats for June"<<endl<<"Rainy Days:  "
        <<setw(3)<<rJun<<endl<<"Cloudy Days: "<<setw(3)<<cJun<<endl
        <<"Sunny Days:  "<<setw(3)<<sJun<<endl<<endl;
    july(wthr,MNTHS,rJul,cJul,sJul);
    cout<<"Stats for July"<<endl<<"Rainy Days:  "
        <<setw(3)<<rJul<<endl<<"Cloudy Days: "<<setw(3)<<cJul<<endl
        <<"Sunny Days:  "<<setw(3)<<sJul<<endl<<endl;
    august(wthr,MNTHS,rAug,cAug,sAug);
    cout<<"Stats for August"<<endl<<"Rainy Days:  "
        <<setw(3)<<rAug<<endl<<"Cloudy Days: "<<setw(3)<<cAug<<endl
        <<"Sunny Days:  "<<setw(3)<<sAug<<endl<<endl;
        
    //count rainy, cloudy and sunny days for all three months combined
    rainAll(wthr,MNTHS,rAll,cAll,sAll);
    cout<<"Total"<<endl<<"Rainy Days:  "
        <<setw(3)<<rAll<<endl<<"Cloudy Days: "<<setw(3)<<cAll<<endl
        <<"Sunny Days:  "<<setw(3)<<sAll<<endl<<endl;
    
    //determine which month had the most rain
    cout<<mstRain(rJun,rJul,rAug)<<" had the most rainfall."<<endl<<endl;
    
}

void june(char a[][DYSPM],int n,int &rJun,int &cJun, int &sJun){
     for(int i=0;i<DYSPM;i++){
             if(a[0][i]=='R')rJun++;
             if(a[0][i]=='C')cJun++;
             if(a[0][i]=='S')sJun++;
     }
}

void july(char a[][DYSPM],int n,int &rJul,int &cJul, int &sJul){
     for(int i=0;i<DYSPM;i++){
             if(a[1][i]=='R')rJul++;
             if(a[1][i]=='C')cJul++;
             if(a[1][i]=='S')sJul++;
     }
}

void august(char a[][DYSPM],int n,int &rAug,int &cAug, int &sAug){
     for(int i=0;i<DYSPM;i++){
             if(a[2][i]=='R')rAug++;
             if(a[2][i]=='C')cAug++;
             if(a[2][i]=='S')sAug++;
     }
}

void rainAll(char a[][DYSPM],int n,int &rAll,int &cAll, int &sAll){
     for(int i=0;i<n;i++){
             for(int j=0;j<DYSPM;j++){
                     if(a[i][j]=='R')rAll++;
                     if(a[i][j]=='C')cAll++;
                     if(a[i][j]=='S')sAll++;
             }
     }
}

string mstRain(int rju, int rjul, int ra){
    if(rju>rjul&&rju>ra)return "June";
    if(rjul>rju&&rjul>ra)return "July";
    if(ra>rju&&ra>rjul)return "August";
}

void gtrain(char a[][DYSPM],int n){
     char day;//stores day status (rainy, sunny or cloudy)
     
     //Open the file
     ifstream inputFile;
     inputFile.open("RainOrShine.dat");
     
     //Get rain data from file
     for(int i=0;i<n;i++){
             for(int j=0;j<DYSPM;j++){
                     inputFile>>day;
                     a[i][j]=day;
             }
     }
     
     //Close the file
     inputFile.close();
}
//End Gaddis Chap7 Prob5



//Begin Gaddis Chap7 Prob6
void prob5(){
    //Function Prototypes
    void getNums(int [],int);
    int lwNums(int [],int);
    int hghNums(int [],int);
    int ttlNums(int [],int);
    int avgNums(int [],int);
    
    //Declare variables
    const int SIZE=20;
    int nums[SIZE];
    
    //get file name and input from file
    getNums(nums,SIZE);
    
    //find lowest value
    cout<<"The lowest number is: "<<lwNums(nums,SIZE)<<endl;
    
    //find highest value
    cout<<"The highest number is: "<<hghNums(nums,SIZE)<<endl;
    
    //find total of values
    cout<<"The total of all number is: "<<ttlNums(nums,SIZE)<<endl;
    
    //find average value
    cout<<"The average of the number is: "<<avgNums(nums,SIZE)<<endl<<endl;
    
}

int avgNums(int a[],int n){
    int ttl=0;
    int avg=0;
    
    for(int i=0;i<n;i++){
            ttl+=a[i];
    }
    avg=ttl/n;
    return avg;
}

int ttlNums(int a[],int n){
    int ttl=0;
    
    for(int i=0;i<n;i++){
            ttl+=a[i];
    }
    
    return ttl;
}

int hghNums(int a[],int n){
    int high=a[0];
    
    for(int i=0;i<n;i++){
            if(a[i]>high)high=a[i];
    }
    
    return high;
}

int lwNums(int a[],int n){
    int low=a[0];
    
    for(int i=0;i<n;i++){
            if(a[i]<low)low=a[i];
    }
    
    return low;
}

void getNums(int a[],int n){
     char fName[25];//holds file name given by user
     
     //get file name from user
     cout<<"This program will read in a file of 20 integers "<<endl
         <<"(each on a separate line) and analyze the integers."<<endl<<endl;
     cout<<"Please enter the entire filename (ex:'numbers.txt') and"<<endl
         <<"make sure the file is within this program's folder as well."<<endl<<endl;
     cin>>fName;
     
     //open file
     ifstream inputFile;
     inputFile.open(fName);
     
     //fill array
     for(int i=0;i<n;i++){
             inputFile>>a[i];
     }
     
     //close file
     inputFile.close();  
}
//End Gaddis Chap7 Prob 6
   

//Begin Gaddis Chap7 Prob7
void prob6(){
    //Function Prototypes
    void getFigs(float [][QRTRS],int);
    void lstSls(float [][QRTRS],int,int);
    void qrtCmpr(float [][QRTRS],int,int);
    float qrtTtl(float [][QRTRS],int,int);
    void ttlCmpr(float [][QRTRS],int,int);
    float divAvg(float [][QRTRS],int,int);
    float hghDiv(float [][QRTRS],int,int,int &);
    
    //Declare variables
    const int DIVISIONS=6;
    float qrtrSls[DIVISIONS][QRTRS];
    float hAmt=0;//highest division amount 
    int hDiv=0;//highest division #
    
    //get data from user
    getFigs(qrtrSls,DIVISIONS);
        
    //display specific details for each quarter
    for(int qrtr=0;qrtr<QRTRS;qrtr++){
        cout<<"Quarter "<<qrtr+1<<" figures:"<<endl;
        //display sales for each division
        lstSls(qrtrSls,DIVISIONS, qrtr);
        //each division's change from last quarter (skip for first)
        if(qrtr!=0)qrtCmpr(qrtrSls,DIVISIONS,qrtr);
        //total sales for quarter
        cout<<"Quarter "<<qrtr+1<<"'s total sales: $"
            <<qrtTtl(qrtrSls,DIVISIONS,qrtr)<<endl;
        //company's total increase from last quarter (skip for first)
        if(qrtr!=0)ttlCmpr(qrtrSls,DIVISIONS,qrtr);
        //division sale average
        cout<<"Division avg this quarter: $"<<divAvg(qrtrSls,DIVISIONS,qrtr)<<endl;
        //division with highest sales
        hAmt=hghDiv(qrtrSls,DIVISIONS,qrtr,hDiv);
        cout<<"Division "<<hDiv<<" had the highest sales at $"<<hAmt<<endl;
        cout<<endl<<endl;
    }
}//End Gaddis Chap6 Prob6

float hghDiv(float a[][QRTRS],int n,int q, int &h){
      float high=a[0][q];
      for(int d=0;d<n;d++){
          if(a[d][q]>high){
              high=a[d][q];
              h=d+1;
          }
      }
      return high;
}

float divAvg(float a[][QRTRS],int n,int q){
      float ttl=0,avg=0;
      for(int d=0;d<n;d++){
          ttl+=a[d][q];
      }
      avg=ttl/n;
      return avg;
}

void ttlCmpr(float a[][QRTRS],int n,int q){
     float pTtl=0;//total from previous quarter
     float ttl=0;//current quarter total
     for(int d=0;d<n;d++){
         pTtl+=a[d][q-1];
         ttl+=a[d][q];
     }
     cout<<"Company's change from last quarter: $"<<(ttl-pTtl)<<endl;
}

float qrtTtl(float a[][QRTRS],int n,int q){
     float ttl=0;
     for(int d=0;d<n;d++){
         ttl+=a[d][q];
     }
     return ttl;
}

void qrtCmpr(float a[][QRTRS],int n,int q){
     float dif1,dif2,dif3,dif4,dif5,dif6;
     cout<<"Changes from last Quarter:"<<endl;
     for(int d=0;d<n;d++){
         cout<<"Division "<<d+1<<" change: $"<<(a[d][q]-a[d][q-1])<<endl;
     }
     cout<<endl;
}

void lstSls(float a[][QRTRS],int n,int q){
     for(int d=0;d<n;d++){
         cout<<"Division "<<d+1<<" sales: $"<<a[d][q]<<endl;
     }
     cout<<endl;
}

void getFigs(float a[][QRTRS],int n){
     cout<<"Please enter the sales figures for all 6 divisions for each quarter."<<endl;
     for(int i=0;i<n;i++){
         for(int j=0;j<QRTRS;j++){
             do{
                 cout<<"Enter Q"<<(j+1)<<" sales for division "<<(i+1)<<": ";
                 cin>>a[i][j];
             }while(a[i][j]<0);
         }
     }
     cout<<endl;
}



    
//Begin Gaddis Chap7 Prob8
void prob7(){
        
}//End Gaddis Chap7 Prob8

    
    
    
    
//Begin Gaddis Chap7 Prob9
void prob8(){
       
}//End Gaddis Chap7 Prob9





//Begin Gaddis Chap7 Prob10
void prob9(){
    
}//End Gaddis Chap7 Prob10


void dflt(short val){
        cout<<"You typed "<<val<<" to exit the program"<<endl;
}
