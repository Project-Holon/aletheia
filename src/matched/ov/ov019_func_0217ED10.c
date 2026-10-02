/*
 * function: func_0217ED10
 * address: 0x0217ED10
 * packet: pkt_ov019_0217ED10
 * region: ov019
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020056EC 0x020056EC thumb
 *   d_02180368 0x02180368 data a2
 */
typedef unsigned short u16;
typedef unsigned int u32;
extern u32 func_020056EC(u32 v);
extern const u16 d_02180368[][2];
u16 func_0217ED10(int i)
{
    return d_02180368[func_020056EC(2)][i];
}
