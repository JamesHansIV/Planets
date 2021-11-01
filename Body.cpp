#include "Body.h"
#include <iostream>

//Constructor
Body::Body(float mass, float radius, sf::Vector2f position, sf::Vector2f velocity, sf::Vector2f acceleration) {
	m_mass = mass;
	m_radius = radius;
	m_position = position;
	m_velocity = velocity;
	m_acceleration = acceleration;
}

//Copy Constructor
 Body::Body(const Body& original) {
	m_mass = original.m_mass;
	m_radius = original.m_radius;
	m_position = original.m_position;
	m_velocity = original.m_velocity;
	m_acceleration = original.m_acceleration;
 }

//assignment operator
Body& Body::operator=(const Body& original) {
	m_mass = original.m_mass;
	m_radius = original.m_radius;
	m_position = original.m_position;
	m_velocity = original.m_velocity;
	m_acceleration = original.m_acceleration;
	return *this;
}

//Destructor
Body::~Body(){}

//getters
bool Body::getCollided() { return m_collided; }
float Body::getMass() { return m_mass; }
float Body::getRadius(){ return m_radius; }
sf::Vector2f Body::getPosition() { return m_position; }
sf::Vector2f Body::getVelocity() { return m_velocity; }
sf::Vector2f Body::getAcceleration() { return m_acceleration; }

//setters
void Body::setCollided(bool collided) { m_collided = collided; }
void Body::setMass(float mass) { m_mass = mass; }
void Body::setRadius(float radius) { m_radius = radius; }
void Body::setPosition(sf::Vector2f position) { m_position = position; }
void Body::setVelocity(sf::Vector2f velocity) { m_velocity = velocity; }
void Body::setAcceleration(sf::Vector2f acceleration) { m_acceleration = acceleration; }

//methods
void Body::updateVelocity(std::vector<Body>& bodies, float deltaTime, float timeScale) {
	sf::Vector2f force;

	for(int i = 0; i < bodies.size(); i++) {
		float distance = sqrtf(powf(m_position.x - bodies[i].getPosition().x, 2) + powf(m_position.y - bodies[i].getPosition().y, 2));

		//check for collision
		if(!m_collided && !bodies[i].getCollided() && distance < m_radius + bodies[i].getRadius() && distance != 0) {
			collide(bodies[i], distance);
		}

		if(distance != 0) {
			//find unit vector do determine direction of grav force
			sf::Vector2f unitVector = (bodies[i].getPosition() - m_position) / distance;

			//find force using universal gravitation
			
			force = unitVector * G * m_mass * bodies[i].getMass() / powf(distance, 2);

			//calculate acceleration based off of force
			m_acceleration = force / m_mass;

			//calculate new velocity
			m_velocity += m_acceleration * deltaTime * timeScale;
		}
	}
}

void Body::updatePosition(float deltaTime, double timeScale){
 	m_position.x += m_velocity.x * deltaTime * timeScale;
	m_position.y += m_velocity.y * deltaTime * timeScale;
	m_collided = false;
}


//after collision 
void Body::collide(Body& other, float distance) {
	std::cout << "Collision!" << std::endl;

	//impulse
	 
}

bool Body::inBounds(sf::RenderWindow& window) {
	if(m_position.x > 10 && m_position.x < window.getSize().x && m_position.y > 10 && m_position.y < window.getSize().y) {
		return true;
	} else {
		return false;
	}
}