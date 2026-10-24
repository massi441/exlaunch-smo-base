include(${CMAKE_SOURCE_DIR}/src/framework/cmake/deploy-util.cmake)

generate_npdm(${CMAKE_SOURCE_DIR}/src/framework/src/npdm.json)

deploy_nso(example_mod test_deploy ${CMAKE_SOURCE_DIR}/deploy)
deploy_nso(ml_runtime_subsdk runtime_deploy ${CMAKE_SOURCE_DIR}/deploy)

#if (MULTI_SUBSDK)
#    # deploy_nso(deploy ${MOD_SUBSDK_NAME} ${YUZU_PATH}/${MOD_NAME})
#    # deploy_nso(${MOD_SUBSDK_NAME} ${RYUJINX_PATH}/${MOD_NAME})
#    # deploy_nso(${MOD_SUBSDK_NAME} ${YUZU_PATH})
#    # deploy_nso(${MOD_SUBSDK_NAME} ${YUZU_PATH})
#endif ()
