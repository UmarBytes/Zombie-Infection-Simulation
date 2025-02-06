# Zombie Infection Simulation Using Cellular Automata
**Course: Parallel Computing (COMP H3036)** 

**Institution: Technological University Dublin**

**Completed By: Muhammad Umar Farooq**

**Role in Project: Academic Collaboration**


# Project Introduction
This project models a Zombie Infection outbreak using Cellular Automata, implementing both serial and parallel computing environments to simulate infection dynamics. The project simulates infection scenarios, analyzes performance speed-ups, and evaluates population outcomes under various conditions.

# Technology Stack
**C:** Programming language used for the implementation of the simulation.

**Pthreads:** Used for parallelizing the simulation to speed up the process by utilizing multiple threads.

**Python:** Used for visualizing the simulation results and generating images from the grid data.

# Files Details

**zombie_serial.c:**
Functionality: Contains the code for the serial version of the zombie infection simulation. It simulates the infection process in a single-threaded manner, updating the grid based on neighboring cell states.

**zombie_parallel.c:**
Functionality: Implements the parallel version using Pthreads, where the grid rows are divided among multiple threads, and synchronization is handled using barriers.

**viz.py:**
Functionality: Visualizes the grid data for different days of the simulation. It loads the grid state from text files and generates corresponding images for each day, saving them as PNG files for later review.

# Contact Email
For any inquiries or further details, please contact:

**Email:** umarbytesoflife@gmail.com

**Responsible: Muhammad Umar Farooq**


