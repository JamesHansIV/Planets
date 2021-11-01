/*
*	Handles simulation calculations
**/

#ifndef SIMULATION_H
#define SIMULTAION_H

#include<SFML\System.hpp>
#include "Body.h"

class Simulation {
	private:
	double m_timeScale;
	float m_deltaTime;
	sf::Vector2f m_upperBounds;			//in kilometers	(lower, upper)
	sf::Vector2f m_lowerBounds;			//in kilometers (lower, upper)
	std::vector<Body>m_bodies;
	sf::Clock m_clock;

	public:
	//Simulation(sf::Vector2f lowerBounds, sf::Vector2f upperBounds);
	Simulation(float xLowerBound, float xUpperBound, float yLowerBound, float yUpperBound);
	void addBody(float mass, float radius, sf::Vector2f position, sf::Vector2f velocity, sf::Vector2f acceleration);
	void checkInBounds(int index);
	void checkCollisions();
	void removeBody();
	void update();
	void clear();

	void adjustTimeScale(double change);

	//getters and setters
	Body getBody(int index);
	int getNumBodies();
	double getTimeScale();			void setTimeScale(double scale);
	float getDeltaTime();			void setDeltaTime(float time);
	sf::Vector2f getUpperBounds();	void setUpperBounds(sf::Vector2f bounds);
	sf::Vector2f getLowerBounds();	void setLowerBounds(sf::Vector2f bounds);
	//float getXBound(bool upper);	void setXBounds(float lower, float upper);
	//float getYBound(bool upper);	void setYBounds(float lower, float upper);



	//potential need for optimization
	//look at boids distance calculation optimization
	//
};

#endif