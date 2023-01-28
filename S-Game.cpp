
#include"sgame.h"
using namespace std;
int main()
{
	Game game;
	game.welcome();
	cout<<"\n Press enter to continoue";
	getchar();
	game.showallplayers();
	//game.takeintegerinput();
	
	cout<<"\n Press enter to continoue";
	getchar();
	
	game.selectplayers();

	//game.validateselectedplayer();
	game.showteamplayers();
	
	//cin.ignore(numeric_limits<streamsize>::max(),'\n');
	
	cout<<"\n Press enter to continoue";
	getchar();
	
	game.toss();
	return 0;
}


