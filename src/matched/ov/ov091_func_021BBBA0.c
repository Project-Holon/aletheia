/*
 * function: PLIST_MENU_Close
 * address: 0x021BBBA0
 * packet: pkt_ov091_021BBBA0
 * region: ov091
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   APP_TASKMENU_CloseMenu 0x02027858 thumb
 *   STRBUF_Delete 0x02045808 arm
 *   func_020355C4 0x020355C4 arm
 */
#include "../include/Obj13256.h"
#include "../include/Obj20901.h"
struct TaskMenu;
struct U16Vec;
extern void APP_TASKMENU_CloseMenu(struct TaskMenu *m);
extern void STRBUF_Delete(struct U16Vec *vec);
typedef unsigned char  u8;
extern u8 func_020355C4(void);
void PLIST_MENU_Close(unsigned char *a,unsigned char *b) {unsigned char i;APP_TASKMENU_CloseMenu((struct TaskMenu *)(((struct Obj13256 *)b)->f74));for(i=0;i<b[0];i++)STRBUF_Delete((struct U16Vec *)(*(unsigned int *)((unsigned int)b+(unsigned int)i*12+20)));((struct Obj20901 *)a)->f8=func_020355C4();}
