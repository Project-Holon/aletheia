/*
 * function: func_021EF93C
 * address: 0x021EF93C
 * packet: pkt_ov026_021EF93C
 * region: ov026
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020056EC 0x020056EC thumb
 */

typedef unsigned int u32;
typedef short s16;
extern u32 func_020056EC(u32);
void func_021EF93C(s16 *p)
{
    p[9] = 0;
    p[10] = func_020056EC(16) + 50;
}
