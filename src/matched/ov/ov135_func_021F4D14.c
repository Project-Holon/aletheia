/*
 * function: func_021F4D14
 * address: 0x021F4D14
 * packet: pkt_ov135_021F4D14
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   APP_TASKMENU_UpdateMenu 0x02027974 thumb
 *   APP_TASKMENU_IsFinish 0x020279E8 thumb
 *   APP_TASKMENU_GetCursorPos 0x02027A04 thumb
 *   func_021F5060 0x021F5060 thumb ov135
 */
#include "../include/Obj00045.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void APP_TASKMENU_UpdateMenu(void *);
struct TaskMenu;
extern u32 APP_TASKMENU_IsFinish(struct TaskMenu *m);
extern u8 APP_TASKMENU_GetCursorPos(const u8 *);
extern void func_021F5060(void);
int func_021F4D14(char *p) { int result; result=0; if(((struct Obj00045 *)p)->fE08) { APP_TASKMENU_UpdateMenu(((struct Obj00045 *)p)->fE08); if(APP_TASKMENU_IsFinish(((struct Obj00045 *)p)->fE08)) { result=APP_TASKMENU_GetCursorPos(((struct Obj00045 *)p)->fE08); if(result==0) result=1; else if(result==1) result=2; func_021F5060(); } } return result; }
