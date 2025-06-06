# Project K-DNA

This project uses the [mata](https://github.com/VeriFIT/mata) library for automata operations.  
Mata is included as a git submodule and built together with this project using CMake.
Please consult the github page of mata incase of missing dependencies.
---

## Setup Instructions

### 1. Clone the repository and initialize submodules

```bash
cd K-DNA
git submodule update --init --recursive
```

### 2. Build the mata   source so we can use the library

```bash
cd external/mata/
make debug
```

### 3. Build the project itself

```bash
cd ../../../  # From external/mata/ back to project root
mkdir build && cd build
cmake ..
make
```

### 4. Running the program

```bash
./K-DNA
```

