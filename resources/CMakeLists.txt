
add_custom_target(copy_images
	COMMAND ${CMAKE_COMMAND} -E copy_directory_if_different 
        "${CMAKE_CURRENT_SOURCE_DIR}/images/"
        "$<TARGET_FILE_DIR:main>/resources/images"
    COMMENT "Copying images"
)

add_dependencies(main copy_images)

