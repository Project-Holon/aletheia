/*
 * function: func_02024158
 * address:  0x02024158
 * packet:   pkt_02024158
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled Thumb leaf in the ARM9 module: extracts bit 2 of the byte at
 * +3. Pairs with func_02024160, which extracts bit 3.
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned int u32;
typedef unsigned char u8;

u32 func_02024158(const u8 *p)
{
    return ((u32)*(const u8 *)(p + 3) << 29) >> 31;
}
