# CobraStdLib

**CobraStdLib** is the **standard library** for the [Cobra programming language](https://github.com/SujalChoudhari/Cobra).
It provides core runtime utilities and foundational components as a **modular, shared library** (`.dll` / `.so`) for use in Cobra programs.

---

## Repository

* **Library:** [https://github.com/SujalChoudhari/CobraStdLib](https://github.com/SujalChoudhari/CobraStdLib)
* **Language Core:** [https://github.com/SujalChoudhari/Cobra](https://github.com/SujalChoudhari/Cobra)

---

## Purpose

CobraStdLib defines the **runtime backbone** of Cobra. It focuses on clarity, efficiency, and modularity to allow independent development of each functional area.

**Key objectives:**

* Provide a **consistent runtime API** for the Cobra language
* Enable **fine-grained modular builds** (only link what’s needed)
* Maintain **cross-platform compatibility** across Windows, Linux, and macOS
* Serve as a **clean reference** for language–library integration in compiler design

---

## Features and Modules

| Module      | Description                                      | Status        |
| ----------- | ------------------------------------------------ | ------------- |
| Math        | Arithmetic operations and constants              | ✅ Implemented |
| Strings     | String manipulation and formatting               | ✅ Implemented |
| IO          | Console input/output utilities                   | 🚧 Planned    |
| File        | File reading, writing, and seeking               | 🚧 Planned    |
| Path        | Path normalization, joining, absolute resolution | 🚧 Planned    |
| Algorithms  | Sorting and searching algorithms                 | 🚧 Planned    |
| Collections | Dynamic arrays, hashmaps, and sets               | 🚧 Planned    |
| Time & Date | Time retrieval, formatting, and timers           | 🚧 Planned    |
| Concurrency | Threads, mutexes, and async primitives           | 🚧 Planned    |

---

## Build Instructions

**Requirements:**

* **CMake ≥ 3.20**
* **C++23** compliant compiler (GCC, Clang, or MSVC)

```bash
git clone https://github.com/SujalChoudhari/CobraStdLib.git
cd CobraStdLib
mkdir build && cd build
cmake ..
cmake --build .
```

**Output:**
Platform-specific shared libraries such as:

* `cobra_math.dll` / `libcobra_math.so`
* `cobra_string.dll` / `libcobra_string.so`
* (and others as modules are implemented)

---

## Integration with Cobra

CobraStdLib is dynamically linked by the **Cobra runtime**, enabling:

* Independent testing and versioning of modules
* On-demand linking of required functionality
* Clear separation of **language core** and **standard utilities**

This design supports a compiler–runtime model similar to languages like **Go** or **Rust**, ensuring maintainability and extensibility.

---

## Roadmap

* Finalize and test `IO`, `File`, and `Path` modules
* Add optimized data structures and algorithms
* Integrate concurrency primitives
* Implement standardized time/date utilities
* Improve build scripts and CI integration

---

## Contributing

Contributions are welcome.
Report issues or open pull requests for new modules, optimizations, or documentation improvements.
