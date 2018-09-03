//Game stats implementation and manipulation
#include<iostream>
using namespace std;
int main()
{
  unsigned int score= 5000;
  cout<<"score: "<<score<<endl;
  score+=100;
  cout<<"score: "<<score<<endl;

  int lives = 3;
  lives++;

  lives=3;
  int bonus = ++lives*10;

  //Using enum
  const int ALIEN_POINTS = 150;
  int alienskilled = 10;
  int score = alienskilled*ALIEN_POINTS;
  cout<<"score: "<<score<<endl;

  enum difficulty {NOVICE,EASY,NORMAL,HARD,UNBEATABLE};
  difficulty mydifficulty = EASY;

  enum ship {FIGHTER = 25,BOMBER,CRUISER=50,DESTROYER=100};
  ship myship = BOMBER;
  cout<<"\nTo upgrade my ship to a cruiser will cost "
  <<(CRUISER-myship)<<" Resource Points.\n";
  return 0;
}
