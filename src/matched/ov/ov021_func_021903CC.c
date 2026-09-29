/*
 * function: func_021903CC
 * address:  0x021903CC
 * packet:   pkt_ov021_021903CC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled leaf predicate, called from func_021BEF8C.
 */

typedef unsigned char  u8;
typedef unsigned int   u32;

int func_021903CC(u8 *p)
{
    if (*(u32 *)(p + 0x16C) == 0)
        return 1;
    return 0;
}
