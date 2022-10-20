## Syntax ##

Note the following:

1. The file name and the module name must be the same.
2. The number of bits in the counter is specified with the parameter WIDTH. It is currently set to 8-bit.
3. The always_ff @ (posedge clk) is the way that one specifies a clocked circuit.
‘<=’ in line 12 and 13 are non-block assignments which should be used within an always_ff block.
4. {WIDTH{1’b0}} in line 12 uses the concatenation operator { } to form WIDTH bits of ‘0’. 

<img width="844" alt="image" src="https://user-images.githubusercontent.com/69715492/196957958-ca118146-d033-4172-9552-d865d5e889ae.png">

## Short-Cut for Running Shell Scripts ##
When you have multiple terminal scripts to run, you can put it all into one .sh file (e.g. doit.sh) and then run the file.

```
source ./doit.sh
```

