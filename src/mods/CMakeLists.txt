add_executable(ml_mods) # Change the name to something that you like

target_link_libraries(ml_mods PRIVATE ml_subsdk_startup)

target_sources(ml_mods PRIVATE
    main.cpp
    ModRegistry.cpp
)

target_compile_definitions(ml_mods PRIVATE SUBSDK_MODULE_NAME="ml_mods")
