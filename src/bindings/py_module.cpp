#include <pybind11/pybind11.h>
#include "math_utils.hpp"
#include "math_utils.h"

namespace py = pybind11;

// Binding code for the math_utils module
PYBIND11_MODULE(math_utils, m) {
    m.doc() = "Example C++ math utilities module";
    m.def("add", &add, "Add two integers"); // Now 'add' is recognized
