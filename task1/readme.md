# Task 1 #

## Steps 1 and 2 ##
* Forked the github repo to my own github account
* Cloned the repo to my device using github desktop
* Opened the folder in VS Code 

## Step 3 ##
## Step 4 ##
## Step 5 ##
## Step 6 ##
Opened counter.vcd file in gtkwave to get a waveform:

<img width="700" alt="image" src="https://user-images.githubusercontent.com/69715492/196927519-165f4c2b-0dbf-49d1-abe0-d73e3fa92f44.png">

**How do the waveform signals work?**\
**CLK**: goes up and down at fixed term intervals

**RST/EN**:\
In the testbench file counter_tb.cpp\
<img width="226" alt="image" src="https://user-images.githubusercontent.com/69715492/196928951-51261de5-75c1-4212-a76e-6b9f1492ca39.png">

It states the conditions for rst and en to activate
<img width="1052" alt="image" src="https://user-images.githubusercontent.com/69715492/196929373-7c2d2fa4-f538-491b-8044-f15fd3288fd9.png">

**Count**:\
To understand the count waveform we need to look at the counter module code in the System Verilog file (counter.sv)
<img width="456" alt="image" src="https://user-images.githubusercontent.com/69715492/196931531-76219837-3eaa-4cf0-ae43-b8664503e4c9.png">

Line 12 tells us if rst is asserted, the counter is synchronously reset to 0. Else the count is increased by 1 (given that the enable is also high). All of this occurs at the postive edge of the clock (showed by *posedge clk*)

<img width="975" alt="image" src="https://user-images.githubusercontent.com/69715492/196955990-222096f6-4a93-4560-9426-8e824166d081.png">

As we can see, the counter starts at the positive edge after enable is set to 1. The reset is triggered at the rising edge of the clock cycle where it occurred. This is at the positive edge of cycle 16. At this edge, the counter is reset.

## TEST YOURSELF CHALLENGES ##
**Modify testbench so that you stop counting for 3 cycles once the counter reaches 0x9, and then resume counting** 



**Implement asynchronous reset**
