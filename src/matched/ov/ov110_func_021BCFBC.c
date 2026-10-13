/*
 * function: PMSIV_MENU_SetDecideEntry
 * address: 0x021BCFBC
 * packet: pkt_ov110_021BCFBC
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   APP_TASKMENU_WIN_SetActive 0x02028218 thumb
 *   APP_TASKMENU_WIN_SetDecide 0x0202822C thumb
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Obj;
extern void APP_TASKMENU_WIN_SetActive(struct Obj *obj, u32 a);
extern void APP_TASKMENU_WIN_SetDecide(char *,int);
void PMSIV_MENU_SetDecideEntry(char *p,u32 index,int value) { int i; for(i=0;i<3;i++) { if (*(void **)((u32)p+(u32)i*4+0x64)) APP_TASKMENU_WIN_SetActive(*(void **)((u32)p+(u32)i*4+0x64),0); } if (*(void **)((u32)p+index*4+0x64)) APP_TASKMENU_WIN_SetDecide(*(char **)((u32)p+index*4+0x64),value); }
