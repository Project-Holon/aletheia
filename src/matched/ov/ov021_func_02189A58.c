/*
 * function: func_02189A58
 * address:  0x02189A58
 * packet:   pkt_ov021_02189A58
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled leaf setter, called from func_021BEF8C.
 */

typedef unsigned char  u8;
typedef unsigned int   u32;

void func_02189A58(u8 *p, u32 v)
{
    *(u32 *)(p + 0x140) = v;
}
