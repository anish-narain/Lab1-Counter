# Task 2 #

## Steps 1 and 2 ##
* Added Vbuddy.cpp (VBuddy API) and Vbuddy.cfg (which contains port number of the computer that the VBuddy is connected to) to Task 2 folder
* Connected Vbuddy to computer and found serial number of device's port by running a command
* Altered new testbench code and added the serial number

<img width="550" alt="image" src="https://user-images.githubusercontent.com/69715492/198828912-54930fda-80eb-4fb0-9628-5d6da1911051.png">


## Step 3 ##
Pressing the silver button on the Vbuddy stops the counter. Once pressed it no longer runs. This is because top->en = vbdFlag(). So while toggle switch state is 1, en = 1. As soon as button pressed, toggle switch state becomes 0 and en = 0, meaning counter stops incrementing.

<img width="600" alt="image" src="https://user-images.githubusercontent.com/69715492/197213885-b1b58b8d-b578-4bde-986e-0700a81fba44.png">

Changing the vbdHex() in the testbench code to vbdPlot() allows you to plot the counter on the screen.

<img width="600" alt="image" src="https://user-images.githubusercontent.com/69715492/197215788-f8298b47-b7bd-4ce7-851e-2e3b0439b116.png">

**Functions learned:**\
*vbdFlag()*: VBuddy has a rotary encode (at the bottom left of the display screen). This comes with two features:
* you can rotate the encoder to change value
* you can press the encoder button to change flag state

The vbdFlag() function returns the current state of the flag (1 or 0). Pressing the button changes the flag state (aka toggle switch state) between 0 and 1.

*vbdHex()*: presents numbers in hex display. [NEED TO UNDERSTAND HOW THIS WORKS, ASK UTA]

<img width="350" alt="image" src="https://user-images.githubusercontent.com/69715492/198829897-f48f351c-5eba-4166-a020-8ab7f1d62db3.png">

*vbdPlot()*: plots output in x-y graph

## TEST YOURSELF CHALLENGE ##
Here I modifed the counter and testbench files so that the en signal controls the direction of counting: ‘1’ for up and ‘0’ for down, via the vbdFlag() function.

To do this I changed the counter file to have these conditions:

<img width="411" alt="image" src="https://user-images.githubusercontent.com/69715492/197218840-07fcebb7-9805-4b99-bef6-d93f127097bd.png">

When en is high, counter increments. Else, the counter decrements. Using the hex display worked but it was difficult to capture the incrementing/decrementing in an image so I changed the display to plot and got this after pressing the toggle button several times:

<img width="705" alt="image" src="https://user-images.githubusercontent.com/69715492/197221072-cee1ff9a-bcdd-48e1-8d33-de3c0d98c237.png">
