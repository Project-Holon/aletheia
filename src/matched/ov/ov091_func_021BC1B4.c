/*
 * function: PLIST_MENU_ItemRestoresHp
 * address: 0x021BC1B4
 * packet: pkt_ov091_021BC1B4
 * region: ov091
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_02020FE4 0x02020FE4 thumb
 */
extern unsigned int func_02020FE4(void *,unsigned int,unsigned int);
int PLIST_MENU_ItemRestoresHp(unsigned short *p,void *id) { if(func_02020FE4(id,27,*p)) return 1; return 0; }
