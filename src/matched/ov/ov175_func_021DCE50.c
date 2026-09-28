/*
 * function: func_021DCE50
 * address:  0x021DCE50
 * packet:   pkt_021DCE50
 * region:   ov175
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   (none)
 *
 * Two-word setter: stores the caller's word at +0xc and hard-codes 2 at +0x1c.
 */

typedef unsigned long u32;

void func_021DCE50(char *ctx, u32 v)
{
    *(u32 *)(ctx + 0xc) = v;
    *(u32 *)(ctx + 0x1c) = 2;
}
