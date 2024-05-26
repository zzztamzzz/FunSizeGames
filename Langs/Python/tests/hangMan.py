import random

def get_word():
    words = ['python', 'java', 'swift', 'javascript', 'ruby', 'perl']
    return random.choice(words).upper()

def display_board(word, guessed_letters):
    display = [letter if letter in guessed_letters else '_' for letter in word]
    print(' '.join(display))

def hangman():
    word_to_guess = get_word()
    guessed_letters = set()
    attempts = 6

    print("Welcome to Hangman!")
    print("Guess the word letter by letter.")
    
    while attempts > 0:
        display_board(word_to_guess, guessed_letters)
        guess = input("Enter a letter: ").upper()

        if guess in guessed_letters:
            print("You have already guessed that letter.")
        elif guess in word_to_guess:
            guessed_letters.add(guess)
            if set(word_to_guess) == guessed_letters:
                print(f"Congratulations! You guessed the word: {word_to_guess}")
                break
        else:
            attempts -= 1
            print(f"Wrong guess! You have {attempts} attempts left.")
            guessed_letters.add(guess)
    
    if attempts == 0:
        print(f"Sorry, you lost! The word was: {word_to_guess}")

if __name__ == "__main__":
    hangman()
