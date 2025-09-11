# Hangman Game in C#

A simple **console-based Hangman game** written in C# as a first C# project.  
The game selects a random word from a list in `words.txt` and lets you guess letters until you solve the word or run out of lives.

---

## 🎯 Features

- Randomly selects a word from `words.txt` (currently contains 1026 words).  
- Tracks remaining lives and displays the hangman figure progressively.  
- Shows guessed letters and underscores for unguessed letters.  
- Keeps score across multiple rounds.  
- Allows replay after each round.  
- Input validation:
  - Accepts only single alphabetic characters.  
  - Prevents duplicate guesses. 
