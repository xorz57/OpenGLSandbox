add_executable(Example09 src/Main.cpp src/Shader.cpp)

target_include_directories(Example09 PRIVATE ${Stb_INCLUDE_DIR})

target_link_libraries(Example09 PRIVATE glad::glad)
target_link_libraries(Example09 PRIVATE glfw)
target_link_libraries(Example09 PRIVATE glm::glm)
target_link_libraries(Example09 PRIVATE imgui::imgui)

if(CMAKE_GENERATOR MATCHES "Visual Studio")
    add_custom_target(Example09Assets COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_CURRENT_LIST_DIR}/assets ${CMAKE_CURRENT_BINARY_DIR}/$<CONFIG>/assets)
else()
    add_custom_target(Example09Assets COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_CURRENT_LIST_DIR}/assets ${CMAKE_CURRENT_BINARY_DIR}/assets)
endif()
add_dependencies(Example09 Example09Assets)
