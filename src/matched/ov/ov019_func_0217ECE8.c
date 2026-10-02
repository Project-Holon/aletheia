/*
 * function: func_0217ECE8
 * address: 0x0217ECE8
 * packet: pkt_ov019_0217ECE8
 * region: ov019
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_020056EC 0x020056EC thumb
 *   d_02180380 0x02180380 data a2
 * Extent follower func_0217ED04 is already filed separately.
 */
typedef unsigned short u16;
typedef unsigned int u32;
extern u32 func_020056EC(u32 v);
extern const u16 d_02180380[][2];
u16 func_0217ECE8(int i)
{
    return d_02180380[func_020056EC(4)][i];
}
