#include <iostream>  // for input output operations like print
#include <fstream>   // for reading file
#include <vector>    // for vector
#include <cstdlib>   // for abs
#include <algorithm> // for sort
#include <string>    // for string
#include <utility>   // for pair

std::pair<std::vector<int>, std::vector<int>> parse_file(const std::string &path)
{
    int num_1, num_2;
    std::vector<int> column_1, column_2;
    std::ifstream file(path);

    if (!file.is_open())
    {
        std::cerr << "Failed to open file: " << path << std::endl;
        return {column_1, column_2};
    }
    while (file >> num_1 >> num_2)
    {
        column_1.push_back(num_1);
        column_2.push_back(num_2);
    }

    return {column_1, column_2};
}

std::pair<std::vector<int>, std::vector<int>> sort_lists(const std::vector<int>& column_1,const std::vector<int>& column_2)
{
    std::vector<int> sorted_column_1 = column_1;
    std::vector<int> sorted_column_2 = column_2;
    
    std::sort(sorted_column_1.begin(),sorted_column_1.end());
    std::sort(sorted_column_2.begin(),sorted_column_2.end());

    return {sorted_column_1,sorted_column_2};
}

long long sum_dif_lists(const std::vector<int>& list_1, const std::vector<int>& list_2)
{
    auto result = sort_lists(list_1,list_2);
    auto sorted_list_1 = result.first;
    auto sorted_list_2 = result.second;
    auto ptr_list_1 = sorted_list_1.begin();
    auto ptr_list_2 = sorted_list_2.begin();
    long long score=0;

    while (ptr_list_1 != sorted_list_1.end()&& ptr_list_2 != sorted_list_2.end())
    {
    score += std::abs(*ptr_list_1-*ptr_list_2);
    ptr_list_1++;
    ptr_list_2++;
    }

    return score;
}

void day_1()
{
    std::string path = "..\\resources\\input_1_p_1";
    auto result = parse_file(path);
    auto list_1 = result.first;
    auto list_2 = result.second;
    std::cout<< "diff number is: " <<sum_dif_lists(list_1,list_2)<<std::endl;
}

int main()
{
    day_1();
    return 0;
}