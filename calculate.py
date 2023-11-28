import matplotlib.pyplot as plt
import math
import numpy as np

def main():
    input_filename = 'results.txt'
    output_filename = 'data.txt'
    parsedData = parseData(input_filename)
    writeDataToFile(output_filename, parsedData)

def parseData(filename):
    #dictionary to save all the data
    data = {}
    with open(filename, 'r') as file:
        for line in file:
            #split the string into 2 parts: algorithmName:data
            parts = line.split(':')
            #index 0 is the algorithm name
            algorithmName = parts[0]
            #Get a list of all the values split at whitespace and put them into a list
            values = list(map(float, parts[1].split()))
            #set the array to specific indexes of the list to get for different inputs
            array1 = values[0:10]
            array2 = values[10:20]
            array3 = values[20:30]
            array4 = values[30:40]
            array5 = values[40:50]
            #make a dictionary with algorithmName as key as a value for the data dictionary to get the values
            data[algorithmName] = {
                "100":array1,
                "1000":array2,
                "10000":array3,
                "100000":array4,
                "1000000":array5
            }
    return data

def writeDataToFile(output_filename, parsedData):
    with open(output_filename, 'w') as output_file:
        for algorithmName, arrays in parsedData.items():
            output_file.write(f"Algorithm Name: {algorithmName}\n")
            for inputSize, array in arrays.items():
                avg = sum(array) / len(array)
                low = min(array)
                high = max(array)
                output_file.write(f"Input Size: {inputSize}\n")
                output_file.write(f"Lowest Time: {low} ms\n")
                output_file.write(f"Highest Time: {high} ms\n")
                output_file.write(f"Average Time: {avg} ms\n\n")

if __name__ == "__main__":
    main()