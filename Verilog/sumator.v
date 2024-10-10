module sumator (A1, A2, A3, A4, B1, B2, B3, B4, C, O1, O2, O3, O4);
    input A1, A2, A3, A4, B1, B2, B3, B4;
    output O1, O2, O3, O4, C;
    wire w1, w2, w3;

    full_adder G1(A4, B4, 0, O4, w1); // Least significant bit
    full_adder G2(A3, B3, w1, O3, w2);
    full_adder G3(A2, B2, w2, O2, w3);
    full_adder G4(A1, B1, w3, O1, C); // Most significant bit

endmodule