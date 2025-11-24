#include <string>
#include "day_4.h"
#include <vector>
#include <fstream>
#include <optional>
#include <iostream>
#include <utility>

auto read_input(std::string &path) -> std::optional<std::vector<std::string>>
{
    std::ifstream file(path);
    if (!file)
        return std::nullopt;
    std::string line;
    std::vector<std::string> grid;

    while (std::getline(file, line))
    {
        if (!line.empty())
            grid.push_back(line);
    }
    return grid;
}

auto day_4_part_1() -> void
{
    std::string path = ("../../resources/input_4.txt");
    auto grid = read_input(path);
    if (!grid)
    {
        std::cerr << "Error in generating grid vector from file path \n";
        return;
    }

    const std::vector<std::string> &input_grid = *grid;
    int count = 0;
    std::vector<std::pair<int, int>> directions = {
        {-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
    int w = input_grid[0].size();
    int h = input_grid.size();

    for (int row = 0; row < h; row++)
    {
        for (int col = 0; col <w; col++)
        {
            if (input_grid[row][col] != 'X')
                continue;

            for (auto [drow, dcol] : directions)
            {
                int row2 = row + drow;
                int row3 = row + 2 * drow;
                int row4 = row + 3 * drow;
                int col2 = col + dcol;
                int col3 = col + 2 * dcol;
                int col4 = col + 3 * dcol;

                if (row4 >= 0 && row4 < h && col4 >= 0 && col4 < w && input_grid[row2][col2] == 'M' && input_grid[row3][col3] == 'A' && input_grid[row4][col4] == 'S')
                {
                    count++;
                }
            }
        }
    }
    std::cout << "XMAS was found " << count << " times. \n";
}

auto day_4_part_2() -> void
{
   
}

int main()
{

     day_4_part_1();
     day_4_part_2();

    return 0;
}