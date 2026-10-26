#include "ExampleMod/Actors/MyActor.h"

#include <Library/LiveActor/ActorActionFunction.h>
#include <Library/LiveActor/ActorInitUtil.h>
#include <Library/LiveActor/ActorSensorUtil.h>
#include <Library/Nerve/NerveSetupUtil.h>
#include <Library/Nerve/NerveUtil.h>
#include <Library/Placement/PlacementFunction.h>
#include <Util/SensorMsgFunction.h>
#include <ml/Input/InputUtil.h>
#include <ml/Log/Log.h>

namespace ml {

namespace {

NERVE_IMPL(MyActor, Wait)
NERVE_IMPL(MyActor, CapHit)

NERVES_MAKE_STRUCT(MyActor, Wait, CapHit)

}

MyActor::MyActor(const char* name) : al::LiveActor(name) {

}

void MyActor::init(const al::ActorInitInfo& info) {
    al::initActor(this, info); // this initializes the actor with whatever name is in the level editor

    al::initNerve(this, &NrvMyActor.Wait, 0);

    al::tryGetStringArg(&mCapHitMessage, info, "CapHitMessage"); // this reads the debug message property stored in the level editor

    this->makeActorAlive();
}

void MyActor::attackSensor(al::HitSensor* self, al::HitSensor* other) {
    rs::sendMsgPushToPlayer(other, self);

    if (al::sendMsgEnemyAttack(other, self)) {
        LOG_TRACE("Haha! Hit target %s!", al::getSensorHost(other)->getName());
    }
}

bool MyActor::receiveMsg(const al::SensorMsg* message, al::HitSensor* other, al::HitSensor* self) {
    if (!al::isNerve(this, &NrvMyActor.CapHit) && (rs::isMsgCapAttack(message) || rs::isMsgCapAttackCollide(message))) {
        al::setNerve(this, &NrvMyActor.Wait);
        return true;
    }

    return false;
}

void MyActor::movement() {
    al::LiveActor::movement();
    // Add any logic that needs to run per frame here
}

void MyActor::exeWait() {
    if (al::isFirstStep(this)) {
        al::startAction(this, "Wait");
    }
}

void MyActor::exeCapHit() {
    if (al::isFirstStep(this)) {
        al::startAction(this, "Wait");

        if (mCapHitMessage) {
            LOG_DEBUG("Hit by cappy! %s", mCapHitMessage);
        }
    }

    if (al::isActionEnd(this)) {
        al::setNerve(this, &NrvMyActor.Wait);
    }
}

}
