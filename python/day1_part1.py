from resources import *

def parse_file(file_path):
    list_1=[]
    list_2 = []
    
    with open(file_path,'r') as file:
        for line in file:
            num_1,num_2 = map(int,line.strip().split())
            list_1.append(num_1)
            list_2.append(num_2)
        return list_1,list_2
    


if __name__ == "__main__":
    file_path = "resources\input_1_p_1"
    column_1, column_2 =parse_file(file_path)
    print("hi")