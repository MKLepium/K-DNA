# Project K-DNA

This project uses the [mata](https://github.com/VeriFIT/mata) library for automata operations.  
Mata is included as a git submodule and built together with this project using CMake.
Please consult the github page of mata incase of missing dependencies.
---

# About the Program
This program generates and prints all valid DNA k-mers accepted by a simple non-deterministic finite automaton (NFA). A k-mer is a substring of length k consisting of DNA nucleotides {A, C, G, T}.

How it Works
The program constructs an NFA with a specified number of states.

Each transition in the automaton corresponds to reading one nucleotide.

Starting from the initial state, the program explores all possible paths through the automaton that lead to a final state.

Only sequences (k-mers) of lengths between min_k and max_k that end in a final state are collected.

The resulting k-mers are printed, grouped by their lengths.

| Parameter                  | Description                                                                                             | Default Value |
|----------------------------|---------------------------------------------------------------------------------------------------------|---------------|
| `num_of_states_for_automaton` | The number of states in the automaton. Determines the length of sequences the automaton accepts and influences the complexity of generated k-mers. | 5             |
| `min_k`                    | The minimum length of k-mers to generate and output.                                                   | 5             |
| `max_k`                    | The maximum length of k-mers to generate and output.                                                   | 10            |


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
./K-DNA <num_of_states> <min_k> <max_k>
```

- num_of_states: Number of states in the automaton (integer ≥ 1)
- min_k: Minimum length of k-mers to generate (integer ≥ 1)
- max_k: Maximum length of k-mers to generate (integer ≥ min_k)

Example:
```bash
./K-DNA 5 5 6
```

This runs the program with an automaton of 5 states and generates all k-mers of length 5 to 10.

If invalid arguments are provided, the program prints a usage message explaining the expected input.



