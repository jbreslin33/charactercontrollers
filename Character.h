#ifndef Character_H
#define Character_H


#include "Ogre.h"
#include "OIS.h"

using namespace Ogre;
//using namespace OgreBites;

class Character
{
public:

	Character(Ogre::SceneManager* mSceneMgr, std::string name,int xPos, int yPos); // : NUM_MODELS(6), ANIM_CHOP(8)
	~Character();
    void addTime(Real deltaTime);

protected:

	void setupContent();
	void setupModels();
	void cleanupContent();

	SceneNode* mModelNodes;
	AnimationState* mAnimStates;
	Real mAnimSpeeds;

	Vector3 mSneakStartPos;
	Vector3 mSneakEndPos;

    std::string mName;
    Ogre::SceneManager* mSceneManager;

    int xPos;
    int yPos;
};

#endif

