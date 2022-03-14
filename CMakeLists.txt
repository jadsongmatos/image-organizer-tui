cmake_minimum_required(VERSION 3.21)

include(FetchContent)

# --- Fetch FTXUI --------------------------------------------------------------
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

# --- Fetch json --------------------------------------------------------------

FetchContent_Declare(json URL https://github.com/nlohmann/json/releases/download/v3.10.5/json.tar.xz)
FetchContent_MakeAvailable(json)

# ------------------------------------------------------------------------------

project(image-organizer-tui
    LANGUAGES CXX
    VERSION 1.0.0
    )


set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


find_package(QT NAMES Qt6 COMPONENTS Core LinguistTools REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Core LinguistTools REQUIRED)

add_executable(image-organizer-tui src/main.cpp src/search.cpp src/search.h src/process.cpp src/process.h src/traverse.cpp src/traverse.h src/list.h src/list.cpp)
#target_include_directories(image-organizer-tui src)

target_link_libraries(image-organizer-tui
    Qt${QT_VERSION_MAJOR}::Core
    )

target_link_libraries(image-organizer-tui
    nlohmann_json::nlohmann_json
    )

target_link_libraries(image-organizer-tui
    ftxui::screen
    ftxui::dom
    ftxui::component
    )

install(TARGETS image-organizer-tui RUNTIME DESTINATION "bin")
