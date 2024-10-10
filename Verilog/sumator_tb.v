`timescale 1ns/1ps
module sumator_tb;

reg a1, a2, a3, a4;
reg b1, b2, b3, b4;
wire o1, o2, o3, o4;
wire carry;

sumator uut1(a1, a2, a3, a4, b1, b2, b3, b4, carry, o1, o2, o3, o4);

initial begin
    $display("Time\t A + B = Sum");
    $monitor("%g\t %b%b%b%b + %b%b%b%b = %b%b%b%b%b", $time, a1, a2, a3, a4, b1, b2, b3, b4, carry, o1, o2, o3, o4);
    a1 = 1; a2 = 1; a3 = 1; a4 = 1; 
    b1 = 1; b2 = 1; b3 = 1; b4 = 1; 
    #10;
    $finish;
end

endmodule