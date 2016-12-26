cmake_minimum_required(VERSION 2.6)
project(mugen)

set (PROJECT_INCLUDE_DIR 
    ${PROJECT_SOURCE_DIR}/source
    ${PROJECT_SOURCE_DIR}/vendor
)

include_directories(${PROJECT_INCLUDE_DIR})

add_executable(mugen source/main.c source/mugen.c source/engine.c source/parser.c source/utilities.c vendor/containers/vec.c vendor/containers/map.c vendor/memory/memory.c vendor/tar/microtar.c vendor/thread/thread.c)

if (UNIX)
    target_link_libraries(mugen m pthread)
endif ()

if (UNIX AND NOT APPLE)
    target_link_libraries(mugen rt)
endif ()

if (MSVC)
    target_link_libraries(mugen kernel32 user32 gdi32 winspool shell32 ole32 oleaut32 uuid comdlg32 advapi32)
endif (MSVC)

install(TARGETS mugen RUNTIME DESTINATION bin)
