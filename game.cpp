#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

// Function to generate a random number between min and max
int generateRandomNumber(int min, int max) {
    return min + rand() % (max - min + 1);
}

// Function to check if the player has been eaten by any NPC
bool isEaten(int playerMass, const std::vector<int>& npcMasses) {
    for (int mass : npcMasses) {
        if (mass > playerMass) {
            return true;
        }
    }
    return false;
}

int main() {
    // Seed the random number generator
    srand(time(0));

    // Initialize player mass and NPC masses
    int playerMass = 0;
    std::vector<int> npcMasses = {10, 15, 20, 25};

    // Game loop
    while (true) {
        // Generate a random mass for the player to eat
        int massToEat = generateRandomNumber(1, 5);

        // Increase player mass by the mass eaten
        playerMass += massToEat;

        // Check if the player has been eaten by any NPC
        if (isEaten(playerMass, npcMasses)) {
            std::cout << "Game Over! You have been eaten." << std::endl;
            break;
        }

        // Print player mass and NPC masses
        std::cout << "Player Mass: " << playerMass << std::endl;
        std::cout << "NPC Masses: ";
        for (int mass : npcMasses) {
            std::cout << mass << " ";
        }
        std::cout << std::endl;

        // Generate a random delay before the next iteration
        int delay = generateRandomNumber(1, 3);
        std::cout << "Next iteration in " << delay << " seconds." << std::endl;
        std::cout << std::endl;

        // Wait for the delay
        for (int i = 0; i < delay; i++) {
            sleep(1);
        }
    }

    return 0;
}
