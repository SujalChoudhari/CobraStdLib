
# CobraStdLib

**CobraStdLib** is the standard library for the [Cobra programming language](https://github.com/SujalChoudhari/Cobra). It is designed as a modular, shared library (DLL/.so) that provides essential runtime functionality and utilities to support Cobra programs.

---

## Repository

- **Repo URL:** [https://github.com/SujalChoudhari/CobraStdLib](https://github.com/SujalChoudhari/CobraStdLib)
- **Cobra Language:** [https://github.com/SujalChoudhari/Cobra](https://github.com/SujalChoudhari/Cobra)

---

## Overview

The CobraStdLib aims to be a comprehensive, efficient, and easy-to-integrate standard library for the Cobra language. It provides:

- Core **mathematical functions and constants**
- Basic **input/output utilities**
- **File handling** operations
- **Path manipulation** utilities
- (Future) **Data structures**, **string processing**, **time/date**, and more

The library is built as modular shared libraries (DLL on Windows, .so on Unix-like systems), enabling fine-grained usage and easier maintenance.

---

## Current Modules

| Module        | Description                           |
|---------------|-------------------------------------|
| Math          | Arithmetic functions, constants     |
| IO            | Console input/output utilities      |
| File          | Basic file handling (open, read, write, seek) |
| Path          | Path manipulation (join, normalize, absolute) |
| Algorithms    | Sorting, searching algorithms       |
| Collections   | Dynamic arrays, hashmaps, sets      |
| String        | Substring, search, formatting, regex |
| Time & Date   | Current time, formatting, timers    |
| Concurrency   | Threads, mutexes, async              |

---

## Module Status

- [x] Math - Implemented  
- [x] IO - Implemented  
- [x] File - Implemented  
- [x] Path - Implemented  
- [ ] Algorithms - In Progress  
- [ ] Collections - Planned  
- [ ] String - Planned  
- [ ] Time & Date - Planned  
- [ ] Concurrency - Planned  

---

## Build Instructions

Ensure you have **CMake 3.20+** and a C++23 capable compiler installed.

Clone the repo:
```bash
git clone https://github.com/SujalChoudhari/CobraStdLib.git
cd CobraStdLib
````

Build using CMake:

```bash
mkdir build
cd build
cmake ..
cmake --build .
```

This will produce shared libraries like `cobra_math.dll` / `libcobra_math.so` and others inside the build directory.

---

## Integration with Cobra Language

The Cobra language runtime will dynamically load and link with these shared libraries to provide its standard library features. This modular approach allows:

* Independent development and testing of modules
* Optional linking of required modules only
* Clear separation between language core and standard utilities

---

## Contribution & Roadmap

Contributions are welcome! Please raise issues or submit pull requests for bugs, enhancements, or new modules.

### Next priorities:

* [ ] Complete **algorithms** module (sorting, searching)
* [ ] Implement **collections** (dynamic arrays, hashmaps)
* [ ] Develop **string** utilities (formatting, manipulation)
* [ ] Add **time & date** functions
* [ ] Design and add **error handling** and **logging** facilities
* [ ] Explore **concurrency** support


