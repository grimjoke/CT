# boilerplate
cmake_minimum_required(VERSION 3.16.3)
project(CT VERSION 0.2.0)

#ADDER use logic 

option(USE_ADDER "A simple library for adding two floats" ON)

if(USE_ADDER)
    
    add_subdirectory(Adder)

    list(APPEND EXTRA_LIBS Adder)
    list(APPEND EXTRA_INCLUDES "Adder")
    list(APPEND EXTRA_LINKS adder)

endif()


configure_file(CT_Config.h.in CT_Config.h)

add_executable(${PROJECT_NAME} main.cpp)


target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_BINARY_DIR})



# DOWNLOAD ALL SUBMODULES
find_package(Git QUIET)
if(GIT_FOUND AND EXISTS "${PROJECT_SOURCE_DIR}/.git")
# Updating modules as needed
    option(GIT_SUBMODULE "Check submodules during build" ON)
    if(GIT_SUBMODULE)
        message(STATUS "Submodule Update")
        execute_process(COMMAND ${GIT_EXECUTABLE} submodule update --init --recursive
                        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
                        RESULT_VARIABLE GIT_SUBMOD_RESULT)
        if(NOT GIT_SUBMOD_RESULT EQUAL "0")
            message(FATAL_ERROR "git submodule update --init failed with ${GIT_SUBMOD_RESULT}, please checkout submodules")
        endif()
    endif()
endif()

#CHECK ALL SUBMODULES
if(NOT EXISTS "${PROJECT_SOURCE_DIR}/external/glfw/CMakeLists.txt")
    message(FATAL_ERROR "The glfw submodule was not downloaded! GIT_SUBMODULE was turned off or failed. Please checkout ")
endif()

add_subdirectory(external/glfw)

target_include_directories(${PROJECT_NAME} 
    PUBLIC external/glfw/include
    ${EXTRA_INCLUDES}
)

target_link_directories(${PROJECT_NAME} 
    PRIVATE external/glfw/src
    ${EXTRA_LIBS}
)


target_link_libraries(${PROJECT_NAME} ${EXTRA_LINKS} glfw)

INSTALL(TARGETS ${PROJECT_NAME} DESTINATION bin)
INSTALL(FILES "${PROJECT_BINARY_DIR}/CT_Config.h" DESTINATION include)