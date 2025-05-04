cmake_minimum_required(VERSION 3.14)
project(math_utils_demo LANGUAGES CXX)

# Find Python interpreter and development (headers + library) for embedding
find_package(Python 3 COMPONENTS Interpreter Development REQUIRED)

# Pull in pybind11 via FetchContent
include(FetchContent)
FetchContent_Declare(
  pybind11
  GIT_REPOSITORY https://github.com/pybind/pybind11.git
  GIT_TAG        v2.10.4  # or whichever stable release you prefer
)
FetchContent_MakeAvailable(pybind11)

# Core C++ library
add_library(math_utils_lib
    src/lib/math_utils.cpp
)
target_include_directories(math_utils_lib PUBLIC
    $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/src/lib>
)

# Python extension module using pybind11
pybind11_add_module(math_utils
    src/bindings/py_module.cpp
)
# Ensure the module can find our headers
target_include_directories(math_utils PRIVATE
    ${CMAKE_SOURCE_DIR}/src/lib
)
# Link the core library into the Python module
target_link_libraries(math_utils PRIVATE math_utils_lib)

# Optional install targets
target_compile_features(math_utils_lib PUBLIC cxx_std_11)
install(TARGETS math_utils_lib math_utils
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib
        RUNTIME DESTINATION bin
)
