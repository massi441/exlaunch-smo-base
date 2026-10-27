#include "ExampleMod/Hooks/PlayerInvincibleHook.h"

#include <Library/Controller/InputFunction.h>
#include <Player/PlayerTrigger.h>
#include <Scene/StageScene.h>
#include <exl/hook/trampoline.hpp>
#include <ml/Log/Log.h>
#include <ml/Mod/ModUtil.h>

namespace {

bool sInvincibleEnabled = false;

HOOK_DEFINE_TRAMPOLINE(StageSceneInitHook) {
    static void Callback(StageScene* thisPtr, const al::SceneInitInfo& info) {
        Orig(thisPtr, info);

        sInvincibleEnabled = ml::getModStorageValue<bool>("InvincibleEnabled", sInvincibleEnabled);
    }
};

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

            ml::setModStorageValue("InvincibleEnabled", sInvincibleEnabled);
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
    StageSceneInitHook::InstallAtSymbol("_ZN10StageScene4initERKN2al13SceneInitInfoE");
    StageScenePlayHook::InstallAtSymbol("_ZN10StageScene7exePlayEv");
    PlayerTriggerAnyDamageHook::InstallAtSymbol("_ZNK13PlayerTrigger13isOnAnyDamageEv");
}
