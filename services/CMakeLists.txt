cmake_minimum_required(VERSION 3.20)

project(drive_api
    VERSION 0.1.0
    DESCRIPTION "Drive backend API service"
    LANGUAGES CXX
)

include(GNUInstallDirs)

# ========================
# Find Softadastra (GLOBAL)
# ========================
find_package(softadastra REQUIRED)

# ========================
# Sources
# ========================
file(GLOB_RECURSE DRIVE_API_SOURCES
    CONFIGURE_DEPENDS
    "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp"
)

# ========================
# Executable
# ========================
add_executable(drive_api ${DRIVE_API_SOURCES})

target_compile_features(drive_api PRIVATE cxx_std_20)

target_include_directories(drive_api
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# ========================
# Linking
# ========================
target_link_libraries(drive_api
    PRIVATE
        drive::engine
        softadastra::cli
)

# ========================
# Compiler options
# ========================
if(MSVC)
    target_compile_options(drive_api PRIVATE /W4 /permissive-)
else()
    target_compile_options(drive_api PRIVATE -Wall -Wextra -Wpedantic)
endif()

# ========================
# Install
# ========================
install(
    TARGETS drive_api
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

# ========================
# Summary
# ========================
message(STATUS "------------------------------------------------------")
message(STATUS "drive_api configured (${PROJECT_VERSION})")
message(STATUS "Using global softadastra package")
message(STATUS "------------------------------------------------------")
