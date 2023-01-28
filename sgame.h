
#include<iostream>
#include<cstdlib>
#include<ctime>
#include<limits>
#include<string>
#include<vector>
using namespace std;
class Player
{
	public:
		Player();
		string name;
		int id;
		int runsscored;
		int ballsplayed;
		int ballsbowled;
		int runsgiven;
		int wicketstaken;
};
Player::Player()
{
	runsscored=0;
	ballsplayed=0;
	ballsbowled=0;
	runsgiven=0;
	wicketstaken=0;
	
}
class Team
{
	public:
		Team();
		string name;
		int totalrunsscored;
		int wicketslost;
		int totalballsbowled;
		vector<Player>players;
};
Team::Team()
{
	totalrunsscored=0;
	wicketslost=0;
	totalballsbowled=0;
	
}
class Game
{
	public:
		Game();
	int playersperteam;
	int maxballs;
	int totalplayers;
	string players[11];	
	bool isfirstinnings;
	Team teamA,teamB;
	Team *battingteam, *bowlingTeam;
	Player *batsman, *bowler;
		
	void welcome();
	void showallplayers();
	int takeintegerinput();
	void selectplayers();
	bool validateselectedplayer(int);
	void showteamplayers();
	void toss();
	void tosschoice(Team);
	void startfirstinnings();
	void initializeplayers();
	void playinnings();
	void bat();
	
};
Game::Game()
{
	playersperteam=4;
	maxballs=6;
	totalplayers=11;
	
	players[0] = "Virat";
	players[1] = "Rohit";
	players[2] = "Dhawan";
	players[3] = "Pant";
	players[4] = "Karthik";
	players[5] = "KLRahul";
	players[6] = "Jadeja";
	players[7] = "Hardik";
	players[8] = "Bumrah";
	players[9] = "BKumar";
	players[10] = "Ishant";
	
	isfirstinnings=false;
	teamA.name="Team-A";
	teamB.name="Team-B";
}
void Game::welcome()
{
	cout<<"_______________________________________________________________"<<endl;
	cout<<"|==========================CRIC-IN============================|"<<endl;
	cout<<"|                                                             |"<<endl;
	cout<<"|               welcome to virtual cricket gaem               |"<<endl;
	cout<<"_______________________________________________________________"<<endl;
	
	cout<<endl<<endl;
	cout<<"____________________________________________________________________________"<<endl;
	cout<<"|============================INSTRUCTION===================================|"<<endl;
	cout<<"----------------------------------------------------------------------------"<<endl;
	cout<<"|                                                                          |"<<endl;
	cout<<"|        1. create 2 team(team A and team B with -4                        |"<<endl;
	cout<<"|         players each ) from a given pool of 11 players.                  |"<<endl;
	cout<<"|        2. lead the toss and decide the choice of play.                   |"<<endl;
	cout<<"|        3. each innings will be of 6 balls                                |"<<endl;
	cout<<"----------------------------------------------------------------------------"<<endl;
}
void Game::showallplayers()
{
	cout<<endl;
	cout<<"---------------------------------------------------------------------------"<<endl;
	cout<<"|========================Pool of Players==================================|"<<endl;
	cout<<"---------------------------------------------------------------------------"<<endl;
	cout<<endl;
	
	for(int i=0;i<totalplayers;i++)
	{
		cout<<"\t\t\t["<<i<<"]"<<players[i]<<endl;
	}
}
int Game::takeintegerinput()
{
	int n;
	
	
	while(!(cin>>n))
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(),'\n');
		cout<<"invalid input ! \nPlease try again eith valid input: ";
	}
	return n;
}
void Game :: selectplayers()
{
	cout<<endl;
	cout<<"---------------------------------------------------------------------------"<<endl;
	cout<<"|============================Create Team-A and Team-B=====================|"<<endl;
	cout<<"---------------------------------------------------------------------------"<<endl;
	
	for(int i=0;i<playersperteam;i++)
	{
		//team A
		teamAselection:
		cout<<endl<<"Select player "<<i+1<<" of Team-A  - ";
		int playerindexteamA= takeintegerinput();
		
		if(playerindexteamA<0 || playerindexteamA >10)
		{
			cout<<endl<<"please select from the given players "<<endl;
			goto teamAselection;
		}
		else if(!validateselectedplayer(playerindexteamA))
		{
			cout<<endl<<"player has been selected already. Please select other player "<<endl;
			goto teamAselection;
		}
		else
		{
			Player teamAplayer;
		    teamAplayer.id= playerindexteamA;
		    teamAplayer.name = players[playerindexteamA];
		    teamA.players.push_back(teamAplayer);
		}
		
		//teamB
		teamBselection:
		cout<<endl<<"Select player "<<i+1<<" of Team-B  - ";
		int playerindexteamB= takeintegerinput();
		if(playerindexteamB<0 || playerindexteamB >10)
		{
		    cout<<endl<<"please select from the given players "<<endl;
		    
	     	goto teamBselection;
	    }
	    else
	    {
	    	Player teamBplayer;
		    teamBplayer.name = players[playerindexteamB];
		    teamB.players.push_back(teamBplayer);
	    }
	}
}
bool Game :: validateselectedplayer(int index)
{
	int n;
	vector<Player>players;
	players = teamA.players;
	n=players.size();
	for(int i=0;i<n;i++)
	{
		if(players[i].id== index)
		{
			return false;
		}
	}
	players = teamB.players;
	n=players.size();
	for(int i=0;i<n;i++)
	{
		if(players[i].id== index)
		{
			return false;
		}
	}
	return true;
}
void Game :: showteamplayers()
{
	vector<Player>teamAplayers = teamA.players;
	vector<Player>teamBplayers = teamB.players;
	cout<<endl<<endl;
	cout<<"-------------------------------\t\t--------------------------------"<<endl;
	cout<<"|===============Team A=========\t\t=============Team B=============|"<<endl;
	cout<<"-------------------------------\t\t--------------------------------"<<endl;
	
	for(int i=0;i<playersperteam;i++)
	{
		cout<<"|\t"<<"["<<i<<"]"<<teamAplayers[i].name<<"\t\t|"
		<<"\t\t\t"
		<<"|\t"<<"["<<i<<"]"<<teamBplayers[i].name<<"\t\t|"<<endl;
	}
	cout<<"-------------------------------\t\t-------------------------------"<<endl<<endl;
}
void Game :: toss()
{
	cout<<endl;
	cout<<"------------------------------------------------------------------"<<endl;
	cout<<"|=============================Let's Toss==========================|"<<endl;
	cout<<"------------------------------------------------------------------"<<endl<<endl;
	
	cout<<"Tossing the coin................."<<endl<<endl;
	srand(time(NULL));
	int randomvalue=rand()%2;
	switch(randomvalue)
	{
		case 0:
			cout<<"Team A won the toss "<<endl<<endl;
			tosschoice(teamA);
			break;
			case 1:
				cout<<"Team B won the toss "<<endl<<endl;
				tosschoice(teamB);
				break;
	}
}
void Game :: tosschoice(Team tosswinnerteam)
{
	cout<<"Enter 1 to bat or 2 to bowl first."<<endl
	<<"1. Bat "<<endl
	<<"2. Bowl"<<endl;
	
	int tossinput = takeintegerinput();
	
	cin.ignore(numeric_limits<streamsize>::max(),'\n');
	switch(tossinput)
	{
		case 1:
			cout<<endl<<tosswinnerteam.name<<"  won the toss and elected to bat first"<<endl<<endl;
			if(tosswinnerteam.name.compare("Team A") == 0)
			{
				battingteam = &teamA;
				bowlingTeam = &teamB;
			}
			else
			{
				battingteam = &teamB;
				bowlingTeam = &teamA;
			}
			break;
		case 2:
			cout<<endl<<tosswinnerteam.name<<"won the toss and elected to bowl first"<<endl<<endl;
			if(tosswinnerteam.name.compare("Team A") == 0)
			{
				bowlingTeam = &teamA;
				battingteam = &teamB;
			}
			else
			{
				bowlingTeam = &teamB;
				battingteam = &teamA;
			}
			break;
		default:
			cout<<endl<<"Invalid input . Please try again: "<<endl<<endl;
			tosschoice(tosswinnerteam);
			break;
	}
}
void Game :: startfirstinnings()
{
	cout<<"\t\t |||  FIRST INNINGS STARTS  |||"<<endl<<endl;
	isfirstinnings=true;
	initializeplayers();
	playinnings();
}
void Game :: initializeplayers()
{
	batsman = &battingteam->players[0];
	bowler = &bowlingTeam->players[0];
	
	cout<<battingteam->name<<"-"<<batsman->name<<"is batting "<<endl;
	cout<<bowlingTeam->name<<"-"<<bowler->name<<"is bowling "<<endl<<endl;
}
void Game :: playinnings()
{
	for(int i=0;i<maxballs;i++)
	{
		cout<<"Press enter to bowl.....";
		getchar();
		cout<<"Bowling......"<<endl;
		bat();
	}
}
void Game :: bat()
{
	srand(time(NULL));
	int runsscored = rand() % 7;
	//score bat
	batsman->runsscored = batsman->runsscored + runsscored;
	battingteam->totalrunsscored = battingteam->totalrunsscored + runsscored;
	batsman->ballsplayed = batsman->ballsplayed + 1;
	//bowler score
	bowler->ballsbowled = bowler->ballsbowled + 1;
	bowlingTeam->totalballsbowled = bowlingTeam->totalballsbowled + 1;
	bowler->runsgiven = bowler->runsgiven + runsscored;
	
	cout<<endl<<bowler->name<<" to "<<batsman->name<<" "<<runsscored<<" runs!"<<endl<<endl;
}



