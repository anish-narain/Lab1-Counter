# Task 2 #

## Steps 1 and 2 ##
* Added Vbuddy.cpp and Vbuddy.cfg to Task 2 folder
* Connected Vbuddy to computer and found serial number of device's port running a command
* Altered new testbench code and added the serial number

## Step 3 ##
Pressing the silver button on the Vbuddy stops the counter. Once pressed it no longer runs.

<img width="600" alt="image" src="https://user-images.githubusercontent.com/69715492/197213885-b1b58b8d-b578-4bde-986e-0700a81fba44.png">

Changing the vbdHex() in the testbench code to vbdPlot() allows you to plot the counter on the screen.

<img width="600" alt="image" src="https://user-images.githubusercontent.com/69715492/197215788-f8298b47-b7bd-4ce7-851e-2e3b0439b116.png">

## TEST YOURSELF CHALLENGE ##
Here I modifed the counter and testbench files so that the en signal controls the direction of counting: ‘1’ for up and ‘0’ for down, via the vbdFlag() function.

To do this I changed the counter file to have these conditions:

<img width="411" alt="image" src="https://user-images.githubusercontent.com/69715492/197218840-07fcebb7-9805-4b99-bef6-d93f127097bd.png">

When en is high, counter increments. Else, the counter decrements. Using the hex display worked but it was difficult to capture the incrementing/decrementing in an image so I changed the display to plot and got this after pressing the toggle button several times:

<img width="705" alt="image" src="https://user-images.githubusercontent.com/69715492/197221072-cee1ff9a-bcdd-48e1-8d33-de3c0d98c237.png">
