add_executable(Example06 src/Main.cpp)

target_include_directories(Example06 PRIVATE ${Stb_INCLUDE_DIR})

target_link_libraries(Example06 PRIVATE glad::glad)
target_link_libraries(Example06 PRIVATE glfw)
target_link_libraries(Example06 PRIVATE glm::glm)
target_link_libraries(Example06 PRIVATE imgui::imgui)

if(CMAKE_GENERATOR MATCHES "Visual Studio")
    add_custom_target(Example06Assets COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_CURRENT_LIST_DIR}/assets ${CMAKE_CURRENT_BINARY_DIR}/$<CONFIG>/assets)
else()
    add_custom_target(Example06Assets COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_CURRENT_LIST_DIR}/assets ${CMAKE_CURRENT_BINARY_DIR}/assets)
endif()
add_dependencies(Example06 Example06Assets)
