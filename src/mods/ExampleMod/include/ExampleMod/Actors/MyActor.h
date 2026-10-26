#pragma once

#include <Library/LiveActor/LiveActor.h>

namespace ml {

/**
 * A simple static actor that reacts to Cappy's attacks and damages
 * Mario when touching him.
 */
class MyActor : public al::LiveActor {
public:
    MyActor(const char* name);
    
    void init(const al::ActorInitInfo& info) override;
    void attackSensor(al::HitSensor* self, al::HitSensor* other) override;
    bool receiveMsg(const al::SensorMsg* message, al::HitSensor* other, al::HitSensor* self) override;
    void movement() override;

    void exeWait();
    void exeCapHit();

private:
    const char* mCapHitMessage = nullptr;
};

}