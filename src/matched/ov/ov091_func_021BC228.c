/*
 * function: PLIST_MENU_GetItemUseMessage
 * address: 0x021BC228
 * packet: pkt_ov091_021BC228
 * region: ov091
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   PLIST_MENU_GetItemUseKind 0x021BBE74 thumb ov091
 */
extern int PLIST_MENU_GetItemUseKind(int);
int PLIST_MENU_GetItemUseMessage(int unused,int id) { switch(PLIST_MENU_GetItemUseKind(id)) { case 26: case 27: return 22; case 28: return 21; default: return 21; } }
