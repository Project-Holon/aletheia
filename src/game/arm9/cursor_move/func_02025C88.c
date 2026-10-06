/*
 * function: func_02025C88
 * address:  0x02025C88
 * packet:   pkt_02025C88
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled Thumb leaf in the ARM9 module: byte accessor over a 0x10-entry
 * table of 4-byte records.
 *
 * symbols:
 *   d_0209FB1B  0x0209FB1B  data  a1
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char u8;
typedef unsigned int u32;

extern u8 d_0209FB1B;

u32 func_02025C88(u32 x)
{
    if (x >= 0x10u)
        return 2;
    return (&d_0209FB1B)[x * 4];
}
