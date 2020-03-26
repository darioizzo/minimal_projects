pybind11_add_module(core core.cpp)

target_link_libraries(core PRIVATE Pagmo::pagmo)
target_include_directories(core SYSTEM PRIVATE "${pybind11_INCLUDE_DIR}")
target_compile_definitions(core PRIVATE "${pybind11_DEFINITIONS}")

set_property(TARGET core PROPERTY CXX_STANDARD 17)
set_property(TARGET core PROPERTY CXX_STANDARD_REQUIRED YES)
set_property(TARGET core PROPERTY CXX_EXTENSIONS NO)