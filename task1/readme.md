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
**1. Modify testbench so that you stop counting for 3 cycles once the counter reaches 0x9, and then resume counting** 
<img width="515" alt="image" src="https://user-images.githubusercontent.com/69715492/196978376-0ee430e4-8386-4bd5-bd15-c92dbdaa7793.png">
* Got rid of the reset at clock cycle 15
* Set enable to 0 from clock 15 to clock 17
<img width="800" alt="image" src="https://user-images.githubusercontent.com/69715492/196979455-c386eea2-5f03-439c-801a-f5489770b115.png">

***Incorrect Approach***

<img width="228" alt="image" src="https://user-images.githubusercontent.com/69715492/196974695-26e149a6-1dc1-412e-8559-5e5299d512e8.png">

Removed (i==15) from top->rst condition (which was correct) but changed top->en condition to (4<i & i<15 | i>17)

This produced the following waveform

<img width="800" alt="image" src="https://user-images.githubusercontent.com/69715492/196974820-64b04368-2051-4456-8e50-c4c30ca18f95.png">

Enable goes low at positive edge of clock cycle 15 meaning the counter stops counting at clock cycle 16. Hence the counter already reaches 0A and then stops, instead of stopping at 09. Decreasing to i<=13 (i<14) fixed this issue. 

Furthermore, the counter stops for 4 cycles instead of 3. This is because the enable gets set to high at i>17 or i=18, and then counter restarts at the clock cycle after that. Decreasing the range to i>=16 (i>15) fixed this issue.

**2. Implement asynchronous reset**

Adding posedge rst within the always_ff @() makes reset asynchronous

<img width="350" alt="image" src="https://user-images.githubusercontent.com/69715492/196984778-835abecd-34f6-4e94-9317-ec0076a86ff6.png">

I set the reset to i==8.

<img width="350" alt="image" src="https://user-images.githubusercontent.com/69715492/196984885-9dc991c0-a869-4301-bbc9-d3a8e6226ab0.png">

Giving a waveform where the reset does not occur at the positive edge of the clock cycle

<img width="786" alt="image" src="https://user-images.githubusercontent.com/69715492/196985652-07029d04-823f-4cc1-ab56-39189ed97dfa.png">




