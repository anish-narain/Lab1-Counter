# Task 4 #
In this task I had to take the output from the counter (8 bit binary number) and convert it into three BDC digits.

**Why 3?**\
BDC is where a 4 bit binary number is used to represent a decimal digit. This wastes bits because a 4 bit number can represent 16 digits however decimal only has 10 digits.

<img width="88" alt="image" src="https://user-images.githubusercontent.com/69715492/198831364-fb88fd99-65bb-493a-916f-d5062a8c3b73.png">

So ideally an 8 bit binary number would produce a 2 digit BCD. However if our binary number exceeds 1001 (into the wasted bits) we get an overflow into a third BCD digit. 

Running 1111 1111 (max 8 bit binary number) produces 3 digit BCD:

<img width="300" alt="image" src="https://user-images.githubusercontent.com/69715492/198831469-fc909c1e-71cd-461e-b13b-4b1926ff3387.png">

**To implement this task, I had to:**
1. Create a top-level module that combines counter module and a binary-to-BCD coverter
2. Create a testbench function to 
  * initialize DUT (top)
  * provide input signals into DUT at the correct time
  * display output signals
3. Modify doit.sh file to
  * compile .sv and testbench code into C++ (using verilator command)
  * produce Make file
  * Run binary file

## Step 1 ##
I made sure to copy the relevant files into task4. For the counter module, I copied the original version.

[NEED TO ANNOTATE THESE screenshots]

Top module:

<img width="500" alt="image" src="https://user-images.githubusercontent.com/69715492/198832141-6fdf5d47-80e1-41e9-96e8-f211feefb5a1.png">

Bin2BCD Module:

<img width="500" alt="image" src="https://user-images.githubusercontent.com/69715492/198832237-314076b1-c5b7-4b13-9385-2be597932d84.png">

**Understanding the Bin2BCD Algorithm**\
[INSERT (See Lecture 4)]

## Step 2 ##

[Annotate image in OneNote]

## Step 3 ##
I copied the doit.sh file from a previous task 

<img width="500" alt="image" src="https://user-images.githubusercontent.com/69715492/198832692-31658c1a-ad87-4473-ab33-29ffaa998957.png">

