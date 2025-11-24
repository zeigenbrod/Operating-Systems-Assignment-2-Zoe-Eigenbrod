# Project 2 README

## Files Included

* `main.cpp` – Main file that implements Banker’s Algorithm. Takes resource allocation data from any given input file, and outputs a safe sequence if possible.

* `input.txt` – Example input file that runs a safe state.

* `input2.txt` – Example input file that can only output an unsafe state.

## How to Use

### 1. Compile

```bash
g++ main.cpp -o bankers
```

### 2. Run

```bash
./bankers input.txt
```

* `input.txt`: runs a **safe** state.
* `input2.txt` → shows what an **unsafe** state would look like.

Example:

```bash
./bankers input.txt
# Output: System is in a SAFE state
# Safe sequence: P0 -> P1 -> P2 -> P3 -> P4
```

```bash
./bankers input2.txt
# Output: System is in an UNSAFE state
```
