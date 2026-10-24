#include "ModRegistry.h"

#ifdef ML_STATIC_RUNTIME
#include <ml/Mod/ModRuntime.h>
#endif

extern "C" void userMain() {
#ifdef ML_STATIC_RUNTIME
    ml::ModRuntime::Initialize();
#endif

    ml::ModRegistry::RegisterMods();
}
