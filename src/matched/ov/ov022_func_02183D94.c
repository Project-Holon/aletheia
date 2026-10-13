/*
 * function: UNION_APP_SendQuitAccept
 * address: 0x02183D94
 * packet: pkt_ov022_02183D94
 * region: ov022
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * Callee's filed definition says void; original caller reads r0 at
 * 02183DA2, and ov012 callee leaves GFL_NET_SendData result live.
 * symbols:
 *   UNION_COMMAND_SendAppQuitAccept 0x02173E68 thumb ov012
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern u32 UNION_COMMAND_SendAppQuitAccept(u32 a);
void UNION_APP_SendQuitAccept(u8 *p)
{
    if (p[17] != 255 && UNION_COMMAND_SendAppQuitAccept(p[17]) == 1) p[17] = 255;
}
