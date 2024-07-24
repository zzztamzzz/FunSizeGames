using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading;

class Program
{
    static void Main(string[] args)
    {
        Console.CursorVisible = false;
        int width = 40;
        int height = 20;
        int score = 0;
        int speed = 100;
        Console.SetWindowSize(width, height + 2);
        Console.SetBufferSize(width, height + 2);

        Snake snake = new Snake();
        Point food = FoodGenerator.GenerateFood(width, height, snake);
        Draw(food, '@');

        while (true)
        {
            if (Console.KeyAvailable)
            {
                ConsoleKeyInfo key = Console.ReadKey(true);
                snake.ChangeDirection(key.Key);
            }

            snake.Move();

            if (snake.Head.Equals(food))
            {
                snake.Grow();
                score += 10;
                food = FoodGenerator.GenerateFood(width, height, snake);
                Draw(food, '@');
                speed = Math.Max(speed - 5, 10);  // Increase speed
            }

            if (snake.IsCollision(width, height))
            {
                break;
            }

            Console.Clear();
            snake.Draw();
            Draw(food, '@');
            DrawScore(score, width);

            Thread.Sleep(speed);
        }

        Console.SetCursorPosition(width / 2 - 5, height / 2);
        Console.Write("Game Over");
        Console.SetCursorPosition(width / 2 - 7, height / 2 + 1);
        Console.Write($"Your Score: {score}");
        Console.ReadKey();
    }

    static void Draw(Point point, char symbol)
    {
        Console.SetCursorPosition(point.X, point.Y);
        Console.Write(symbol);
    }

    static void DrawScore(int score, int width)
    {
        Console.SetCursorPosition(0, 21);
        Console.Write($"Score: {score}".PadRight(width));
    }
}

class Snake
{
    public List<Point> Body { get; private set; }
    public Point Head => Body.First();
    private Direction currentDirection;

    public Snake()
    {
        Body = new List<Point> { new Point(10, 10), new Point(9, 10), new Point(8, 10) };
        currentDirection = Direction.Right;
    }

    public void Move()
    {
        Point newHead = Head;
        switch (currentDirection)
        {
            case Direction.Up:
                newHead = new Point(Head.X, Head.Y - 1);
                break;
            case Direction.Down:
                newHead = new Point(Head.X, Head.Y + 1);
                break;
            case Direction.Left:
                newHead = new Point(Head.X - 1, Head.Y);
                break;
            case Direction.Right:
                newHead = new Point(Head.X + 1, Head.Y);
                break;
        }
        Body.Insert(0, newHead);
        Body.RemoveAt(Body.Count - 1);
    }

    public void Grow()
    {
        Body.Add(Body.Last());
    }

    public void ChangeDirection(ConsoleKey key)
    {
        switch (key)
        {
            case ConsoleKey.W when currentDirection != Direction.Down:
                currentDirection = Direction.Up;
                break;
            case ConsoleKey.S when currentDirection != Direction.Up:
                currentDirection = Direction.Down;
                break;
            case ConsoleKey.A when currentDirection != Direction.Right:
                currentDirection = Direction.Left;
                break;
            case ConsoleKey.D when currentDirection != Direction.Left:
                currentDirection = Direction.Right;
                break;
        }
    }

    public void Draw()
    {
        foreach (Point point in Body)
        {
            Console.SetCursorPosition(point.X, point.Y);
            Console.Write('O');
        }
    }

    public bool IsCollision(int width, int height)
    {
        if (Head.X < 0 || Head.X >= width || Head.Y < 0 || Head.Y >= height)
        {
            return true;
        }
        return Body.Skip(1).Any(p => p.Equals(Head));
    }
}

class Point
{
    public int X { get; }
    public int Y { get; }

    public Point(int x, int y)
    {
        X = x;
        Y = y;
    }

    public override bool Equals(object obj)
    {
        if (obj is Point other)
        {
            return X == other.X && Y == other.Y;
        }
        return false;
    }

    public override int GetHashCode()
    {
        return HashCode.Combine(X, Y);
    }
}

class FoodGenerator
{
    public static Point GenerateFood(int width, int height, Snake snake)
    {
        Random random = new Random();
        Point food;
        do
        {
            food = new Point(random.Next(0, width), random.Next(0, height));
        } while (snake.Body.Contains(food));
        return food;
    }
}

enum Direction
{
    Up,
    Down,
    Left,
    Right
}
