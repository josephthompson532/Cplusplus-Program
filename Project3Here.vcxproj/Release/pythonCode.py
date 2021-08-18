import string
import re
from collections import defaultdict

def listItemCounts():

    f = open("./Release/CS210_Project_Three_Input_File.txt")
    myfile = f.read()
    f.close()
    
    mydict = defaultdict(lambda: 0)
    for x in myfile.split():
        mydict[x] += 1 
    
    for key, value in mydict.items():
        print("{:.<17}{:.>3}".format(key, value))


def getItemCount(name):
    
    f = open("./Release/CS210_Project_Three_Input_File.txt")
    myfile = f.read()
    f.close()

    counter = 0

    for x in myfile.split():
        if x.upper() == name.upper():
            counter += 1

    return counter

def createHistogram():

    f = open("./Release/CS210_Project_Three_Input_File.txt")
    myfile = f.read()
    f.close()
    
    mydict = defaultdict(lambda: 0)
    for x in myfile.split():
        mydict[x] += 1 
    
    f = open("./Release/frequency.dat", "w")
    for key, value in mydict.items():
        f.write("{} {}".format(key, value))
    f.close()