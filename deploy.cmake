generate_npdm(${CMAKE_SOURCE_DIR}/src/framework/src/npdm.json)

if (YUZU_MODS_PATH)
    deploy_mod(yuzu_deploy ${YUZU_MODS_PATH}/${MOD_NAME}/exefs)
endif()

if (RYUJINX_MODS_PATH)
    deploy_mod(ryujinx_deploy ${RYUJINX_MODS_PATH}/${MOD_NAME}/exefs)
endif()
