# Zombies Infection Simulation Using Cellular Automata
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

## Social Media & Connect 🌐
GitHub Repository: [Java Fundamentals (ITP)](https://github.com/UmarBytes/INTRODUCTION-TO-PROGRAMING-ITP)

**Fiverr:** [UmarFarooq on Fiverr](https://www.fiverr.com/umarfarooq872?public_mode=true) – Need help with NLP, AI, ML, Deep Learning, LLMs, Data Science, or Computer Science? Let's collaborate!

**Facebook:** [Umar Gujjar](https://www.facebook.com/mumar.gujjar.923?_rdc=1&_rdr#) – Stay connected for updates and support.

**YouTube:** [UmarBytes of Life](https://www.youtube.com/@UmarBytesoflife) – Tune in for tutorials, guides, and programming discussions.

**ORCID ID:** [Umar’s ORCID Profile](https://orcid.org/my-orcid?orcid=0009-0008-0919-6720) – Explore my research papers and academic contributions.

