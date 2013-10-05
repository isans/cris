cmake_minimum_required( VERSION 2.6 ) 

set( CMAKE_DEBUG_POSTFIX "d" ) 
set( project_name CRIS )
project( ${project_name} )

message( "CMAKE_SYSTEM: ${CMAKE_SYSTEM}" )
message( "cmake_system_name: ${CMAKE_SYSTEM_NAME}")
message( "cmake_system_processor: ${CMAKE_SYSTEM_PROCESSOR}" )
message( "cmake_system_version: ${CMAKE_SYSTEM_VERSION}" )

if( CMAKE_SYSTEM_PROCESSOR STREQUAL "arm" )
	set( arm_target TRUE )
	set( target_name "-arm.a" )
	set( process_suffix "-arm" )
endif()

FILE(GLOB_RECURSE SRCS 
	src/*.cpp 
	include/*.h
) 

INCLUDE_DIRECTORIES( 
	src/
	include/
)
add_subdirectory( modules )
add_subdirectory( examples )

option( BUILD_DOCUMENTATION "Use Doxygen to create the HTML based API documentation" OFF )

if(BUILD_DOCUMENTATION)

	set( PROJECT_NAME "CRIS" )
	set( PROJECT_NUMBER "1.0.0" )
	set( DOXYFILE_LATEX "OFF" )
	configure_file(Doxyfile.in 
					 ${PROJECT_BINARY_DIR}/Doxyfile  @ONLY IMMEDIATE)
					 
	include(UseDoxygen)

endif()