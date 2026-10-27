#include "ExampleMod/Hooks/PlayerInvincibleHook.h"

#include <Library/Controller/InputFunction.h>
#include <Player/PlayerTrigger.h>
#include <Scene/StageScene.h>
#include <exl/hook/trampoline.hpp>
#include <ml/Log/Log.h>

namespace {

bool sInvincibleEnabled = false;

/**
 * Toggles the invincibility flag when Up is pressed on the D-Pad
 */
HOOK_DEFINE_TRAMPOLINE(StageScenePlayHook) {
    static void Callback(StageScene* thisPtr) {
        Orig(thisPtr);

        if (al::isPadTriggerUp(-1)) {
            sInvincibleEnabled = !sInvincibleEnabled;

            if (sInvincibleEnabled) {
                LOG_DEBUG("Activated invincibility mode");
            } else {
                LOG_DEBUG("Deactivated invincibility mode");
            }
        }
    }
};

/**
 * Stops the player from being entering the damage state
 */
HOOK_DEFINE_TRAMPOLINE(PlayerTriggerAnyDamageHook) {
    static bool Callback(const PlayerTrigger* thisPtr) {
        if (sInvincibleEnabled) {
            return false;
        }

        return Orig(thisPtr);
    }
};

}

void PlayerInvincibleHook::Install() {
    StageScenePlayHook::InstallAtSymbol("_ZN10StageScene7exePlayEv");
    PlayerTriggerAnyDamageHook::InstallAtSymbol("_ZNK13PlayerTrigger13isOnAnyDamageEv");
}
