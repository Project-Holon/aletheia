/*
 * function: func_021C30B8
 * address:  0x021C30B8
 * packet:   pkt_ov021_021C30B8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Runs func_021C1CB0 with kind 0x11 and stores the argument at +0x9C (EXACT*: pad).
 *
 * symbols:
 *   func_021C1CB0  0x021C1CB0  thumb  ov021
 */

typedef unsigned char u8;
typedef unsigned int u32;

extern int func_021C1CB0(void *a, u8 *b, int c);

int func_021C30B8(void *a, u8 *b, u32 c)
{
    int r = func_021C1CB0(a, b, 0x11);

    if (r == 0)
        return 0;
    *(u32 *)(b + 0x9C) = c;
    return r;
}
