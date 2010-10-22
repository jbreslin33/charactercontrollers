#ifndef __CHARACTER_H__
#define __CHARACTER_H__

#include "Ogre.h"
#include "OIS.h"

using namespace Ogre;

#define CHAR_HEIGHT 5          // height of character's center of mass above ground

class Character
{

public:

    Character(Camera* cam, int numberOfCharacters, std::vector<std::string> names,	std::vector<std::string> meshes);
    ~Character();

	void setupBody(SceneManager* sceneMgr);

protected:

	Camera* mCamera;

	std::vector<SceneNode*> mModelNodes;
	std::vector<Entity*>    mBodyEnts;
	std::vector<SceneNode*> mBodyNodes;
	std::vector<std::string*> mNames;
	std::vector<std::string*> mMeshes;

    int mNumberOfCharacters;

};

#endif
