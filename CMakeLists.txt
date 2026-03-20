cmake_minimum_required(VERSION 3.15)

project(matrix-toy LANGUAGES CXX)

find_package(FLTK REQUIRED)

find_package(SDL2 REQUIRED)

add_executable(matrix-toy)

set_target_properties(matrix-toy PROPERTIES CXX_STANDARD 17)

set(I_DIR
            "./src"
)

set(FL_DIR
            "${I_DIR}/fl"
)

set(CXX_SRC
            "${I_DIR}/main.cpp"
            "${I_DIR}/mat.cpp"
            "${I_DIR}/win.cpp"
            "${I_DIR}/sdl.cpp"
)

set(FL_SRC
            "${FL_DIR}/window.cxx"
)

target_sources(matrix-toy
                            PRIVATE
                                    "${CXX_SRC}"
                                    "${FL_SRC}"
)

target_link_libraries(matrix-toy PRIVATE m "${FLTK_LIBRARIES}" SDL2::SDL2)

install(TARGETS matrix-toy RUNTIME DESTINATION
    "${CMAKE_CURRENT_SOURCE_DIR}/bin")
