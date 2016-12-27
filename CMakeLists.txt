cmake_minimum_required(VERSION 2.6)
project(mugen)

set (PROJECT_INCLUDE_DIR 
    ${PROJECT_SOURCE_DIR}/source
    ${PROJECT_SOURCE_DIR}/vendor/containers
    ${PROJECT_SOURCE_DIR}/vendor/lua
    ${PROJECT_SOURCE_DIR}/vendor/memory
    ${PROJECT_SOURCE_DIR}/vendor/pdfgen
    ${PROJECT_SOURCE_DIR}/vendor/profiler
    ${PROJECT_SOURCE_DIR}/vendor/tar
    ${PROJECT_SOURCE_DIR}/vendor/thread
    ${PROJECT_SOURCE_DIR}/vendor/utf8
)

include_directories(${PROJECT_INCLUDE_DIR})

set(LUA_SRCS 
    ${PROJECT_SOURCE_DIR}/vendor/lua/lzio.c
    ${PROJECT_SOURCE_DIR}/vendor/lua/lvm.c
    ${PROJECT_SOURCE_DIR}/vendor/lua/lutf8lib.c
    ${PROJECT_SOURCE_DIR}/vendor/lua/lundump.c
    ${PROJECT_SOURCE_DIR}/vendor/lua/ltablib.c
    ${PROJECT_SOURCE_DIR}/vendor/lua/ltm.c
    ${PROJECT_SOURCE_DIR}/vendor/lua/lstrlib.c
    ${PROJECT_SOURCE_DIR}/vendor/lua/ltable.c
    ${PROJECT_SOURCE_DIR}/vendor/lua/lstring.c
    ${PROJECT_SOURCE_DIR}/vendor/lua/lstate.c
    ${PROJECT_SOURCE_DIR}/vendor/lua/lparser.c
    ${PROJECT_SOURCE_DIR}/vendor/lua/loslib.c
    ${PROJECT_SOURCE_DIR}/vendor/lua/lopcodes.c
    ${PROJECT_SOURCE_DIR}/vendor/lua/loadlib.c
    ${PROJECT_SOURCE_DIR}/vendor/lua/lobject.c
    ${PROJECT_SOURCE_DIR}/vendor/lua/lmem.c
    ${PROJECT_SOURCE_DIR}/vendor/lua/lmathlib.c
    ${PROJECT_SOURCE_DIR}/vendor/lua/llex.c
    ${PROJECT_SOURCE_DIR}/vendor/lua/linit.c
    ${PROJECT_SOURCE_DIR}/vendor/lua/liolib.c
    ${PROJECT_SOURCE_DIR}/vendor/lua/lgc.c
    ${PROJECT_SOURCE_DIR}/vendor/lua/lfunc.c
    ${PROJECT_SOURCE_DIR}/vendor/lua/ldump.c
    ${PROJECT_SOURCE_DIR}/vendor/lua/ldo.c
    ${PROJECT_SOURCE_DIR}/vendor/lua/ldblib.c
    ${PROJECT_SOURCE_DIR}/vendor/lua/ldebug.c
    ${PROJECT_SOURCE_DIR}/vendor/lua/lctype.c
    ${PROJECT_SOURCE_DIR}/vendor/lua/lcorolib.c
    ${PROJECT_SOURCE_DIR}/vendor/lua/lbitlib.c
    ${PROJECT_SOURCE_DIR}/vendor/lua/lcode.c
    ${PROJECT_SOURCE_DIR}/vendor/lua/lbaselib.c
    ${PROJECT_SOURCE_DIR}/vendor/lua/lauxlib.c
    ${PROJECT_SOURCE_DIR}/vendor/lua/lapi.c
)

set(MUGEN_SRCS
    ${PROJECT_SOURCE_DIR}/source/main.c
    ${PROJECT_SOURCE_DIR}/source/mugen.c
    ${PROJECT_SOURCE_DIR}/source/engine.c
    ${PROJECT_SOURCE_DIR}/source/parser.c
    ${PROJECT_SOURCE_DIR}/source/utilities.c
)

add_executable(mugen  
    ${MUGEN_SRCS}
    ${LUA_SRCS}
    ${PROJECT_SOURCE_DIR}/vendor/containers/vec.c 
    ${PROJECT_SOURCE_DIR}/vendor/containers/map.c 
    ${PROJECT_SOURCE_DIR}/vendor/memory/memory.c 
    ${PROJECT_SOURCE_DIR}/vendor/tar/microtar.c 
    ${PROJECT_SOURCE_DIR}/vendor/thread/thread.c
    ${PROJECT_SOURCE_DIR}/vendor/pdfgen/pdfgen.c
)

if (UNIX)
    target_link_libraries(mugen m pthread)
endif ()

if (UNIX AND NOT APPLE)
    target_link_libraries(mugen rt)
endif ()

if (WIN32)
    target_link_libraries(mugen kernel32 user32 gdi32 winspool shell32 ole32 oleaut32 uuid comdlg32 advapi32 kernel32 user32 gdi32 winspool shell32 ole32 oleaut32 uuid comdlg32 advapi32.lib)
endif ()

install(TARGETS mugen RUNTIME DESTINATION bin)
