# Cplusplus-Program

## Summarize the project and what problem it was solving.
This code reads a text file consisting of a list of grocery items. Each entry in the text file represents a purchase of the item listed. We needed to create a program that would identify which items were sold for a day and the quantity of each of the items sold. To do this, I created a C++ based program that would call embedded Python functions to process the data and display the findings.

## What did you do particularly well?
I did a particularly good job of making the histogram crisp and good looking. The UI was excellent and offered a please user experience as well.

## Where could you enhance your code? How would these improvements make your code more efficient, secure, and so on?
I would have liked to include colors in some of the text to further style the UI. I also would have liked to add functionality that allowed the user to enter the name of the file to be read. As it stands the name of the file is hard-coded in, but this is relatively inflexible. The program would be more versatile if there was a name for the text file to be entered. I also feel it would enhance security if I could find a work around for creating the temporary file to create the histogram. The results of this file are available to anyone to read once created, which is a security risk.

## Which pieces of the code did you find most challenging to write, and how did you overcome this? What tools or resources are you adding to your support network?
I found the histogram to be the most challenging to right. To make it look good, you need to use the setw function and play with advanced output formatting. Furthermore, I had to create an interim file to hold the items with their quantities first, before creating the histogram. This is a little tricky. All around the histogram function involves a lot of functionality that is jumping back and forth between C++ and Python.

## What skills from this project will be particularly transferable to other projects or course work?
Embedding Python in C++ is a skill that will serve to be eminently useful in other projects and course work. It will allow me to leverage the best of both languages. I feel this is the most valuable skill I've learned in the program to date!

## How did you make this program maintainable, readable, and adaptable?
I used a consistent variable naming scheme, I commented my code, I created modularized code organized into an easily understandable set of functions, and my functions that call functions in Python are not too closely integrated in Python. For example, the CallIntFunc and CallProcedure functions, can be called in a variety of different C++ functions to call code in Python.
