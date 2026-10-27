#include "ModRegistry.h"

#include <ml/Log/Log.h>
#include <ml/Mod/Mod.h>

#ifdef REGISTER_EXAMPLE
#include <ExampleMod/ExampleMod.h>
#endif

namespace ml {

void ModRegistry::RegisterMods() {
    LOG_INFORMATION("Registering mods for module '%s'", ML_SUBSDK_MODULE_NAME);

    ml::setLogLevel(ml::LogLevel::Verbose);

#ifdef REGISTER_EXAMPLE
    ml::RegisterMod<ml::ExampleMod>("EXAMPLE_MOD");
#endif

    LOG_INFORMATION("Registered mods for module '%s'", ML_SUBSDK_MODULE_NAME);
}

}
