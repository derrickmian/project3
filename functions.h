#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <vector>
#include <string>

void initializeGrid(std::vector<std::vector<char>>& grid, int gridSize);
bool placeWordInGrid(std::vector<std::vector<char>>& grid, const std::string& word, int gridSize, bool vertical);
std::string generateHTML(const std::vector<std::vector<char>>& grid);

#endif // FUNCTIONS_H
