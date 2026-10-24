# Change the name to something that you like, just make sure other instances are renamed as well
add_executable(example_mod)

target_link_libraries(example_mod PRIVATE ml_subsdk_startup)
target_link_libraries(example_mod PRIVATE ml_subsdk_common)

target_sources(example_mod PRIVATE
    main.cpp
    ModRegistry.cpp
)

target_compile_definitions(example_mod PRIVATE SUBSDK_MODULE_NAME="example_mod") # The name of the NSO module (shows up on stack traces)

make_nso(example_mod ${SUBSDK_DEPLOY_NAME})
