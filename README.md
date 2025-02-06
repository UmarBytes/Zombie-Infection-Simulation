# Zombie Infection Simulation Using Cellular Automata
**Course: Parallel Computing (COMP H3036)** \n
Institution: Technological University Dublin
Completed By: Muhammad Umar Farooq
Role in Project: Academic Collaboration

Project Introduction
This project models a Zombie Infection outbreak using Cellular Automata, implementing both serial and parallel computing environments to simulate infection dynamics. The project simulates infection scenarios, analyzes performance speed-ups, and evaluates population outcomes under various conditions.

Project Features
Parallel and Serial Simulations: Implementations for both serial and parallel simulations using Pthreads.
Infection Simulation: Simulates infection dynamics using the Cellular Automata model, where each cell represents a susceptible, infected (zombie), or removed individual.
Performance Analysis: Provides speed-up comparisons between parallel and serial simulations.
Visualization: Visualizes the grid at various time steps and saves it for further analysis.
Technology Stack
C: Programming language used for the implementation of the simulation.
Pthreads: Used for parallelizing the simulation to speed up the process by utilizing multiple threads.
Matplotlib (via Python): Used for visualizing the simulation results and generating images from the grid data.
Files Details
Here’s a breakdown of the key files in the project:

zombie_serial.c:
Functionality: Contains the code for the serial version of the zombie infection simulation. It simulates the infection process in a single-threaded manner, updating the grid based on neighboring cell states.

zombie_parallel.c:
Functionality: Implements the parallel version using Pthreads, where the grid rows are divided among multiple threads, and synchronization is handled using barriers.

viz.py:
Functionality: Visualizes the grid data for different days of the simulation. It loads the grid state from text files and generates corresponding images for each day, saving them as PNG files for later review.

python
Copy
Edit
import numpy as np
import matplotlib.pyplot as plt

for day in range(0, 100, 10):
    data = np.loadtxt(f'grid_day_{day}.txt')
    plt.imshow(data, cmap='viridis')
    plt.title(f'Day {day}')
    plt.colorbar()
    plt.savefig(f'Visualization_day_{day}.png')
    plt.close()
Zombie Infection Using Cellular Automata.pdf:
Functionality: Contains the detailed project documentation, including the abstract, system architecture, flowcharts for both serial and parallel simulations, pseudo-code, and performance analysis.

Zombie Infection Using Cellular Automata.docx:
Functionality: Provides a similar documentation overview, including system design, project specifications, and implementation details for both serial and parallel models.

speedup.png:
Functionality: A graph illustrating the speed-up analysis of the simulation, comparing real-time performance of parallel and serial simulations with varying numbers of threads.

Setup Instructions
To set up and run the Zombie Infection Simulation project, follow these steps:

Clone the Repository
Clone the repository to your local machine:

bash
Copy
Edit
git clone https://github.com/your-repo-link.git
Compile the C Code
Use the following command to compile the C files:

For serial simulation:
bash
Copy
Edit
gcc -g -o serial_simulation zombie_serial.c
For parallel simulation:
bash
Copy
Edit
gcc -g -pthread -o parallel_simulation zombie_parallel.c
Run the Simulations

To run the serial simulation:
bash
Copy
Edit
./serial_simulation
To run the parallel simulation:
bash
Copy
Edit
./parallel_simulation
Visualize the Results
After running the simulation, you can visualize the results by running the following Python script:

bash
Copy
Edit
python viz.py
Contact Email
For any inquiries or further details, please contact:
Email: umarbytesoflife@gmail.com

Responsible: Muhammad Umar Farooq


