#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string>
#include <vector>
#define SCRWIDTH  800
#define SCRHEIGHT  600

	int game_state=1;


#include "functions.hpp"
#include "state_manager.hpp" 
#include "importer.hpp"


int main()
{

    sf::RenderWindow window(sf::VideoMode(SCRWIDTH, SCRHEIGHT), "GRA");

//ziarno liczb losowych
srand (time(NULL));

Intro intro;
Logo logo;
Game_screen game;
intro.initialize("Intro",&window);
logo.initialize("Logo",&window);
game.initialize("Game Screen",&window);

bool clockstart = 0;
sf::Clock clock;
sf::Time timeSinceLastUpdate;

    while (window.isOpen())
    {
	
        if(game_state==1){
			
		intro.Run();
		
	}
	
	if(game_state==2){
		
			logo.Run();

		}
       
           	if(game_state==3){

				if (!clockstart){
					clock.restart();
					timeSinceLastUpdate = sf::Time::Zero;
					clockstart = 1;
				}

			game.Run(clock, timeSinceLastUpdate);
		
		}
		
			if(game_state==4){
			std::cout<<"GAME OVER"<<std::endl;
			return 0;
		
		}
           
    }
    
    return 0;
}
