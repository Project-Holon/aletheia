/*
 * function: func_020713A4
 * address:  0x020713A4
 * packet:   pkt_02071104
 * region:   arm9
 * compiler: ../2.0/sp2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Unlabelled leaf of the 0x02071104 family (saves no lr, so disasm.py
 * never labels it): the identity constructor. Writes the 0x1000 unit
 * scale into f00/f14 and zeroes f04/f10/f30/f34.
 *
 * PINNED ../2.0/sp2 on the "kept constants" tell: the image materialises
 * the unit scale FIRST, `mov r2, #0x1000` (`01 2a a0 e3`) at 0x020713A4
 * followed by `str r2, [r0]`, and only then `mov r1, #0` (`00 10 a0 e3`)
 * at 0x020713AC. 1.1p1 -O4,p schedules the zero first for the same 36
 * bytes, 9 concrete bytes out; binding both constants to locals declared
 * in either order, and writing f14 immediately after f00, all keep the
 * zero-first schedule. Under the pin the same C is 36 bytes, 0 mismatches.
 */
typedef unsigned char u8;
typedef int           s32;

struct DST {
    s32 f00;
    s32 f04;
    u8  pad_08[8];
    s32 f10;
    s32 f14;
    u8  pad_18[0x18];
    s32 f30;
    s32 f34;
};

void func_020713A4(struct DST *d)
{
    d->f00 = 0x1000;
    d->f04 = 0;
    d->f10 = 0;
    d->f14 = 0x1000;
    d->f30 = 0;
    d->f34 = 0;
}
