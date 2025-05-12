#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <map>
#include <unordered_set>

int main(int argc, char **argv)
{
    std::string my_text;
    std::ifstream my_file;
    std::vector<int> input_vector;
    int input_number;
    std::unordered_set<int> input_hash_set;
    int comp;
    int i=0;

    my_file.open(argv[1]);
    while (my_file>>input_number)
    {
       input_vector.push_back(input_number);
       std::cout<<input_vector[i]<<std::endl;
       i++;
    }

    for( i=0; i<input_vector.size();i++)
    {
        //use map if needed sorting a bit slower, key value pairs.(uses binary search tree for example red-black-tree) lookup, insertions, deletion O(logn)
        // use hashset -> unique elements but not sorted. finding element O(1), no ke values paris just elements.
        comp = 2020 - input_vector[i];
        if(input_hash_set.find(comp)!=input_hash_set.end())
        {
         input_hash_set.insert(input_vector[i]);
         
        }
        else{
           break;
         }  
    }
    std::cout<<"2 numbers to make 2020 are:"<<comp<<" "<<input_vector[i]<<std::endl;
    std::cout <<"multiplication of the 2 nums are:"<<comp<< "x"<<input_vector[i]<<"="<<comp*input_vector[i]<<std::endl;
    return 0;
}