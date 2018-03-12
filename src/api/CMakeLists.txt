####################################################################################
##
##     _____    ____ _       ____ _        __ _      __ _  __ _  ______ _   ___ _
##    / /| |]  |  __ \\     / ___ \\      / \ \\    |   \\/   |]|  _____|] / ___|]
##   / //| |]  | |] \ \\   | |]  \_|]    / //\ \\   | |\ / /| |]| |]___ _ ( ((_ _
##  / //_| |]_ | |]  ) ))  | |]  __ _   / _____ \\  | |]\_/ | |]|  _____|] \___ \\
## |_____   _|]| |]_/ //   | |]__/  |] / //    \ \\ | |]    | |]| |]___ _   ___) ))
##       |_|]  |_____//     \_____/|]]/_//      \_\\|_|]    |_|]|_______|] |____//
## 
##
####################################################################################
##
##
##  File    : CMakeLists.txt
##  Author  : Anthony Islas
##  Purpose : File Description
##  Group   : Api
##
##  TODO    : None
##
##  License : None
##
####################################################################################


#
# Includes
#
target_include_directories( ${TARGET} 
                            PUBLIC
                              ${CMAKE_CURRENT_SOURCE_DIR}
                            )

set( TEST_INCLUDES 
    ${TEST_INCLUDES}
     ${CMAKE_CURRENT_SOURCE_DIR}/ )

#
# Source
#
target_sources( ${TARGET}
                PUBLIC
                  # Add sources here
                  ${CMAKE_CURRENT_SOURCE_DIR}/PhysicalObject.cpp
                  ${CMAKE_CURRENT_SOURCE_DIR}/PhysicsManager.cpp
                  )

if ( UNIT_TEST )
  
  if ( NOT EXISTS  ${CMAKE_CURRENT_SOURCE_DIR}/gtest ) 

    message( AUTHOR_WARNING "No tests to build for ${CMAKE_CURRENT_SOURCE_DIR}" )
    return()

  endif()

  add_subdirectory( ${CMAKE_CURRENT_SOURCE_DIR}/gtest )

  set( TEST_SOURCES 
       ${TEST_SOURCES} 
       PARENT_SCOPE )


endif()

