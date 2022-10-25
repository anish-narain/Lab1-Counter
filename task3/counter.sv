module counter #(
    parameter WIDTH = 8
)(
    //interface signals
    input logic     clk,            //clock
    input logic     rst,            //reset
    input logic     en,             //counter enable
    input int       vbdvalues,
    output logic [WIDTH-1:0] count  //count output
);

always_ff @ (posedge clk, posedge rst)
    // if (en) count <= count + {{WIDTH-1{1'b0}}, {1'b1}};
    // else count <= count - {{WIDTH-1{1'b0}}, {1'b1}};

    if (en) count <= vbdvalue;
    else count <= count - {{WIDTH-1{1'b0}}, {1'b1}};

endmodule