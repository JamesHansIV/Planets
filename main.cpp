
#include<SFML\Graphics.hpp>
#include<SFML\Window.hpp>
#include<SFML\System.hpp>
#include<iostream>

/*
	FEATURES TO ADD/Bugs to fix											Date Completed	Notes
	0.	Why dont the planets fly off the left and tops of window		9.17.2021		
	1.	Separate files and cleaner main.cpp								9.17.2021
	2.	UI overlay (should be very simple)								9.21.2021
	3.	Pause/Play														10.31.2021
			Time multiplier for fast forward and slow down				10.31.2021
	4.	User Input														10.14.2021
	5.	Collisions
	6.	Planet trajectary paths
	7.	Planet trails
	8.	Custom planet creation and input
	9.	FPS Counter														9.21.2021
	10.	"Stary" background
	11.	Zoom/frame of reference
	13. A few predefined bodies (star, moon, etc)	

	!!! NO MORE UNLESS ABSOLUTELY NECESSARY !!!
*/


#include "Body.h"
#include "Simulation.h";
#include "FPSCounter.h"

#include "HUD.h"




int main() {
	//Create Window
	sf::RenderWindow window(sf::VideoMode(1200,800), "Planets", sf::Style::Titlebar | sf::Style::Resize | sf::Style::Close);

	//create hud
	HUD hud(window);

	//load font
	sf::Font font;
	if(!font.loadFromFile("consola.ttf")) std::cout << "\nError!";

	sf::Text text;
	text.setFont(font);
	text.setCharacterSize(10);
	text.setFillColor(sf::Color::White);

	int frameCount = 0;

	//create circle vector
	std::vector<sf::CircleShape> circles;

	//create fpscounter
	FPSCounter fps;

	//create simulation
	Simulation sim(-1.0e100,-1.0e100,1.0e100,1.0e100);

	//open window and run it as long as the window is open
	while(window.isOpen()) {
		sf::Event event;

		//check events
		while(window.pollEvent(event)) {
			//close event
			if(event.type == sf::Event::Closed) {
				window.close();
			}
			if(event.type == sf::Event::MouseButtonReleased) {
				//sf::Vector2i mousePos = {sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y};
				//
				////Create new body object
				//sim.addBody(10e12, 5, {(float)mousePos.x, (float)mousePos.y}, {0,0}, {0,0});

				////Create new circle object
				//sf::CircleShape c(sim.getBody(sim.getNumBodies() - 1).getRadius());
				//c.setFillColor(sf::Color::Blue);
				//circles.push_back(c);

			}
			if(event.type == sf::Event::KeyReleased){
				if(event.key.code == sf::Keyboard::Right) {
					sim.adjustTimeScale(0.25);
				}
				if(event.key.code == sf::Keyboard::Left) {
					sim.adjustTimeScale(-0.25);
				}
				if(event.key.code == sf::Keyboard::Space) {
					if(sim.getTimeScale() != 0) {
						sim.setTimeScale(0);
					} else {
						sim.setTimeScale(1);
					}
				}
				if(event.key.code == sf::Keyboard::C) {
					circles.clear();
					sim.clear();
				}
				if(event.key.code == sf::Keyboard::E){
					//Create new body objec
					sf::Vector2i mousePos = {sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y};

					//Create new body object
					sim.addBody(5.972e18, 6378e-3, {(float)mousePos.x, (float)mousePos.y}, {0,0}, {0,0});

					//Create new circle object
					sf::CircleShape c(sim.getBody(sim.getNumBodies() - 1).getRadius());
					c.setFillColor(sf::Color::Blue);
					circles.push_back(c);
				}
				if(event.key.code == sf::Keyboard::M){
					//Create new body objec
					sf::Vector2i mousePos = {sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y};

					//Create new body object
					sim.addBody(7.348e16, 1738e-3, {(float)mousePos.x, (float)mousePos.y}, {15,0}, {0,0});

					//Create new circle object
					sf::CircleShape c(sim.getBody(sim.getNumBodies() - 1).getRadius());
					c.setFillColor(sf::Color::White);
					circles.push_back(c);
				}
				if(event.key.code == sf::Keyboard::S) {
					//Create new body objec
					sf::Vector2i mousePos = {sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y};

					//Create new body object
					sim.addBody(1998.5e3, 132712, {(float)mousePos.x, (float)mousePos.y}, {0,0}, {0,0});

					//Create new circle object
					sf::CircleShape c(sim.getBody(sim.getNumBodies() - 1).getRadius());
					c.setFillColor(sf::Color::Yellow);
					circles.push_back(c);
				}
				if(event.key.code == sf::Keyboard::H) {
					hud.toggleHelp();
				}
				if(event.key.code == sf::Keyboard::F) {
					hud.toggleFPS();
				}
			}
		}
		sim.update();
		float frameTime = sim.getDeltaTime();


		window.clear(sf::Color::Black);

		
		if(circles.size() > 0) {
			for(int i = 0; i < circles.size(); i++) {
				try {
					circles[i].setPosition(sim.getBody(i).getPosition().x - circles[i].getRadius(), sim.getBody(i).getPosition().y - circles[i].getRadius());
					window.draw(circles[i]);
				} catch (std::runtime_error&) {
					std::cout << "eror" << std::endl;
				}
			}
		}


		//update HUD
		hud.updateHUD(window, sim.getTimeScale(), frameTime);

		window.display();
	}



	return 0;
}