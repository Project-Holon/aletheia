/*
 * function: func_02072758
 * address:  0x02072758
 * packet:   pkt_02071DD4
 * region:   arm9
 * compiler: ../2.0/sp2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   MATCH
 *
 * Not a member of the 0x02071CDC constructor family: the subsystem's boot
 * sequence. Spins until func_02089978(0) reports ready, runs the three
 * initialisers, then hands 0 to func_02089B38.
 *
 * PINNED ../2.0/sp2 on the "kept constants" tell (docs/FRONTEND-PINS.md).
 * The image rematerialises the last call's zero argument, `mov r0, #0`
 * (`00 00 a0 e3`) at 0x0207277C, although the spin loop is still holding a
 * zero live in the callee-saved r4 it set up at 0x0207275C; dsi/1.1p1 -O4,p
 * reuses it and emits `mov r0, r4` (`04 00 a0 e1`) instead, the same 48
 * bytes with exactly those 2 concrete bytes out. Five spellings measured in
 * docs/notes/pkt_02071DD4.c.txt (a `z` local, a bare literal 0, a
 * `for (z = 0; ...)` head, passing the same `z` to the last call, and the
 * truthiness form `while (f(0))`) all share the constant. Under the pin the
 * same C is 48 bytes, 0 mismatches: BYTE-CORRECT, and the 2-byte codegen
 * difference is gone.
 *
 * CAPPED AT MATCH for lack of an outside witness, not for codegen. Three of
 * the five PC24 sites (func_020731E0, func_02073D7C, func_02075858) have no
 * branch anywhere in the image outside this function's own 48 bytes, and
 * nothing under src/matched/ reproduces the ranges that define them, so the
 * `label` and `matched` classes both refuse. There is nothing to split: this
 * is one function, and it is the sole caller of all three. It promotes to
 * EXACT unchanged the moment any one of 0x020731E0, 0x02073D7C, 0x02075858
 * is filed EXACT elsewhere, or a second caller of one is decompiled.
 *
 * symbols:
 *   func_02089978  0x02089978  arm
 *   func_020731E0  0x020731E0  arm
 *   func_02073D7C  0x02073D7C  arm
 *   func_02075858  0x02075858  arm
 *   func_02089B38  0x02089B38  arm
 */
typedef int s32;

extern s32  func_02089978(s32 a);
extern void func_020731E0(void);
extern void func_02073D7C(void);
extern void func_02075858(void);
extern void func_02089B38(s32 a);

void func_02072758(void)
{
    while (func_02089978(0) != 0)
        ;

    func_020731E0();
    func_02073D7C();
    func_02075858();
    func_02089B38(0);
}
