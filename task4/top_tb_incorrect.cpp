//Header files (not name Vcounter.h for module counter)
#include "Vcounter.h"
#include "verilated.h"
#include "verilated_vcd_c.h"
#include "vbuddy.cpp"

int main(int argc, char **argv, char **env) {
    int i;
    int clk;

    Verilated::commandArgs(argc, argv);
    //instatiate the counter module as Vcounter
    //this is the DUT (name of all generated files)
    Vcounter* top = new Vcounter;
    //turn on signal tracing and tell Verilator to
    //dump the waveform data to counter.vcd
    Verilated::traceEverOn(true);
    VerilatedVcdC* tfp = new VerilatedVcdC;
    top->trace (tfp, 99);
    tfp->open ("counter.vcd");

    //initialize simulation inputs
    top->clk = 1;
    top->rst = 1;
    top->en = 0;

    //run simulation for many clock cycles
    for (i=0; i<300; i++) {

        //dump variables into VCD file and toggle clock
        for (clk=0; clk<2; clk++) {
            tfp->dump (2*i+clk);
            top->clk = !top->clk;
            top->eval ();
        }
        
        // Send count value to Vbuddy
        vbdHex(4, (int(top->bcd))>> 12 & 0xF);
        vbdHex(3, (int(top->bcd))>> 8 & 0xF);
        vbdHex(2, (int(top->bcd))>> 4 & 0xF);
        vbdHex(1, (int(top->bcd)) & 0xF);
        vbdCycle(i+1);
        // end of Vbuddy output section

        top->eval();
        if (Verilated::gotFinish()) exit(0);
    }
    tfp->close();
    exit(0);
}
