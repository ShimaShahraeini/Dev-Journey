using System;

namespace SnakeGame
{
    internal class Snake
    {
        private Coord headPos; 
        private List<Coord> bodyPos; 
        private Direction currentDirection;
        private int tailLength;

        public Snake() : this(new Coord(10, 1), Direction.Down) { }

        public Snake(Coord snakeFirstPos, Direction firstDir)
        {
            headPos = snakeFirstPos;
            currentDirection = firstDir;
            tailLength = 1;
            bodyPos = new List<Coord>();
        }
        public Coord SnakeHeadPos
        {
            get {return headPos;}
        }
        //By exposing it as IEnumerable<Coord>, the outside world can read (loop over) the snake’s body but can’t directly mess with the list. It’s safer.
        public IEnumerable<Coord> SnakeBodyPos
        { //IEnumerable<Coord> = “read-only view of the body that you can foreach over”.
            get {return bodyPos;}
        }

        private bool IsOpposite(Direction dir1, Direction dir2)
        {
            return (dir1 == Direction.Left && dir2 == Direction.Right) ||
                (dir1 == Direction.Right && dir2 == Direction.Left) ||
                (dir1 == Direction.Up && dir2 == Direction.Down) ||
                (dir1 == Direction.Down && dir2 == Direction.Up);
        }

        public void ChangeDirection(Direction newDirection)
        {
            if (!IsOpposite(newDirection,currentDirection))
                currentDirection = newDirection;
        }


        public void Move(){
            
            //add old head to the body
            bodyPos.Add(new Coord(headPos.X, headPos.Y));
            
            //apply direction to the headPos
            switch (currentDirection)
            {
                case Direction.Left:
                    headPos = new Coord(headPos.X - 1, headPos.Y);
                    break;
                case Direction.Right:
                    headPos = new Coord(headPos.X + 1, headPos.Y);
                    break;
                case Direction.Up:
                    headPos = new Coord(headPos.X, headPos.Y - 1);
                    break;
                case Direction.Down:
                    headPos = new Coord(headPos.X, headPos.Y + 1);
                    break;
            }
        
            //trim body
            if( bodyPos.Count > tailLength)
                bodyPos.RemoveAt(0);

        }

        public void Grow(){ tailLength++; }

        public bool IsCollidingWithSelf(){ return bodyPos.Contains(headPos); }

        public bool Contains(Coord c){ return headPos.Equals(c) || bodyPos.Contains(c); }
    }
}