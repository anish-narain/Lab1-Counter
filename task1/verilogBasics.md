# Summary of Lecture 2 #

## Modules: Behavioural vs Structural ##
**There are two types of modules**

* **Behavioural:** describes what a module does
* **Structural:** (top-level module) describes how it is built from simpler modules.

Behavioural assigns and Structural combines past assignments. 

**Key Words**\
Every module need to be began and ended using *module* and *endmodule* keywords. 

<img width="250" alt="image" src="https://user-images.githubusercontent.com/69715492/200417841-155c3fd8-9f41-4b2e-a437-07083346635b.png">

*assign* keyword is used to specify a combinational circuit

<img width="250" alt="image" src="https://user-images.githubusercontent.com/69715492/200418024-0cd3ef29-76e3-466d-a4d4-92f56ac4259d.png">

*input* and *output* keywords are used to specify the inputs an outputs of the module block. *logic* defines a 0 or 1 signal. We place a logic line after the input/output declaration to specify an internal node.

<img width="400" alt="image" src="https://user-images.githubusercontent.com/69715492/200419960-5eae5942-9710-427b-9bf1-7f2cef8e45b5.png">

## Syntax and Precedence of Operators ##
Syntax Rules:

<img width="250" alt="image" src="https://user-images.githubusercontent.com/69715492/200417475-0dc59c2a-dff0-4de0-9003-6c6388f8213b.png">

Precedence of operators: (left column shows the symbol used by system verilog to represent the operator)

<img width="250" alt="image" src="https://user-images.githubusercontent.com/69715492/200420187-ef32a393-969f-4b85-8930-46e86adc5023.png">

## Operations ##
A *reduction operator* reduces multiples bits to a single bit under a single operator. 

<img width="250" alt="image" src="https://user-images.githubusercontent.com/69715492/200420863-2d138271-3510-41b0-9458-9a184c32ec77.png">

*Conditional assignment* in this format is used to implement a mutliplexer:

<img width="250" alt="image" src="https://user-images.githubusercontent.com/69715492/200421001-fe3cc419-d798-49f6-98e2-7e108548eb4a.png">

## Number Formatting ##

<img width="300" alt="image" src="https://user-images.githubusercontent.com/69715492/200422304-dcab36f6-5136-4c21-b00a-ac7bc6772be6.png">

General format is N'Bxxxxx where N is number of bits, B is the base: b = binary, d = decimal, h = hexadecimal. Not specifying the size (number of bits) in a design is not recommended. This is because System Verilog is **describing hardware**, it's not simply writing code.

## Bit Manipulation ##

<img width="400" alt="image" src="https://user-images.githubusercontent.com/69715492/200432559-3c2d1e75-1086-4f20-818a-8748388a263b.png">

{,} Use curly brackets for concatenation. Placing Width-1{1'b0} means making 1 bit binary number 0, have Width-1 number of bits (7 bits). 

# Sequential and Combinational Logic #
First note all of these key terms:

* Combinational logic = does not depend on previous inputs/outputs. Only needs current input to determine output.
  * Examples: half-adder, full-adder, multiplexer, demultiplexer
* Sequential logic = requires past inputs/outputs to determine output. It is essentially a combinational circuit but with the additional properties of memory (to remember previous inputs) and feedback.
  * Examples: latches, flip-flops, finite state machines

<img width="400" alt="image" src="https://user-images.githubusercontent.com/69715492/200434090-1b0e123e-10ed-47a9-9802-1599ee3b697c.png">

               *Sequential circuit*

Sequential Logic can be of two forms:
* Asynchronous: In asynchronous circuit, state of the device can change at any time (triggered by input event) and not dependant on the clock
* Synchronous: state of the device only changes at discrete times in response to a clock signal

<img width="400" alt="image" src="https://user-images.githubusercontent.com/69715492/200434803-150d8bdf-4204-499e-80e1-d52820bb8236.png">

## Sequential Logic ##

<img width="400" alt="image" src="https://user-images.githubusercontent.com/69715492/200435079-8c871c83-cc3e-4664-b3cb-d936468abf0a.png">

How you specify synchronous vs asynchronous for reset:

<img width="400" alt="image" src="https://user-images.githubusercontent.com/69715492/200435168-77f6ddf7-6295-4328-ba26-7a36d8689253.png">

By defining reset withing @(), it means asynchronous can happen anytime the reset signal is asserted and does not depend on posedge of clk

**Note: always_ff @() used to specify D flip-flops in System Verilog**

One important thing to remember with sequential circuits is blocking vs non-blocking assignments. With sequential, always use blocking.

<img width="400" alt="image" src="https://user-images.githubusercontent.com/69715492/200435878-27b8da72-12fc-4225-80e2-7f921a63cbd3.png">

## Combinational Logic ##
Combinational logic can be implemented using:
* Always
* Always-Case
* If-Else
* Casez

always_comb used to specify combinational logic.

**Always**

<img width="400" alt="image" src="https://user-images.githubusercontent.com/69715492/200424330-843d52cb-73e9-48b2-97d0-203479c8a9d9.png">

**Always-Case**

<img width="400" alt="image" src="https://user-images.githubusercontent.com/69715492/200423957-65b75ad5-71d6-43ec-b387-60a6b2f3c881.png">

*7-segment decoder (used to provide 7 output signals to drive a 7-segment display)*

**If-Else**

<img width="400" alt="image" src="https://user-images.githubusercontent.com/69715492/200423884-d79af323-1a45-44c0-ba77-50aabd43cdf1.png">

*Creating a priority encoder circuit (which detects the highest priority signal being set)*

**Casez**

<img width="400" alt="image" src="https://user-images.githubusercontent.com/69715492/200424455-c34e70b0-3a50-40bb-b841-f032758db103.png">

*Creating priority encoder again. The '?' is a don't care.*

# Miscellaneous #
## Floating Output Z ##
<img width="400" alt="image" src="https://user-images.githubusercontent.com/69715492/200422899-f0af4212-8ab9-416a-84a4-ff1efc6159e5.png">

## Delays ##
<img width="400" alt="image" src="https://user-images.githubusercontent.com/69715492/200422940-46c4f286-783f-412f-96e2-170589055ffa.png">

