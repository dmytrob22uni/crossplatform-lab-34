cmake_minimum_required(VERSION 3.16) # qt's requirement
project(widgets_app VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17) # qt's requirement
set(CMAKE_CXX_STANDARD_REQUIRED ON) # enfore 17, don't fallback
set(CMAKE_EXPORT_COMPILE_COMMANDS ON) # compile_commands.json for clangd

# find Qt 6 components
find_package(Qt6 REQUIRED COMPONENTS Core Gui Widgets) # fail on missing

# automatic processing of Qt meta-object compilers
set(CMAKE_AUTOMOC ON) # moc - meta-object compiler (generate code for qt's features)
set(CMAKE_AUTORCC ON) # rcc - resource compiler (embed files into app)
set(CMAKE_AUTOUIC ON) # uic - ui compiler (detect .ui and generate header)

# make named bin from sources
add_executable(widgets_app
    main.cpp
    CustomButton.h
    CustomButton.cpp
    CustomCheckBox.h
    CustomCheckBox.cpp
    NativeWindow.h
    NativeWindow.cpp
    CustomWindow.h
    CustomWindow.cpp
)

# link Qt 6 libraries strictly to bin with no pub interfaces
target_link_libraries(widgets_app PRIVATE
    Qt6::Core
    Qt6::Gui
    Qt6::Widgets
)

set_target_properties(widgets_app PROPERTIES
    OUTPUT_NAME "widgets_app"
)
