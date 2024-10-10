`timescale 1ns/1ps
module full_adder_tb;

reg a, b, c;
wire Sum, Carry;

full_adder uut1(a, b, c, Sum, Carry);

initial begin
    $display("Time\t a b c | C S");
    $monitor("%g\t %b %b %b | %b %b", $time, a, b, c, Carry, Sum);
    a = 0; b = 0; c = 0; #10;
    a = 0; b = 0; c = 1; #10;
    a = 0; b = 1; c = 0; #10;
    a = 0; b = 1; c = 1; #10;
    a = 1; b = 0; c = 0; #10;
    a = 1; b = 0; c = 1; #10;
    a = 1; b = 1; c = 0; #10;
    a = 1; b = 1; c = 1; #10;
    $finish;
end

endmodule
