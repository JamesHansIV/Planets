#include "HUD.h"

HUD::HUD(sf::RenderWindow& window){
	//vars
	help = false;
	hideHud = false;
	fpsToggle = true;
	textCharSize = 12;
	textColor = sf::Color::White;

	//initialize font
	font.loadFromFile("consola.ttf");

	//intialize texts
	initializeText(fpsText, 5, 5);
	initializeText(playSpeedText, 5, window.getSize().y - 20);
	initializeText(helpText, 5, window.getSize().y - 45);
}

void HUD::initializeText(sf::Text& text, int xPos, int yPos) {
	text.setFont(font);
	text.setCharacterSize(textCharSize);
	text.setFillColor(textColor);
	text.setPosition(xPos, yPos);
}

void HUD::toggleHud(){
	if(hideHud) hideHud = false;
	else hideHud = true;
}

void HUD::toggleFPS() {
	if(fpsToggle) {
		fpsToggle = false;
		fpsText.setString("");
	} else {
		fpsToggle = true;
	}	
}

void HUD::toggleHelp() {
	if(!help) {
		help = true;
		helpText.setPosition(5, helpText.getPosition().y - 110);
		helpText.setString("H: Close help\nF: Toggle FPS\nM: moon\nE: earth\nS: sun\nC: clear planets\nRL Arrows: Increase/decrease simulation speed\nSpace: Pause/unpause\nLeft Click : Custom Planet(not implemented)");
	} else {
		help = false;
		helpText.setPosition(5, helpText.getPosition().y + 110);
		helpText.setString("H: Help");
	}
}

void HUD::updateTexts(double timeScale, float frameTime){
	std::string str;

	//update fps
	if(fpsToggle) {
		str = std::to_string(fps.calcFPS(frameTime, 200));
		str.erase(6, 9);
		fpsText.setString("FPS: " + str);
	}

	//update playspeed
	if(timeScale != 0) {
		str = std::to_string(timeScale);
		if(timeScale == 1) str.erase(1, 9);
		else if(timeScale < 10) {
			str.erase(4, 9);
		} else str.erase(5.9);
		playSpeedText.setString(str + "x Speed");
	}
	else playSpeedText.setString("Paused");

	//update help
	if(!help) {
		helpText.setString("H: Help");
	}
}

void HUD::updateHUD(sf::RenderWindow& window, double timeScale, float frameTime){
	//update
	updateTexts(timeScale, frameTime);

	//draw
	if(!hideHud) {
		window.draw(fpsText);
		window.draw(playSpeedText);
		window.draw(helpText);
	}
}
