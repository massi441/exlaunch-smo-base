# Change the name to something that you like, just make sure other instances are renamed as well
add_executable(ml_mod)

target_sources(ml_mod PRIVATE
    main.cpp
    ModRegistry.cpp
)

target_compile_definitions(ml_mod PRIVATE SUBSDK_MODULE_NAME="example_mod") # The name of the NSO module (shows up on stack traces)

# Pick a number for your subsdk, between 0 to 8; subsdk9 is reserved for the runtime.
make_subsdk(ml_mod "subsdk8" "ml_mod")
