using System;

namespace SnakeGame
{
    internal class Coord
    {
        private int x, y;
        public int X { get { return x; } }
        public int Y { get { return y; } }

        public Coord(int x, int y)
        {
            this.x = x;
            this.y = y;
        }
        public override bool Equals(object? obj)
        {
            if ((obj == null) || !GetType().Equals(obj.GetType()))
                return false;

            Coord other = (Coord)obj;
            return other.X == X && other.Y == Y;
        }

        public override int GetHashCode()
        {
            // Combine X and Y into a single hash code
            return HashCode.Combine(X, Y);
        }


        public void ApplyMovementDirection(Direction direction)
        {
            switch (direction)
            {
                case Direction.Left:
                    x--;
                    break;
                case Direction.Right:
                    x++;
                    break;
                case Direction.Down:
                    y++;
                    break;
                case Direction.Up:
                    y--;
                    break;
            }
        }
    }
}