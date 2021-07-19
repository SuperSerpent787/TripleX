#include <iostream>
#include <ctime>

void PrintIntroduction(int Difficulty)
{
    std::cout << "\n\nYou are a spy, hired under Queen Allison whom managed to sneak to King Bear's level " << Difficulty;
    std::cout << " Data Room...\nAll that stands between you and the mission is a locked door mechanism correct codes...\n\n";
}

bool PlayGame(int Difficulty)
{
    PrintIntroduction(Difficulty);

    const int CodeA = rand() % Difficulty + Difficulty;
    const int CodeB = rand() % Difficulty + Difficulty;
    const int CodeC = rand() % Difficulty + Difficulty;
    
    const int CodeSum = CodeA + CodeB + CodeC;
    const int CodeProduct = CodeA * CodeB * CodeC;

    // Print CodeSum and CodeProduct to the terminal
    std::cout << "+ There are 3 numbers in the code.";
    std::cout << "\n+ The codes add up to: " << CodeSum;
    std::cout << "\n+ The codes multiply to give: " << CodeProduct << std::endl;

    int GuessA, GuessB, GuessC;

    // Store player guess
    std::cin >> GuessA >> GuessB >> GuessC;

    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA * GuessB * GuessC;

    // Check if the player's guess is correct
    if (GuessSum == CodeSum && GuessProduct == CodeProduct)
    {
        std::cout << "\n*** The locked door opens and, before you, another door appears: how many layers are there? ***";
        return true;
    }
    else
    {
        std::cout << "\n*** King Bear has not been alerted yet. There is always time to continue opening doors. ***";
        return false;
    }
}

int main()
{ 
    srand(time(NULL)); // Create new random sequence based on time of day

    int LevelDifficulty = 1;
    int const MaxDifficulty = 5;

    while (LevelDifficulty <= MaxDifficulty) // Loop game until all levels completed
    {
        bool bLevelComplete = PlayGame(LevelDifficulty);
        std::cin.clear(); // Clears any errors
        std::cin.ignore(); // Discards the buffer

        if (bLevelComplete)
        {
            ++LevelDifficulty;
        }
        
    }
    std::cout << "\n*** Successfully breaking into the data room, you find the secret recipes to King Bear's honey. ***\n";
    return 0;
}