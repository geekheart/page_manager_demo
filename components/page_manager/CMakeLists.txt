file(GLOB SOURCES page_manager/src/*.c)

idf_component_register(SRCS ${SOURCES}
                        INCLUDE_DIRS page_manager/inc
                        REQUIRES lvgl)
