#ifndef FPSCOUNTER_H
#define FPSCOUNTER_H

#include<vector>
#include<SFML\System.hpp>

class FPSCounter{
private:
	std::vector <float> frameTimes;
public:
	double calcFPS(float frameTime, int numFrameTimes);
};

#endif