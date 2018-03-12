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
##  Purpose : String module files
##  Group   : String
##
##
##  License : GNU GPL v3
##
####################################################################################

#
# Dependencies
#
cmake_minimum_required ( VERSION 3.5.0 )

set ( CMAKE_BUILD_TYPE debug )


####################################################################################
#
# Options
#
####################################################################################
option( UNIT_TEST         "Enable Google Test Framework"                    OFF )
option( BUILD_THIRDPARTY  "Perform steps to checkout and build thirdparty"  OFF )

#
# Necessary libs
#
set( COMPONENTS "${CMAKE_CURRENT_SOURCE_DIR}/../components" CACHE TYPE STRING )

set( THIRDPARTY 
    "${CMAKE_CURRENT_SOURCE_DIR}/../../thirdparty" 
     CACHE STRING 
    "Thirdparty directory" )


#
# Get our modules after options
#
list( APPEND 
      CMAKE_MODULE_PATH
      ${COMPONENTS}/cmake 
      )

include( ExternalProject )
include( GoogleTestSetup )
include( OptionPrinter   )
include( VersionExtract  )

####################################################################################
#
# Project setup
#
####################################################################################
version_extract_str( ${CMAKE_CURRENT_SOURCE_DIR}/versions.txt PROJECT_VERSION )
project ( 
          Physics 
          VERSION 
          ${PROJECT_VERSION}
          )

message ( "Configuring " ${PROJECT_NAME} )
detailed_print( "PROJECT VERSION" CLR_MAGENTA ${PROJECT_VERSION} CLR_CYAN 14 LEFT )

set( PHYSICS_TARGETS "" )

include_directories ( ${PROJECT_BINARY_DIR} )

#
# We are creating a target for this directory
#
set        ( TARGET        KomorebiPhysics    )
add_library( ${TARGET}     SHARED          "" )
set        ( PHYSICS_RPATH 
             ${PHYSICS_RPATH}
             ${PROJECT_SOURCE_DIR}/lib )


#
# Add to targets
#
set( PHYSICS_TARGETS 
    ${PHYSICS_TARGETS} 
    ${TARGET} 
    )



####################################################################################
#
# Necessary libs
#
####################################################################################
find_library( KomorebiString ${COMPONENTS}/lib )

set( PHYSICS_LIBS 
     ${PHYSICS_LIBS}
     KomorebiString )

set( PHYSICS_RPATH 
     ${PHYSICS_RPATH}
     ${COMPONENTS}/lib )

include_directories( ${COMPONENTS} )



####################################################################################
#
# Regression test variable
#
####################################################################################
set ( TEST_SOURCES
      "" 
    )
set ( TEST_INCLUDES
      ""
    )
set ( TEST_RESOURCES
      ${CMAKE_BINARY_DIR}/gtest_resources/
    )

####################################################################################
#
# Necessary packages
#
####################################################################################
find_package ( Threads )



####################################################################################
#
# Source directories
#
####################################################################################
message ( "Configuring ${PROJECT_NAME}")

add_subdirectory( ${CMAKE_CURRENT_SOURCE_DIR}/src )



####################################################################################
#
# Configuration stuff
#
####################################################################################
configure_file ( ${PROJECT_SOURCE_DIR}/src/common/config.hpp.in
                 ${PROJECT_BINARY_DIR}/config.hpp 
                 @ONLY 
                )




####################################################################################
#
# Link libraries
#
####################################################################################
target_link_libraries( ${TARGET} ${PHYSICS_LIBS} )

set_target_properties( ${TARGET}
                           PROPERTIES
                             INSTALL_RPATH "${PHYSICS_RPATH}" )






####################################################################################
#
# UNIT TESTS
#
####################################################################################
if ( UNIT_TEST )

  if ( NOT EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/gtest )

    message( STATUS "No tests to build for ${TARGET}" )

    return()

  else()

    if ( NOT TEST_SOURCES )

      message( STATUS "No tests to build for target ${GTEST_TARGET}" )

      return()

    endif()


    ####################################################################################
    #
    # Automate naming of target
    #
    ####################################################################################
    # auto_test_name( ${CMAKE_CURRENT_SOURCE_DIR} GTEST_NAME )
    set             ( GTEST_TARGET "${TARGET}Tests" )

    message ( "Target Name: " ${GTEST_TARGET} )

    #
    # Setup 
    #
    set ( RESOURCE_FILES ""
        )

    ####################################################################################
    #
    # executable
    #
    ####################################################################################
    add_executable ( ${GTEST_TARGET}  ${TEST_SOURCES} )

    add_dependencies( ${GTEST_TARGET} gtest )


    ####################################################################################
    #
    # Define test cases for each
    #
    ####################################################################################



    ####################################################################################
    #
    # Resources necessary to run these tests
    #
    ####################################################################################
    setup_resources (${GTEST_TARGET} "${RESOURCE_FILES}" )

    ####################################################################################
    #
    # Add GTest includes
    #
    ####################################################################################
    target_include_directories ( ${GTEST_TARGET} 
                                  PUBLIC 
                                  ${TEST_INCLUDES}
                                  ${GTEST_ROOT}/include 
                                  )

    print_include_dirs ( ${GTEST_TARGET} )

    ####################################################################################
    #
    # Set default main and gtest libraries
    #
    ####################################################################################
    set ( LIBS 
          ${GTEST_LIB}
          ${GTEST_LIB_MAIN}
          ${CMAKE_THREAD_LIBS_INIT}
          ${TARGET}
          )

    target_link_libraries( ${GTEST_TARGET} ${LIBS} )


    #
    # RPATH
    #
    set_target_properties( ${GTEST_TARGET}
                           PROPERTIES
                             INSTALL_RPATH ${PHYSICS_RPATH} )


    #
    # Add to targets
    #
    set( PHYSICS_TARGETS 
        ${PHYSICS_TARGETS} 
        ${GTEST_TARGET} 
        )

  endif()

endif()




####################################################################################
#
# Install rules
#
####################################################################################
install( TARGETS ${PHYSICS_TARGETS} 
         RUNTIME DESTINATION ${PROJECT_SOURCE_DIR}/bin
         LIBRARY DESTINATION ${PROJECT_SOURCE_DIR}/lib
         )
