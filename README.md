# Project 2 README

## Files Included

* `main.cpp` – Main file that implements Banker’s Algorithm. Takes resource allocation data from any given input file, and outputs a safe sequence if possible.

* `input.txt` – input file that runs a safe state.

* `input2.txt` –input file that can only output an unsafe state.

## How to Use

### 1. Input File Format

*The program expects an input file containing data for the Banker's Algorithm in the following order:*
Two integers, processes P and resource types R (# of each)

*Allocation Matrix (P rows × R columns):*
Shows how many instances of each resource type are currently allocated to each process.


*Max Matrix (P rows × R columns):*
Shows max demand for each process for each resource type.


*Available Vector (1 row × R columns):*
Shows instances for each resource type available in system.

### 2. Compile

```bash
g++ main.cpp -o bankersalg
```

### 3. Run

```bash
./bankersalg input.txt
```

* `input.txt`: runs a safe state.
* `input2.txt`: shows what an unsafe state would look like.

