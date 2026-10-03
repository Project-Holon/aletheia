# A doubled halfword extension is an (int) cast on a u16 local

Shape (Thumb, -O4,p): a loop-invariant value gets two zero-extension pairs before the loop.

    lsls r0, r6, #0x10
    lsrs r0, r0, #0x10
    lsls r0, r0, #0x10
    lsrs r3, r0, #0x10

Source: an `int` parameter is stored in a `u16` local, and the uses add the local with an explicit
`(int)` cast.

    void f(char *p, int d) { int i; u16 e; ... e = d; for (...) buf->v[i] += (int)e; }

The first pair is the store into `e`, the second is the `(int)e` conversion, hoisted out of the loop.
Plain `+= e`, `+= (u16)e`, a u16 parameter, or `int e = (u16)d` give one pair, or give two pairs
with the parameter and a hoisted constant in swapped callee-saved registers.

Witness: src/matched/ov/ov119_func_021E4324.c (wave B3).
