/*
 * function: func_02070C5C
 * address:  0x02070C5C
 * packet:   pkt_02070C5C
 * region:   arm9
 * compiler: ../2.0/sp2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * symbols:
 *   func_0206DDA4  0x0206DDA4  arm
 *
 * The narrow sibling of src/matched/func_02070D18.c: the same flag-driven
 * fan-out of func_0206DDA4(cmd, ptr, count) register-block uploads over one
 * object, without the leading bit-5/bit-3 block and without the `first` latch.
 *
 * PIN ../2.0/sp2, the "kept branches" tell (docs/FRONTEND-PINS.md), exactly
 * the tell its sibling func_02070D18 carries.  The image writes the 0x19 and
 * 0x1c arms out SEPARATELY, each closing with its own `bl 0x0206dda4` and its
 * own unconditional branch to the join -- `bl` / `b 0x2070cb8` at
 * 0x02070C84/0x02070C88 for the 0x19 arm and `bl` / `b 0x2070cb8` at
 * 0x02070C98/0x02070C9C for the 0x1c arm -- and gives the 0x1a arm a third
 * call site at 0x02070CB4.  1.1p1 -O4,p re-lays the outer arms: on the source
 * below it emits the 0x1a arm as the FALL-THROUGH of the first test (beq, not
 * bne).  docs/notes/pkt_02070C5C.c.txt records that wall and three further
 * spellings against it (`if (f & 4) ... else if (f & 2) ...`, the
 * reverse-nested variant, and the flattened chain); every one of those bodies
 * turned out to be correct C and the note's own recommended spelling, quoted
 * below verbatim, is byte-exact the moment the front end changes.  Under the
 * pin the same C is 124 bytes, 0 mismatches.
 *
 * The flag word is RE-READ before the trailing bit-0 test (`ldr r0, [r4]` at
 * 0x02070C64 and again at 0x02070CB8), so the second `*(u32 *)a` is required;
 * caching it in the local across the fan-out drops the reload.
 *
 * The former `*` was the unlabelled follower at 0x02070CD8 (a 64-byte leaf
 * that saves no lr), now seeded in layout/function_starts.txt and matched
 * in src/matched/arm9/func_02070CD8.c; the extent is 124 bytes and EXACT.
 */
typedef unsigned char u8;
typedef unsigned int  u32;

extern void func_0206DDA4(u32 cmd, const void *params, u32 n);

void func_02070C5C(u8 *a)
{
    u32 f;

    f = *(u32 *)a;
    if ((f & 4) == 0) {
        if ((f & 2) == 0)
            func_0206DDA4(0x19, a + 0x28, 0xc);
        else
            func_0206DDA4(0x1c, a + 0x4c, 3);
    } else {
        if ((f & 2) == 0)
            func_0206DDA4(0x1a, a + 0x28, 9);
    }

    f = *(u32 *)a;
    if ((f & 1) == 0)
        func_0206DDA4(0x1b, a + 4, 3);
}
