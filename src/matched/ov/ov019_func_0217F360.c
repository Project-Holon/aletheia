/*
 * function: UNION_MSG_SetupMainMenu
 * address: 0x0217F360
 * packet: pkt_ov019_0217F360
 * region: ov019
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   UNION_MSG_SetupMenu 0x0217F2A8 thumb ov019
 *   d_0218042C 0x0218042C data a4
 *   d_021804DC 0x021804DC data a4
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern const u32 d_0218042C[];
extern const u32 d_021804DC[];
extern void UNION_MSG_SetupMenu(char *p, u32 a, u32 b, u32 c, u32 d);
void UNION_MSG_SetupMainMenu(char *p, u32 a)
{
    UNION_MSG_SetupMenu(p, a, (u32)d_021804DC, 6, (u32)d_0218042C);
}
