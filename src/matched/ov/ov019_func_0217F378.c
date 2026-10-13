/*
 * function: UNION_MSG_DeleteMainMenu
 * address: 0x0217F378
 * packet: pkt_ov019_0217F378
 * region: ov019
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   UNION_MSG_DeleteMenu 0x0217F2F4 thumb ov019
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern void UNION_MSG_DeleteMenu(u8 *p);
void UNION_MSG_DeleteMainMenu(void *p) { UNION_MSG_DeleteMenu(p); }
