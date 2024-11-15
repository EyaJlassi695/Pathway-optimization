# Pathway-optimization
Here's a suggested description for your GitHub project, including the uploaded image:

---

# Labyrinth Generator

This project is a C-based program that generates perfect labyrinths, where each point has a unique path to every other point, using the SDL2 library for visualization. The project was developed by **Ahmed Ghamgui**, **Eya Jlassi**, and **Yassine Regayeg**, under the guidance of **Mme. Sonia Alouane** as part of our first-year Advanced Techniques studies.

## Features
- **Perfect Labyrinth Generation**: The program creates a perfect maze with no loops or inaccessible areas.
- **Interactive Gameplay**: The user can control a movable square to navigate the labyrinth, aiming to reach a target.
- **Visual Interface**: The labyrinth is displayed with a red path on a black background for clarity. The player and target are represented as colored squares.
- ![image](https://github.com/user-attachments/assets/5eb98d18-f1b7-4d84-ab92-142d3b025e30)


## Technical Details
- **Language**: C
- **Libraries**: SDL2 for graphical rendering
- **Algorithm**: Prim’s algorithm is used to generate the labyrinth by randomly selecting cells and connecting paths while ensuring no loops.
- **Data Structures**: The labyrinth is represented as a matrix of cells, each storing its own wall status and coordinates.

## How to Run
1. Install SDL2 and GCC.
2. Compile the project:
   ```bash
   gcc -o main main.c -lSDL2
   ```
3. Run the executable:
   ```bash
   ./main
   ```

## Challenges
The project team faced several challenges, particularly in implementing the SDL2 library for graphical output in C. However, through collaboration and perseverance, the team was able to complete the project successfully.

## Authors
- **Ahmed Ghamgui** - Code implementation
- **Eya Jlassi** - Research and project approach
- **Yassine Regayeg** - Documentation and report writing with LaTeX
