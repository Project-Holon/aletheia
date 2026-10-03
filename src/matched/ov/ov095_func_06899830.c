/*
 * function: func_06899830
 * address: 0x06899830
 * packet: pkt_ov095_06899830
 * region: ov095
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * Follower after the 06899820 linker veneer; ends at 0689983C.
 * symbols:
 *   d_0689D768 0x0689D768 data ov095 a4
 */
typedef unsigned int u32;
extern unsigned char d_0689D768[];
unsigned char *func_06899830(u32 *p)
{
    *p = 3;
    return d_0689D768;
}
