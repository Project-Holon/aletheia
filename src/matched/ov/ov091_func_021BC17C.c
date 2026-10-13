/*
 * function: PLIST_MENU_IsSpecialItemKind
 * address: 0x021BC17C
 * packet: pkt_ov091_021BC17C
 * region: ov091
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   PLIST_MENU_GetItemUseKind 0x021BBE74 thumb ov091
 *   func_02020FE4 0x02020FE4 thumb
 */
extern int PLIST_MENU_GetItemUseKind(int);
extern unsigned int func_02020FE4(void *,unsigned int,unsigned int);
int PLIST_MENU_IsSpecialItemKind(unsigned short *p,int id) { switch(PLIST_MENU_GetItemUseKind(id)) { case 26:return 1; case 27:return 1; case 28: if(func_02020FE4((void *)id,39,*p)) return 1; break; } return 0; }
