#include "gameInstance.h"

int main(void) 
{
	gameInstance* gi = new gameInstance(1080, 1080);

	gi->launchInstance();

	delete gi;
	
}






