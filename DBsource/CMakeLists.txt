add_library(dblib "")

target_sources(dblib
    PRIVATE 
        #${CMAKE_CURRENT_LIST_DIR}/DBAttribute.cpp
        #${CMAKE_CURRENT_LIST_DIR}/DBDatabase.cpp
        ${CMAKE_CURRENT_LIST_DIR}/DBIFilters.cpp
        #${CMAKE_CURRENT_LIST_DIR}/DBTable.cpp
        ${CMAKE_CURRENT_LIST_DIR}/DBTypes.cpp
    PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}/DBAttribute.hpp
        ${CMAKE_CURRENT_LIST_DIR}/DBDatabase.hpp
        ${CMAKE_CURRENT_LIST_DIR}/DBIFilters.hpp
        ${CMAKE_CURRENT_LIST_DIR}/DBTable.hpp
        ${CMAKE_CURRENT_LIST_DIR}/DBTypes.hpp
    )

target_include_directories(dblib 
    PUBLIC 
        ${CMAKE_CURRENT_LIST_DIR}
    )

