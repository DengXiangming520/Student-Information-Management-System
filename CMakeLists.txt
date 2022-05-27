cmake_minimum_required(VERSION 3.22)
project(stu_info_manager C)

set(CMAKE_C_STANDARD 11)

add_executable(stu_info_manager main.c heads/for_main.h function_module/main_menu.c heads/main_menu.h function_module/login_module.c heads/login_module.h heads/for_function_module.h heads/users.h function_module/registered_module.c heads/registered_module.h function_module/secondary_menu.c heads/secondary_menu.h function_module/add_module.c heads/add_module.h heads/stu_info.h function_module/query_module.c heads/query_module.h function_module/delete_module.c heads/delete_module.h function_module/statistic_module.c heads/statistic_module.h function_module/modify_module.c heads/modify_module.h)
