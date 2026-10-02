/*
 * function: func_0217ED2C
 * address: 0x0217ED2C
 * packet: pkt_ov019_0217ED2C
 * region: ov019
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020056EC 0x020056EC thumb
 *   d_02180370 0x02180370 data a2
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u32 func_020056EC(u32 v);
extern const u16 d_02180370[][2];
u16 func_0217ED2C(int i)
{
    return d_02180370[func_020056EC(4)][i];
}
