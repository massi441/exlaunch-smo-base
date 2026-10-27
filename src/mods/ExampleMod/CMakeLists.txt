add_library(example_mod)

target_include_directories(example_mod PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

target_link_libraries(example_mod PRIVATE ml_core_smo) # ml_core_smo brings in all the framework dependencies

file(GLOB_RECURSE SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp
)

target_sources(example_mod PRIVATE ${SOURCES})
