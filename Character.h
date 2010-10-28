#ifndef __CHARACTER_H__
#define __CHARACTER_H__

#include "Ogre.h"
#include "OIS.h"

using namespace Ogre;

#define CHAR_HEIGHT 5          // height of character's center of mass above ground

class Character
{

public:

    Character(Camera* cam);
    ~Character();

	void setupBodys(int numberOfBodys);



	Camera* mCamera;

	std::vector<SceneNode*> mModelNodes;
	std::vector<Entity*>    mBodyEnts;
	std::vector<SceneNode*> mBodyNodes;

};

#endif
