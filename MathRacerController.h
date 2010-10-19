#ifndef __MATHRACERCONTROLLER_H__
#define __MATHRACERCONTROLLER_H__

#include "Ogre.h"
#include "OIS.h"

#include "SinbadCharacterController.h"

using namespace Ogre;


class MathRacerController : public SinbadCharacterController
{

public:

	MathRacerController(Camera* cam,std::string name) : SinbadCharacterController(cam,name)
	{
	}

	void run()
	{
        mKeyDirection.z = -1;
        setBaseAnimation(ANIM_RUN_BASE, true);
	}
};

#endif
