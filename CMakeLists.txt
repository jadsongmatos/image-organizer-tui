cmake_minimum_required(VERSION 3.21)

# --- Fetch FTXUI --------------------------------------------------------------
include(FetchContent)

set(FETCHCONTENT_UPDATES_DISCONNECTED TRUE)
FetchContent_Declare(ftxui
        GIT_REPOSITORY https://github.com/ArthurSonzogni/ftxui
        GIT_TAG v0.11
        )

FetchContent_GetProperties(ftxui)
if(NOT ftxui_POPULATED)
    FetchContent_Populate(ftxui)
    add_subdirectory(${ftxui_SOURCE_DIR} ${ftxui_BINARY_DIR} EXCLUDE_FROM_ALL)
endif()

# ------------------------------------------------------------------------------

project(image-organizer-tui
        LANGUAGES CXX
        VERSION 1.0.0
        )

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

add_executable(image-organizer-tui ./src/main.cpp src/search.cpp src/search.h src/process.cpp src/process.h)
target_include_directories(image-organizer-tui PRIVATE src)

target_link_libraries(image-organizer-tui
        Qt::Core
        )

find_package(Qt6 COMPONENTS
        Core
        REQUIRED)

target_link_libraries(image-organizer-tui
        ftxui::screen
        ftxui::dom
        ftxui::component
        )

install(TARGETS image-organizer-tui RUNTIME DESTINATION "bin")