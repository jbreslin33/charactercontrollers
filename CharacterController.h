
#ifndef __CHARACTERCONTROLLER_H__
#define __CHARACTERCONTROLLER_H__

#include "Ogre.h"
#include "OIS.h"

using namespace Ogre;

#define NUM_ANIMS 13           // number of animations the character has
#define CHAR_HEIGHT 5          // height of character's center of mass above ground
#define CAM_HEIGHT 2           // height of camera above character's center of mass
#define TURN_SPEED 500.0f      // character turning in degrees per second
#define ANIM_FADE_SPEED 7.5f   // animation crossfade speed in % of full weight per second
#define JUMP_ACCEL 30.0f       // character jump acceleration in upward units per squared second
#define GRAVITY 90.0f          // gravity in downward units per squared second

class CharacterController
{
protected:

	// all the animations our character has, and a null ID
	// some of these affect separate body parts and will be blended together
	enum AnimID
	{
		ANIM_IDLE_BASE,
		ANIM_IDLE_TOP,
		ANIM_RUN_BASE,
		ANIM_RUN_TOP,
		ANIM_HANDS_CLOSED,
		ANIM_HANDS_RELAXED,
		ANIM_DRAW_SWORDS,
		ANIM_SLICE_VERTICAL,
		ANIM_SLICE_HORIZONTAL,
		ANIM_DANCE,
		ANIM_JUMP_START,
		ANIM_JUMP_LOOP,
		ANIM_JUMP_END,
		ANIM_NONE
	};

public:

    CharacterController(Camera* cam);
    ~CharacterController();

	void addTime(Real deltaTime);
	void injectKeyDown(const OIS::KeyEvent& evt);
	void injectKeyUp(const OIS::KeyEvent& evt);

#if OGRE_PLATFORM == OGRE_PLATFORM_IPHONE
	void injectMouseMove(const OIS::MultiTouchEvent& evt);
    void injectMouseDown(const OIS::MultiTouchEvent& evt);

#else
	void injectMouseMove(const OIS::MouseEvent& evt);


	void injectMouseDown(const OIS::MouseEvent& evt, OIS::MouseButtonID id);

#endif

	void setupBody(SceneManager* sceneMgr);
	void setupAnimations();
	void setupCamera(Camera* cam);
	void updateBody(Real deltaTime);
	void updateAnimations(Real deltaTime);
	void fadeAnimations(Real deltaTime);
    void updateCamera(Real deltaTime);
    void updateCameraGoal(Real deltaYaw, Real deltaPitch, Real deltaZoom);
	void setTopAnimation(AnimID id, bool reset = false);
	void setRunSpeed(Real runSpeed);
	void run();
	void setBaseAnimation(AnimID id, bool reset = false);

protected:

    std::string mName;
	Camera* mCamera;

	SceneNode* mCameraPivot;
	SceneNode* mCameraGoal;
	SceneNode* mCameraNode;
	Real mPivotPitch;

	AnimationState* mAnims[NUM_ANIMS];    // master animation list
	AnimID mBaseAnimID;                   // current base (full- or lower-body) animation
	AnimID mTopAnimID;                    // current top (upper-body) animation
	bool mFadingIn[NUM_ANIMS];            // which animations are fading in
	bool mFadingOut[NUM_ANIMS];           // which animations are fading out

	Vector3 mGoalDirection;     // actual intended direction in world-space
	Real mVerticalVelocity;     // for jumping
	Real mTimer;                // general timer to see how long animations have been playing
	Real mRunSpeed;
	Vector3 mKeyDirection;      // player's local intended direction based on WASD keys

public:


	std::vector<SceneNode*> mModelNodes;

	Entity*    mBodyEnt;
    SceneNode* mBodyNode;

    //std::vector<Entity*> mBodyEntVec;
	//std::vector<SceneNode*> mBodyNodeVec;

    int mMyElementInVector;

};

#endif
