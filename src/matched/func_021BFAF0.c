/*
 * function: func_021BFAF0
 * address:  0x021BFAF0
 * packet:   pkt_021B9500
 * region:   ov114
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *
 * Linear search of the 0x021d3b20 list for the node whose +0x18 key matches;
 * NULL when absent.  The compound condition and the named base pointer are
 * what leave the single shared test block at 0x021bfb00 with the entry
 * jumping to it; the base is not folded into the pool word.
 */

typedef unsigned char u8;
typedef unsigned int u32;

u8 *func_021BFAF0(u32 key)
{
    u8 **base = (u8 **)0x021d3b20;
    u8 *p = base[1];

    while (p != 0 && *(u32 *)(p + 0x18) != key)
        p = *(u8 **)(p + 0x1c);
    return p;
}
