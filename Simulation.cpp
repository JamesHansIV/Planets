
#include "Simulation.h"
#include <iostream>

Simulation::Simulation(float xLowerBound, float xUpperBound, float yLowerBound, float yUpperBound) {
	m_timeScale = 1;
	m_lowerBounds.x = xLowerBound;
	m_upperBounds.x = xUpperBound;
	m_lowerBounds.y = yLowerBound;
	m_upperBounds.y = yUpperBound;
}

//addBody
void Simulation::addBody(float mass, float radius, sf::Vector2f position, sf::Vector2f velocity, sf::Vector2f acceleration) {
	m_bodies.push_back(Body(mass, radius, position, velocity, acceleration));
}

//checkInBounds
void Simulation::checkInBounds(int index) {
	if(index < m_bodies.size()) {
		if(m_bodies[index].getPosition().x < m_upperBounds.x && m_bodies[index].getPosition().x > m_lowerBounds.x && m_bodies[index].getPosition().y < m_upperBounds.y && m_bodies[index].getPosition().y > m_lowerBounds.y) {
			checkInBounds(index++); //call function again
		} else {

			m_bodies.erase(m_bodies.begin() + index); //erase current body if out of bounds
			checkInBounds(index);
		}
	}
}

//checkCollisions
void Simulation::checkCollisions() {
	for(int i = 0; i < m_bodies.size(); i++) {
		for(int j = 0; j < m_bodies.size(); i++) {
		
		}
	}
}


//removeBody
void Simulation::removeBody() {
	
}

void Simulation::clear() {
	m_bodies.clear();
}

//update
void Simulation::update() {
	//restart clock
	m_deltaTime = m_clock.restart().asSeconds();

	//update body kinematics
	for(int i = 0; i < m_bodies.size(); i++) {
		m_bodies[i].updateVelocity(m_bodies, m_deltaTime,m_timeScale);
		m_bodies[i].updatePosition(m_deltaTime, m_timeScale);
	}

	//check boundries
	for(int i = 0; i < m_bodies.size(); i++) {
		//checkInBounds(0); //also need to delete corresponding circle
	}
}

void Simulation::adjustTimeScale(double change) {
	m_timeScale += change;
	if(m_timeScale < 0) m_timeScale = 0;
}

//getters
Body Simulation::getBody(int index) { 
	//std::cout << m_bodies[index].getRadius();
	return m_bodies[index]; }
int Simulation::getNumBodies() { return m_bodies.size(); }
double Simulation::getTimeScale() { return m_timeScale; }
float  Simulation::getDeltaTime() { return m_deltaTime; }
sf::Vector2f Simulation::getUpperBounds() { return m_upperBounds; }
sf::Vector2f Simulation::getLowerBounds() { return m_lowerBounds; }

//setters
void Simulation::setTimeScale(double scale) { m_timeScale = scale; }
void Simulation::setDeltaTime(float time) { m_deltaTime = time; }
void Simulation::setUpperBounds(sf::Vector2f bounds) { m_upperBounds = bounds; }
void Simulation::setLowerBounds(sf::Vector2f bounds) { m_lowerBounds = bounds; }

//void Simulation::setXBounds(float lower, float upper) {
//	m_lowerBounds.x = lower;
//}
//void Simulation::setYBounds(float lower, float upper) {
//	m_yBounds[0] = lower;
//	m_yBounds[1] = upper;
//}