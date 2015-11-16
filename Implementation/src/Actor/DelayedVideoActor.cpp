// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //
// Team USA - Software Engineering Project (Fall 2015).
// LEGEND OF THE GREAT UNWASHED
// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //
/// \file DelayedVideoActor.cpp
/// \brief Declares DelayedVideoActor class.
// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //
#include "DelayedVideoActor.h"

using namespace teamusa;

	DelayedVideoActor::DelayedVideoActor( Region region, int textureID, int delaysteps, int disappearStep,int layer ){
		//....
		mVideo = new ActorVideo;
		mVideo->textureID = textureID;
		mVideo->layer = layer;

		delaySteps=disappearStep - delaysteps;
		textureId=textureID;
		currentStep =0;
		disappear = -1;
	}

	DelayedVideoActor::~DelayedVideoActor( void ){
		//....
		delete mVideo;
	}


	const ActorEvent DelayedVideoActor::step(Player& player)
	{
		// Handle per-frame updates...

		ActorEvent e;
		// Assign data...
		currentStep++;

		if (currentStep == delaySteps) {
			mVideo->textureID = textureId;
		}
		else if (currentStep == disappear) {
			mVideo->textureID = -1;
		}

		return e;
	}

	// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //




