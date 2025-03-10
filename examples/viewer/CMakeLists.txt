## Copyright 2021 The Khronos Group
## SPDX-License-Identifier: Apache-2.0

if (${CMAKE_SOURCE_DIR} STREQUAL ${CMAKE_CURRENT_SOURCE_DIR})
  message(FATAL_ERROR
    "The ANARI example viewer currently cannot be built stand alone from the"
    " SDK source tree."
  )
endif()

project(anariViewer LANGUAGES CXX)

## Build viewer ##

add_executable(${PROJECT_NAME}
  MainWindow.cpp
  main.cpp
  OrbitManipulator.cpp
)

target_compile_definitions(${PROJECT_NAME} PRIVATE GLM_ENABLE_EXPERIMENTAL)

target_link_libraries(${PROJECT_NAME} PRIVATE
  imgui_glfw
  anari
  anari_test_scenes
  stb_image
  glad
)

install(TARGETS ${PROJECT_NAME}
  LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
  RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
  ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
)
