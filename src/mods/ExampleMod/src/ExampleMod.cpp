#include "ExampleMod/ExampleMod.h"

#include <ml/Mod/FactoryRegistry.h>

#include "ExampleMod/Actors/MyActor.h"
#include "ExampleMod/Hooks/PlayerInvincibleHook.h"

namespace ml {

void ExampleMod::InstallHooks() {
    PlayerInvincibleHook::Install();
}

void ExampleMod::RegisterActors() {
    ml::RegisterFactoryActor<MyActor>("MyActor");
}

}
