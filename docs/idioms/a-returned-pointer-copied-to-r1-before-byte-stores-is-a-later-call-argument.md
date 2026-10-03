# A returned pointer copied to r1 before byte stores is a later call argument

summary: When a returned pointer is copied from r0 into r1 before stores through it, and the next call only sets r0, that pointer is the call's second argument. Omitting it removes the copy and shifts the stores and branches.

Found in: src/matched/ov/ov095_func_06898B6C.c (0x06898B6C), src/matched/ov/ov095_func_068989CC.c (0x068989CC).

The first function stores two bytes into a returned message and then calls a fixed veneer:

```c
p = func_06898BCC(b, 0x2a, 0x1f);
p[4] = *d;
p[5] = t;
func_06898BDC(b, p);
```

The image copies the call result with `adds r1,r0,#0`, loads `*d` into r0, and stores through r1. It then puts b into r0 and calls 06898BDC with the pointer still live in r1. The veneer reaches ov093 func_021C88C8; its matched body saves both r0 and r1 and forwards both arguments to two dispatchers.

Declaring the veneer with one argument and calling `func_06898BDC(b)` compiled 62 rather than 64 bytes, with 18 concrete differences. Pointer casts, inline setters, named-zero offset and a bounded type permuter did not restore the missing copy. Passing p as the independently proven second argument gives EXACT, 64 bytes.

The second function has three stores through y, including a halfword at +6. Its 06898B40 veneer reaches the same two-argument dispatcher. Calling `func_06898B40(b, y)` closes the former 176/180, 33-byte residue to EXACT, 180 bytes. No store reorder is needed.
