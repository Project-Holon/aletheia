/*
 * function: PMSIV_MENU_SelectItem
 * address: 0x021BCF18
 * packet: pkt_ov110_021BCF18
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   PMSIV_MENU_SetItemAnim 0x021BD0F8 thumb ov110
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void PMSIV_MENU_SetItemAnim(u8 *p, int i, int flag);
void PMSIV_MENU_SelectItem(void *p,int mode) { switch(mode) { case 0: PMSIV_MENU_SetItemAnim(p,0,1); break; case 1: PMSIV_MENU_SetItemAnim(p,6,1); break; } }
