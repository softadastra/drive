cmake_minimum_required(VERSION 3.20)

function(drive_add_app_if_present app_name)
    set(app_dir "${CMAKE_CURRENT_SOURCE_DIR}/${app_name}")

    if(EXISTS "${app_dir}/CMakeLists.txt")
        message(STATUS "[drive] adding app: ${app_name}")
        add_subdirectory("${app_name}")
    else()
        message(STATUS "[drive] skipping app: ${app_name} (no CMakeLists.txt)")
    endif()
endfunction()

drive_add_app_if_present(bridge)
drive_add_app_if_present(cli)
drive_add_app_if_present(desktop)
drive_add_app_if_present(mobile)
drive_add_app_if_present(web)
