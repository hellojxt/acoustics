set(UTILS_SRC
    ${CMAKE_CURRENT_SOURCE_DIR}/macros.h      
    ${CMAKE_CURRENT_SOURCE_DIR}/math.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/nano_timer.h  
    ${CMAKE_CURRENT_SOURCE_DIR}/nano_timer.c
    ${CMAKE_CURRENT_SOURCE_DIR}/timer.hpp     
    ${CMAKE_CURRENT_SOURCE_DIR}/timer.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/MathUtil.cpp  
    ${CMAKE_CURRENT_SOURCE_DIR}/Conversions.h
    ${CMAKE_CURRENT_SOURCE_DIR}/FreqWeighting.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/FreqWeighting.cpp
    CACHE FILE "Utility source")
set(UTILS_OPENGL_SRC
    ${CMAKE_CURRENT_SOURCE_DIR}/GL_Wrapper.h
    ${CMAKE_CURRENT_SOURCE_DIR}/GL_Wrapper.cpp
    CACHE FILE "OpenGL utility source")
