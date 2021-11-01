#include "FPSCounter.h"
#include<iostream>

double FPSCounter::calcFPS(float frameTime, int numFrames){
	//if the number of frameTimes in the vector is equal to the number of 
	//frames in the average remove the oldest frame time from the vecotr
	if(frameTimes.size() == numFrames){
		frameTimes.erase(frameTimes.begin());
	} 

	//add new frame time to the end of the vector
	frameTimes.push_back(frameTime);

	//calculate fps
	float totalFrameTime = 0;

	for(int i = 0; i < frameTimes.size(); i++){
		totalFrameTime += frameTimes[i];
	}
	
	return (frameTimes.size() / totalFrameTime);
}