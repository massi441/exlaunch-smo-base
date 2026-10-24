# Change the name to something that you like, just make sure other instances are renamed as well
add_executable(ml_mod)

target_link_libraries(ml_mod PRIVATE ml_runtime)

target_sources(ml_mod PRIVATE
    main.cpp
    ModRegistry.cpp
)

# Pick a number for your subsdk, between 0 to 8; subsdk9 is reserved for the runtime.
# The last parameter is the name of the NSO module (which shows up in stack traces)
make_subsdk(ml_mod "subsdk8" "ml_mod")
