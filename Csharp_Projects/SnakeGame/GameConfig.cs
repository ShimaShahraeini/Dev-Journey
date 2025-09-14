using System.Text.Json;

namespace SnakeGame
{
    public class GameConfig
    {
        public int GridWidth { get; set; } = 70;       // defaults
        public int GridHeight { get; set; } = 30;
        public int FrameDelay { get; set; } = 100;     // milliseconds
        public int InitialAppleCount { get; set; } = 3;
    }
}
