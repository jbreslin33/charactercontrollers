#include "Character.h"

	Character::Character(Ogre::SceneManager* mSceneMgr, std::string name,int x, int y, int z)
	{
	    //unique character name
	    mName = name;

	    //starting position
	    xPos = x;
	    yPos = y;
	    zPos = z;

        //the all powerful SceneManager
	    mSceneManager = mSceneMgr;

        //actually create and show the model on screen...assuming you put it somewhere visible etc.
        setupModel();
	}

    void Character::addTime(Real deltaTime)
    {
        mAnimStates->addTime(mAnimSpeeds * deltaTime);
    }

	void Character::setupModel()
	{

		SceneNode* sn = NULL;
		Entity* ent = NULL;
		AnimationState* as = NULL;

		// create scene nodes for the models at regular angular intervals
		sn = mSceneManager->getRootSceneNode()->createChildSceneNode();
		//sn->yaw(Radian(Math::TWO_PI * (float)i / (float)NUM_MODELS));
		sn->translate(xPos, yPos, zPos, Node::TS_LOCAL);
		mModelNodes = sn;

		// create and attach a jaiqua entity
        ent = mSceneManager->createEntity(mName, "Sinbad.mesh");
		sn->attachObject(ent);

		// enable the entity's sneaking animation at a random speed and loop it manually since translation is involved
		as = ent->getAnimationState("Dance");
        as->setEnabled(true);
        as->setLoop(true);
		mAnimSpeeds = Math::RangeRandom(0.5, 1.5);
		mAnimStates = as;

	}

    void Character::updateBody      (Real deltaTime)
    {

    }
    void Character::updateAnimations(Real deltaTime)
    {

    }
    void Character::updateCamera    (Real deltaTime)
    {

    }

	void Character::cleanupContent()
	{
		mModelNodes = NULL;
		mAnimStates = NULL;
		mAnimSpeeds = NULL;
	}









