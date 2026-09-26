/*
 * function: func_021F54CC
 * address:  0x021F54CC
 * packet:   pkt_021F54CC
 * region:   ov194
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   DIFF
 *
 * Zeroes a 0x20-entry u16 buffer, has MI_CpuCopy8 fill it from the caller's
 * source, then counts wide/ASCII digit code units: 1 when more than four.
 *
 * DIFF: byte-correct and same size except the zero-fill loop prologue
 * (offsets +0x04..+0x1A, 22 bytes).  The image emits the body first with the
 * counter decremented at the bottom (`strh r1,[r4]; adds r4,#2; subs r3,#1;
 * bne`); dsi/1.1p1 always emits `subs` before the store (`subs r1,#1; strh
 * r5,[r2]; adds r2,#2; cmp r1,#0; bgt`) and picks r5 for the stored zero.  It
 * hoists the later `c = 0` into that register.  Tried: for/while, index vs
 * pointer, `i != 0` vs `i > 0`, do/while.  Everything from +0x1C on is exact.
 *
 * symbols:
 *   func_02082D44    0x02082D44  arm
 */

typedef unsigned short u16;

extern void func_02082D44(void *a, u16 *b, int n);

int func_021F54CC(void *src, int n)
{
    u16 buf[0x20];
    u16 *d;
    int i, j, c;

    d = buf;
    for (i = 0x20; i > 0; i--)
        *d++ = 0;
    func_02082D44(src, buf, n * 2);
    c = 0;
    for (j = 0; j < 0x20; j++) {
        u16 v = buf[j];

        if ((v >= 0x30 && v <= 0x39) || (v >= 0xFF10 && v <= 0xFF19))
            c++;
        if (c > 4)
            return 1;
    }
    return 0;
}
