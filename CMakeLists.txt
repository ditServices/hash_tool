cmake_minimum_required(VERSION 3.17)
project(copy_tool)

set(CMAKE_CXX_STANDARD 17)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

add_executable(copy_tool CopyTool.cpp CopyTool.h CopyFrame.cpp CopyFrame.h copytoolID.h ErrorHandler.cpp ErrorHandler.h copytool_errors.h FileHandler.cpp FileHandler.h md5_engine.cpp md5_engine.h xxh_engine.cpp xxh_engine.h)
target_link_libraries(copy_tool ${CONAN_LIBS})
