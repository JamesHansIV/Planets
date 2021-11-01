#ifndef HUD_H
#define HUD_H

//made up of ui elements

#include<SFML\Graphics.hpp>
#include<SFML\Window.hpp>

#include "FPSCounter.h"

class HUD {
private:
	//ui elements
	/*						Done
		1. fps				X
		2. help				X
		3. controls
		4. planet info
	*/

	//vars
	bool hideHud;
	bool help;
	bool fpsToggle;
	int textCharSize;
	sf::Color textColor;

	FPSCounter fps;

	sf::Font font;
	sf::Text fpsText;		//text that displays fps
	sf::Text scaleText;		//text for scale
	sf::Text playSpeedText;	//text for play speed / pause / play
	sf::Text helpText;

public:
	//Constructor
	HUD(sf::RenderWindow& window);

	//text
	void initializeText(sf::Text& text, int xPos, int yPos);


	//methods
	void updateHUD(sf::RenderWindow& window, double timeScale, float frameTime);

	//update functions
	void updateTexts(double timeScale, float frameTime);

	void toggleHud();
	void toggleHelp();
	void toggleFPS();
	void displayUserControls();
 
};

#endif