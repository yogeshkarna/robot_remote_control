add_library(robot_remote_control-robot_controller
            RobotController.cpp
            ../TelemetryBuffer.cpp
            ../Statistics.cpp
)
target_link_libraries (robot_remote_control-robot_controller stdc++fs robot_remote_control-types robot_remote_control-update_thread)

add_dependencies(robot_remote_control-robot_controller versionheaders)

if(ZLIB_FOUND)
        target_link_libraries(robot_remote_control-robot_controller robot_remote_control-compression)
        target_compile_definitions(robot_remote_control-robot_controller PUBLIC -DZLIB_FOUND)
endif()

target_include_directories(robot_remote_control-robot_controller
	PUBLIC
		$<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/src>
		$<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
)

install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/
	DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/robot_remote_control
	FILES_MATCHING PATTERN "*.hpp"
)

install (TARGETS
        robot_remote_control-robot_controller
        EXPORT robot_remote_control-targets
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
        RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
