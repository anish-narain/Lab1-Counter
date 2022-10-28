# Task 3 #
## Step 1: Loadable Counter ##
In this task you can decide a starting value using the rotary toggle. Anytime the rotary button is pressed the counter resets to the starting value and starts from there.

Originally our counter code was:

<img width="450" alt="image" src="https://user-images.githubusercontent.com/69715492/198644871-526e4d41-11eb-410d-9e56-6a982d9c5bd9.png">

Now our code is: 

<img width="450" alt="image" src="https://user-images.githubusercontent.com/69715492/198644630-c6e4e4e6-92ea-4e9b-982c-ab93a1574119.png">

The difference is, we have replaced our en signal with ld and v. Looking closer at the if else statement explains the change: 

<img width="450" alt="image" src="https://user-images.githubusercontent.com/69715492/198647846-f60aa585-b575-42a2-9d4c-75139e44e062.png">

When rst is 0, count = either v or count+1 depending on the value of ld. When ld = 1, v is chosen and when ld = 0, count + 1 is chosen. To implement these conditions, I needed to:
* v = vbdValue()
* ld = 1 when rotary button pressed for a clock cycle and then changed back to 0



## Step 2: Single Stepping ##
In this task I needed to modify the counter.sv so that it increments everytime the rotary encoder switch is pressed.
