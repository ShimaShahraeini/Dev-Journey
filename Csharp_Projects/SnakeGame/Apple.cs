using System;

namespace SnakeGame
{
    internal class Apple
    {
        private Coord position = new Coord(1, 1);

        public Coord ApplePos => position;

        public Apple(Random rand, Snake snake, Coord gridDimensions)
        {
            Respawn(rand, snake, gridDimensions);
            
        }

        public void Respawn(Random rand, Snake snake, Coord gridDimensions)
        {
            do{
                position = new Coord(rand.Next(1, gridDimensions.X - 1), rand.Next(1, gridDimensions.Y - 1));
            }while(snake.Contains(position));
        }

    }
}
