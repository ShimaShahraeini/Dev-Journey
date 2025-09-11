using System;

class Program
{
    // Static Random instance for all random operations
    static Random rand = new Random();

    static void Main()
    {
        int score = 0;
        int rounds = 0;

        do
        {
            string? word = PickWord();
            if (word == null)
            {
                Console.WriteLine("No word could be selected. Exiting.");
                break;
            }

            if (PlayHangman(word))
                score++;
            rounds++;

            Console.WriteLine($"Round {rounds}: Current score: {score}");
        } while (AskReplay());
    }

    static bool PlayHangman(string word)
    {
        int maxLives = 7;
        int currentLives = maxLives;
        bool win = false;
        var guessedLetters = new List<char>();

        while (currentLives > 0 && !win)
        {
            DisplayWord(word, guessedLetters);
            Console.WriteLine($"Remaining lives: {currentLives}/{maxLives}");
            Console.WriteLine("Guessed letters: " + string.Join(", ", guessedLetters));

            char guess = GetGuess(guessedLetters);
            guessedLetters.Add(guess);

            win = CheckWin(word, guessedLetters);

            if (word.Contains(guess) && !guessedLetters.Contains(guess))
            {
                Console.WriteLine("\nCorrect!");
            }
            else
            {
                Console.WriteLine("Incorect!");
                currentLives--;
                ShowHangman(maxLives, currentLives);
            }

        }

        if (win)
            Console.WriteLine($"Congratulations, you win! The word was '{word}'.");
        else
            Console.WriteLine($"Game over! The word was '{word}'.");

        return win;
    }

    static string? PickWord()
    {
        string[] wordList;

        try
        {
            // Read all lines from the file into an array
            wordList = File.ReadAllLines("words.txt");

            // Remove empty lines just in case
            wordList = Array.FindAll(wordList, w => !string.IsNullOrWhiteSpace(w));

            if (wordList.Length == 0)
            {
                Console.WriteLine("words.txt is empty!");
                return null;
            }
        }
        catch (Exception e)
        {
            Console.WriteLine("Error reading words.txt: " + e.Message);
            return null; // exit program if file not found
        }

        // Pick a random word
        return wordList[rand.Next(wordList.Length)];

    }

    static void DisplayWord(string word, List<char> guessedLetters)
    {
        foreach (char c in word)
        {
            if (guessedLetters.Contains(c))
                Console.Write($"{c} ");
            else
                Console.Write("_ ");
        }
        Console.WriteLine("\n");
    }

    static char GetGuess(List<char> guassedLetters)
    {
        while (true)
        {
            Console.Write("Please Guess a Letter: ");
            string? input = Console.ReadLine();

            //if user press Enter
            if (string.IsNullOrWhiteSpace(input))
            {
                Console.WriteLine("Please enter a letter.");
                continue; // skip this turn
            }
            char guess = char.ToLower(input[0]); //if user input chapital letter  

            //if user enter an already guessed char
            if (guassedLetters.Contains(guess))
            {
                Console.WriteLine("You already guessed that letter.");
                continue; // skip this turn
            }

            //if user enter anything other than a valid char
            if (!char.IsLetter(guess))
            {
                Console.WriteLine("Please enter a valid letter.");
                continue; // skip this turn
            }

            return guess;
        }
    }

    static bool CheckWin(string word, List<char> guessedLetters)
    {
        foreach (char c in word)
        {
            if (!guessedLetters.Contains(c))
            {
                return false;
            }
        }
        return true;
    }

    static bool AskReplay()
    {
        Console.Write("Play again? (y/n): ");
        string? input = Console.ReadLine();
        return input?.Trim().ToLower() == "y";
    }

    static void ShowHangman(int maxLives, int currentLives)
    {
        string[] hangmanStages =
        {
            "",                     // 0: no parts
            "  O  ",                 // 1
            "  O  \n  |  ",          // 2
            "  O  \n /|  ",          // 3
            "  O  \n /|\\ ",         // 4
            "  O  \n /|\\ \n /  ",   // 5
            "  O  \n /|\\ \n / \\",  // 6
            "  O  \n /|\\ \n / \\\nDEAD" // 7: player lost
        };

        int index = maxLives - currentLives;

        // Clamp index to valid range
        int stage = (int)((maxLives - currentLives) * (hangmanStages.Length - 1) / (double)maxLives);
        
        Console.WriteLine(hangmanStages[stage]);
        Console.WriteLine("\n");
    }
    
}
