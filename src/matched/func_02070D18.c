/*
 * function: func_02070D18
 * address:  0x02070D18
 * packet:   pkt_02070C5C
 * region:   arm9
 * compiler: ../2.0/sp2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * The wide sibling of func_02070C5C (docs/notes/pkt_02070C5C.c.txt): the same
 * flag-driven fan-out of func_0206DDA4 commands over one object, with a
 * leading bit-5/bit-3 block and a `first` latch.
 *
 * PIN ../2.0/sp2, the "kept branches" tell (docs/FRONTEND-PINS.md).  The image
 * writes the two arms of the bit-1 fan-out out SEPARATELY, each closing with
 * its own unconditional branch to the join: `bl 0x0206DDA4` / `b 0x02070DBC`
 * at 0x02070D8C/0x02070D90 for the 0x19 arm and `bl 0x0206DDA4` /
 * `b 0x02070DBC` at 0x02070D9C/0x02070DA0 for the 0x1a arm, with the shared
 * `add r1, r5, #0x28` hoisted between the `cmp r4, #0` and the `beq` at
 * 0x02070D78..0x02070D80.  1.1p1 -O4,p cross-jumps the pair into ONE `bl` and
 * one branch, giving 188 bytes against the original's 196.  Under the pin the
 * same C is 196 bytes, 0 mismatches.
 *
 * symbols:
 *   func_0206DDA4  0x0206DDA4  arm
 */

typedef unsigned char u8;
typedef unsigned int u32;

extern void func_0206DDA4(u32 cmd, void *p, u32 n);

void func_02070D18(u8 *a)
{
    u32 f;
    u32 first;

    f = *(u32 *)a;
    first = 0;
    if ((f & 4) == 0)
        first = 1;
    if ((f & 0x20) != 0 && (f & 8) == 0) {
        if (first != 0) {
            func_0206DDA4(0x1c, a + 0x4c, 3);
            first = 0;
        }
        func_0206DDA4(0x1b, a + 0x10, 3);
    }
    f = *(u32 *)a;
    if ((f & 2) == 0) {
        if (first != 0)
            func_0206DDA4(0x19, a + 0x28, 0xc);
        else
            func_0206DDA4(0x1a, a + 0x28, 9);
    } else {
        if (first != 0)
            func_0206DDA4(0x1c, a + 0x4c, 3);
    }
    f = *(u32 *)a;
    if ((f & 1) == 0)
        func_0206DDA4(0x1b, a + 4, 3);
}
