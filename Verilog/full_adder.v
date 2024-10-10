module full_adder (A, B, C, Sum, Carry);
    input A, B, C;
    output Sum, Carry;
    wire w1, w2, w3;
    half_adder uut1(A, B, w1, w2);
    half_adder uut2(w1, C, Sum, w3);
    or G1 (Carry, w2, w3); 
endmodule