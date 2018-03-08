cmake_minimum_required(VERSION 3.9)
project(filler_visualizator)

#set(CMAKE_C_FLAGS "-framework OpenGL -framework AppKit")

set(CMAKE_C_STANDARD 99)

link_directories(libftprintf)

link_libraries(ftprintf mlx)

include_directories(
        inc
        libftprintf/inc
        libftprintf/libft/inc
)

set(INC_DIR inc)
set(SRC_DIR src)
set(INC
        ${INC_DIR}/color.h
        ${INC_DIR}/key_events.h
        ${INC_DIR}/key_map.h
        ${INC_DIR}/visualizator.h inc/graphics.h)
set(SRC
        ${SRC_DIR}/draw.c
        ${SRC_DIR}/draw_grid.c
        ${SRC_DIR}/draw_o.c
        ${SRC_DIR}/draw_x.c
        ${SRC_DIR}/graphics.c
        ${SRC_DIR}/main.c
        ${SRC_DIR}/plateau.c
        src/error_exit.c)

add_executable(filler_visualizator ${INC} ${SRC})

target_link_libraries(filler_visualizator "-framework OpenGL" "-framework AppKit")
