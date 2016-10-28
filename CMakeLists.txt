cmake_minimum_required(VERSION 2.6)
project(qRubyDump)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)

find_package(Qt5Core)

add_executable(qRubyDump
    src/main.cpp
    src/lsjson.cpp

    src/datablocks/lslinkedlist.cpp
    src/datablocks/lslistItem.cpp
    src/datablocks/lslistitem_string.cpp
    src/datablocks/lslistitem_array.cpp
    src/datablocks/lslistitem_hash.cpp
    src/datablocks/lslistitem_object.cpp
    src/datablocks/lslistitem_imemo.cpp
    src/datablocks/lslistitem_data.cpp
    src/datablocks/lslistitem_module.cpp
    src/datablocks/lslistitem_iclass.cpp
    src/datablocks/lslistitem_struct.cpp
    src/datablocks/lslistitem_regexp.cpp
    )

target_link_libraries(qRubyDump
    Qt5::Core
    )

# Install data files
install(DIRECTORY
    ${PROJECT_SOURCE_DIR}/data
    DESTINATION ${PROJECT_BINARY_DIR}
    )
