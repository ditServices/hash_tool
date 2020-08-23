cmake_minimum_required(VERSION 3.17)
project(copy_tool)

set(CMAKE_CXX_STANDARD 20)
set(wxWidgets_ROOT_DIR </usr/include/wx-3.0-unofficial>)
set(wxWidgets_CONFIGURATION mswu)

set(CMAKE_CXX_FLAGS_RELEASE "-O3")

find_package(wxWidgets COMPONENTS core base REQUIRED)
include(${wxWidgets_USE_FILE})

find_package(PkgConfig REQUIRED)
pkg_check_modules(XXHASH REQUIRED IMPORTED_TARGET libxxhash)
pkg_check_modules(SSL REQUIRED IMPORTED_TARGET libssl)
pkg_check_modules(CRYPTO REQUIRED IMPORTED_TARGET libcrypto)

add_executable(copy_tool CopyTool.cpp CopyTool.h CopyFrame.cpp CopyFrame.h copytoolID.h ErrorHandler.cpp ErrorHandler.h copytool_errors.h FileHandler.cpp FileHandler.h md5_engine.cpp md5_engine.h xxh_engine.cpp xxh_engine.h)
target_link_libraries(copy_tool ${wxWidgets_LIBRARIES} PkgConfig::XXHASH PkgConfig::SSL PkgConfig::CRYPTO)
