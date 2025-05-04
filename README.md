# cppybind-math-utils

A simple example of creating a Python extension module using C++ and pybind11. This project demonstrates how to expose C++ functions to Python for performance-critical code using modern CMake and pybind11.

## 🧩 Features

- Written in modern C++ (C++11 or newer)
- Python bindings using [pybind11](https://github.com/pybind/pybind11)
- Build with CMake
- Minimal example: add two integers

## 📦 Prerequisites

- Python ≥ 3.7
- CMake ≥ 3.14
- A C++ compiler (g++, clang++, MSVC)
- pybind11 (can be installed via pip or fetched by CMake)

Install pybind11 via pip:

```bash
pip install pybind11
```

## 🛠️ Build Instructions
```bash
git clone https://github.com/yourusername/cppybind-math-utils.git
cd cppybind-math-utils
mkdir build && cd build
cmake ..
make
```

This will generate a Python extension module named math_utils.*.so or .pyd.


## 🧪 Example Usage in Python

```bash
import math_utils

print(math_utils.add(10, 32))  # Output: 42
```

## 📁 Project Structure

```bash
cppybind-math-utils/
├── CMakeLists.txt
├── src/
│   ├── lib/
│   │   ├── math_utils.cpp
│   │   └── math_utils.hpp
│   └── bindings/
│       └── py_module.cpp
```

## 📖 References

- [pybind11](https://github.com/pybind/pybind11)
- [Modern CMake Best Practices](https://github.com/Kitware/CMake/wiki/Modern-CMake-Best-Practices)