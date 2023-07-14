option(ASSIMP_BUILD_ASSIMP_TOOLS OFF)
option(ASSIMP_BUILD_SAMPLES OFF)
option(ASSIMP_BUILD_TESTS OFF)
add_subdirectory(${CMAKE_SOURCE_DIR}/3rdparty/assimp)

set_target_properties(assimp PROPERTIES FOLDER 3rdparty) # Override standard 'GLFW3' subfolder

set(ASSIMP_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/3rdparty/assimp/include)
# set(GLFW_DEFINITIONS -DGLFW_INCLUDE_NONE)
set(ASSIMP_LIBRARIES ${ASSIMP_LIBRARIES} assimp)