#include <iostream>
#include <cstdlib>  // for rand() and srand()
#include <ctime>    // for time()

int main() 
{
    // Seed the random number generator
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    // Generate a random number between 1 and 100
    int numberToGuess = std::rand() % 100 + 1;
    int playerGuess = 0;

    std::cout << "Welcome to the Number Guessing Game!" << std::endl;
    std::cout << "I have selected a number between 1 and 100." << std::endl;
    std::cout << "Try to guess it!" << std::endl;

    // Loop until the player guesses the correct number
    while (playerGuess != numberToGuess) 
    {
        std::cout << "Enter your guess: ";
        std::cin >> playerGuess;

        if (playerGuess > numberToGuess) 
        {
            std::cout << "Too high! Try again." << std::endl;
        } 
        else if (playerGuess < numberToGuess) 
        {
            std::cout << "Too low! Try again." << std::endl;
        } 
        else 
        {
            std::cout << "Congratulations! You guessed the correct number." << std::endl;
        }
    }

    return 0;
}
