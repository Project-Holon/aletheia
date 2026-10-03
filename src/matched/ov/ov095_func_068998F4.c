/*
 * function: func_068998F4
 * address: 0x068998F4
 * packet: pkt_ov095_068998F4
 * region: ov095
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * Follower after the 068998E4 linker veneer; ends at 06899900.
 * symbols:
 *   d_0689D6F8 0x0689D6F8 data ov095 a4
 */
typedef unsigned int u32;
extern unsigned char d_0689D6F8[];
unsigned char *func_068998F4(u32 *p)
{
    *p = 1;
    return d_0689D6F8;
}
