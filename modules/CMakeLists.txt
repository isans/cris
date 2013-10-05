
project( modules )
macro(add_component name)
    set( COMPONENT_DEPEND_NAME ${name} )
	add_definitions(   
		-DCRIS_BUILT_AS_DLL
	)	
	add_library( ${name} SHARED ${name}.cpp ${SRCS} ${name}.h )
    
	set_target_properties( ${name} PROPERTIES PROJECT_LABEL "(module) ${COMPONENT_DEPEND_NAME}"
		OUTPUT_NAME ${COMPONENT_DEPEND_NAME}${process_suffix} 
		DEBUG_POSTFIX ${CMAKE_DEBUG_POSTFIX}
		RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin" ) 
endmacro()

add_component(iClebo)
add_component(Ollo)
