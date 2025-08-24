import os

def parse_file(file_path):
    """
    Parse through each line the input file, save the 2 numbers in each line as int and append them into 2 lists.
    Args:
        file_path (string): path to input file

    Returns:
        list_1,list_2(lists): list_1 contains column 1 of numbers from input file.
                              list_2 contains column 2 of numbers from input file.
    """
    list_1 = []
    list_2 = []
    
    with open(file_path,'r') as file:
        for line in file:
            num_1,num_2 = map(int,line.strip().split()) # 3 4 
            list_1.append(num_1)
            list_2.append(num_2)
    return list_1,list_2


def sort_lists(list_1,list_2):
    return sorted(list_1),sorted(list_2)
    
def sum_dif_lists(list_1,list_2):
    score = 0
    sorted_list_1, sorted_list_2 = sort_lists(list_1,list_2)
    for a, b in zip(sorted_list_1,sorted_list_2): 
        score += abs(a-b)
    return score

def day_1():
    file_path = os.path.join("..","resources", "input_1_p_1")
    column_1, column_2 =parse_file(file_path)
    score = sum_dif_lists(column_1,column_2)
    print(f"{score}")

if __name__ == "__main__":
    day_1()