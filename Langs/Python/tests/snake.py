import curses
import random

# Initialize the screen
screen = curses.initscr()
curses.curs_set(0)  # Hide the cursor
screen.nodelay(1)  # Non-blocking input
screen.timeout(100)  # Refresh rate in milliseconds

# Define the initial position and size of the snake and the game window
sh, sw = screen.getmaxyx()
w = curses.newwin(sh, sw, 0, 0)

# Create the snake and food
snake_x = sw//4
snake_y = sh//2
snake = [
    [snake_y, snake_x],
    [snake_y, snake_x-1],
    [snake_y, snake_x-2]
]
food = [sh//2, sw//2]
w.addch(food[0], food[1], curses.ACS_PI)

# Initialize the snake's direction
key = curses.KEY_RIGHT
score = 0

# Main game loop
while True:
    next_key = w.getch()
    key = key if next_key == -1 else next_key

    if key == curses.KEY_DOWN:
        new_head = [snake[0][0] + 1, snake[0][1]]
    if key == curses.KEY_UP:
        new_head = [snake[0][0] - 1, snake[0][1]]
    if key == curses.KEY_LEFT:
        new_head = [snake[0][0], snake[0][1] - 1]
    if key == curses.KEY_RIGHT:
        new_head = [snake[0][0], snake[0][1] + 1]

    # Insert new head of the snake
    snake.insert(0, new_head)

    # Check if snake has eaten the food
    if snake[0] == food:
        score += 1
        food = None
        while food is None:
            nf = [
                random.randint(1, sh-1),
                random.randint(1, sw-1)
            ]
            food = nf if nf not in snake else None
        w.addch(food[0], food[1], curses.ACS_PI)
    else:
        # Remove last part of the snake's tail
        tail = snake.pop()
        w.addch(tail[0], tail[1], ' ')

    # Check if snake has hit the wall or itself
    if (
        snake[0][0] in [0, sh] or
        snake[0][1] in [0, sw] or
        snake[0] in snake[1:]
    ):
        curses.endwin()
        quit()

    # Draw the snake
    w.addch(snake[0][0], snake[0][1], curses.ACS_CKBOARD)

