namespace SnakeGame
{
    internal class ConsoleRenderer : IRenderer
    {
        public void Render(Game game)
        {
            Console.SetCursorPosition(0, 0);
            Console.WriteLine($"Score: {game.Score}");
            Console.WriteLine($"HighScore: {game.HighScore}");

            for (int y = 0; y < game.GridDimensions.Y; y++)
            {
                for (int x = 0; x < game.GridDimensions.X; x++)
                {
                    var coord = new Coord(x, y);

                    if (game.Snake.SnakeHeadPos.Equals(coord))
                    {
                        Console.ForegroundColor = ConsoleColor.DarkGreen;
                        Console.Write("■");
                        Console.ResetColor();
                    }
                    else if (game.Snake.SnakeBodyPos.Contains(coord))
                    {
                        Console.ForegroundColor = ConsoleColor.Green;
                        Console.Write("■");
                        Console.ResetColor();
                    }
                    else if (game.Apples.Any(a => a.ApplePos.Equals(coord)))
                    {
                        Console.ForegroundColor = ConsoleColor.Red;
                        Console.Write("●");
                        Console.ResetColor();
                    }
                    else if (x == 0 || y == 0 || x == game.GridDimensions.X - 1 || y == game.GridDimensions.Y - 1)
                    {
                        Console.ForegroundColor = ConsoleColor.Gray;
                        Console.Write("#");
                        Console.ResetColor();
                    }
                    else
                        Console.Write(" ");
                }
                Console.WriteLine();
            }
        }
    }
}
