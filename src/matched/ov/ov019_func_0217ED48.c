/*
 * function: UNION_MSG_GetTradeChatMsg
 * address: 0x0217ED48
 * packet: pkt_ov019_0217ED48
 * region: ov019
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020056EC 0x020056EC thumb
 *   d_02180360 0x02180360 data a2
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u32 func_020056EC(u32 v);
extern const u16 d_02180360[][2];
u16 UNION_MSG_GetTradeChatMsg(int i)
{
    return d_02180360[func_020056EC(2)][i];
}
