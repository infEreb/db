add_library(features "")

target_sources(features
    PRIVATE 
        ${CMAKE_CURRENT_LIST_DIR}/Features.cpp
    PUBLIC 
        ${CMAKE_CURRENT_LIST_DIR}/Features.hpp
    )

target_include_directories(features 
    PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}
    )