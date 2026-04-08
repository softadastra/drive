cmake_minimum_required(VERSION 3.20)

project(drive
    VERSION 0.1.0
    DESCRIPTION "Offline-first file sync powered by Softadastra"
    LANGUAGES CXX
)

include(GNUInstallDirs)
include(CMakePackageConfigHelpers)
include(CTest)

# ========================
# Global options
# ========================
option(DRIVE_BUILD_APP "Build drive application" ON)
option(DRIVE_BUILD_TESTS "Build drive tests" OFF)
option(DRIVE_BUILD_EXAMPLES "Build drive examples" OFF)
option(DRIVE_INSTALL "Install drive packages" ON)
option(DRIVE_WARNINGS_AS_ERRORS "Treat warnings as errors" OFF)

# ========================
# Propagate options
# ========================
set(DRIVE_BUILD_TESTS
    ${DRIVE_BUILD_TESTS}
    CACHE BOOL "Build drive tests" FORCE
)

set(DRIVE_WARNINGS_AS_ERRORS
    ${DRIVE_WARNINGS_AS_ERRORS}
    CACHE BOOL "Treat warnings as errors" FORCE
)

# ========================
# Global settings
# ========================
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

# ========================
# Helper
# ========================
function(drive_add_component component_name)
    set(component_dir "${CMAKE_CURRENT_SOURCE_DIR}/components/${component_name}")

    if(EXISTS "${component_dir}/CMakeLists.txt")
        message(STATUS "[drive] adding component: ${component_name}")
        add_subdirectory("${component_dir}")
    else()
        message(FATAL_ERROR "[drive] missing component: ${component_name}")
    endif()
endfunction()

# ========================
# Components
# ========================
drive_add_component(watcher)
drive_add_component(adapter)
drive_add_component(engine)

# ========================
# App
# ========================
if(DRIVE_BUILD_APP)
    if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/app/CMakeLists.txt")
        add_subdirectory(app)
    else()
        message(FATAL_ERROR "[drive] app/ exists but CMakeLists.txt is missing")
    endif()
else()
    message(STATUS "[drive] app disabled")
endif()

# ========================
# Root package config
# ========================
if(DRIVE_INSTALL)
    write_basic_package_version_file(
        "${CMAKE_CURRENT_BINARY_DIR}/driveConfigVersion.cmake"
        VERSION ${PROJECT_VERSION}
        COMPATIBILITY SameMajorVersion
    )

    configure_package_config_file(
        "${CMAKE_CURRENT_SOURCE_DIR}/cmake/driveConfig.cmake.in"
        "${CMAKE_CURRENT_BINARY_DIR}/driveConfig.cmake"
        INSTALL_DESTINATION "${CMAKE_INSTALL_LIBDIR}/cmake/drive"
        PATH_VARS CMAKE_INSTALL_LIBDIR
    )

    install(
        FILES
            "${CMAKE_CURRENT_BINARY_DIR}/driveConfig.cmake"
            "${CMAKE_CURRENT_BINARY_DIR}/driveConfigVersion.cmake"
        DESTINATION "${CMAKE_INSTALL_LIBDIR}/cmake/drive"
    )

    install(
        FILES
            "${CMAKE_CURRENT_SOURCE_DIR}/README.md"
            "${CMAKE_CURRENT_SOURCE_DIR}/LICENSE"
        DESTINATION "${CMAKE_INSTALL_DATADIR}/drive"
        OPTIONAL
    )
endif()

# ========================
# Summary
# ========================
message(STATUS "------------------------------------------------------")
message(STATUS "Drive configured (${PROJECT_VERSION})")
message(STATUS "Build app:        ${DRIVE_BUILD_APP}")
message(STATUS "Build tests:      ${DRIVE_BUILD_TESTS}")
message(STATUS "Build examples:   ${DRIVE_BUILD_EXAMPLES}")
message(STATUS "Install:          ${DRIVE_INSTALL}")
message(STATUS "Warnings=error:   ${DRIVE_WARNINGS_AS_ERRORS}")
message(STATUS "Build type:       ${CMAKE_BUILD_TYPE}")
message(STATUS "Install prefix:   ${CMAKE_INSTALL_PREFIX}")
message(STATUS "------------------------------------------------------")
