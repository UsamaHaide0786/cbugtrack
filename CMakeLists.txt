# Set architecture explicitly for arm64
set(CMAKE_OSX_ARCHITECTURES "x86_64")
set(CMAKE_OSX_DEPLOYMENT_TARGET "10.12" CACHE STRING "Minimum OS X deployment version" FORCE)
# Set compilers for the arm64 architecture (clang and clang++)
set(CMAKE_C_COMPILER /usr/bin/clang)
set(CMAKE_CXX_COMPILER /usr/bin/clang++)

# Project name and configurations
project(bugtrack)

set(CMAKE_CXX_STANDARD 11)

# Find and link FLTK
find_package(FLTK REQUIRED)
include_directories(${FLTK_INCLUDE_DIR})

# Use pkg-config to find Cairo
find_package(PkgConfig REQUIRED)
pkg_check_modules(CAIRO REQUIRED cairo)

# Include directories for Cairo and FLTK
include_directories(${CAIRO_INCLUDE_DIRS})
include_directories(${FLTK_INCLUDE_DIR})

# Link directories for Cairo and FLTK
link_directories(${CAIRO_LIBRARY_DIRS})
link_directories(${FLTK_LIBRARY_DIRS})

# Define source files
set(SOURCES
		src/main.cpp
)

# Create an executable and specify it's a macOS application bundle
add_executable(${PROJECT_NAME} MACOSX_BUNDLE ${SOURCES})

# Link libraries (FLTK and Cairo)
target_link_libraries(${PROJECT_NAME} ${FLTK_LIBRARIES} ${CAIRO_LIBRARIES})

# Set application properties to specify the bundle
set_target_properties(${PROJECT_NAME} PROPERTIES
		MACOSX_BUNDLE TRUE
		MACOSX_BUNDLE_GUI_IDENTIFIER com.yourcompany.bugtrack
		MACOSX_BUNDLE_BUNDLE_VERSION 1.0
		MACOSX_BUNDLE_SHORT_VERSION_STRING 1.0
		MACOSX_BUNDLE_LONG_VERSION_STRING "BugTrack version 1.0"
		MACOSX_BUNDLE_ICON_FILE "resources/123.icns"
)

# If you have any additional resources like images or icons
# You can copy them into the bundle
install(FILES resources/123.icns DESTINATION ${CMAKE_BINARY_DIR}/${PROJECT_NAME}.app/Contents/Resources)

# Optionally, add a post-build step to move resources or finalize the app bundle
add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
		COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_SOURCE_DIR}/resources ${CMAKE_BINARY_DIR}/${PROJECT_NAME}.app/Contents/Resources
)