# Adds a mod library that doesn't require registration
function(ml_add_lib target dir option)
    option(${option} "Enable building the ${dir} library" OFF)
    if (NOT ${option})
        return()
    endif()

    add_subdirectory(${dir})
    target_link_libraries(ml_mod_base INTERFACE ${target})
    target_compile_definitions(ml_mod_base INTERFACE ${option})
endfunction()

# Adds a mod library with a mod that gets registered
function(ml_add_mod target dir option register)
    ml_add_lib(${target} ${dir} ${option})

    if (${option} AND (NOT DEFINED CACHE{${register}} OR ${register}))
        target_compile_definitions(ml_mod_base INTERFACE ${register})
    endif()
endfunction()

# Register all your custom mods in this function. For each mod, pass:
# ----
# 1. The name of the cmake target of the mod
# 2. The name of the directory at which the mod is located
# 3. The name of the option that enables building the mod
# 4. The name of the option that enables registering the mod in ModRegistry.cpp
# ----
# Note: Not registering a mod is opt-in. When a mod is built, it is also registered by default.
# Registration can be turned off by setting the REGISTER_X variable to off in your CMake preset.
function(ml_register_mods)
    ml_add_mod(example_mod ExampleMod BUILD_EXAMPLE REGISTER_EXAMPLE)
endfunction()
