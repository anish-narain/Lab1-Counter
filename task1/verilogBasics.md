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

## Combinational Logic ##
Combinational logic can be implemented using:
* Always
* Always-Case
* If-Else
* Casez

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

