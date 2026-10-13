/*
 * function: PMSIV_MENU_StartPress
 * address: 0x021BCEE4
 * packet: pkt_ov110_021BCEE4
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * Extent ends in two-byte alignment padding at 0x021BCF16.
 * symbols:
 *   PMSIV_MENU_PressEntry2 0x021BCDE0 thumb ov110
 *   PMSIV_MENU_PressBackItem 0x021BCE24 thumb ov110
 *   PMSIV_MENU_PressEntry1 0x021BCE54 thumb ov110
 *   PMSIV_MENU_PressEntry0 0x021BCEA0 thumb ov110
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void PMSIV_MENU_PressEntry2(u8 *p);
extern void PMSIV_MENU_PressBackItem(void *);
extern void PMSIV_MENU_PressEntry1(char *);
extern void PMSIV_MENU_PressEntry0(char *);
void PMSIV_MENU_StartPress(char *p,u32 mode) { switch(mode) { case 0: PMSIV_MENU_PressEntry2((u8 *)p); break; case 1: PMSIV_MENU_PressBackItem(p); break; case 2: PMSIV_MENU_PressEntry1(p); break; case 3: PMSIV_MENU_PressEntry0(p); break; } }
