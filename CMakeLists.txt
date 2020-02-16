cmake_minimum_required(VERSION 2.8)
project(clog)



include_directories(./inc)
include_directories(./src)

aux_source_directory(. SRC_LIST)
aux_source_directory(./src SRC_LIST)

message(STATUS "${SRC_LIST}")

add_executable(main ${SRC_LIST})
add_library(clog STATIC ./src/clog.c)

ENABLE_TESTING()
add_test(test_invalid_input ${PROJECT_BINARY_DIR}/main)
set_tests_properties(test_invalid_input 
    PROPERTIES PASS_REGULAR_EXPRESSION "Invalid arguments")

add_test(test_normal ${PROJECT_BINARY_DIR}/main "cristiano")
set_tests_properties(test_normal 
    PROPERTIES PASS_REGULAR_EXPRESSION "cristiano")

# 安装静态库
install(TARGETS clog ARCHIVE DESTINATION lib)
# 安装动态库
# install(TARGETS clog LIBRARY DESTINATION lib) 
# 安装可执行文件
# install(TARGETS main RUNTIME DESTUNATION bin)

# 安装头文件
install(FILES ./inc/clog.h DESTINATION include/clog)
