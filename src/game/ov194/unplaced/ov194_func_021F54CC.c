/*
 * function: func_021F54CC
 * address:  0x021F54CC
 * packet:   pkt_ov194_021F54CC
 * region:   ov194
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Zeroes a 0x20-entry u16 buffer (aggregate initialiser gives the
 * post-decrement loop), has MI_CpuCopy8 fill it from the caller's source, then
 * counts wide/ASCII digit code units: 1 when more than four.  Initialising c
 * at its declaration fixes the register of n.
 *
 * symbols:
 *   MI_CpuCopy8    0x02082D44  arm
 */

typedef unsigned short u16;

extern void MI_CpuCopy8(void *a, u16 *b, int n);

int func_021F54CC(void *src, int n, int a2)
{
    u16 buf[0x20] = {0};
    int j, c = 0;

    MI_CpuCopy8(src, buf, n * 2);
    for (j = 0; j < 0x20; j++) {
        u16 v = buf[j];

        if ((v >= 0x30 && v <= 0x39) || (v >= 0xFF10 && v <= 0xFF19))
            c++;
        if (c > 4)
            return 1;
    }
    return 0;
}
