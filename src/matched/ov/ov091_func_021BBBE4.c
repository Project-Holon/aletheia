/*
 * function: PLIST_MENU_GetSelectedCommand
 * address: 0x021BBBE4
 * packet: pkt_ov091_021BBBE4
 * region: ov091
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   APP_TASKMENU_IsFinish 0x020279E8 thumb
 *   APP_TASKMENU_GetCursorPos 0x02027A04 thumb
 */
#include "../include/Obj13257.h"
typedef unsigned int   u32;
struct TaskMenu;
extern u32 APP_TASKMENU_IsFinish(struct TaskMenu *m);
typedef unsigned char  u8;
extern u8 APP_TASKMENU_GetCursorPos(const u8 *p);
unsigned int PLIST_MENU_GetSelectedCommand(int a,unsigned char *b) {if(APP_TASKMENU_IsFinish(((struct Obj13257 *)b)->f74)==0)return 23;return *(unsigned short *)((unsigned int)b+APP_TASKMENU_GetCursorPos((const u8 *)(*(int *)&((struct Obj13257 *)b)->f74))*2+2);}
