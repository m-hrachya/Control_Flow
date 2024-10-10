// and_gate.v - half_adder

module half_adder (A, B, Sum, Carry);
    input A, B;
    output  Sum, Carry;
    xor G1 (Sum, A, B);
    and G2 (Carry, A, B);
endmodule

