/*
 * unit: yes
 * function: B_BAG_MAIN_ShowCursorAt,B_BAG_MAIN_HideCursor,B_BAG_MAIN_HideCursor2,B_BAG_MAIN_LayoutCursorOnly
 * address: 0x0220D9A8
 * packet: pkt_ov197_0220D9A8
 * region: ov197
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   B_BAG_MAIN_LayoutCursor 0x0220D98C thumb ov197
 *   B_BAG_MAIN_SetCursorVisible 0x0220D974 thumb ov197
 */
typedef unsigned char u8;typedef unsigned short u16;typedef unsigned int u32;
extern void B_BAG_MAIN_LayoutCursor(u8 *,u32);extern void B_BAG_MAIN_SetCursorVisible(char *,int);
void B_BAG_MAIN_ShowCursorAt(u8 *p,u32 i){B_BAG_MAIN_LayoutCursor(p,i);B_BAG_MAIN_SetCursorVisible((char *)p,1);}
void B_BAG_MAIN_HideCursor(char *p){B_BAG_MAIN_SetCursorVisible(p,0);}
void B_BAG_MAIN_HideCursor2(char *p){B_BAG_MAIN_SetCursorVisible(p,0);}
void B_BAG_MAIN_LayoutCursorOnly(u8 *p,u32 i){B_BAG_MAIN_LayoutCursor(p,i);}
