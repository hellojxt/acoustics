# tinyXML-based Parser
set(PARSER_SRC
    ${CMAKE_CURRENT_SOURCE_DIR}/Parser.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Parser.h
    ${CMAKE_CURRENT_SOURCE_DIR}/ImpulseResponseParser.h
    ${CMAKE_CURRENT_SOURCE_DIR}/ImpulseResponseParser.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/../tinyxml/tinystr.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/../tinyxml/tinystr.h
    ${CMAKE_CURRENT_SOURCE_DIR}/../tinyxml/tinyxml.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/../tinyxml/tinyxmlerror.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/../tinyxml/tinyxml.h
    ${CMAKE_CURRENT_SOURCE_DIR}/../tinyxml/tinyxmlparser.cpp
    CACHE FILE "tinyxml Parser sources")

set(LIBCONFIG_PARSER_SRC
    ${CMAKE_CURRENT_SOURCE_DIR}/ParseConfig.h
    CACHE FILE "libConfig Parser sources")

set(RIGID_PARSER_SRC
    ${CMAKE_CURRENT_SOURCE_DIR}/ParseConfig.h
    ${CMAKE_CURRENT_SOURCE_DIR}/RigidsimParseConfig.h
    ${CMAKE_CURRENT_SOURCE_DIR}/RigidsimParseConfig.cpp
    CACHE FILE "Parser sources for rigidsim")

