#include "Character.h"

Character::Character(Camera* cam)
{
    mCamera = cam;
    mNumberOfBodys = 0;
    mBodysCreated = false;
	//setupBody(cam->getSceneManager());
}
Character::~Character() { }

	void Character::setupBodys(int numberOfBodys)
	{
	    mNumberOfBodys = numberOfBodys;
        for (int i = 0; i < numberOfBodys; i++)
        {
            // create main model
            mBodyNodes.push_back(mCamera->getSceneManager()->getRootSceneNode()->createChildSceneNode(Vector3::UNIT_Y * CHAR_HEIGHT));

			mModelNodes.push_back(mBodyNodes.at(i));

            mBodyEnts.push_back(mCamera->getSceneManager()->createEntity("SinbadBody" + StringConverter::toString(i + 1), "Sinbad.mesh"));
            mBodyNodes.at(i)->attachObject(mBodyEnts.at(i));

            mBodyNodes.at(i)->translate(10 * i, 0, -10  * i, Node::TS_LOCAL);

        }
	}










