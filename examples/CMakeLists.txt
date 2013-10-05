
project( examples )

set( project_name iCleboExample )
include_directories( ../modules )
add_executable(iCleboExample iCleboExample.cpp )

set_target_properties( ${project_name} PROPERTIES PROJECT_LABEL "(example) ${project_name}"
	OUTPUT_NAME ${project_name}${process_suffix} 
	DEBUG_POSTFIX ${CMAKE_DEBUG_POSTFIX}
	RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin" ) 
target_link_libraries( ${project_name} iClebo )

set( project_name OlloExample )
include_directories( ../modules )
add_executable(OlloExample OlloExample.cpp )

set_target_properties( ${project_name} PROPERTIES PROJECT_LABEL "(example) ${project_name}"
	OUTPUT_NAME ${project_name}${process_suffix} 
	DEBUG_POSTFIX ${CMAKE_DEBUG_POSTFIX}
	RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin" ) 
target_link_libraries( ${project_name} Ollo )

set( project_name configExample)
include_directories( ../modules )
add_executable(configExample configExample.cpp )

set_target_properties( ${project_name} PROPERTIES PROJECT_LABEL "(example) ${project_name}"
	OUTPUT_NAME ${project_name}${process_suffix} 
	DEBUG_POSTFIX ${CMAKE_DEBUG_POSTFIX}
	RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin" ) 
target_link_libraries( ${project_name} iClebo )