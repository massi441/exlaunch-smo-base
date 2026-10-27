# Change the name to something that you like, just make sure other instances are renamed as well
add_executable(ml_mod)

target_link_libraries(ml_mod PRIVATE ml_runtime)
target_link_libraries(ml_mod PRIVATE ml_mod_registry)

target_sources(ml_mod PRIVATE
    main.cpp
    ModRegistry.cpp
)

# Add all your registerable mods in this scope. For each one, pass:
# ----
# 1. The name of the cmake target of the mod
# 2. The name of the directory at which the mod is located
# 3. The name of the option that enables building the mod
# 4. The name of the option that enables registering the mod in ModRegistry.cpp
# ----
# Note: Not registering a mod is opt-in. When a mod is built, it is also registered by default.
# Registration can be turned off by setting the REGISTER_X variable to off in your CMake preset.
# Then, update your CMakePreset.json's presets to enable the mods of your choice
ml_add_registerable_mod(example_mod ExampleMod BUILD_EXAMPLE REGISTER_EXAMPLE)

# Pick a number for your subsdk, between 0 to 8; subsdk9 is reserved for the runtime.
# The last parameter is the name of the NSO module (which shows up in stack traces)
make_subsdk(ml_mod "subsdk8" "ml_mod")
