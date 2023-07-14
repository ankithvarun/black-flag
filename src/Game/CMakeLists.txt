make_executable()

target_precompile_headers(${PROJECT} PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/stdafx.h)

target_include_directories(${PROJECT} PUBLIC
    ${PLOG_INCLUDE_DIR}
    ${GLM_INCLUDE_DIR}
    ${OPENGL_INCLUDE_DIR}
    ${GLFW_INCLUDE_DIR}
    ${GLAD_INCLUDE_DIR}
    ${IMGUI_INCLUDE_DIR}
    ${STB_INCLUDE_DIR}
    ${ASSIMP_INCLUDE_DIR}
    )

target_link_libraries(${PROJECT}
    ${OPENGL_LIBRARIES}
    ${GLFW_LIBRARIES}
    ${GLAD_LIBRARIES}
    ${IMGUI_LIBRARIES}
    ${ASSIMP_LIBRARIES}
    MathLib
    FftLib
    GraphicsLib
    OceanLib
    ShipLib
    PirateShipLib
    CannonballLib
    TreasureLib
    )

# Data files
configure_file(
    ${CMAKE_CURRENT_SOURCE_DIR}/data/ocean.cfg
    ${CMAKE_CURRENT_BINARY_DIR}/data/ocean.cfg COPYONLY)
configure_file(
    ${CMAKE_CURRENT_SOURCE_DIR}/data/ocean.vert
    ${CMAKE_CURRENT_BINARY_DIR}/data/ocean.vert COPYONLY)
configure_file(
    ${CMAKE_CURRENT_SOURCE_DIR}/data/ocean.frag
    ${CMAKE_CURRENT_BINARY_DIR}/data/ocean.frag COPYONLY)
    
configure_file(
    ${CMAKE_CURRENT_SOURCE_DIR}/data/ship.vert
    ${CMAKE_CURRENT_BINARY_DIR}/data/ship.vert COPYONLY)
    
configure_file(
    ${CMAKE_CURRENT_SOURCE_DIR}/data/ship.frag
    ${CMAKE_CURRENT_BINARY_DIR}/data/ship.frag COPYONLY)

configure_file(
    ${CMAKE_CURRENT_SOURCE_DIR}/data/ship.mtl
    ${CMAKE_CURRENT_BINARY_DIR}/data/ship.mtl COPYONLY)

configure_file(
    ${CMAKE_CURRENT_SOURCE_DIR}/data/ship.obj
    ${CMAKE_CURRENT_BINARY_DIR}/data/ship.obj COPYONLY)

configure_file(
    ${CMAKE_CURRENT_SOURCE_DIR}/data/PirateShip.mtl
    ${CMAKE_CURRENT_BINARY_DIR}/data/PirateShip.mtl COPYONLY)
    
configure_file(
    ${CMAKE_CURRENT_SOURCE_DIR}/data/PirateShip.obj
    ${CMAKE_CURRENT_BINARY_DIR}/data/PirateShip.obj COPYONLY)

configure_file(
    ${CMAKE_CURRENT_SOURCE_DIR}/data/cannonball.mtl
    ${CMAKE_CURRENT_BINARY_DIR}/data/cannonball.mtl COPYONLY)

configure_file(
    ${CMAKE_CURRENT_SOURCE_DIR}/data/cannonball.obj
    ${CMAKE_CURRENT_BINARY_DIR}/data/cannonball.obj COPYONLY)

configure_file(
    ${CMAKE_CURRENT_SOURCE_DIR}/data/texture.jpg
    ${CMAKE_CURRENT_BINARY_DIR}/data/texture.jpg COPYONLY)
        
configure_file(
    ${CMAKE_CURRENT_SOURCE_DIR}/data/treasure.mtl
    ${CMAKE_CURRENT_BINARY_DIR}/data/treasure.mtl COPYONLY)

configure_file(
    ${CMAKE_CURRENT_SOURCE_DIR}/data/treasure.obj
    ${CMAKE_CURRENT_BINARY_DIR}/data/treasure.obj COPYONLY)

configure_file(
    ${CMAKE_CURRENT_SOURCE_DIR}/data/treasure_chest.jpg
    ${CMAKE_CURRENT_BINARY_DIR}/data/treasure_chest.jpg COPYONLY)

configure_file(
    ${CMAKE_CURRENT_SOURCE_DIR}/data/Sail_Texture.jpg
    ${CMAKE_CURRENT_BINARY_DIR}/data/Sail_Texture.jpg COPYONLY)

configure_file(
    ${CMAKE_CURRENT_SOURCE_DIR}/data/Sail_Texture.png
    ${CMAKE_CURRENT_BINARY_DIR}/data/Sail_Texture.png COPYONLY)

configure_file(
    ${CMAKE_CURRENT_SOURCE_DIR}/data/Wood.jpg
    ${CMAKE_CURRENT_BINARY_DIR}/data/Wood.jpg COPYONLY)

configure_file(
    ${CMAKE_CURRENT_SOURCE_DIR}/data/Wood2.jpg
    ${CMAKE_CURRENT_BINARY_DIR}/data/Wood2.jpg COPYONLY)
    
configure_file(
    ${CMAKE_CURRENT_SOURCE_DIR}/data/Metal.jpg
    ${CMAKE_CURRENT_BINARY_DIR}/data/Metal.jpg COPYONLY)

    configure_file(
    ${CMAKE_CURRENT_SOURCE_DIR}/data/texture002.png
    ${CMAKE_CURRENT_BINARY_DIR}/data/texture002.png COPYONLY)

configure_file(
    ${CMAKE_CURRENT_SOURCE_DIR}/data/texture007.png
    ${CMAKE_CURRENT_BINARY_DIR}/data/texture007.png COPYONLY)

# Screen post-processing shaders
configure_file(
    ${CMAKE_CURRENT_SOURCE_DIR}/data/screen.vert
    ${CMAKE_CURRENT_BINARY_DIR}/data/screen.vert COPYONLY)

configure_file(
    ${CMAKE_CURRENT_SOURCE_DIR}/data/screen.frag
    ${CMAKE_CURRENT_BINARY_DIR}/data/screen.frag COPYONLY)


