# Project 2 Documentation 

## Description

This program implements the Banker’s Algorithm for resource allocation. It was written in C++.

Reads matrices representing Allocation, Maximum, and Available resources from an input file. It calculates the **Need** matrix and determines whether the system is in a safe state or an unsafe state.

If system is safe, a safe sequence of process execution is displayed. If unsafe, the program reports that no safe sequence exists.

## Components

### Matrices

* Allocation – What current resources are being assigned to each process.
* Maximum – What the maximum demand of each process is.
* Need – Calculated as `Maximum – Allocation`, the remaining resources each process needs to complete.
* Available – The resources currently available in the system.

### Safety Algorithm

* Checks if each process can finish with available resources.
* Marks processes when they can complete.
* Updates available resources as processes finish.
* From there, determine if the system can finish all processes without deadlock.
