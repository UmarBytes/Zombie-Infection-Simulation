import numpy as np
import matplotlib.pyplot as plt


for day in range(0, 100, 10):
    data = np.loadtxt(f'grid_day_{day}.txt')
    plt.imshow(data, cmap='viridis')
    plt.title(f'Day {day}')
    plt.colorbar()
    plt.savefig(f'Visualization_day_{day}.png')
    plt.close()