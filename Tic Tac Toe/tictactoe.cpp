//Tic Tac Toe
//Play's a game of tic tac toe against a human opponent

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

//Globals
const char X = 'X';
const char O = 'O';
const char EMPTY = ' ';
const char TIE = 'T';
const char NO_ONE = 'N';

//functions
void instructions();
char askYesNo(string question);
int askNumber(string question, int high, int low = 0);
char humanPiece();
char opponent(char piece);
void displayBoard(const vector<char>& board);
char winner(const vector<char>& board);
bool isLegal(const vector<char>& board, int move);
int humanMove(const vector<char>& board, char human);
int computerMove(vector<char> board, char computer);
void announceWinner(char winner, char computer, char human);

int main()
{
  int move;
  const int NUM_SQUARES = 9;
  vector<char> board(NUM_SQUARES,EMPTY);

  instructions();
  char human = humanPiece();
  char computer = opponent(human);
  char turn = X;
  displayBoard(board);

  while(winner(board)==NO_ONE)
  {
    if(turn==human)
    {
      move  = humanMove(board, human);
      board[move] = human;
    }
    else
    {
      move = computerMove(board, computer);
      board[move] = computer;
    }
    displayBoard(board);
    turn = opponent(turn);
  }

  announceWinner(winner(board), computer, human);

  return 0;
}

void instructions()
{
  cout<<"Welcome to Tic Tac Toe, a showdown between Man and Machine\n";
  cout<<"This is where you come to test your mettle in the legendary game of the X's and O's\n\n";

  cout<<"Make your move by entering a set of numbers from 0 to 8.\n";
  cout<<"It corresponds to the boxes shown below\n\n";

  cout<<"1 | 2 | 3\n";
  cout<<"---------\n";
  cout<<"4 | 5 | 6\n";
  cout<<"---------\n";
  cout<<"7 | 8 | 9\n";

  cout<<"Prepare yourself!\n\n";
}

char askYesNo(string question)
{
  char response;
  do {
    cout<<question<< "(y/n): ";
    cin>>response;
  } while(response != 'y' && response!= 'n');
  return response;
}

int askNumber(string question, int high, int low)
{
  int number;
  do{
    cout<<question<<" ("<<low+1<<" - "<<high+1<<"): ";
    cin>>number;
  } while(number>high+1 || number<low+1);
  return number-1;
}

char humanPiece()
{
  char go_first = askYesNo("Do you want the first move?");
  if(go_first == 'y')
  {
    cout<<"\nThen take the first move. You will need it.\n";
    return X;
  }
  else
  {
    cout<<"\nYour bravery will lead to your downfall.\n";
    return O;
  }
}

char opponent(char piece)
{
  if(piece == X)
    return O;
  else
    return X;
}

void displayBoard(const vector<char>& board)
{
  cout<<"\n\t"<<board[0]<<" | "<<board[1]<<" | "<<board[2];
  cout<<"\n\t"<<"------------";
  cout<<"\n\t"<<board[3]<<" | "<<board[4]<<" | "<<board[5];
  cout<<"\n\t"<<"------------";
  cout<<"\n\t"<<board[6]<<" | "<<board[7]<<" | "<<board[8];
  cout<<"\n\t"<<"------------";
  cout<<"\n\n";
}

char winner(const vector<char>& board)
{
  const int WINNING_ROWS[8][3] = {
    {0,1,2},
    {3,4,5},
    {6,7,8},
    {0,3,6},
    {1,4,7},
    {2,5,8},
    {0,4,8},
    {2,4,6}
  };

  const int TOTAL_ROWS = 8; //Number of ways to win in the game

  for(int row=0;row<TOTAL_ROWS;row++)
  {
    if(board[WINNING_ROWS[row][0]]!=EMPTY &&
    board[WINNING_ROWS[row][0]]==board[WINNING_ROWS[row][1]] &&
    board[WINNING_ROWS[row][1]]==board[WINNING_ROWS[row][2]])
    {
      return board[WINNING_ROWS[row][0]];
    }
  }

  if(count(board.begin(),board.end(),EMPTY) == 0)
    return TIE;

  return NO_ONE;
}

inline bool isLegal(int move, const vector<char>& board)  //Inline is good for marking
{
  return (board[move] == EMPTY);
}

int humanMove(const vector<char>& board, char human)
{
  int move = askNumber("Where will you play?",(board.size()-1));
  while(!isLegal(move,board))
  {
    cout<<"\nThat square is already occupied!\n";
    move = askNumber("Where will you play?",(board.size()-1));
  }
  cout<<"Cool!\n";
  return move;
}

//Implementing AI
//If computer can win in this move, do it
//If human can win next move, block it
//If nothing is know, then take boxes in following order, centre, corner and then middle of side
int computerMove(vector<char> board, char computer)
{
  //If computer can win the next move, make the move
  for(int move=0;move<board.size();move++)
  {
    if(isLegal(move,board))
    {
      board[move] = computer;
      if(winner(board) == computer)
      {
        cout<<move<<endl;
        return move;
      }
      board[move] = EMPTY;
    }
  }

  char human = opponent(computer);
  for(int move=0;move<board.size();move++)
  {
    if(isLegal(move,board))
    {
      board[move] = human;
      if(winner(board) == human)
      {
        cout<<move<<endl;
        return move;
      }
      board[move] = EMPTY;
    }
  }
  //AI part to improve
  // const int BEST_MOVES[] = {4,0,2,6,8,1,3,5,7};
  // for(int i=0;i<board.size();i++)
  // {
  //   int move = BEST_MOVES[i];
  //   if(isLegal(move,board))
  //   {
  //     cout<<move<<endl;
  //     return move;
  //   }
  // }

  //New AI
  if(board[4]== human)
  {
    if(board[0]==computer && board[2]==computer && board[6]==EMPTY && board[3]==EMPTY && board[1]==EMPTY)  //8 conditions for checking double attacks
    {
      int move = 6;
      cout<<move<<endl;
      return move;
    }
    else if(board[0]==computer && board[2]==computer && board[5]==EMPTY && board[8]==EMPTY && board[1]==EMPTY)
    {
      int move = 8;
      cout<<move<<endl;
      return move;
    }
    else if(board[0]==computer && board[6]==computer && board[3]==EMPTY && board[7]==EMPTY && board[8]==EMPTY)
    {
      int move = 8;
      cout<<move<<endl;
      return move;
    }
    else if(board[0]==computer && board[6]==computer && board[3]==EMPTY && board[1]==EMPTY && board[2]==EMPTY)
    {
      int move = 2;
      cout<<move<<endl;
      return move;
    }
    else if(board[6]==computer && board[8]==computer && board[2]==EMPTY && board[5]==EMPTY && board[7]==EMPTY)
    {
      int move = 2;
      cout<<move<<endl;
      return move;
    }
    else if(board[6]==computer && board[8]==computer && board[3]==EMPTY && board[0]==EMPTY && board[7]==EMPTY)
    {
      int move = 0;
      cout<<move<<endl;
      return move;
    }
    else if(board[2]==computer && board[8]==computer && board[5]==EMPTY && board[0]==EMPTY && board[1]==EMPTY)
    {
      int move = 0;
      cout<<move<<endl;
      return move;
    }
    else if(board[2]==computer && board[8]==computer && board[5]==EMPTY && board[6]==EMPTY && board[7]==EMPTY)
    {
      int move = 6;
      cout<<move<<endl;
      return move;
    }
    const int BEST_MOVES[] = {4,0,2,6,8,1,3,5,7};
    for(int i=0;i<board.size();i++)
    {
      int move = BEST_MOVES[i];
      if(isLegal(move,board))
      {
        cout<<move<<endl;
        return move;
      }
    }
  }
  else
  {
    if((board[0]==human && board[8] == human) || (board[2]==human && board[6] == human)) //Conditions for checking DA when computer occupies centre
    {
      const int BEST_MOVES[] = {1,3,5,7,0,2,6,8,4};
      for(int i=0;i<board.size();i++)
      {
        int move = BEST_MOVES[i];
        if(isLegal(move,board))
        {
          cout<<move<<endl;
          return move;
        }
      }
    }
    else
    {
      if(board[4]==computer)
      {
        if(board[0]==computer && board[2]==EMPTY && board[3]==EMPTY&&board[6]==EMPTY)
        {
          int move = 6;
          cout<<move<<endl;
          return move;
        }
        else if(board[2]==computer&&board[0]==EMPTY&&board[5]==EMPTY&&board[8]==EMPTY)
        {
          int move = 8;
          cout<<move<<endl;
          return move;
        }
        else if(board[6]==computer&&board[0]==EMPTY&&board[7]==EMPTY&&board[8]==EMPTY)
        {
          int move = 8;
          cout<<move<<endl;
          return move;
        }
        else if(board[8]==computer&&board[2]==EMPTY&&board[6]==EMPTY&&board[7]==EMPTY)
        {
          int move = 6;
          cout<<move<<endl;
          return move;
        }
      }
      const int BEST_MOVES[] = {4,0,2,6,8,1,3,5,7};
      for(int i=0;i<board.size();i++)
      {
        int move = BEST_MOVES[i];
        if(isLegal(move,board))
        {
          cout<<move<<endl;
          return move;
        }
      }
    }
  }
}

void announceWinner(char winner, char computer, char human)
{
  if(winner == computer)
  {
    cout<<winner<<"'s won!\n";
    cout<<"You can't beat this AI, LOL!\n";
  }
  else if (winner == human)
  {
    cout<<winner<<"'s won!\n'";
    cout<<"Good Job, but can you beat it again?\n";
  }
  else
  {
    cout<<"It's a tie!\n";
    cout<<"Try again to see if you can beat the AI!\n";
  }
}

//Improvements
//Can make a better AI which will randomize all the "smart" moves available for it
//Display of the board can be formatted
//Can implement a multiplayer component where the opponent is a player from the network
