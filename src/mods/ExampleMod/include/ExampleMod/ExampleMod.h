#pragma once

#include <ml/Mod/Mod.h>

namespace ml {

class ExampleMod : public ml::Mod {
public:
    void RegisterActors() override;
    void InstallHooks() override;
};

}
