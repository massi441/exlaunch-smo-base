generate_npdm(${CMAKE_SOURCE_DIR}/src/framework/src/npdm.json)

deploy_mod(test_deploy ${CMAKE_SOURCE_DIR}/deploy)

# TODO: Yuzu, Ryujinx, and FTP deployments