//A Hero's inventory theme
#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main()
{
  vector<string> inventory;
  inventory.push_back("sword");
  inventory.push_back("armor");
  inventory.push_back("shield");

  vector<string>::iterator myIterator;
  vector<string>::const_iterator iter;

  cout<<"\nYour items:\n";
  for(iter = inventory.begin();iter!=inventory.end();iter++)
    cout<<*iter<<endl;

  cout<<"You have "<<inventory.size()<<" items";
  // cout<<"\nYour items:\n";
  // for(int i=0;i<inventory.size();i++)
  //   cout<<inventory[i]<<endl;



  cout<<"\nYou trade your sword for a battle-axe.";
  // inventory[0]="battle-axe";

  myIterator = inventory.begin();
  *myIterator = "battle axe";

  cout<<"You have "<<inventory.size()<<" items";
  cout<<"\nYour items:\n";
  for(int i=0;i<inventory.size();i++)
    cout<<inventory[i]<<endl;

  cout<<"\nThe item named "<<inventory[0]<<" has "<<inventory[0].size();
  cout<<" letters in it.\n";

  cout<<"\nThe item named "<<myIterator->size()<<" has "<<inventory[0].size();
  cout<<" letters in it.\n";

  cout<<"\nYou recover a crossbow from a slain enemy.";
  inventory.insert(inventory.begin(),"crossbow");


  cout<<"\nYour shield is destroyed in a fierce battle.";
  // inventory.pop_back();
  inventory.erase(inventory.begin()+2);

  cout<<"You have "<<inventory.size()<<" items";
  cout<<"\nYour items:\n";
  for(int i=0;i<inventory.size();i++)
    cout<<inventory[i]<<endl;

  cout<<"\nYou were robbed of all your possesions by a thief!";
  inventory.clear();
  if(inventory.empty())
  {
    cout<<"\nYou have nothing.\n";
  }
}
