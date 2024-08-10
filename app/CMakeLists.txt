project(app)

add_library(app OBJECT
    mainwindow.cpp
    mainwindow.ui
    tokeneditor.cpp
    delegatecell.cpp
)
target_link_libraries(app Qt5::Widgets)