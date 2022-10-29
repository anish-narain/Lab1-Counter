# Verilator Info #

## Key Ideas ##

* **System Verilog** is a hardware description and verification language (HDL) for desigining digital hardware. It is a superset of Verilog (like mySQL for SQL). System Verilog adds object-oriented programming and is particularly suitable for register-transfer level design (RTL). System Verilog is commonly used for designing microprocessors like RISC-V
* **Verilator** is a software package to simulate System Verilog designs. It is a cycle-accurate simulator rather than an event-driven simulator. This means:
  * Verilator signals can only be 1 or 0
  * Cannot evaluate glitches in the circuit
* **Why Verilator?** 
  * Verilator is used because most modern digital circuits are synchronous which matches well with the cycle-accurate simulator.
  * Furthemore if we only care about functionality at register transfer level, Verilator is much faster than event-driven simulators. 
  * Verilator is so fast because it translates System Verilog into C++ and then uses a highly efficient C++ compiler to produce natively executable "model" (program of the design) known as DUT (Device-Under-Test). 

<img width="600" alt="image" src="https://user-images.githubusercontent.com/69715492/198826680-d7a83987-3ae8-486c-91bd-0b08d8901b35.png">


## Files and Conversion ##
**Testbench**

One disadvantage of translating a Verilog design into C++ executable is that you normally cannot interact with your simulator. Thus we're not able to actually test our design. 

To accomodate for this we write a separate testbench file in C++ which we use to:
* instantiate the DUT (model)
* provide input signals at the correct time
* display output signals

Say, the executable program produced by Verilator is called “Vcounter”, then simulation is done running by running Vcounter itself. To know if Vcounter (the Device Under Test or DUT) is working, you have to write a “wrapper” program that instantiate the DUT, provide input signals at the correct time, and display or compare the output signals. The wrapper program is known as a testbench for the DUT. When producing the executable model of the counter, it must include the DUT as well as the testbench code.

**How does Verilator Work?**

<img width="600" alt="image" src="https://user-images.githubusercontent.com/69715492/198827855-e1f8d354-5fbe-45cc-94d9-e26771ca7f73.png">


Here are the following steps for creating and running the counter module:
1. Use VS Code to create and edit *counter.sv* (System Verilog is used to define a RT Level module)
2. Use VS Code to create test bench file *counter_tb.cpp* (Wrapper program)
3. Use Verilator (software package that brings everything together) to compile the HDL source code (.sv file) and testbench (.cpp file) and VBuddy API (Vbuddy.cpp) to produce:
  * C++ program which contains synthesized hardware
  * Testbench procedures
  * Header files
  * Make file (*VCount.mk*) which tells the C++ how to compile and link everything together to produce final executable model of counter with built in testbench (*VCounter*)
4. This executable model can be executed by the computer to produce output signals which can be displayed as a waveform or driven to an external unit (VBuddy)

**Understanding Testbench**

<img width="500" alt="image" src="https://user-images.githubusercontent.com/69715492/198828188-ea573aa5-3064-49f1-81e0-70dba77fda2a.png">

<img width="500" alt="image" src="https://user-images.githubusercontent.com/69715492/198828200-52d14626-c115-49ae-9e85-3abec6e5f755.png">

**Understanding doit.sh**

<img width="500" alt="image" src="https://user-images.githubusercontent.com/69715492/198828241-c5ff74d5-0b47-4b3d-9048-00c19ba6661a.png">
