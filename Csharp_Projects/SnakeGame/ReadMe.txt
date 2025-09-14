# Snake Game in C#

A classic **Snake game** implemented in C# for the console, featuring growing difficulty, multiple apples, score tracking, and a high-score system.  

This project was designed as a learning exercise to explore C# fundamentals, object-oriented programming, and software design patterns.  

---

## Features

- **Classic Snake Gameplay** – Move the snake to eat apples and grow longer. Avoid hitting the walls or yourself.  
- **Multiple Apples** – There are multiple apples on the board at the same time.  
- **Score & High Score** – Keeps track of your score during the game and saves the high score to a file.  
- **Dynamic Speed** – The snake speeds up as your score increases.  
- **Pause & Restart** – Press `P` to pause/resume and `ENTER` to restart after a game over.  
- **Configurable Game Settings** – Grid size, number of apples, and frame delay can be loaded from a `config.json` file.  
- **Separation of Concerns** – The game logic is separated from the rendering, using an `IRenderer` interface. This makes it easy to swap the console for another UI (e.g., GUI).  

---

## Project Structure

SnakeGame/
├─ Program.cs # Entry point; loads config and starts the game
├─ Game.cs # Core game logic: snake movement, collisions, scoring
├─ Snake.cs # Snake model with head, body, movement, and growth
├─ Apple.cs # Apple model with random spawning
├─ Coord.cs # Simple struct for X/Y positions
├─ IRenderer.cs # Interface for rendering the game
├─ ConsoleRenderer.cs # Console-specific rendering implementation
├─ GameConfig.cs # Game configuration model
├─ config.json # JSON configuration file

---

## How It Works

1. **Game Loop** – The `Game.Run()` method handles input, updates the snake’s position, checks for collisions, and renders the game every frame.  
2. **Snake Logic** – The snake moves in its current direction, grows when eating an apple, and checks for collisions with itself or the walls.  
3. **Apples** – Apples are randomly placed on the grid, and new ones spawn when eaten.  
4. **Rendering** – The `IRenderer` interface allows the game to be rendered using different methods. Currently, `ConsoleRenderer` draws the grid, snake, and apples.  
5. **Configuration** – Game parameters like grid size, apple count, and speed are loaded from `config.json` using `System.Text.Json`.  
6. **High Score** – Scores are saved to a file in the user’s AppData folder, so progress is preserved between sessions.  

---

## What I Learned

- **C# Basics** – Classes, properties, constructors, enums, lists, and loops.  
- **Object-Oriented Design** – Created separate classes for Snake, Apple, Game, and Coord to encapsulate behavior.  
- **Interfaces** – Learned how `IRenderer` allows for multiple rendering implementations without changing game logic.  
- **Threading & Input** – Used `Task.Run` to handle console input asynchronously while keeping the game loop running.  
- **File I/O** – Read/write high scores and configuration files.  
- **JSON Serialization** – Used `System.Text.Json` to load game settings from a `config.json` file.  
- **Clean Code Practices** – Separation of concerns, read-only properties for safety, and extensible design.  

---

## How to Play

- Use **Arrow Keys** to move the snake.  
- Press **P** to pause/resume the game.  
- Press **ENTER** to restart after a game over.  

---

## Configuration (`config.json`)

```json
{
  "GridX": 70,
  "GridY": 30,
  "ApplesCount": 3,
  "FrameDelay": 100
}
feel free to adjust this variables in json file as you whish to create your own game and play it.
