#include <iostream>
#include <string>
#include <fstream>
#include <vector>

int main(int argc, char **argv)
{
    //std::cout << "hi" <<std::endl;
    std::string my_text;
    // std::cout << Mytext.empty() << std::endl;
    std::ifstream my_file;
    my_file.open("..\\resources\\input.txt");
    if (my_file.is_open())
    {
        my_file>>my_text;
        std::cout << my_text;
    }
    return 0;
}