using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading;
using System.Threading.Tasks;
using System.IO;



namespace SnakeGame
{
    internal class Game
    {
        private readonly IRenderer renderer;

        private GameState state;
        private Snake snake;
        private List<Apple> apples;
        private int ApplesCount {get; set;}
        private Coord gridDimensions;

        public Coord GridDimensions => gridDimensions;
        public Snake Snake => snake;
        public List<Apple> Apples => apples;

        public int Score{ get; set; }
        public int FrameDelay_mili{ get; set; }
        private Random rand;
        public int HighScore{ get; private set;}
        private Direction? requestedDirection;

        public Game(IRenderer renderer, GameConfig config)
        {
            this.renderer = renderer;

            state = GameState.Running;

            gridDimensions = new Coord(config.GridWidth, config.GridHeight);
            FrameDelay_mili = config.FrameDelay;
            ApplesCount = config.InitialAppleCount;

            Score = 0;
            snake = new Snake();

            rand = new Random();
            apples = new List<Apple>();
            for(int i = 0; i < ApplesCount; i++)
                AddNewApple();

            LoadHighScore();
        }

        public void Run()
        {
            Console.CursorVisible = false; // hide blinking cursor
            Console.Clear(); // clean screen ONCE
            StartInputThread();

            while (true)
            {
                if (state == GameState.Running)
                {
                    //Apply input FIRST
                    if (requestedDirection.HasValue)
                    {
                        snake.ChangeDirection(requestedDirection.Value);
                        requestedDirection = null; // reset
                    }

                    //move the snake
                    snake.Move();

                    //Check collisions (before drawing)
                    var eatenApple = apples.FirstOrDefault(a => a.ApplePos.Equals(snake.SnakeHeadPos));
                    if (eatenApple != null)
                    {
                        snake.Grow();
                        Score++;
                        apples.Remove(eatenApple);
                        AddNewApple();
                    }else if(IsCollision())
                    {
                        state = GameState.GameOver;
                    }

                    //Speed increase every 5 appless to increase defficulty
                    if (Score%5==0 && Score!=0)
                    {
                        FrameDelay_mili = Math.Max(30, (int)(100 / (1 + Math.Log(1 + Score / 5.0))));

                    }

                    //render screen
                    renderer.Render(this);

                    //Frame delay
                    Thread.Sleep(FrameDelay_mili);

                }else if(state == GameState.Paused)
                {
                    Console.WriteLine($"Score: {Score}");
                    renderer.Render(this);
                    Console.SetCursorPosition(0, gridDimensions.Y + 2);
                    Console.WriteLine("=== PAUSED ===");
                    Console.WriteLine("Press P to resume");

                    // Wait here until unpaused (no redraw spam)
                    while (state == GameState.Paused)
                        Thread.Sleep(FrameDelay_mili);


                }else if (state == GameState.GameOver)
                {   
                    renderer.Render(this);
                    SaveHighScore();
                    Console.WriteLine();
                    Console.SetCursorPosition(0, gridDimensions.Y + 2);
                    Console.WriteLine("=== GAME OVER ===");
                    Console.WriteLine("Press ENTER to restart");

                    // Wait here until restart (no redraw spam)
                    while (state == GameState.GameOver)
                        Thread.Sleep(FrameDelay_mili);

                }

            }

        }

        private void StartInputThread()
        {   //It runs on a background thread, so your main game loop keeps running
            Task.Run(() =>
            {
                while (true)
                {
                    ConsoleKey key = Console.ReadKey(true).Key;

                    switch (key)
                    {
                        case ConsoleKey.LeftArrow:
                            requestedDirection = Direction.Left;
                            break;
                        case ConsoleKey.RightArrow:
                            requestedDirection = Direction.Right;
                            break;
                        case ConsoleKey.UpArrow:
                            requestedDirection = Direction.Up;
                            break;
                        case ConsoleKey.DownArrow:
                            requestedDirection = Direction.Down;
                            break;
                        case ConsoleKey.P:
                            if (state == GameState.Running)
                                state = GameState.Paused;
                            else if (state == GameState.Paused)
                                state = GameState.Running;
                            Console.Clear(); 
                            break;
                        case ConsoleKey.Enter:
                            if (state == GameState.GameOver)
                            {
                                Reset();
                                state = GameState.Running;
                            }
                            Console.Clear(); 
                            break;
                    }
                }
            });
        }

        private void AddNewApple()
        {
            var newApple = new Apple(rand, snake, gridDimensions);

            while (apples.Any(a => a.ApplePos.Equals(newApple.ApplePos)))
            {
                newApple.Respawn(rand, snake, gridDimensions);
            }

            apples.Add(newApple);
        }

        private bool IsCollision()
        {
            return  (snake.SnakeHeadPos.X == 0 ||
                    snake.SnakeHeadPos.Y == 0 || 
                    snake.SnakeHeadPos.X == gridDimensions.X -1|| 
                    snake.SnakeHeadPos.Y == gridDimensions.Y -1 ||
                    snake.IsCollidingWithSelf());
        }

        public void Reset()
        {
            Score = 0;
            snake = new Snake();
            apples.Clear();
            for(int i = 0; i < ApplesCount; i++)
                AddNewApple();
            FrameDelay_mili = 100; 
        }

        private readonly string highScoreFile = Path.Combine(Environment.GetFolderPath(Environment.SpecialFolder.ApplicationData), "SnakeGame", "highscore.txt");

        public void SaveHighScore()
        {
            if (Score > HighScore)
            {
                HighScore = Score;
                try
                {
                    File.WriteAllText(highScoreFile, HighScore.ToString());
                }
                catch
                {
                    // Could log error or ignore
                }
            }
        }

        public void LoadHighScore()
        {
            if (File.Exists(highScoreFile))
            {
                string text = File.ReadAllText(highScoreFile);
                if (int.TryParse(text, out int score))
                    HighScore = score;
                else
                    HighScore = 0; // fallback if corrupted
            }
            else
            {
                HighScore = 0;
            }
        }


    }
}