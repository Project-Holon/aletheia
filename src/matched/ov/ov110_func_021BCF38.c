/*
 * function: PMSIV_MENU_IsPressDone
 * address: 0x021BCF38
 * packet: pkt_ov110_021BCF38
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * Extent ends in two-byte alignment padding at 0x021BCF6E.
 * symbols:
 *   PMSIV_MENU_IsEntry2Done 0x021BCDFC thumb ov110
 *   PMSIV_MENU_IsBackItemDone 0x021BCE30 thumb ov110
 *   PMSIV_MENU_IsEntry1Done 0x021BCE70 thumb ov110
 *   PMSIV_MENU_IsEntry0Done 0x021BCEBC thumb ov110
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int PMSIV_MENU_IsEntry2Done(char *);
extern int PMSIV_MENU_IsBackItemDone(char *);
extern int PMSIV_MENU_IsEntry1Done(char *);
extern int PMSIV_MENU_IsEntry0Done(char *);
int PMSIV_MENU_IsPressDone(char *p,u32 mode) { switch(mode) { case 0: return PMSIV_MENU_IsEntry2Done(p); case 1: return PMSIV_MENU_IsBackItemDone(p); case 2: return PMSIV_MENU_IsEntry1Done(p); case 3: return PMSIV_MENU_IsEntry0Done(p); } return 1; }
