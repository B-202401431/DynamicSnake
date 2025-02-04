# 🐍 **Snake Game** 🐍

Welcome to the **Snake Game**! 🎮 A fun and classic game where you control a snake 🐍 that eats food 🍏 to grow longer, while trying to avoid colliding with the walls 🚧 or your own body. This version is implemented in **C++** 🖥️ and runs in your console!

## 🎯 **Game Features**
- **Snake Movement**: Control the snake using the `WASD` keys or the arrow keys.
- **Growing Snake**: Every time the snake eats food, it grows in length.
- **Increasing Difficulty**: As you score more, the snake's speed increases 🏃‍♂️.
- **Game Over**: The game ends when the snake collides with the walls or its own body.
- **Score Tracking**: Your score is displayed, and the game gets harder as you progress! 💥

## 📸 **Game Screenshot**

Here’s a preview of what the game looks like in action:

![Snake Game Screenshot](https://github.com/B-202401431/-Snake-Game-in-C-Windows-Console-/blob/main/Screenshot%20(348).png)


---

## 🏁 **How to Play**

1. **Start the Game**: Press any key to begin the game.
2. **Control the Snake**: Use `W`, `A`, `S`, `D` or the Arrow keys to control the snake's movement.
3. **Eat Food**: The snake grows longer each time it eats food.
4. **Avoid Collisions**: The game ends if the snake hits the walls or its own body.
5. **Exit Game**: Press `ESC` to exit at any time.

---

## 🛠️ **Code Explanation**

Let’s dive into the main parts of the code to understand how everything works. 💡

### 1. **Snake Class (`snake.h`)**
The `Snake` class is where the magic happens, as it controls everything related to the snake.

#### **Attributes**:
- **`cord pos`**: Stores the current position of the snake's head.
- **`int len`**: Keeps track of the snake's length.
- **`int vel`**: Defines the speed of the snake.
- **`char dir`**: The direction the snake is moving (`'u'`, `'d'`, `'r'`, `'l'`).
- **`vector<cord> body`**: A collection of the snake's body parts (each `cord` contains an `x` and `y`).

#### **Methods**:
- **`change_dir(char dir)`**: Changes the snake's direction based on user input (`WASD` or arrow keys).
- **`move()`**: Moves the snake in the current direction and updates its position.
- **`food_eaten(cord food_pos)`**: Checks if the snake eats food (i.e., if its head collides with food).
- **`length_inc()`**: Increases the length of the snake.
- **`snake_collide_border()`**: Detects if the snake hits the border or its own body.

### 2. **Food Class (`food.h`)**
The `Food` class is responsible for generating food for the snake.

#### **Attributes**:
- **`cord pos`**: The position of the food on the board.

#### **Methods**:
- **`food_gen()`**: Randomly generates food at a position on the board.

### 3. **Cord Class (`cord.h`)**
The `cord` class defines coordinates for both the snake and food. It includes:

- **`x`** and **`y`**: The x and y coordinates of the snake or food.

### 4. **Main Game Loop**
The main game loop runs continuously until the game is over. It does the following:

- **Draws the Game Board**: The snake, food, and borders are drawn.
- **Captures User Input**: The game listens for user input (`WASD` or arrow keys) to change the snake's direction.
- **Moves the Snake**: The snake moves in the current direction.
- **Checks for Collisions**: The game checks if the snake collides with walls or itself.
- **Increases Speed**: As the score increases, the snake's speed increases.
- **Ends the Game**: If the snake hits a wall or itself, the game ends.

---

## 📂 **Project Structure**
Here’s a quick look at the project files:

- **`snake.h`**: Contains the Snake class with all its logic.
- **`food.h`**: Contains the Food class that generates random food.
- **`cord.h`**: Contains the `cord` class that stores x and y coordinates for snake and food.
- **Main File**: Contains the game loop, board rendering, and user input handling.

---

## 💻 **How to Run the Game**

1. **Install a C++ Compiler**: You need a C++ compiler, like **GCC** or **MinGW**, installed on your system.
2. **Clone or Download the Repository**:
   ```bash
   git clone https://github.com/your-repo/snake-game.git
