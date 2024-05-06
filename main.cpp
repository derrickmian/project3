#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <string>
#include "functions.h"

int main() {
    srand(time(nullptr));
    const int gridSize = 10;
    std::vector<std::string> words = {"HELLO", "WORLD", "CPLUSPLUS", "DERRICK", "EDDY"};
    std::vector<std::vector<char>> grid;

    initializeGrid(grid, gridSize);

    for (const auto& word : words) {
        bool vertical = rand() % 2;
        if (!placeWordInGrid(grid, word, gridSize, vertical)) {
            std::cerr << "Failed to place word: " << word << std::endl;
        }
    }

    for (auto& row : grid) {
        for (char& cell : row) {
            if (cell == '.') {
                cell = 'A' + rand() % 26;
            }
        }
    }

    // Output HTML and embedded JavaScript
    std::cout << "Content-type: text/html\n\n";
    std::cout << "<!DOCTYPE html><html lang='en'><head><meta charset='UTF-8'><title>Word Search Game</title>";
    std::cout << "<style>table { border-collapse: collapse; } td { width: 30px; height: 30px; border: 1px solid #000; text-align: center; cursor: pointer; } td.selected { background-color: #ADD8E6; }</style>";
    std::cout << "</head><body>";
    std::cout << "<table id='wordGrid'>";
    for (const auto& row : grid) {
        std::cout << "<tr>";
        for (char cell : row) {
            std::cout << "<td>" << cell << "</td>";
        }
        std::cout << "</tr>";
    }
    std::cout << "</table>";
    std::cout << "<script>";
    std::cout << "document.addEventListener('DOMContentLoaded', function() {";
    std::cout << "const grid = document.getElementById('wordGrid');";
    std::cout << "let selectedCells = [];";
    std::cout << "let isSelecting = false;";
    std::cout << "grid.onmousedown = function(event) { if (event.target.tagName === 'TD') { isSelecting = true; event.target.classList.add('selected'); selectedCells.push(event.target); }};";
    std::cout << "grid.onmouseover = function(event) { if (event.target.tagName === 'TD' && isSelecting) { event.target.classList.add('selected'); selectedCells.push(event.target); }};";
    std::cout << "grid.onmouseup = function() { isSelecting = false; validateWord(); };";
    std::cout << "function validateWord() { const word = selectedCells.map(cell => cell.textContent).join(''); const validWords = ['HELLO', 'WORLD', 'CPLUSPLUS', 'DERRICK', 'EDDY']; if (validWords.includes(word)) { alert('Correct! ' + word); selectedCells.forEach(cell => cell.style.backgroundColor = 'lime'); } else { alert('Try again!'); selectedCells.forEach(cell => cell.classList.remove('selected')); } selectedCells = []; };";
    std::cout << "});";
    std::cout << "</script>";
    std::cout << "</body></html>";

    return 0;
}
