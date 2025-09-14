using System;
using System.IO;
using System.Text.Json;

namespace SnakeGame
{
    class Program
    {
        static void Main()
        {
            GameConfig config = GameConfigLoader.LoadConfig(); // load JSON
            IRenderer renderer = new ConsoleRenderer();
            Game game = new Game(renderer, config);
            game.Run();
        }
    }
    public static class GameConfigLoader
    {
        public static GameConfig LoadConfig(string path = "config.json")
        {
            if (File.Exists(path))
            {
                string json = File.ReadAllText(path);
                return JsonSerializer.Deserialize<GameConfig>(json) ?? new GameConfig();
            }
            else
            {
                return new GameConfig(); // fallback to defaults
            }
        }
    }
}