#include<iostream>
using namespace std;
int main()
{
  cout<<"\nWelcome to Computer Guess\n\n";
  cout<<"This is a game where you will pick a number from 1-100 and then the computer ";
  cout<<"will try to guess it within 7 moves!\n";
  // cout<<"Enter a number: ";
  int low=1,high=100;
  int med=(low+high)/2;
  int answer=0;
  int moves=0;
  while(low<=high)
  {
    med=(low+high)/2;
    moves++;
    cout<<"Is the number "<<med<<" ?"<<endl;
    cout<<"(Enter 1 for equal, 2 for less than and 3 for greater than)"<<endl;
    cin>>answer;
    if(answer==1)
    {
      cout<<"The number is "<<med<<"!!"<<endl;
      cout<<"Found in "<<moves<<" moves"<<endl;
      break;
    }
    else if(answer==3)
    {
      low=med+1;
    }
    else
    {
      high=med-1;
    }
  }
  cout<<"GAME OVER"<<endl;
  return 0;
}
