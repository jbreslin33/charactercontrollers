#include "Character.h"

	Character::Character(Ogre::SceneManager* mSceneMgr, std::string name,int x, int y)
	{
	    mName = name;
	    xPos = x;
	    yPos = y;
	    mSceneManager = mSceneMgr;
        setupModels();
	}

    void Character::addTime(Real deltaTime)
    {
        mAnimStates->addTime(mAnimSpeeds * deltaTime);
        /*
        for (unsigned int i = 0; i < NUM_MODELS; i++)
        {
			// update sneaking animation based on speed
			mAnimStates[i]->addTime(mAnimSpeeds[i] * deltaTime);

			if (mAnimStates[i]->getTimePosition() >= ANIM_CHOP)   // when it's time to loop...
			{

				Quaternion rot(Degree(-60), Vector3::UNIT_Y);   // how much the animation turns the character

				// find current end position and the offset
				Vector3 currEnd = mModelNodes[i]->getOrientation() * mSneakEndPos + mModelNodes[i]->getPosition();
				Vector3 offset = rot * mModelNodes[i]->getOrientation() * -mSneakStartPos;

				mModelNodes[i]->setPosition(currEnd + offset);
				mModelNodes[i]->rotate(rot);

				mAnimStates[i]->setTimePosition(0);   // reset animation time
			}
        }
        */
    }

	void Character::setupModels()
	{

		SceneNode* sn = NULL;
		Entity* ent = NULL;
		AnimationState* as = NULL;

      // for (unsigned int i = 0; i < NUM_MODELS; i++)
       // {
			// create scene nodes for the models at regular angular intervals
			sn = mSceneManager->getRootSceneNode()->createChildSceneNode();
			//sn->yaw(Radian(Math::TWO_PI * (float)i / (float)NUM_MODELS));
			sn->translate(xPos, yPos, -20, Node::TS_LOCAL);
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
        //}

		// create name and value for skinning mode
		//StringVector names;
		//names.push_back("Skinning");
		//String value = "Software";

		// change the value if hardware skinning is enabled
        //Pass* pass = ent->getSubEntity(0)->getMaterial()->getBestTechnique()->getPass(0);
		//if (pass->hasVertexProgram() && pass->getVertexProgram()->isCharacterIncluded()) value = "Hardware";

	}

	void Character::cleanupContent()
	{
		mModelNodes = NULL;
		mAnimStates = NULL;
		mAnimSpeeds = NULL;
	}









