#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include "functions.h"

// Function to initialize the grid
void initializeGrid(std::vector<std::vector<char>>& grid, int gridSize) {
    for (int i = 0; i < gridSize; i++) {
        std::vector<char> row(gridSize, '.'); // Fill grid initially with placeholder
        grid.push_back(row);
    }
}

// Function to place words in the grid
bool placeWordInGrid(std::vector<std::vector<char>>& grid, const std::string& word, int gridSize, bool vertical) {
    int maxAttempts = 50; // Reduced number of attempts to avoid infinite loops
    while (maxAttempts-- > 0) {
        int startRow = rand() % gridSize;
        int startCol = rand() % gridSize;

        // Determine if the word fits vertically or horizontally
        //if vertical is true:
        int endRow = startRow + (vertical ? word.size() - 1 : 0);
        //if horiztonal
        int endCol = startCol + (vertical ? 0 : word.size() - 1);

        // Check boundaries
        if (endRow >= gridSize || endCol >= gridSize) continue; //finds a randomly generated new placement for word.

        // Check if the word can be placed
        //we assume it can be place
        bool canPlace = true;
        //check each character where the word is 
        //intended to be pplaced to ensure there 
        //are no conflicts with existing words.
        for (int i = 0; i < word.size(); i++) { 
            int row = startRow + (vertical ? i : 0);
            int col = startCol + (vertical ? 0 : i);
            if (grid[row][col] != '.' && grid[row][col] != word[i]) {
                canPlace = false;
                break;
            }
        }

        // Place the word if possible
        if (canPlace) {
            for (int i = 0; i < word.size(); i++) {
                int row = startRow + (vertical ? i : 0);
                int col = startCol + (vertical ? 0 : i);
                grid[row][col] = word[i];
            }
            return true;
        }
    }
    return false; // Return false if the word couldn't be placed
}
