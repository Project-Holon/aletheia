/*
 * function: func_021C0CE4
 * address:  0x021C0CE4
 * packet:   pkt_ov021_021C0CE4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Runs func_021C0DDC when bit 0 of the flags is set.
 *
 * symbols:
 *   func_021A448C  0x021A448C  thumb  ov021
 *   func_021C0DDC  0x021C0DDC  thumb  ov021
 */

typedef unsigned int u32;

extern int func_021A448C(u32 *p, int a);
typedef unsigned char  u8;
extern int func_021C0DDC(u8 *a, u32 b, int c);

int func_021C0CE4(u8 *a, u32 b, u32 flags)
{
    int r = 0;
    int h = func_021A448C((u32 *)a, b);

    if (flags & 1)
        r = func_021C0DDC(a, b, h);
    return r;
}
