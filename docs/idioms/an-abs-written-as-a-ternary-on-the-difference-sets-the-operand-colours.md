# An abs written as a ternary on the difference sets the operand colours

summary: when the code `subs rD, rA, rB; bpl +2; rsbs rD, rD, #0` matches but
the two operands (often u16 stack parameters loaded with `ldrh`) come out in
swapped callee-saved registers for the whole prologue, write the absolute value
in the macro form `d = ((a - b) < 0) ? -(a - b) : (a - b);` instead of
`d = a - b; if (d < 0) d = -d;`. The instructions are the same; the ternary form
creates the operand values in a different order in the IR, and the colouring of
`a` and `b` follows it.

Found in: src/matched/ov/ov172_func_021B6CA4.c (0x021B6CA4, ov172, Thumb).
Original: `ldrh r6, [r0, #4]; ldrh r4, [r0]; subs r0, r4, r6` (y0 = r4,
y1 = r6). With `ady = y0 - y1; if (ady < 0) ady = -ady;` the compiler gave
y0 = r6, y1 = r4. Declaration order, statement order (ady before adx) and u16
x parameters did not change it. Writing both adx and ady in the ternary form
closed the function.

Try it when a register swap sits on values that feed an abs and nothing else
in the function is different.
