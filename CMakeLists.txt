cmake_minimum_required(VERSION 2.6)
project(mugen)

set (PROJECT_INCLUDE_DIR 
    ${PROJECT_SOURCE_DIR}/source
    ${PROJECT_SOURCE_DIR}/vendor
)

include_directories(${PROJECT_INCLUDE_DIR})

add_executable(mugen source/main.c source/mugen.c source/engine.c source/parser.c source/utilities.c vendor/containers/vec.c vendor/containers/map.c vendor/memory/memory.c vendor/tar/microtar.c vendor/thread/thread.c)

if (UNIX)
    target_link_libraries(mugen m pthread rt)
endif (UNIX)

install(TARGETS mugen RUNTIME DESTINATION bin)
