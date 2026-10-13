/*
 * function: PMSIV_MENU_IsEntryFinished
 * address: 0x021BCFF0
 * packet: pkt_ov110_021BCFF0
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   APP_TASKMENU_WIN_IsFinish 0x02028230 thumb
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u32 APP_TASKMENU_WIN_IsFinish(u8 *);
u32 PMSIV_MENU_IsEntryFinished(char *p,u32 index) { return APP_TASKMENU_WIN_IsFinish(*(u8 **)((u32)p+index*4+0x64)); }
