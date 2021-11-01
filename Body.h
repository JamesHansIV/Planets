#ifndef BODY_H
#define BODY_H

#include<SFML\Graphics.hpp>

class Body{
private:
	const float G = 6.67e-15; //do scale math to make actual constant
	//const float G = 6.67e-11;
	float m_mass;	//in gigagrams
	float m_radius; //1 pixel = Gm (1e6 km)
	sf::Vector2f m_position;
	sf::Vector2f m_velocity; //
	sf::Vector2f m_acceleration;
	bool m_collided;

public:
	//constructors
	Body() {}
	Body(float mass, float radius, sf::Vector2f position, sf::Vector2f velocity, sf::Vector2f acceleration);

	//copy constructor
	Body(const Body& original);

	//asignment operator
	Body& operator=(const Body& original);

	//destructor
	~Body();
	
	//getters and setters
	bool getCollided();					void setCollided(bool collided);
	float getMass();					void setMass(float mass);
	float getRadius();					void setRadius(float radius);
	sf::Vector2f getPosition();			void setPosition(sf::Vector2f position);
	sf::Vector2f getVelocity();			void setVelocity(sf::Vector2f velocity);
	sf::Vector2f getAcceleration();		void setAcceleration(sf::Vector2f acceleration); 

	//methods
	void updateVelocity(std::vector<Body>&bodies, float deltaTime, float timeScale);
	void updatePosition(float deltaTime, double timeScale);
	void collide(Body& other, float distance);
	bool inBounds(sf::RenderWindow& window);

};

#endif BODY_H