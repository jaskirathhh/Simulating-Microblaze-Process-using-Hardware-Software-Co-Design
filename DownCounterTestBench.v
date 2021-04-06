`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 04/06/2021 11:06:34 PM
// Design Name: 
// Module Name: DownCounterTestBench
// Project Name: 
// Target Devices: 
// Tool Versions: 
// Description: 
// 
// Dependencies: 
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
//////////////////////////////////////////////////////////////////////////////////

module DownCounterTestBench(

    );
    reg Clock,Reset;        //input regsiters
    wire [3:0]GPIO_4bits;   //output
    initial begin           //resetting clock and reset
    Clock = 0;
    Reset = 0;
    #100 Reset = 1;         //reset after 100ns
    end
    
    always                  //Toggle clock after every 5 ns
        #5 Clock=~Clock;
        
    DownCounter_MB_wrapper dut
   (.Clock(Clock),
    .GPIO_4bits(GPIO_4bits),
    .Reset(Reset));
   
endmodule
