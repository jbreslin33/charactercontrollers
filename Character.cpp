
#include "Character.h"

    Character::Character(Camera* cam, int numberOfCharacters, std::vector<std::string> names, std::vector<std::string> meshes)
{
    mNames              = names;
    mMeshes             = meshes;
    mNumberOfCharacters = numberOfCharacters;

	setupBody(cam->getSceneManager());
}

	void Character::setupBody(SceneManager* sceneMgr)
	{
        for (int i = 0; i < mNumberOfCharacters; i++)
        {
            // create main model
            mBodyNodes.push_back(sceneMgr->getRootSceneNode()->createChildSceneNode(Vector3::UNIT_Y * CHAR_HEIGHT));

			mModelNodes.push_back(mBodyNodes.at(i));

            mBodyEnts.push_back(sceneMgr->createEntity("SinbadBody" + StringConverter::toString(i + 1), "Sinbad.mesh"));
            mBodyNodes.at(i)->attachObject(mBodyEnts.at(i));

            mBodyNodes.at(i)->translate(10 * i, 0, -10  * i, Node::TS_LOCAL);

        }
	}










